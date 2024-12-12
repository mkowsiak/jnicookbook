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

package recipeNo031.redux;

public class HelloWorld {

  // Location of native code will be passed from the
  // outside. In this case, Main class makes sure
  // to extract native code from JAR file
  String libFileLocation = null;

  /* This is the native method we want to call */
  public native void displayMessage();

  // In constructor we pass only location of the lib
  // file
  public HelloWorld(String lib) {
    this.libFileLocation = lib;
  }

  // This method will load native code
  // and call native method declared above
  public void callNativeMethod() {
    System.load(libFileLocation);
    displayMessage();
  }
}
