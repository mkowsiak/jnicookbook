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

#include <map>
#include "jni.h"
#include "recipeNo047_redux_FillTheMap.h"

using namespace std;

JNIEXPORT void JNICALL Java_recipeNo047_redux_FillTheMap_fillTheMap
  (JNIEnv *env, jclass cls, jobject obj) {

  map<int, int> map;
  map[0] = 0;
  map[1] = 1;
  map[2] = 2;
  map[3] = 3;

  jclass mapClass = env->FindClass("java/util/Map");
  if(mapClass == NULL) {
    return;                  // alternatively, throw exception (recipeNo019)
  }

  jclass integerClass = env->FindClass("java/lang/Integer");
  if(integerClass == NULL) {
    return;                  // alternatively, throw exception (recipeNo019)
  }

  jmethodID putMethodID = 
    env->GetMethodID(
          mapClass, 
          "put", 
          "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;" );

  if(putMethodID == NULL) {
    return;                  //                 - || -  
  }

  jmethodID integerConstructorID = env->GetMethodID(
                                          integerClass, "<init>", "(I)V" ); 
  if(integerConstructorID == NULL) {
    return;                  //                 - || -
  }

  for (auto const& pair: map) {

    jobject key = env->NewObject(
                        integerClass, 
                        integerConstructorID, 
                        pair.first);

    jobject value = env->NewObject(
                        integerClass, 
                        integerConstructorID, 
                        pair.second);

    if(key == NULL || value == NULL) {
      return;
    }
    env->CallObjectMethod(obj, putMethodID, key, value);
    
  }

  env->DeleteLocalRef(mapClass);
  env->DeleteLocalRef(integerClass);

}
