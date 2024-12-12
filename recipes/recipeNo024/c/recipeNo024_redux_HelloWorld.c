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
#include <unistd.h>
#include "jni.h"
#include "recipeNo024_redux_HelloWorld.h"

void mode_1 () {
  printf ("Mode 1\n");
}

void mode_2 () {
  printf ("Mode 2\n");
}

void mode_3 () {
  printf ("Mode 3\n");
}

void mode_default () {
  printf ("Mode default\n");
}

JNIEXPORT void JNICALL Java_recipeNo024_redux_HelloWorld_displayMessage
  (JNIEnv * env, jclass obj, int mode) {
  int i = 0;
  while (i++ < 3) {
    sleep (10);
    switch (mode) {
      case 1:
        mode_1 ();
        break;
      case 2:
        mode_2 ();
        break;
      case 3:
        mode_3 ();
        break;
      default:
        mode_default ();
    }
  }
}
