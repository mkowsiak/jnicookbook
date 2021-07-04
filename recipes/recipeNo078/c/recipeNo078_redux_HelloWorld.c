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
#include "jni.h"
#include "recipeNo078_redux_HelloWorld.h"
#include <string.h>
#include <pthread.h>

void huge_static();

JNIEXPORT void JNICALL Java_recipeNo078_redux_HelloWorld_displayMessage
  (JNIEnv * env, jclass obj) {

  size_t stack_size; 

  stack_size = pthread_get_stacksize_np(pthread_self());

  printf("[JNI wrapper] Stack size: %zd\n", stack_size); 
  printf("[JNI wrapper] I will call huge_static()\n"); 

  huge_static();

  printf("[JNI wrapper] Back in the wrapper\n");

}
