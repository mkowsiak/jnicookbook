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

package recipeNoD003.redux;

public class AllocateMemory {

  /* This is the native method we want to call */
  public static native boolean allocate(int size);

  /* Inside static block we will load shared library */
  static {
    System.loadLibrary("AllocateMemory");
  }

  public static void main(String[] args) {

    int i    = 0;
    int size = 2;

    /* 
      This message will help you determine whether
      java.library.path is correctly set
    */
    System.out.println("library: " + System.getProperty("java.library.path"));

    // Sky is the limit!
    while( i++ < 1000 ) {

      if(! AllocateMemory.allocate(size) ) {
        break;
      }
   
      size *= 2;

      try {
        Thread.sleep(5000);
      } catch(InterruptedException ex) {
        // I don't care
      }

    }
  }
}
