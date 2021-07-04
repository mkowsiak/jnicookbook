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
#include "recipeNo044_redux_GetCurrentThread.h"

JNIEXPORT void JNICALL Java_recipeNo044_redux_GetCurrentThread_displayMessage
  (JNIEnv * env, jclass obj) {

  // First, we have to find Thread class
  jclass cls = (*env)->FindClass (env, "java/lang/Thread");

  // Then, we can look for it's static method 'currentThread'
  /* 
    Remember that you can always get method signature using javap tool
    > javap -s -p java.lang.Thread | grep -A 1 currentThread
    public static native java.lang.Thread currentThread();
    descriptor: ()Ljava/lang/Thread; 
  */
  jmethodID mid = (*env)->GetStaticMethodID (env, cls, "currentThread",
                                             "()Ljava/lang/Thread;");

  // Once you have method, you can call it. Remember that result is
  // a jobject 
  jobject thread = (*env)->CallStaticObjectMethod (env, cls, mid);
  if (thread == NULL) {
    printf ("Error while calling static method: currentThread\n");
  }
  // Now, we have to find another method - 'getId'
  /* 
    Remember that you can always get method signature using javap tool
    > javap -s -p java.lang.Thread | grep -A 1 getId
    public long getId();
    descriptor: ()Jjavap -s -p java.lang.Thread | grep -A 1 currentThread
  */
  jmethodID mid_getid = (*env)->GetMethodID (env, cls, "getId", "()J");
  if (mid_getid == NULL) {
    printf ("Error while calling GetMethodID for: getId\n");
  }

  // This time, we are calling instance method, note the difference
  // in Call... method 
  jlong tid = (*env)->CallLongMethod (env, thread, mid_getid);

  // Finally, let's call 'getName' of Thread object
  /* 
    Remember that you can always get method signature using javap tool
    > javap -s -p java.lang.Thread | grep -A 1 getName
    public final java.lang.String getName();
    descriptor: ()Ljava/lang/String;
  */
  jmethodID mid_getname =
    (*env)->GetMethodID (env, cls, "getName", "()Ljava/lang/String;");

  if (mid_getname == NULL) {
    printf ("Error while calling GetMethodID for: getName\n");
  }
  // As above, we are calling instance method 
  jobject tname = (*env)->CallObjectMethod (env, thread, mid_getname);

  // Remember to retrieve characters from String object
  const char *c_str;
  c_str = (*env)->GetStringUTFChars (env, tname, NULL);
  if (c_str == NULL) {
    return;
  }
  // display message from JNI
  printf ("[C   ] name: %s id: %ld\n", c_str, tid);

  // and make sure to release allocated memory before leaving JNI
  (*env)->ReleaseStringUTFChars (env, tname, c_str);
}
