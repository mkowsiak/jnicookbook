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
#include "jni.h"
#include "recipeNo038_redux_PassHashMap.h"

JNIEXPORT int JNICALL Java_recipeNo038_redux_PassHashMap_displayHashMap
  (JNIEnv * env, jclass obj, jobjectArray keys, jobjectArray values) {

  /* We need to get array size. There is strong assumption that
     keys and values have the same length
   */
  int arraySize = (*env)->GetArrayLength (env, keys);

  /* For all elements in array, we will convert them to C based strings
   */
  for (int i = 0; i < arraySize; i++) {
    /* First, we take key */
    jstring objKey = (*env)->GetObjectArrayElement (env, keys, i);
    const char *c_string_key = (*env)->GetStringUTFChars (env, objKey, 0);

    /* Then, we take the value value  */
    jobject objValue = (*env)->GetObjectArrayElement (env, values, i);
    const char *c_string_value = (*env)->GetStringUTFChars (env, objValue, 0);

    /* And we print some info for user */
    printf ("[key, value] = [%s, %s]\n", c_string_key, c_string_value);

    /* Make sure to release stuff */
    (*env)->ReleaseStringUTFChars (env, objKey, c_string_key);
    (*env)->DeleteLocalRef (env, objKey);

    (*env)->ReleaseStringUTFChars (env, objValue, c_string_value);
    (*env)->DeleteLocalRef (env, objValue);
  }

  return 0;

}
