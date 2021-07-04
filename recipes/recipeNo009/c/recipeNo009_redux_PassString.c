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
#include "recipeNo009_redux_PassString.h"

JNIEXPORT void JNICALL Java_recipeNo009_redux_PassString_displayString
  (JNIEnv * env, jclass obj, jstring str) {

  //we have to get string bytes into C string
  const char *c_str;

  c_str = (*env)->GetStringUTFChars (env, str, NULL);
  
  if (c_str == NULL) {
    return;
  }
  printf ("Passed string: %s\n", c_str);

  //after using it, remember to release the memory
  (*env)->ReleaseStringUTFChars (env, str, c_str);
}
