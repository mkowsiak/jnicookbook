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

package recipeNo029.redux;

import java.io.*;
import java.io.IOException;

public class Daemon {

  /* This is the native method we want to call
     Just being curious, here. As both: daemon and demon
     are close relatives, I guess we can use
     demonize to make something become dameon ;)
  */
  public static native int demonize();

  /* Inside static block we will load shared library
   */
  static {
    System.loadLibrary("Daemon");
  }

  public static void main(String[] args) {
    /* 
      This message will help you determine whether
      java.library.path is correctly set
    */
    System.out.println("library: " + System.getProperty("java.library.path"));

    /* Call to shared library */
    int pid = Daemon.demonize();

    /* Depending on pid value we are either looping forever (daemon)
       or quiting application
    */
    if (pid == 0) {
      try {
        /* I don't care about file, I simply assume that we can
           access /tmp
        */

        /* Close all streams */
        System.err.close();
        System.in.close();

        /* Redirect System.out to file
              I make strong assumption here that we have access
              to /tmp
        */
        OutputStream output = new FileOutputStream("/tmp/daemon_java");
        PrintStream printOut = new PrintStream(output);

        System.setOut(printOut);

        /* main daemon loop

               Ever and ever forever you'll be the one
               That shines in me like the morning sun
        ...
            */
        while (true) {
          Thread.sleep(1000);
          System.out.println("I am daemon ;)");
          System.out.flush();
        }
      } catch (IOException e) {
        // I don't care about exception
      } catch (Exception ex) {
        // I don't care about exception
      }
    } else {
      /* Quit Java application - but daemon will still works
       */
      System.out.println("Quiting Java application");
    }
  }
}
