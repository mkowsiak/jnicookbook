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
#include <limits.h>
#include "jni.h"
#include "recipeNo058_redux_PassLongAsString.h"

JNIEXPORT void JNICALL Java_recipeNo058_redux_PassLongAsString_passULong
  (JNIEnv * env, jclass obj, jstring str) {

  //we have to get string bytes into C string
  const char *c_str;
  const char *errstr;

  c_str = (*env)->GetStringUTFChars (env, str, NULL);
  
  if (c_str == NULL) {
    return;
  }

  printf ("Passed string:          %s\n", c_str);
  unsigned long ul = strtoul(c_str, NULL, 0); 
  printf ("Parsed value (64bit):   %lu\n", ul);
  printf ("Parsed value (32bit):   %u\n", (unsigned int) ul);

  //after using it, remember to release the memory
  (*env)->ReleaseStringUTFChars (env, str, c_str);
}
