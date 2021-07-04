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

package recipeNo039.redux;

public class PassArray2D {

  /* This is the native method we want to call */
  public native int displayArray2D();

  /* Inside static block we will load shared library */
  static {
    System.loadLibrary("PassArray2D");
  }

  private double[][] doubleData = { {0, 1}, {2, 3}, {4, 5} };

  public double[][] getDoubleData() {
    return doubleData;
  }

  public static void main(String[] args) {
    /* 
      This message will help you determine whether
      java.library.path is correctly set
    */
    System.out.println("library: " + System.getProperty("java.library.path"));

    PassArray2D obj = new PassArray2D();
    obj.displayArray2D();
  }
}
