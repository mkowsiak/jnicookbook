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
#include "recipeNo026_redux_PassArray.h"

JNIEXPORT void JNICALL Java_recipeNo026_redux_PassArray_passBooleanArray
  (JNIEnv * env, jclass obj, jobjectArray array) {

  printf ("Boolean array\n");
  /* get size of the array */
  jsize len = (*env)->GetArrayLength (env, array);

  /* for all elements of outer array (array of objects) */
  for (int i = 0; i < len; i++) {

    /* get the array at following indexes of array
       then, we will get elements of the inner array */
    jbooleanArray body = (*env)->GetObjectArrayElement (env, array, i);
    jsize innerLen = (*env)->GetArrayLength (env, body);

    printf ("  Row %d: ", i);

    /* elements of inner array will be referenced by C pointer */
    jboolean *booleanBody = (*env)->GetBooleanArrayElements (env, body, 0);
    for (int j = 0; j < innerLen; j++) {
      /* do some stuff */
      printf ("%s ", booleanBody[j] == JNI_TRUE ? "true" : "false");
    }
    printf ("\n");

    /* release body when you decide it is no longer needed */
    (*env)->ReleaseBooleanArrayElements (env, body, booleanBody, 0);
  }
}

JNIEXPORT void JNICALL Java_recipeNo026_redux_PassArray_passByteArray
  (JNIEnv * env, jclass obj, jobjectArray array) {

  printf ("Byte array\n");
  /* get size of the array */
  jsize len = (*env)->GetArrayLength (env, array);

  /* for all elements of outer array (array of objects) */
  for (int i = 0; i < len; i++) {

    /* get the array at following indexes of array
       then, we will get elements of the inner array */
    jbyteArray body = (*env)->GetObjectArrayElement (env, array, i);
    jsize innerLen = (*env)->GetArrayLength (env, body);

    printf (" Row %d: ", i);

    /* elements of inner array will be referenced by C pointer */
    jbyte *byteBody = (*env)->GetByteArrayElements (env, body, 0);
    for (int j = 0; j < innerLen; j++) {
      /* do some stuff */
      printf ("%d ", byteBody[j]);
    }
    printf ("\n");

    /* release body when you decide it is no longer needed */
    (*env)->ReleaseByteArrayElements (env, body, byteBody, 0);
  }

}

JNIEXPORT void JNICALL Java_recipeNo026_redux_PassArray_passCharArray
  (JNIEnv * env, jclass obj, jobjectArray array) {

  printf ("Char array\n");
  /* get size of the array */
  jsize len = (*env)->GetArrayLength (env, array);

  /* for all elements of outer array (array of objects) */
  for (int i = 0; i < len; i++) {

    /* get the array at following indexes of array
       then, we will get elements of the inner array */
    jcharArray body = (*env)->GetObjectArrayElement (env, array, i);
    jsize innerLen = (*env)->GetArrayLength (env, body);

    printf (" Row %d: ", i);

    /* elements of inner array will be referenced by C pointer */
    jchar *charBody = (*env)->GetCharArrayElements (env, body, 0);
    for (int j = 0; j < innerLen; j++) {
      /* do some stuff */
      printf ("%c ", charBody[j]);
    }
    printf ("\n");

    /* release body when you decide it is no longer needed */
    (*env)->ReleaseCharArrayElements (env, body, charBody, 0);
  }

}

JNIEXPORT void JNICALL Java_recipeNo026_redux_PassArray_passShortArray
  (JNIEnv * env, jclass obj, jobjectArray array) {

  printf ("Short array\n");
  /* get size of the array */
  jsize len = (*env)->GetArrayLength (env, array);

  /* for all elements of outer array (array of objects) */
  for (int i = 0; i < len; i++) {

    /* get the array at following indexes of array
       then, we will get elements of the inner array */
    jshortArray body = (*env)->GetObjectArrayElement (env, array, i);
    jsize innerLen = (*env)->GetArrayLength (env, body);

    printf (" Row %d: ", i);

    /* elements of inner array will be referenced by C pointer */
    jshort *shortBody = (*env)->GetShortArrayElements (env, body, 0);
    for (int j = 0; j < innerLen; j++) {
      /* do some stuff */
      printf ("%hd ", shortBody[j]);
    }
    printf ("\n");

    /* release body when you decide it is no longer needed */
    (*env)->ReleaseShortArrayElements (env, body, shortBody, 0);
  }

}

JNIEXPORT void JNICALL Java_recipeNo026_redux_PassArray_passIntArray
  (JNIEnv * env, jclass obj, jobjectArray array) {

  printf ("Int array\n");
  /* get size of the array */
  jsize len = (*env)->GetArrayLength (env, array);

  /* for all elements of outer array (array of objects) */
  for (int i = 0; i < len; i++) {

    /* get the array at following indexes of array
       then, we will get elements of the inner array */
    jintArray body = (*env)->GetObjectArrayElement (env, array, i);
    jsize innerLen = (*env)->GetArrayLength (env, body);

    printf (" Row %d: ", i);

    /* elements of inner array will be referenced by C pointer */
    jint *intBody = (*env)->GetIntArrayElements (env, body, 0);
    for (int j = 0; j < innerLen; j++) {
      /* do some stuff */
      printf ("%d ", intBody[j]);
    }
    printf ("\n");

    /* release body when you decide it is no longer needed */
    (*env)->ReleaseIntArrayElements (env, body, intBody, 0);
  }
}

JNIEXPORT void JNICALL Java_recipeNo026_redux_PassArray_passLongArray
  (JNIEnv * env, jclass obj, jlongArray array) {

  printf ("Long array\n");
  /* get size of the array */
  jsize len = (*env)->GetArrayLength (env, array);

  /* for all elements of outer array (array of objects) */
  for (int i = 0; i < len; i++) {

    /* get the array at following indexes of array
       then, we will get elements of the inner array */
    jlongArray body = (*env)->GetObjectArrayElement (env, array, i);
    jsize innerLen = (*env)->GetArrayLength (env, body);

    printf (" Row %d: ", i);

    /* elements of inner array will be referenced by C pointer */
    jlong *longBody = (*env)->GetLongArrayElements (env, body, 0);
    for (int j = 0; j < innerLen; j++) {
      /* do some stuff */
      printf ("%ld ", longBody[j]);
    }
    printf ("\n");

    /* release body when you decide it is no longer needed */
    (*env)->ReleaseLongArrayElements (env, body, longBody, 0);
  }
}

JNIEXPORT void JNICALL Java_recipeNo026_redux_PassArray_passFloatArray
  (JNIEnv * env, jclass obj, jfloatArray array) {

  printf ("Float array\n");
  /* get size of the array */
  jsize len = (*env)->GetArrayLength (env, array);

  /* for all elements of outer array (array of objects) */
  for (int i = 0; i < len; i++) {

    /* get the array at following indexes of array
       then, we will get elements of the inner array */
    jfloatArray body = (*env)->GetObjectArrayElement (env, array, i);
    jsize innerLen = (*env)->GetArrayLength (env, body);

    printf (" Row %d: ", i);

    /* elements of inner array will be referenced by C pointer */
    jfloat *floatBody = (*env)->GetFloatArrayElements (env, body, 0);
    for (int j = 0; j < innerLen; j++) {
      /* do some stuff */
      printf ("%f ", floatBody[j]);
    }
    printf ("\n");

    /* release body when you decide it is no longer needed */
    (*env)->ReleaseFloatArrayElements (env, body, floatBody, 0);
  }
}

JNIEXPORT void JNICALL Java_recipeNo026_redux_PassArray_passDoubleArray
  (JNIEnv * env, jclass obj, jdoubleArray array) {

  printf ("Double array\n");
  /* get size of the array */
  jsize len = (*env)->GetArrayLength (env, array);

  /* for all elements of outer array (array of objects) */
  for (int i = 0; i < len; i++) {

    /* get the array at following indexes of array
       then, we will get elements of the inner array */
    jdoubleArray body = (*env)->GetObjectArrayElement (env, array, i);
    jsize innerLen = (*env)->GetArrayLength (env, body);

    printf (" Row %d: ", i);

    /* elements of inner array will be referenced by C pointer */
    jdouble *doubleBody = (*env)->GetDoubleArrayElements (env, body, 0);
    for (int j = 0; j < innerLen; j++) {
      /* do some stuff */
      printf ("%f ", doubleBody[j]);
    }
    printf ("\n");

    /* release body when you decide it is no longer needed */
    (*env)->ReleaseDoubleArrayElements (env, body, doubleBody, 0);
  }
}
