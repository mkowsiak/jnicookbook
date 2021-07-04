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
#include "recipeNo079_redux_PassObject.h"

JNIEXPORT void JNICALL Java_recipeNo079_redux_PassObject_passObject
  (JNIEnv * env, jclass obj, jobject objarg) {

  /* 
    Get objarg's class - objarg is the one we pass from
    Java 
  */
  jclass cls = (*env)->GetObjectClass (env, objarg);

  /* 
    For accessing primitive types from class use
    following field descriptors

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

  /* 
    Get int field

    Take a look here, we are passing char* with
    field descriptor - e.g. "I" => int
  */

  jfieldID fidInt = (*env)->GetFieldID (env, cls, "iVal", "I");
  jint iVal = (*env)->GetIntField (env, objarg, fidInt);
  printf ("iVal: %d\n", iVal);

  (*env)->SetIntField (env, objarg, fidInt, 42);

  /* Get String field */
  jfieldID fidString =
    (*env)->GetFieldID (env, cls, "sVal", "Ljava/lang/String;");
  jobject sVal = (*env)->GetObjectField (env, objarg, fidString);

  // we have to get string bytes into C string
  const char *c_str;
  c_str = (*env)->GetStringUTFChars (env, sVal, NULL);
  if (c_str == NULL) {
    return;
  }

  printf ("sVal: %s\n", c_str);

  // after using it, remember to release the memory
  (*env)->ReleaseStringUTFChars (env, sVal, c_str);

  // Now, we want to pass value from C to Java
  char buffer[] = "This is a sample string from C";

  jobject newString = (*env)->NewStringUTF(env, buffer);
  (*env)->SetObjectField (env, objarg, fidString, newString);

}
