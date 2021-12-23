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
#include "recipeNo055_redux_PassObject.h"

/*

  Note that for method signatures (like intValue, etc.) you
  have to pay attention to return values.

  You can always get method's signature using javap

  > javap -s java.lang.Integer | grep -A 2 intValue
    public int intValue();
      descriptor: ()I

  For primitive types, list of types follows:

  +---+---------+
  | Z | boolean |
  | B | byte    |
  | C | char    |
  | S | short   |
  | I | int     |
  | J | long    |
  | F | float   |
  | D | double  |
  +-------------+
  
*/

JNIEXPORT void JNICALL Java_recipeNo055_redux_PassObject_passBoolean
  (JNIEnv * env, jclass obj, jobject objarg) {

  jclass cls = (*env)->GetObjectClass (env, objarg);

  jmethodID booleanValue = (*env)->GetMethodID(env, cls, "booleanValue", "()Z"); 

  jboolean result = (*env)->CallBooleanMethod(env, objarg, booleanValue);

  printf("%-22s: %s\n", "Passed value (boolean)", 
    result == JNI_TRUE ? "true" : "false");

}

JNIEXPORT void JNICALL Java_recipeNo055_redux_PassObject_passByte
  (JNIEnv * env, jclass obj, jobject objarg) {

  jclass cls = (*env)->GetObjectClass (env, objarg);

  jmethodID byteValue = (*env)->GetMethodID(env, cls, "byteValue", "()B"); 

  jbyte result = (*env)->CallByteMethod(env, objarg, byteValue);

  printf("%-22s: %d\n", "Passed value (byte)", result);


}

JNIEXPORT void JNICALL Java_recipeNo055_redux_PassObject_passCharacter
  (JNIEnv * env, jclass obj, jobject objarg) {

  jclass cls = (*env)->GetObjectClass (env, objarg);

  jmethodID charValue = (*env)->GetMethodID(env, cls, "charValue", "()C"); 

  jchar result = (*env)->CallCharMethod(env, objarg, charValue);

  printf("%-22s: %c\n", "Passed value (char)", result);


}

JNIEXPORT void JNICALL Java_recipeNo055_redux_PassObject_passFloat
  (JNIEnv * env, jclass obj, jobject objarg) {

  jclass cls = (*env)->GetObjectClass (env, objarg);

  jmethodID floatValue = (*env)->GetMethodID(env, cls, "floatValue", "()F"); 

  jfloat result = (*env)->CallFloatMethod(env, objarg, floatValue);

  printf("%-22s: %f\n", "Passed value (float)", result);


}

JNIEXPORT void JNICALL Java_recipeNo055_redux_PassObject_passInteger
  (JNIEnv * env, jclass obj, jobject objarg) {

  jclass cls = (*env)->GetObjectClass (env, objarg);

  jmethodID intValue = (*env)->GetMethodID(env, cls, "intValue", "()I"); 

  jint result = (*env)->CallIntMethod(env, objarg, intValue);

  printf("%-22s: %d\n", "Passed value (int)", result);


}

JNIEXPORT void JNICALL Java_recipeNo055_redux_PassObject_passLong
  (JNIEnv * env, jclass obj, jobject objarg) {

  jclass cls = (*env)->GetObjectClass (env, objarg);

  jmethodID longValue = (*env)->GetMethodID(env, cls, "longValue", "()J"); 

  jlong result = (*env)->CallLongMethod(env, objarg, longValue);

  printf("%-22s: %ld\n", "Passed value (long)", result);


}

JNIEXPORT void JNICALL Java_recipeNo055_redux_PassObject_passShort
  (JNIEnv * env, jclass obj, jobject objarg) {

  jclass cls = (*env)->GetObjectClass (env, objarg);

  jmethodID shortValue = (*env)->GetMethodID(env, cls, "shortValue", "()S"); 

  jshort result = (*env)->CallShortMethod(env, objarg, shortValue);

  printf("%-22s: %hd\n", "Passed value (short)", result);


}

JNIEXPORT void JNICALL Java_recipeNo055_redux_PassObject_passDouble
  (JNIEnv * env, jclass obj, jobject objarg) {

  jclass cls = (*env)->GetObjectClass (env, objarg);

  jmethodID doubleValue = (*env)->GetMethodID(env, cls, "doubleValue", "()D"); 

  jdouble result = (*env)->CallDoubleMethod(env, objarg, doubleValue);

  printf("%-22s: %f\n", "Passed value (double)", result);

}

