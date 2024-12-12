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
#include <jni.h>


int main() {
  
  JNIEnv *env;
  JavaVM *jvm;
  JavaVMInitArgs vm_args;
  JavaVMOption options[3];         // Make sure to prepare array of arguments
                                   // for as many arguments as you want to pass

  // This one (java.class.path) is hardcoded, but I guess we could 
  // make something better here. I simply assume that in sample codes
  // main function will be called either from lib or from root directory
  // of given sample code. It's possible to use some env variables here
  // or to pass this value to main, but I don't care.
  // This is just a sample. 
  options[0].optionString = "-Djava.class.path=./target:../target";

  // if you want, you can pass additional parameters for JVM following way
  // options[1].optionString = "-verbose:jni";

  // checking JNI related issues
  // options[2].optionString = "-Xcheck:jni";

  vm_args.options = options;
  vm_args.ignoreUnrecognized = 0;
  vm_args.version = JNI_VERSION_1_8;
  vm_args.nOptions = 1;           // in case you are passing additional
                                  // arguments for JVM, make sure to update
                                  // the number of arguments here

  // I don't care about supper duper error handling here
  // in case we can't make it to create JVM. If JVM fails, just boil down.
  int status = JNI_CreateJavaVM (&jvm, (void **) &env, &vm_args);
  if (status < 0 || !env) {
    printf ("Error - JVM creation failed\n");
    return 1;
  }

  // This is the place where we are looking for class
  // and it's method - "displayMessage".
  jclass cls_Main = (*env)->FindClass (env, "recipeNo051/redux/Main");
  
  // This is the place where we call the method "displayMessage"
  jmethodID method_displayMessage 
    = (*env)->GetStaticMethodID (env, cls_Main, "displayMessage", "()V");

  (*env)->CallStaticVoidMethod(env, cls_Main, method_displayMessage);

  // and we are done
  (*jvm)->DestroyJavaVM( jvm );

}

