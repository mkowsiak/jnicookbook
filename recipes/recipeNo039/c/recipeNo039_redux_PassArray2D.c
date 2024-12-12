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
#include "recipeNo039_redux_PassArray2D.h"

JNIEXPORT int JNICALL Java_recipeNo039_redux_PassArray2D_displayArray2D
  (JNIEnv * env, jclass obj) {

  /* 
    Get objarg's class - objarg is the one we pass from
    Java 
  */
  jclass cls = (*env)->GetObjectClass (env, obj);

  /* 
    Remember that you can alway get method signature using javap tool
    > javap -classpath target -s \
      -p recipeNo039.redux.PassArray2D | grep -A +1 getDoubleData
    public double[][] getDoubleData();
    descriptor: ()[[D
  */
  jmethodID mid = (*env)->GetMethodID (env, cls, "getDoubleData", "()[[D");

  /* We have to make sure that method exists */
  if (mid == NULL) {
    return -1;                  /* method not found */
  }

  /* Now, it's time for getting array of arrays */
  jobject objArray = (*env)->CallObjectMethod (env, obj, mid);

  /* We will iterate over the array so we can get into next array */
  int arraySize = (*env)->GetArrayLength (env, objArray);

  /* We want to go over all elements (all sub arrays) */
  for (int i = 0; i < arraySize; i++) {
    jdoubleArray array = (*env)->GetObjectArrayElement (env, objArray, i);

    /* get size of the array */
    jsize len = (*env)->GetArrayLength (env, array);

    /* get the body of array; it will be referecende by C pointer */
    jdouble *body = (*env)->GetDoubleArrayElements (env, array, 0);

    /* do some stuff */
    for (int p = 0; p < len; p++) {
      printf ("Double value [%d;%d]: %f\n", i, p, body[p]);
    }

    /* release body when you decide it is no longer needed */
    (*env)->ReleaseDoubleArrayElements (env, array, body, 0);
  }

  return 0;

}
