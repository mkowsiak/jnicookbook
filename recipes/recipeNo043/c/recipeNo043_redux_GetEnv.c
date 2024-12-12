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
#include "jni.h"
#include "recipeNo043_redux_GetEnv.h"

JNIEXPORT void JNICALL Java_recipeNo043_redux_GetEnv_getenv
  (JNIEnv * env, jclass obj, jstring strkey) {

  // we have to get string bytes into C string
  const char *c_str_key;
  c_str_key = (*env)->GetStringUTFChars (env, strkey, NULL);
  if (c_str_key == NULL) {
    return;
  }

  char *value = getenv (c_str_key);

  printf ("Getting env variable: '%s' - it has value: '%s'\n", c_str_key,
          value);

  // after using it, remember to release the memory
  (*env)->ReleaseStringUTFChars (env, strkey, c_str_key);

}
