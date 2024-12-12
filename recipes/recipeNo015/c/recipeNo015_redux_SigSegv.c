/*
 * Copyright © 2015-2022 Michal K. Owsiak. All rights reserved.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#include <stdio.h>
#include <signal.h>
#include <setjmp.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "jni.h"
#include "recipeNo015_redux_SigSegv.h"
#include "recipeNo015_redux_SigSegvNoHandler.h"

jmp_buf ljenv;

// OS X uses SIGBUS in case of accessing incorrect memory region
// Linux will use SIGSEGV - this is why we should use two handlers
// there are 31 possible signals we can handle
struct sigaction actions[31];

// this function will set the handler for signal
void setup_signal_handler (int sig, void (*handler) (), struct sigaction *old) {
  struct sigaction action;

  // fill action structure
  // pointer to function that will handle signal
  action.sa_handler = handler;

  // for the masks description take a look
  // at "man sigaction"
  sigemptyset (&(action.sa_mask));
  sigaddset (&(action.sa_mask), sig);

  // you can bring back original signal using
  // SA_RESETHAND passed inside sa_flags
  action.sa_flags = 0;

  // and set new handler for signal 
  sigaction (sig, &action, &actions[sig - 1]);
}

// this function will be called whenever signal occurs
void handler (int handle) {
  // be very condense here
  // just do essential stuff and get
  // back to the place you want to be
  write (STDOUT_FILENO, "Hello from handler\n",
         strlen ("Hello from handler\n"));
  // set original signal handler
  sigaction (handle, &actions[handle - 1], NULL);
  // and jump to where we have set long jump
  siglongjmp (ljenv, 1);
}

// the purpose of this code is to generate SIGSEGV/SIGBUS
void riskyCode () {
  char *error_str = "This code will fail with SIGSEGV";
  *error_str = 'g';
}

// riskCode protected by handler
// this method will not crash JVM
JNIEXPORT void JNICALL Java_recipeNo015_redux_SigSegv_callRiskyCode
  (JNIEnv * env, jclass obj) {

  // setup signal handlers
  // signals are counted from 1 - 31. Array indexes are
  // counted from 0 - 30. This is why we do 10-1 and 11-1
  setup_signal_handler (10, handler, &actions[10 - 1]);
  setup_signal_handler (11, handler, &actions[11 - 1]);

  // set the long jump for the signal handler
  // if handler is called it will jump
  // here with the error code specified
  // as parameter of siglongjmp
  // first call to sigsetjmp returns 0
  if (sigsetjmp (ljenv, 1) == 0) {
    // call the code that will fail
    riskyCode ();
  } else {
    // we can allocate a little bit more than we require
    char exceptionBuffer[1024];
    sprintf (exceptionBuffer, "Error");
    (*env)->ThrowNew (env,
                      (*env)->FindClass (env,
                                         "java/lang/Exception"),
                      exceptionBuffer);
  }

  // if everything was OK, we can set old handlers
  sigaction (10, &actions[10 - 1], NULL);
  sigaction (11, &actions[11 - 1], NULL);
}

// unprotected call to riskyCode; JVM will crash completely
// and will produce hs_er file
JNIEXPORT void JNICALL
Java_recipeNo015_redux_SigSegvNoHandler_callRiskyCodeNoHandler (JNIEnv * env,
                                                                jclass obj) {

  // we are calling risky code, but we don't set SIGBUS/SIGSEGV handler
  riskyCode ();
}
