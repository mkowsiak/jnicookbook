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
#include "recipeNo080_redux_ParseDate.h"

JNIEXPORT jobject JNICALL Java_recipeNo080_redux_ParseDate_parse
  (JNIEnv * env, jclass obj, jstring str) {

  char* date_format_str = "yy/MM/dd'T'hh:mm:ss";

  jclass sdfClass = (*env)->FindClass(env, "java/text/SimpleDateFormat");

  if(sdfClass == NULL) {
    return NULL;
  }

  jmethodID sdfConstructorID 
    = (*env)->GetMethodID( env, sdfClass, "<init>", "(Ljava/lang/String;)V" );

  if(sdfConstructorID == NULL) {
    return NULL;
  }

  jobject sdfObj 
    = (*env)->NewObject(  env, 
                          sdfClass, 
                          sdfConstructorID, 
                          (*env)->NewStringUTF( env, date_format_str ) );

  if(sdfObj == NULL) {
    return NULL;
  }

  jmethodID parseMethodID 
    = (*env)->GetMethodID(  env, 
                            sdfClass, 
                            "parse", 
                            "(Ljava/lang/String;)Ljava/util/Date;");
    
  if(parseMethodID == NULL) {
    return NULL;
  }

  // make sure to handle exceptions related to parsing
  return (*env)->CallObjectMethod(env, sdfObj, parseMethodID, str);

}
