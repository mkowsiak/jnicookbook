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

#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include "jni.h"
#include "recipeNo029_redux_Daemon.h"

/* How to demonize your code propely, google a little bit.
   In this sample, we simply fork and don't care about anything.
   /tmp must be available to the process
*/
int demonize () {
  int pid = fork ();
  switch (pid) {
    case -1:
      return (-1);
    case 0:
      break;
    default:
      return pid;
  }
  return 0;
}

JNIEXPORT int JNICALL Java_recipeNo029_redux_Daemon_demonize
  (JNIEnv * env, jclass obj) {

  /* JNI call will demonize the code and get back to Java */
  int pid = demonize ();

  /* Based on pid value, Java will either become daemon
     or will quit execution
     0  - means we are the daemon
     !0 - means we are oryginal code

     if we are daemon, we can make all the mainteanance here
   */
  if (pid == 0) {
    /* Change the file mode mask */
    umask (0);

    /* Create a new SID for the child process */
    int sid = setsid ();
    if (sid < 0) {
      /* Log the failure */
      exit (EXIT_FAILURE);
    }

    /* Change the current working directory */
    if ((chdir ("/")) < 0) {
      /* Log the failure */
      exit (EXIT_FAILURE);
    }

    /* Close out the standard file descriptors */
    close (STDIN_FILENO);
    close (STDOUT_FILENO);
    close (STDERR_FILENO);

    /* Assign all files to /dev/null */
    open ("/dev/null", O_RDWR);
    dup (0);
    dup (0);
  }
  return pid;

}
