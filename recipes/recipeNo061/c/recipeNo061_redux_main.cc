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
#include <map>
#include <string>
#include <iostream>

int main() {
 
  std::map<std::string, std::string> map = {
		{ "k1", "v1" },
		{ "k2", "v2" }
  };

  const char *class_path = "-Djava.class.path=./target:../target";
 
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
  options[0].optionString = (char *)class_path;
 
  // if you want, you can pass additional parameters for JVM following way
  //options[1].optionString = "-verbose:jni";

  // checking JNI related issues
  //options[2].optionString = "-Xcheck:jni";

  vm_args.options = options;
  vm_args.ignoreUnrecognized = 0;
  vm_args.version = JNI_VERSION_1_6;
  vm_args.nOptions = 1;           // in case you are passing additional
                                  // arguments for JVM, make sure to update
                                  // the number of arguments here

  // I don't care about supper duper error handling here
  // - in case we can't create JVM. If JVM fails, just boil down.
  int status = JNI_CreateJavaVM (&jvm, (void **) &env, &vm_args);
  if (status < 0 || !env) {
    printf ("Error - JVM creation failed\n");
    return 1;
  }

  // Print values inside C++
  std::cout << "[C++  ] - I am sending" << std::endl;
  for(auto const &pair: map)
    std::cout << pair.first << " -> " << pair.second << std::endl;

  // First of all, we have to create HashMap, instantiate it and fill it with 
  // data coming from 'map' object.

  // Creating HashMap - we have to instantiate object of class HashMap
  jclass hashMapClass = env->FindClass("java/util/HashMap");
  if(hashMapClass == NULL) {
    return 2;                           // Note that I don't care
                                        // about cleaning up resources.
                                        // I am shutting down the app 
                                        // and that's it.
  }

  // Get the constructor of HashMap
  jmethodID hashMapConstructorID 
    = env->GetMethodID(hashMapClass, "<init>", "()V");

  if(hashMapConstructorID == NULL) {
    return 3;                           // as above
  }

  jobject hashMap = env->NewObject(hashMapClass, hashMapConstructorID);
  if(hashMap == NULL) {
    return 4;                           // as above ...
  }

  // Get id of 'put' method 
  jmethodID putMethodID 
    = env->GetMethodID(
            hashMapClass, 
            "put", 
            "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;" );

  if(putMethodID == NULL) {
    return 5;                           // ...
  }

  // For each pair inside 'map' I will call 'put' of Java based HashMap
  for(auto const &pair: map) {
    jstring key   = env->NewStringUTF ( pair.first.c_str() );
    jstring value = env->NewStringUTF ( pair.second.c_str() ); 

    env->CallObjectMethod(hashMap, putMethodID, key, value);
  }

  // This is the place where we are looking for class
  // and it's method - "displayMessage".
  jclass cls_Main = env->FindClass ("recipeNo061/redux/Main");
  if(cls_Main == NULL) {
    return 6;
  }
  
  // This is the place where we call the method "displayMessage"
  jmethodID method_displayMap 
    = env->GetStaticMethodID(
            cls_Main, 
            "displayMap", 
            "(Ljava/util/HashMap;)V" );

  if(method_displayMap == NULL) {
    return 7;
  }

  // We can now link all the pieces together by calling displayMap and
  // passing hashMap (one that we have created above) as argument
  jobject result 
    = env->CallStaticObjectMethod(
            cls_Main, 
            method_displayMap, 
            hashMap );
  
  // Note that you can check 'result' for the previous value associated with 
  // 'key'. The same way, you can do in Java:
  // - result == NULL - there was no value associated with the key
  // - result != NULL - the previous value

  // Clean up
  env->DeleteLocalRef( hashMap );

  // and we are done
  jvm->DestroyJavaVM();

  return 0;

}

