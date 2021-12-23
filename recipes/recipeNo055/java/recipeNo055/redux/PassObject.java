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

package recipeNo055.redux;

public class PassObject {

  /* These are the native method we want to call */
  public static native void passBoolean(Boolean obj);
  public static native void passByte(Byte obj);
  public static native void passCharacter(Character obj);
  public static native void passFloat(Float obj);
  public static native void passInteger(Integer obj);
  public static native void passLong(Long obj);
  public static native void passShort(Short obj);
  public static native void passDouble(Double obj);

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

    PassObject.passBoolean( true );
    PassObject.passByte( (byte) 44 );
    PassObject.passCharacter( ',' );
    PassObject.passFloat( 44.44f );
    PassObject.passInteger( 44 );
    PassObject.passLong( 44L );
    PassObject.passShort( (short) 44 );
    PassObject.passDouble( 44.44 );

  }
  
}