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
#include <stdint.h>
#include "jni.h"
#include "recipeNo053_redux_MainPrimitiveArray.h"
#include "recipeNo053_redux_MainArrayElements.h"

void compute(uint8_t *input, uint64_t *output) {

  for(long i=0; i<64000000; i++) {
    output[i] = input[i] + 1;
  }

}

JNIEXPORT void JNICALL 
  Java_recipeNo053_redux_MainPrimitiveArray_getPrimitiveArray
  (JNIEnv *env, jclass cls, jbyteArray input, jlongArray output) {

  uint8_t  *in  = (uint8_t *) (*env)->GetPrimitiveArrayCritical(env, input, 0);
  uint64_t *out = (uint64_t *)(*env)->GetPrimitiveArrayCritical(env, output, 0);

  compute(in, out);
  
  (*env)->ReleasePrimitiveArrayCritical(env, output, out, 0);
  (*env)->ReleasePrimitiveArrayCritical(env, input, in, JNI_ABORT);

}

JNIEXPORT void JNICALL 
  Java_recipeNo053_redux_MainArrayElements_getArrayElements
  (JNIEnv *env, jclass cls, jbyteArray input , jlongArray output) {

  jbyte *in  = (*env)->GetByteArrayElements(env, input, 0);
  jlong *out = (*env)->GetLongArrayElements(env, output, 0);

  compute((uint8_t *) in, (uint64_t *) out);

  (*env)->ReleaseLongArrayElements(env, output, out, 0);
  (*env)->ReleaseByteArrayElements(env, input, in, JNI_ABORT);

}

