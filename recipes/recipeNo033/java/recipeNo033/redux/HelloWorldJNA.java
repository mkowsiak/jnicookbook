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

package recipeNo033.redux;

import com.sun.jna.Library;
import com.sun.jna.Native;

public class HelloWorldJNA {
  public interface CTest extends Library {
    public void displayMessageJNA();
  }

  public static void main(String args[]) {
    // just some value out of the blue ;)
    int iterations = 44;

    if (args.length == 1) {
      try {
        iterations = Integer.parseInt(args[0]);
      } catch (Exception ex) {
        // I will print stack trace and proceed anyway
        // I don't care whether input is lousy or not
        ex.printStackTrace();
      }
    }

    CTest ctest = (CTest) Native.loadLibrary("HelloWorldJNA", CTest.class);

    /* Call to shared library */
    long t_start = System.currentTimeMillis();
    for (int i = 0; i < iterations; i++) {
      ctest.displayMessageJNA();
    }
    long t_end = System.currentTimeMillis();

    System.out.println("JNA:     " + (t_end - t_start));
  }
}
