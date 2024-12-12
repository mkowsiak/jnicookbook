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
#include <stdlib.h>
#include <string.h>
#include <sys/errno.h>
#include "recipeNo076_redux_Main.h"

JNIEXPORT jobject JNICALL Java_recipeNo076_redux_Main_buildObject
  (JNIEnv *env, jobject obj) {

  // Stanislaw Lem. Solaris. Translated by Joanna Kilmartin and Steve Cox
  char* str =
  "fog thickening; visibility 400 yards, with clear patches. Descending to 600 feet.";

  // Let's prepare result holder - Wrapper obj
  jclass    wCls                 
    = (*env)->FindClass( env, "recipeNo076/redux/Wrapper" );
  jmethodID wConstructorID       
    = (*env)->GetMethodID( env, wCls, "<init>", "()V" );
  jmethodID setIntValMethodID    
    = (*env)->GetMethodID( env, wCls, "setIntVal", "(I)V" );
  jmethodID setStringValMethodID 
    = (*env)->GetMethodID( env, wCls, "setStringVal", "(Ljava/lang/String;)V" );

  // Construct new object of type recipeNo076.Wrapper
  jobject wObj = (*env)->NewObject( env, wCls, wConstructorID );

  // Set values of object's fields using set methods
  (*env)->CallVoidMethod( env, wObj, setIntValMethodID, 17);
  (*env)->CallVoidMethod( env, 
                          wObj, 
                          setStringValMethodID, 
                          (*env)->NewStringUTF( env, str ) );
   
  return wObj;

}

