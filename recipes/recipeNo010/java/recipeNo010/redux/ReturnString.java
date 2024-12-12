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

package recipeNo010.redux;

public class ReturnString {

  /* 
    This is the native method we want to call
  	note that this time we expect return value
  	and we don't pass anything inside argument
  	block
  */
  public static native java.lang.String getString();

  /* Inside static block we will load shared library */
  static {
    System.loadLibrary("ReturnString");
  }

  public static void main(String[] args) {
    /* 
      This message will help you determine whether
    	java.library.path is correctly set
    */
    System.out.println("library: " + System.getProperty("java.library.path"));

    /* This is Java variable that will contain result */
    java.lang.String str = null;

    /* Call to shared library */
    str = ReturnString.getString();

    /* We can use the string inside Java */
    System.out.println("String from C: " + str);
  }
}
