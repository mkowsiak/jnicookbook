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
#include "recipeNo014_redux_CreateArray.h"

JNIEXPORT jbooleanArray JNICALL
  Java_recipeNo014_redux_CreateArray_createBooleanArray 
  (JNIEnv * env, jclass obj, int size) {

  //create array that will be passed back to Java
  jbooleanArray array = (jbooleanArray) (*env)->NewBooleanArray (env, size);
  if (array == NULL) {
    return NULL;
  }
  //allocate and fill C based array
  jboolean *boolean_ptr = calloc (size, sizeof (jboolean));
  if (boolean_ptr == NULL) {
    return NULL;
  }
  for (int i = 0; i < size; i++) {
    boolean_ptr[i] = i % 2 == 0 ? JNI_TRUE : JNI_FALSE;
  }

  (*env)->SetBooleanArrayRegion (env, array, 0, size,
                                 (jboolean *) boolean_ptr);

  //release native memory region
  free( boolean_ptr );
  
  return array;

}

JNIEXPORT jbyteArray JNICALL 
  Java_recipeNo014_redux_CreateArray_createByteArray
  (JNIEnv * env, jclass obj, int size) {

  //create array that will be passed back to Java
  jbyteArray array = (jbyteArray) (*env)->NewByteArray (env, size);
  if (array == NULL) {
    return NULL;
  }
  //allocate and fill C based array
  jbyte *byte_ptr = calloc (size, sizeof (jbyte));
  if (byte_ptr == NULL) {
    return NULL;
  }
  for (int i = 0; i < size; i++) {
    byte_ptr[i] = i % 2 == 0 ? -128 : 127;
  }

  (*env)->SetByteArrayRegion (env, array, 0, size, (jbyte *) byte_ptr);

  //release native memory region
  free( byte_ptr );

  return array;

}

JNIEXPORT jcharArray JNICALL 
  Java_recipeNo014_redux_CreateArray_createCharArray
  (JNIEnv * env, jclass obj, int size) {

  //create array that will be passed back to Java
  jcharArray array = (jcharArray) (*env)->NewCharArray (env, size);
  if (array == NULL) {
    return NULL;
  }
  //allocate and fill C based array
  jchar *char_ptr = calloc (size, sizeof (jchar));
  if (char_ptr == NULL) {
    return NULL;
  }
  for (int i = 0; i < size; i++) {
    char_ptr[i] = i % 2 == 0 ? 'a' : 'b';
  }

  (*env)->SetCharArrayRegion (env, array, 0, size, (jchar *) char_ptr);

  //release native memory region
  free( char_ptr );

  return array;

}


JNIEXPORT jshortArray JNICALL 
  Java_recipeNo014_redux_CreateArray_createShortArray
  (JNIEnv * env, jclass obj, int size) {

  //create array that will be passed back to Java
  jshortArray array = (jshortArray) (*env)->NewShortArray (env, size);
  if (array == NULL) {
    return NULL;
  }
  //allocate and fill C based array
  jshort *short_ptr = calloc (size, sizeof (jshort));
  if (short_ptr == NULL) {
    return NULL;
  }
  for (int i = 0; i < size; i++) {
    short_ptr[i] = i % 2 == 0 ? 0xff : 0;
  }

  (*env)->SetShortArrayRegion (env, array, 0, size, (jshort *) short_ptr);

  //release native memory region
  free( short_ptr );  

  return array;

}

JNIEXPORT jintArray JNICALL 
  Java_recipeNo014_redux_CreateArray_createIntArray
  (JNIEnv * env, jclass obj, int size) {

  //create array that will be passed back to Java
  jintArray array = (jintArray) (*env)->NewIntArray (env, size);
  if (array == NULL) {
    return NULL;
  }
  //allocate and fill C based array
  jint *int_ptr = calloc (size, sizeof (jint));
  if (int_ptr == NULL) {
    return NULL;
  }
  for (int i = 0; i < size; i++) {
    int_ptr[i] = i % 2 == 0 ? 0xffffffff : 0;
  }

  (*env)->SetIntArrayRegion (env, array, 0, size, (jint *) int_ptr);

  //release native memory region
  free( int_ptr );

  return array;

}

JNIEXPORT jlongArray JNICALL 
  Java_recipeNo014_redux_CreateArray_createLongArray
  (JNIEnv * env, jclass obj, int size) {

  //create array that will be passed back to Java
  jlongArray array = (jlongArray) (*env)->NewLongArray (env, size);
  if (array == NULL) {
    return NULL;
  }
  //allocate and fill C based array
  jlong *long_ptr = calloc (size, sizeof (jlong));
  if (long_ptr == NULL) {
    return NULL;
  }
  for (int i = 0; i < size; i++) {
    long_ptr[i] = i % 2 == 0 ? 0xffffffffffffffff : 0;
  }

  (*env)->SetLongArrayRegion (env, array, 0, size, (jlong *) long_ptr);

  //release native memory region
  free( long_ptr );

  return array;

}

JNIEXPORT jfloatArray JNICALL 
  Java_recipeNo014_redux_CreateArray_createFloatArray
  (JNIEnv * env, jclass obj, int size) {

  //create array that will be passed back to Java
  jfloatArray array = (jfloatArray) (*env)->NewFloatArray (env, size);
  if (array == NULL) {
    return NULL;
  }
  //allocate and fill C based array
  jfloat *float_ptr = calloc (size, sizeof (jfloat));
  if (float_ptr == NULL) {
    return NULL;
  }
  for (int i = 0; i < size; i++) {
    float_ptr[i] = i % 2 == 0 ? 1.1 : 2.2;
  }

  (*env)->SetFloatArrayRegion (env, array, 0, size, (jfloat *) float_ptr);

  //release native memory region
  free( float_ptr );

  return array;

}

JNIEXPORT jdoubleArray JNICALL 
  Java_recipeNo014_redux_CreateArray_createDoubleArray
  (JNIEnv * env, jclass obj, int size) {

  //create array that will be passed back to Java
  jdoubleArray array = (jdoubleArray) (*env)->NewDoubleArray (env, size);
  if (array == NULL) {
    return NULL;
  }
  //allocate and fill C based array
  jdouble *double_ptr = calloc (size, sizeof (jdouble));
  if (double_ptr == NULL) {
    return NULL;
  }
  for (int i = 0; i < size; i++) {
    double_ptr[i] = i % 2 == 0 ? 1.1 : 2.2;
  }

  (*env)->SetDoubleArrayRegion (env, array, 0, size, (jdouble *) double_ptr);

  //release native memory region
  free( double_ptr );

  return array;

}
