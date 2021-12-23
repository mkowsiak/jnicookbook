/*
 * Copyright © 2021 Michal K. Owsiak. All rights reserved.
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
#include <stdlib.h>
#include <string.h>
#include <sys/errno.h>
#include "recipeNo072_redux_ErrnoGenerator.h"

JNIEXPORT void JNICALL Java_recipeNo072_redux_ErrnoGenerator_generateErrno
  (JNIEnv * env, jobject obj) {

  // Heavily oversized buffer
  // Note that I don't perform any bounds check while
  // calling sprintf 
  char exceptionBuffer[1024];

  FILE *fp = NULL;

  // Setting errno to 0 - before system call
  // e.g.: The CERT ® C Coding Standard: 98 Rules for Developing Safe, Reliable, 
  //       and Secure Systems, Second Edition
  // advises to do so
  errno = 0;

  // This one will most probably fail
  fp = fopen("/this_will_fail", "r");

  if( fp == NULL ) {
    // Let's get errno and errno related message in case there was an error while
    sprintf( exceptionBuffer, "[C] errno: %d message: %s", errno, strerror(errno) );
    printf("%s\n", exceptionBuffer);

    jclass exCls
      = (*env)->FindClass( env, "recipeNo072/redux/ErrnoException" );
    jmethodID exConstructorID
      = (*env)->GetMethodID( env, exCls, "<init>", "(Ljava/lang/String;I)V" );
    jobject exObj
      = (*env)->NewObject( 
                  env, 
                  exCls, 
                  exConstructorID, 
                  (*env)->NewStringUTF( env, strerror(errno)), errno );
    
    (*env)->Throw( env, exObj );
  }

}

