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
#include "recipeNo016_redux_SigTerm.h"
#include "recipeNo016_redux_SigTermNoHandler.h"

jmp_buf ljenv;

// declaration of function for the lib
void riskyCode ();

// this is the handler for the risky code
// if we reach here, it means somebody
// tried to call exit
void stopExit () {
  siglongjmp (ljenv, 1);
}

// riskCode protected by handler
// this method will not exit from JVM
// instead, it will throw exception
JNIEXPORT void JNICALL Java_recipeNo016_redux_SigTerm_callExitCode
  (JNIEnv * env, jclass obj) {

  atexit (stopExit);
  // set the long jump for the exit call handler
  // if handler is called it will jump
  // here with the error code specified
  // as parameter of siglongjmp
  // first call to sigsetjmp returns 0
  if (sigsetjmp (ljenv, 1) == 0) {
    // call the code that will try to exit
    riskyCode ();
  } else {
    // if the code tries to call exit, we are handling it
    // we can allocate a little bit more than we require
    char exceptionBuffer[1024];
    sprintf (exceptionBuffer, "Error");
    (*env)->ThrowNew (env,
                      (*env)->FindClass (env, "java/lang/Exception"),
                      exceptionBuffer);
  }
}

// unprotected call to riskyCode; JVM will exit after this call
JNIEXPORT void JNICALL 
Java_recipeNo016_redux_SigTermNoHandler_callExitCodeNoHandler(JNIEnv * env, 
                                                              jclass obj) {

  // we are calling risky code, but we don't set exit handler
  riskyCode ();
}
