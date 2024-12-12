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
#include "jni.h"
#include "recipeNo034_redux_HelloWorld.h"
#include "recipeNo034_redux_HelloWorld_NativeWrapper.h"

JNIEXPORT void JNICALL 
  Java_recipeNo034_redux_HelloWorld_displayMessage
  (JNIEnv * env, jclass obj) {

  printf ("Hello world from enclosing class!\n");

}

JNIEXPORT void JNICALL
  Java_recipeNo034_redux_HelloWorld_00024NativeWrapper_displayMessage
  (JNIEnv * env, jobject obj) {

  printf ("Hello world from inner class!\n");

}
