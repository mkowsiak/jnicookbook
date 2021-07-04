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

package recipeNo040.redux;

import java.nio.ByteBuffer;

public class PassByteBuffer {

  public static final int BUFFER_SIZE = 44; // I think you know what
                                            // I have meant by that ;)

  /* This is the native method we want to call */
  public static native int displayByteBuffer(Object obj);

  /* This is the native method we want to call */
  public static native int displayDirectByteBuffer(Object obj);

  /* Inside static block we will load shared library */
  static {
    System.loadLibrary("PassByteBuffer");
  }

  public static void main(String[] args) {
    /* 
      This message will help you determine whether
      java.library.path is correctly set
    */
    System.out.println("library: " + System.getProperty("java.library.path"));

    /* Create object to pass */
    ByteBuffer buf = ByteBuffer.allocate(BUFFER_SIZE);
    for (byte i = 0; i < BUFFER_SIZE; i++) {
      buf.put(i);
    }

    /* Create object to pass */
    ByteBuffer bufDirect = ByteBuffer.allocateDirect(BUFFER_SIZE);
    for (byte i = 0; i < BUFFER_SIZE; i++) {
      bufDirect.put(i);
    }

    /* Call to shared library */
    PassByteBuffer.displayByteBuffer(buf);

    PassByteBuffer.displayDirectByteBuffer(bufDirect);
  }
}
