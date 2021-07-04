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
#include "recipeNo037_redux_PassHashMap.h"

JNIEXPORT int JNICALL Java_recipeNo037_redux_PassHashMap_displayHashMap
  (JNIEnv * env, jclass obj, jobject objarg) {

  /* 
    Get objarg's class - objarg is the one we pass from
    Java
  */
  jclass clsHashMap = (*env)->GetObjectClass (env, objarg);

  /* 
    Remember that you can alway get method signature using javap tool
    > javap -s -p java.util.HashMap | grep -A 1 key
    public java.util.Set<K> keySet();
    descriptor: ()Ljava/util/Set;
  */
  jmethodID midKeySet =
    (*env)->GetMethodID (env, clsHashMap, "keySet", "()Ljava/util/Set;");

  /* We have to make sure that method exists */
  if (midKeySet == NULL) {
    return -1;                  /* method not found */
  }

  /* Now, it's time for getting Set of keys */
  jobject objKeySet = (*env)->CallObjectMethod (env, objarg, midKeySet);

  /* Then, we can proceed to accessing keys */
  jclass clsSet = (*env)->GetObjectClass (env, objKeySet);

  /* 
    The same story goes here - use javap to get propper descriptor
    > javap -s -p java.util.Set | grep -A 1 toArray
    public abstract java.lang.Object[] toArray();
    descriptor: ()[Ljava/lang/Object;
  */
  jmethodID midToArray =
    (*env)->GetMethodID (env, clsSet, "toArray", "()[Ljava/lang/Object;");

  /* We have to make sure that method exists */
  if (midKeySet == NULL) {
    return -2;                  /* method not found */
  }

  /* 
    Once we have method, we can call "toArray" and this way
    get array of all keys
  */
  jobjectArray arrayOfKeys =
    (*env)->CallObjectMethod (env, objKeySet, midToArray);

  /* We will iterate over the array so we can get value for each key */
  int arraySize = (*env)->GetArrayLength (env, arrayOfKeys);

  /* We want to go over all elements (all keys) */
  for (int i = 0; i < arraySize; i++) {
    /* First, we need to get key value from array of all keys */
    jstring objKey = (*env)->GetObjectArrayElement (env, arrayOfKeys, i);
    const char *c_string_key = (*env)->GetStringUTFChars (env, objKey, 0);

    /* Once we have key, we can retrieve value for that key */
    jmethodID midGet = 
      (*env)->GetMethodID ( env, 
                            clsHashMap, 
                            "get",
                            "(Ljava/lang/Object;)Ljava/lang/Object;" );


    /* We have to make sure that method exists */
    if (midGet == NULL) {
      return -3;                /* method not found */
    }

    /* It's time to get Value for Key */
    jobject objValue = (*env)->CallObjectMethod (env, objarg, midGet, objKey);
    const char *c_string_value = (*env)->GetStringUTFChars (env, objValue, 0);

    /* Now, we can print values passed to C from Java */
    printf ("[key, value] = [%s, %s]\n", c_string_key, c_string_value);

    /* Make sure to release local stuff */
    (*env)->ReleaseStringUTFChars (env, objKey, c_string_key);
    (*env)->DeleteLocalRef (env, objKey);

    (*env)->ReleaseStringUTFChars (env, objValue, c_string_value);
    (*env)->DeleteLocalRef (env, objValue);
  }

  return 0;

}
