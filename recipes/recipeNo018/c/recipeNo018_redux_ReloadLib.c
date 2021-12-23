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
#include <stdlib.h>
#include <dlfcn.h>
#include "recipeNo018_redux_ReloadLib.h"
#include "foo.h"

#if defined(__APPLE__)
  #define LIB_RELOAD_NAME "libReloadLib.dylib"
#elif defined(__linux__)
  #define LIB_RELOAD_NAME "libReloadLib.so"
#else
  #error Uknown_OS
#endif

JNIEXPORT void JNICALL Java_recipeNo018_redux_ReloadLib_displayMessage
  (JNIEnv * env, jobject obj) {

  /* 
    dynamic library will be handled
    by the variables below
  */
  void *lib_handle;
  void (*fn) ();
  char *error;

  /* make sure to put libfoo on the LIBRARY_PATH */
  lib_handle = dlopen ( LIB_RELOAD_NAME , RTLD_NOW);
  if (!lib_handle) {
    /* In case it faild, let's try to open .so */
    lib_handle = dlopen ("libReloadLib.so", RTLD_NOW);
    if (!lib_handle) {
      fprintf (stderr, "%s\n", dlerror ());
      exit (1);
    }
  }


  /* 
    get the location of the given function inside library
    we will use it later on to call the function
  */
  fn = dlsym (lib_handle, "foo");
  if ((error = dlerror ()) != NULL) {
    fprintf (stderr, "%s\n", error);
    exit (1);
  }

  /* call the function from external library */
  (*fn) ();

  /* 
    close shared library
    and check the error code
  */
  int result = dlclose (lib_handle);
  if (((error = dlerror ()) != NULL) || result != 0) {
    fprintf (stderr, "%s\n", error);
    exit (1);
  }
}
