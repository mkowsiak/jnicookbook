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

package recipeNo072.redux;

public class ErrnoGenerator {

  // This method will call system function that will fail
  // and will set errno; we will wrap it inside ErrnoException
  // that will be thrown back to Java code.
  public native void generateErrno() throws ErrnoException;

  static {
    System.loadLibrary("ErrnoGenerator");
  }

  public static void main(String[] args) {
    ErrnoGenerator gen = new ErrnoGenerator();

    try {
      // This one is supposed to throw error.
      // JNI code is designed such way it's supposed to fail.
      gen.generateErrno();
    } catch(ErrnoException ex) {
      // errno and message sent from C are exactly the same here, in Java world
      System.out.println(
        "[J] errno: " + ex.getErrno() + " message: " + ex.getMessage()
      );
    }

  }
}
