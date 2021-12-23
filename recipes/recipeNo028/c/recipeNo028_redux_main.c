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
#include <jni.h>
#include <pthread.h>

// This structure is used to pass
// jvm pointer - it is passed via void *
// If you need pass more info here (e.g. some data
// for threads), fell free to expand this structure.
struct JVM {
  JavaVM *jvm;
};

// We are creating JVM here.
// We are storing it's pointer inside JVM structure.
// This structure will be used (later on) while
// creating threads.
JNIEnv *create_vm (struct JVM *jvm) {
  JNIEnv *env;
  JavaVMInitArgs vm_args;
  JavaVMOption options;

  // This one (java.class.path) is hardcoded, but I guess we could 
  // make something better here. I simply assume that in sample codes
  // main function will be called either from lib or from root directory
  // of given sample code. It's possible to use some env variables here
  // or to pass this value to main, but I don't care.
  // This is just a sample. 
  options.optionString = "-Djava.class.path=./target:../target";

  vm_args.options = &options;
  vm_args.nOptions = 1;
  vm_args.ignoreUnrecognized = 0;
  vm_args.version = JNI_VERSION_1_8;

  // I don't care about supper duper error handling here
  // in case we can't make it to create JVM. If JVM fails, just boil down.
  int status = JNI_CreateJavaVM (&jvm->jvm, (void **) &env, &vm_args);
  if (status < 0 || !env) {
    printf ("Error: %d\n", status);
    return NULL;
  }
  return env;
}

// We are calling method "fun" from class
// recipeNo027.Main
//
// Note!
// 
// Please, make sure to use "/" as package separator
// in FindClass method using "." will not work here.
void invoke_class (JNIEnv * env) {
  jclass Main_class;
  jmethodID fun_id;
  jclass Main_class_no_package;
  jmethodID fun_id_no_package;

  // This is the place where we are looking for class
  // and it's method.
  Main_class = (*env)->FindClass (env, "recipeNo028/redux/Main");
  if(Main_class == NULL)
    return;
  Main_class_no_package = (*env)->FindClass (env, "Main");
  fun_id = (*env)->GetStaticMethodID (env, Main_class, "fun", "()I");
  fun_id_no_package =
    (*env)->GetStaticMethodID (env, Main_class_no_package, "fun", "()I");

  // This is the place where we call the method
  (*env)->CallStaticIntMethod (env, Main_class, fun_id);
  (*env)->CallStaticIntMethod (env, Main_class_no_package, fun_id_no_package);
}

// main, just main
int main (int argc, char **argv) {
  // First of all, let's try to create JVM
  struct JVM myJvm;
  JNIEnv *myEnv = create_vm (&myJvm);

  if (myEnv == NULL)
    return 1;

  invoke_class (myEnv);

  // Make sure to release JVM at the very end!!
  (*myJvm.jvm)->DestroyJavaVM (myJvm.jvm);

}
