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

package recipeNo020.redux;

public class PassObject {

  /* This is the native method we want to call */
  public static native void displayObject(Object obj);

  /* Inside static block we will load shared library */
  static {
    System.loadLibrary("PassObject");
  }

  public static void main(String[] args) {
    /* 
      This message will help you determine whether
    	java.library.path is correctly set
    */
    System.out.println("library: " + System.getProperty("java.library.path"));

    /* Create object to pass */
    CustomClass cc = new CustomClass();
    cc.iVal = 42;
    cc.dVal = 3.14;
    cc.cVal = 'a';
    cc.bVal = true;
    cc.sVal = "Hello from the CustomClass";
    cc.oVal = new OtherClass();
    cc.oVal.sVal = "Hello from the OtherClass";

    /* Call to shared library */
    PassObject.displayObject( cc );
  }
}
