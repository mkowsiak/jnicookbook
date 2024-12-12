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

package recipeNo056.redux;

public class PassObject {

  /* These are the native method we want to call */
  public static native void passBoxedValue(Object obj);

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

    PassObject.passBoxedValue( true );
    PassObject.passBoxedValue( (byte) 44 );
    PassObject.passBoxedValue( ',' );
    PassObject.passBoxedValue( 44.44f );
    PassObject.passBoxedValue( 44 );
    PassObject.passBoxedValue( 44L );
    PassObject.passBoxedValue( (short) 44 );
    PassObject.passBoxedValue( 44.44 );
    PassObject.passBoxedValue( "44" );

  }
}
