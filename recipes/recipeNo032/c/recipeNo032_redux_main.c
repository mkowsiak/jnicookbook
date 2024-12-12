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
#include <pthread.h>
#include "recipeNo032_redux_Main.h"

/* 
  I have choosen 6 threads, but you can use any other number here 
  (e.g. 42 would be just fine, and 44 would be even better if you come from
  Poland :) ). This value is here to demonstrate that accessing JVM from 
  multiple threads based application is possible
*/

#define NUM_THREADS 6

// mutex will be used during calls to JVM.
// We want to make sure that only one thread
// will use JVM at given time.
pthread_mutex_t mutexjvm;

// Our presious threads.
pthread_t threads[NUM_THREADS];

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

// We are passing JVM that is created inside C.
// As we require JVM inside each thread, we will pass 
// it via structure.
void *jvmThreads (void *myJvm) {

  struct JVM *myJvmPtr = (struct JVM *) myJvm;
  JavaVM *jvmPtr = myJvmPtr->jvm;

  JNIEnv *env = NULL;

  // Each thread will do following:
  // 1. lock the mutex,
  // 2. give some info to the user,
  // 3. attach to JVM,
  // 4. do JVM based stuff,
  // 5. detach from JVM,
  // 6. release mutex,
  // 7. finish thread's job.
  // Done

  pthread_mutex_lock (&mutexjvm);
  printf ("I will call JVM\n");
  (*jvmPtr)->AttachCurrentThread (jvmPtr, (void **) &(env), NULL);
  invoke_class (env);
  (*jvmPtr)->DetachCurrentThread (jvmPtr);
  pthread_mutex_unlock (&mutexjvm);
  pthread_exit (NULL);
}

// We are calling method "fun" from class
// recipeNo032.Main
//
// Note!
// 
// Please, make sure to use "/" as package separator
// in FindClass method using "." will not work here.
void invoke_class (JNIEnv * env) {
  jclass Main_class;
  jmethodID fun_id;

  // This is the place where we are looking for class
  // and it's method.
  Main_class = (*env)->FindClass (env, "recipeNo032/redux/Main");
  fun_id = (*env)->GetStaticMethodID (env, Main_class, "fun", "()I");

  // This is the place where we call the method
  (*env)->CallStaticIntMethod (env, Main_class, fun_id);
}

// main, just main
JNIEXPORT void JNICALL Java_recipeNo032_redux_Main_callmeback
  (JNIEnv * env, jobject obj) {

  // First of all, let's try to create JVM based on what we got from JVM calling us
  struct JVM myJvm;
  (*env)->GetJavaVM (env, &myJvm.jvm);

  // Initialize mutex and start threads
  // Note that we need to join threads, do we?
  // This is quite cumbersome. Some say we don't have to join
  // Some say we need to do that.
  // Thread based programming can be really frustrating.
  pthread_mutex_init (&mutexjvm, NULL);
  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_create (&threads[i], NULL, jvmThreads, (void *) &myJvm);
    pthread_join (threads[i], 0);
  }

  // Now, this is a question of a day
  // Do we have to call 
  // pthread_exit(NULL);
  // ???
  // In my opinion, we shouldn't do it, even though people say we should
  //
  // "An implicit call to pthread_exit() is made when a thread other than the thread in which main() 
  // was first invoked returns from the start routine that was used to create it.  
  // The function's return value serves as the thread's exit status."
}
