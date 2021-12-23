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

package recipeNo058.redux;

public class PassLongAsString {

  /* This is the native method we want to call */
  public static native void passULong(java.lang.String value);

  /* Inside static block we will load shared library */
  static {
    System.loadLibrary("PassLongAsString");
  }

  public static void main(String[] args) {
    /* This message will help you determine whether
       LD_LIBRARY_PATH is correctly set
    */
    System.out.println("library: " + System.getProperty("java.library.path"));

    long value_min = 0;
    long value_max = 4294967295L;
    long value_max_1 = 4294967296L;

    long [] arr = { value_min, value_max, value_max_1 };

    for(int i=0; i < arr.length; i++) {
      System.out.println("I am passing from Java: " + arr[i]);
      PassLongAsString.passULong(java.lang.Long.toUnsignedString(arr[i]));
    }

  }
}
