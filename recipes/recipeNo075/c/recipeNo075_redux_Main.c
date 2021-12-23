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
#include <stdlib.h>
#include <string.h>
#include <sys/errno.h>
#include "recipeNo075_redux_Main.h"

JNIEXPORT jobject JNICALL Java_recipeNo075_redux_Main_buildObject
  (JNIEnv *env, jobject obj) {

  char* str =
  "The Son of a foreign mother, in his blood old heroes\n"
  "And his name will be forty and four";

  // Let's prepare result holder - Wrapper obj
  jclass    wCls           
    = (*env)->FindClass( env, "recipeNo075/redux/Wrapper" );
  jmethodID wConstructorID 
    = (*env)->GetMethodID( env, wCls, "<init>", "(ILjava/lang/String;)V" );

  // once we have everything in place, we can create new object and pass
  // it back to Java
  jobject wObj 
    = (*env)->NewObject(  env, 
                          wCls, 
                          wConstructorID, 
                          44, 
                          (*env)->NewStringUTF( env, str ) );
   
  return wObj;

}

