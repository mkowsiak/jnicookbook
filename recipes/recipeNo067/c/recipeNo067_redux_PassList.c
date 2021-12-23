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
#include "recipeNo067_redux_PassList.h"

JNIEXPORT void JNICALL Java_recipeNo067_redux_PassList_passObjectsAsList
  (JNIEnv * env, jclass cls, jobject list) {

  // Let's get class of object passed as argument
  jclass    cls_List = (*env)->GetObjectClass (env, list);

  // we have to get signature of method 'int size()' - to know 
  // the size of the List
  jmethodID mid_size = (*env)->GetMethodID (env, cls_List, "size",
                                            "()I");

  // once we have size's signature, we can call it
  int       elem_cnt = (*env)->CallIntMethod (env, list, mid_size);

  for (int i = 0; i < elem_cnt; i++) {


    // I am accessing objects inside java.util.List using get method
    // We have to have it's ID
    jmethodID mid_get  = (*env)->GetMethodID (env, cls_List, "get",
                                            "(I)Ljava/lang/Object;");

    // Once we have ID, we can call the method - result is an 
    // object at index 'i'
    jobject   obj      = (*env)->CallObjectMethod (env, list, mid_get, i);

    // Now, let's get ID of the method that will provide us with the 'name'
    // that is stored inside SimpleBean. First of all, let's get the class
    // of the object
    jclass    cls_SimpleBean  = (*env)->GetObjectClass(env, obj);

    // And we can learn what is the ID of method 'getName'
    jmethodID fid_getName     = (*env)->GetMethodID( 
                                            env, 
                                            cls_SimpleBean, 
                                            "getName", 
                                            "()Ljava/lang/String;" );

    // Once we have everything, we can get the value of 'name' that is stored
    // inside 'SimpleBean'
    jobject   name            = (*env)->CallObjectMethod(env, obj, fid_getName);

    // after converting Java style String to C based array of characters
    const char *c_string = (*env)->GetStringUTFChars (env, name, 0);

    // we can print it on the stdout
    printf ("[name] = %s\n", c_string);

    // and release memory used for transfering data from Java to C
    (*env)->ReleaseStringUTFChars (env, name, c_string);
  }
  
}
