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

// This structure is used to pass
// jvm pointer - it is passed via void *
// If you need pass more info here (e.g. some data
// for threads), fell free to expand this structure.
struct JVM {
  JavaVM *jvm;
};

// Declaration of Java based call of
// Main class.
void invoke_class (JNIEnv * env);

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
  vm_args.ignoreUnrecognized = 0;
  vm_args.version = JNI_VERSION_1_8;
  vm_args.nOptions = 1;

  // I don't care about supper duper error handling here
  // in case we can't make it to create JVM. If JVM fails, just boil down.
  int status = JNI_CreateJavaVM (&jvm->jvm, (void **) &env, &vm_args);
  if (status < 0 || !env) {
    printf ("Error\n");
    return NULL;
  }
  return env;
}

// Note! 
// This method will leak fos_class, ps_class and sytem_class object
// We need to release them after we are done. However, I don't care.
// Managing these pointers would make the whole sample more blury.
void redirect_std_out (JNIEnv *env) {
    // Create FileOutputStream that will be used for redirecting
    // System.out
    jclass fos_class        
      = (*env)->FindClass(env, "java/io/FileOutputStream");

    jmethodID fos_constructor 
      = (*env)->GetMethodID(env, fos_class, "<init>", "(Ljava/lang/String;)V");

    jobject fos_object 
      = (*env)->NewObject(  env, 
                            fos_class, 
                            fos_constructor, 
                            (*env)->NewStringUTF(env, "jvm.log") );

    // Create a PrintStream
    jclass ps_class
      = (*env)->FindClass(env, "java/io/PrintStream");

    jmethodID ps_constructor
      = (*env)->GetMethodID(
                  env, 
                  ps_class, 
                  "<init>", 
                  "(Ljava/io/OutputStream;)V" );

    jobject ps_object
      = (*env)->NewObject(env, ps_class, ps_constructor, fos_object);

    // Reassign System.out
    jclass system_class     
      = (*env)->FindClass(env, "java/lang/System");

    jmethodID method_id
      = (*env)->GetStaticMethodID(
                  env,
                  system_class, 
                  "setOut", 
                  "(Ljava/io/PrintStream;)V" );

    (*env)->CallStaticVoidMethod(env, system_class, method_id, ps_object);
}

/* 
  We are calling method "fun" from class
  recipeNo049.redux.Main
  
  Note!
   
  Please, make sure to use "/" as package separator
  in FindClass method using "." will not work here.
*/

void invoke_class (JNIEnv * env) {

  jclass main_class;
  jmethodID fun_id;

  // This is the place where we are looking for class
  // and it's method.
  main_class  = (*env)->FindClass (env, "recipeNo049/redux/Main");
  fun_id      = (*env)->GetStaticMethodID (env, main_class, "fun", "()I");

  // This is the place where we call the method
  (*env)->CallStaticIntMethod (env, main_class, fun_id);
}

// main, just main
int main (int argc, char **argv) {
  // First of all, let's try to create JVM
  struct JVM myJvm;
  JNIEnv *env = create_vm (&myJvm);

  if (env == NULL) {
    return 1;
  }

  printf("Hello from C\n");
  printf("Execute: \n\n");
  printf("> cat jvm.log\n\n");
  printf("To see what JVM printed into System.out\n");

  redirect_std_out (env);

  invoke_class (env); 

  // Make sure to release JVM at the very end!!
  (*myJvm.jvm)->DestroyJavaVM (myJvm.jvm);

}
