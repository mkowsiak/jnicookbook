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
#include "recipeNo056_redux_PassObject.h"

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

JNIEXPORT void JNICALL Java_recipeNo056_redux_PassObject_passBoxedValue
  (JNIEnv * env, jclass obj, jobject objarg) {

  jclass cls = (*env)->GetObjectClass (env, objarg);

  if( (*env)->IsInstanceOf(
                env, 
                objarg, 
                (*env)->FindClass(env, "java/lang/Boolean")) ) {

    jmethodID booleanValue 
      = (*env)->GetMethodID(env, cls, "booleanValue", "()Z");
    jboolean result = (*env)->CallBooleanMethod(env, objarg, booleanValue);

    printf("%-22s: %s\n", "Passed value (boolean)", 
      result == JNI_TRUE ? "true" : "false");

  } else if( (*env)->IsInstanceOf(
                      env, 
                      objarg, 
                      (*env)->FindClass(env, "java/lang/Byte")) ) {

    jmethodID byteValue = (*env)->GetMethodID(env, cls, "byteValue", "()B"); 
    jbyte result = (*env)->CallByteMethod(env, objarg, byteValue);
    printf("%-22s: %d\n", "Passed value (byte)", result);

  } else if( (*env)->IsInstanceOf(
                      env, 
                      objarg, 
                      (*env)->FindClass(env, "java/lang/Character")) ) {
  
    jmethodID charValue = (*env)->GetMethodID(env, cls, "charValue", "()C"); 
    jchar result = (*env)->CallCharMethod(env, objarg, charValue);
    printf("%-22s: %c\n", "Passed value (char)", result);

  } else if( (*env)->IsInstanceOf(
                      env, 
                      objarg, 
                      (*env)->FindClass(env, "java/lang/Float")) ) {
  
    jmethodID floatValue = (*env)->GetMethodID(env, cls, "floatValue", "()F"); 
    jfloat result = (*env)->CallFloatMethod(env, objarg, floatValue);
    printf("%-22s: %f\n", "Passed value (float)", result);

  } else if( (*env)->IsInstanceOf(
                      env, 
                      objarg, 
                      (*env)->FindClass(env, "java/lang/Integer")) ) {

    jmethodID intValue = (*env)->GetMethodID(env, cls, "intValue", "()I"); 
    jint result = (*env)->CallIntMethod(env, objarg, intValue);
    printf("%-22s: %d\n", "Passed value (int)", result);

  } else if( (*env)->IsInstanceOf(
                      env, 
                      objarg, 
                      (*env)->FindClass(env, "java/lang/Long")) ) {

    jmethodID longValue = (*env)->GetMethodID(env, cls, "longValue", "()J"); 
    jlong result = (*env)->CallLongMethod(env, objarg, longValue);
    printf("%-22s: %ld\n", "Passed value (long)", result);

  } else if( (*env)->IsInstanceOf(
                      env, 
                      objarg, 
                      (*env)->FindClass(env, "java/lang/Short")) ) {

    jmethodID shortValue = (*env)->GetMethodID(env, cls, "shortValue", "()S"); 
    jshort result = (*env)->CallShortMethod(env, objarg, shortValue);
    printf("%-22s: %hd\n", "Passed value (short)", result);

  } else if( (*env)->IsInstanceOf(
                      env, 
                      objarg, 
                      (*env)->FindClass(env, "java/lang/Double")) ) {

    jmethodID doubleValue = (*env)->GetMethodID(env, cls, "doubleValue", "()D"); 
    jdouble result = (*env)->CallDoubleMethod(env, objarg, doubleValue);
    printf("%-22s: %f\n", "Passed value (double)", result);

  } else {
  
    printf("You are trying to pass incorrect value\n");

  }
  
}
