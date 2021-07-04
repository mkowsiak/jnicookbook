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
#include "recipeNo011_redux_ReturnPrimitive.h"

JNIEXPORT jboolean JNICALL Java_recipeNo011_redux_ReturnPrimitive_getBoolean
  (JNIEnv * env, jclass obj) {

  jboolean result = JNI_TRUE;
  return result;
}

JNIEXPORT jbyte JNICALL Java_recipeNo011_redux_ReturnPrimitive_getByte
  (JNIEnv * env, jclass obj) {

  jbyte result = 0xff;
  return result;
}

JNIEXPORT jchar JNICALL Java_recipeNo011_redux_ReturnPrimitive_getChar
  (JNIEnv * env, jclass obj) {

  jchar result = 'a';
  return result;
}

JNIEXPORT jshort JNICALL Java_recipeNo011_redux_ReturnPrimitive_getShort
  (JNIEnv * env, jclass obj) {

  jshort result = 0xffff;
  return result;
}

JNIEXPORT jint JNICALL Java_recipeNo011_redux_ReturnPrimitive_getInt
  (JNIEnv * env, jclass obj) {

  jint result = 0xffffffff;
  return result;
}

JNIEXPORT jlong JNICALL Java_recipeNo011_redux_ReturnPrimitive_getLong
  (JNIEnv * env, jclass obj) {

  jlong result = 0xffffffffffffffff;
  return result;
}

JNIEXPORT jfloat JNICALL Java_recipeNo011_redux_ReturnPrimitive_getFloat
  (JNIEnv * env, jclass obj) {

  jfloat result = 1.1;
  return result;
}

JNIEXPORT jdouble JNICALL Java_recipeNo011_redux_ReturnPrimitive_getDouble
  (JNIEnv * env, jclass obj) {

  jdouble result = 1.1;
  return result;
}
