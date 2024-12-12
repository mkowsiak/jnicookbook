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
#include "recipeNo068_redux_PassList.h"

JNIEXPORT void JNICALL Java_recipeNo068_redux_PassList_passObjectsAsList
  (JNIEnv * env, jclass cls, jobject list) {

  // Let's get class of object passed as argument
  jclass    cls_List     = (*env)->GetObjectClass (env, list);

  // we have to get signature of method 'Iterator<E> iterator()' - to know 
  // the size of the List
  jmethodID mid_iterator = (*env)->GetMethodID (env, cls_List, "iterator",
                                            "()Ljava/util/Iterator;");

  // Once we have the method's ID we can get Iterator
  jobject   iterator     = (*env)->CallObjectMethod (env, list, mid_iterator);

  // Let's get class of 'Iterator'
  jclass    cls_Iterator = (*env)->GetObjectClass (env, iterator);
 
  // For traversing the iterator, we have to retrieve IDs of two methods
  // 'hasNext' and 'next'
  jmethodID mid_hasNext  = (*env)->GetMethodID (env, cls_Iterator, "hasNext",
                                            "()Z"); 

  jmethodID mid_next     = (*env)->GetMethodID (env, cls_Iterator, "next",
                                            "()Ljava/lang/Object;");

  while((*env)->CallBooleanMethod(env, iterator, mid_hasNext)) {

    // Once we know there are still objects to traverse, we can
    // call 'next' on 'Iterator'
    jobject   obj        = (*env)->CallObjectMethod(env, iterator, mid_next);

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
