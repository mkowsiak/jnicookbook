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
  JavaVMOption options;

  // This one (java.class.path) is hardcoded, but I guess we could 
  // make something better here. I simply assume that in sample codes
  // main function will be called either from lib or from root directory
  // of given sample code. It's possible to use some env variables here
  // or to pass this value to main, but I don't care.
  // This is just a sample. 
  options.optionString 
    = "-Djava.class.path=./lib/libjava.jar:../lib/libjava.jar";

  vm_args.options = &options;
  vm_args.ignoreUnrecognized = 0;
  vm_args.version = JNI_VERSION_1_8;
  vm_args.nOptions = 1;

  // I don't care about supper duper error handling here
  // in case we can't make it to create JVM. If JVM fails, just boil down.
  int status = JNI_CreateJavaVM (&jvm, (void **) &env, &vm_args);
  if (status < 0 || !env) {
    printf ("Error - JVM creation failed\n");
    return 1;
  }

  // This is the place where we are looking for class
  // and it's method - "path".
  jclass cls_Main = (*env)->FindClass (env, "recipeNo050/redux/Main");
  
  // This is the place where we call the method "path"
  // Method "path" will get the location of JAR file from the Java code
  jmethodID method_path 
    = (*env)->GetStaticMethodID (env, cls_Main, "path", "()Ljava/lang/String;");

  jobject result
    = (*env)->CallStaticObjectMethod (env, cls_Main, method_path);

  const char *c_str;
  c_str = (*env)->GetStringUTFChars(env, result, NULL);
  if(c_str != NULL) {
    printf("Path from Java: %s\n", c_str);
  } else {
    printf("Something went wrong :(");
  }

  (*env)->ReleaseStringUTFChars(env, result, c_str); 


  // Now, let's get it hard way. Let's make a hell lot of JNI based calls
  // Note! I don't care for error handling - but you should check whether
  // each call produced something sensible or not

  // First of all, we have to create object, this is why we look for <init>
  jmethodID method_Main_init 
    = (*env)->GetMethodID(env, cls_Main, "<init>", "()V");

  jobject   obj_Main         
    = (*env)->NewObject(env, cls_Main, method_Main_init);
 
  
  jmethodID method_getClass 
    = (*env)->GetMethodID(env, cls_Main, "getClass", "()Ljava/lang/Class;");

  jobject   obj_Class       
    = (*env)->CallObjectMethod(env, obj_Main, method_getClass);

  
  // Now, we can access method of a class, and call it on behalf of the object
  jclass    cls_Class                  
    = (*env)->GetObjectClass(env, obj_Class);

  jmethodID method_getProtectionDomain 
    = (*env)->GetMethodID(
                env, 
                cls_Class, 
                "getProtectionDomain",
                "()Ljava/security/ProtectionDomain;");

  jobject   obj_ProtectionDomain       
    = (*env)->CallObjectMethod(env, obj_Class, method_getProtectionDomain);


  jclass    cls_ProtectionDomain 
    = (*env)->GetObjectClass(env, obj_ProtectionDomain);

  jmethodID method_getCodeSource 
    = (*env)->GetMethodID(
                env, 
                cls_ProtectionDomain, 
                "getCodeSource", 
                "()Ljava/security/CodeSource;");

  jobject   obj_CodeSource
    = (*env)->CallObjectMethod(env, obj_ProtectionDomain, method_getCodeSource);


  jclass    cls_CodeSource     
    = (*env)->GetObjectClass(env, obj_CodeSource);

  jmethodID method_getLocation 
    = (*env)->GetMethodID(
                env, 
                cls_CodeSource, 
                "getLocation", 
                "()Ljava/net/URL;");

  jobject   obj_URL            
    = (*env)->CallObjectMethod(env, obj_CodeSource, method_getLocation);


  jclass    cls_URL      
    = (*env)->GetObjectClass(env, obj_URL);

  jmethodID method_toURI 
    = (*env)->GetMethodID(env, cls_URL, "toURI", "()Ljava/net/URI;");

  jobject   obj_URI      
    = (*env)->CallObjectMethod(env, obj_URL, method_toURI);


  jclass    cls_File         
    = (*env)->FindClass (env, "java/io/File");

  jmethodID method_File_init 
    = (*env)->GetMethodID(env, cls_File, "<init>", "(Ljava/net/URI;)V");

  jobject   obj_File         
    = (*env)->NewObject(env, cls_File, method_File_init, obj_URI);


  jmethodID method_getPath 
    = (*env)->GetMethodID(env, cls_File, "getPath", "()Ljava/lang/String;");

  jobject   obj_String     
    = (*env)->CallObjectMethod(env, obj_File, method_getPath);

  // Finally, we have path, all we have to do is to "cast" it to char *
  // and print it
  c_str = (*env)->GetStringUTFChars(env, obj_String, NULL);
  if(c_str != NULL) {
    printf("Path from  JNI: %s\n", c_str);
  } else {
    printf("Something went wrong :(");
  }

  // remember to release the native memory
  (*env)->ReleaseStringUTFChars(env, obj_String, c_str); 

  // and we are done
  (*jvm)->DestroyJavaVM( jvm );

}

