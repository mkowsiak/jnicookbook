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
#include "recipeNo077_redux_Main.h"

JNIEXPORT jobject JNICALL Java_recipeNo077_redux_Main_buildObject
  (JNIEnv *env, jobject obj) {

  // Let's prepare result holder - Wrapper obj
  jclass    wCls                 
    = (*env)->FindClass( env, "recipeNo077/redux/Wrapper" );
  jmethodID wConstructorID       
    = (*env)->GetMethodID( env, wCls, "<init>", "()V" );
  jmethodID setStringValMethodID 
    = (*env)->GetMethodID( env, wCls, "setStringVal", "(Ljava/lang/String;)V" );

  // Construct new object of type recipeNo077.Wrapper
  jobject wObj = (*env)->NewObject( env, wCls, wConstructorID );

  // Set values of object's field using set method
  // Note that we are passing `C` style NULL that will
  // be visible as null on `Java` side
  (*env)->CallVoidMethod(env, wObj, setStringValMethodID, NULL );
   
  return wObj;

}

