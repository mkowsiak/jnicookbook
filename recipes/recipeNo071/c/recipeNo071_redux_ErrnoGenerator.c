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
#include <stdlib.h>
#include <string.h>
#include <sys/errno.h>
#include "recipeNo071_redux_ErrnoGenerator.h"

JNIEXPORT void JNICALL Java_recipeNo071_redux_ErrnoGenerator_generateErrno
  (JNIEnv * env, jobject obj, jboolean shouldIFail) {

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

  if(shouldIFail) { 
    // This one will most probably fail
    fp = fopen("/this_will_fail", "r");
  } else {
    // This one has great chance of succeeding
    fp = fopen("/tmp/some_file", "w");
  }

  // We check error code only in case result indicates that there
  // might have been error while callin system call

  if( fp == NULL ) {
    // Let's get errno and errno related message in case there was an error while
    sprintf(  exceptionBuffer, 
              "[C] %s: errno: %d message: %s", 
              shouldIFail ? "true " : "false", errno, strerror(errno) );
    printf("%s\n", exceptionBuffer);
  } else {
    // Otherwise, just print some message
    sprintf(  exceptionBuffer, 
              "[C] %s: everything went fine - no much sense to check errno", 
              shouldIFail ? "true " : "false" );
    printf("%s\n", exceptionBuffer);
  }

}

JNIEXPORT jint JNICALL Java_recipeNo071_redux_ErrnoGenerator_getErrno
  (JNIEnv *env, jclass obj) {

  return errno;

}

