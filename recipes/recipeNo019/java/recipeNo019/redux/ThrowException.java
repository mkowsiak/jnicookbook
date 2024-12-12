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

package recipeNo019.redux;

import java.io.*;

public class ThrowException {

  /* This is the native method we want to call */
  public static native void throwException();

  /* Inside static block we will load shared library */
  static {
    System.loadLibrary("ThrowException");
  }

  public static void main(String[] args) {
    // Printing java.library.path is here just for the convenience
    // so you can check where Java will look for shared libraries
    System.out.println("library: " + System.getProperty("java.library.path"));
    ThrowException thex = new ThrowException();

    try {
      thex.throwException();
    } catch (Exception ex) {
      System.out.println("Exception was thrown in JNI");
    }
    thex.throwException();
  }
}
