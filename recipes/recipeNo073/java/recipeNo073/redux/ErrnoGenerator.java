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

package recipeNo073.redux;

public class ErrnoGenerator {

  // This method will call system function that will fail
  // and will set errno; we will wrap it inside object
  // that will be passed back.
  // shouldIFail == true  - system call will fail and set errno
  // shoudlIFail == false - system call will execute successfully
  public native Object generateErrno(boolean shouldIFail);

  static {
    System.loadLibrary("ErrnoGenerator");
  }

  public static void main(String[] args) {
    ErrnoGenerator gen = new ErrnoGenerator();

    boolean [] flags = { true, false };

    for( boolean flag : flags ) {

      ErrnoWrapper jniResult = (ErrnoWrapper) gen.generateErrno( flag );

      if( jniResult.getResult() == null ) {

        System.out.println(
          "[J] " + (flag ? "true :" : "false:") + 
          " result: null errno: " + 
          jniResult.getErrnoCode() + 
          " message: " + 
          jniResult.getErrnoStr() );

      } else {

        System.out.println(
          "[J] " + (flag ? "true :" : "false:") + 
          " result: " + 
          jniResult.getResult() + 
          " errno: everything is fine - don't check errno" );
      }
    } 
 
  }
}
