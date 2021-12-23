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

package recipeNo033.redux;

public class HelloWorldProcess {

  public static void main(String[] args) throws Exception {

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

    /* 
       Remember! Call the code with -Drecipe033=`pwd` or
       something else - wherever you have compiled code
       e.g.: -Drecipe033=`pwd`/lib/

       I don't make any safety checks! If you do something
       wrong you will get an Exception in your face.
    */
    long t_start = System.currentTimeMillis();
    for (int i = 0; i < iterations; i++) {
      ProcessBuilder pb = new ProcessBuilder(System.getProperty("recipe033") + "main").inheritIO();
      Process p = pb.start();
    }
    long t_end = System.currentTimeMillis();

    System.out.println("Process: " + (t_end - t_start));
  }
}
