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

package recipeNo018.redux;

import java.io.*;

public class ReloadLib {

  /* This is the native method we want to call */
  public static native void displayMessage();

  /* Inside static block we will load shared library */
  static {
    System.loadLibrary("ReloadLibJNI");
  }

  public static void main(String[] args) {
    System.out.println("library: " + System.getProperty("java.library.path"));
    ReloadLib reloadLib = new ReloadLib();
    reloadLib.displayMessage();

    System.out.println("Before you enter text recompile library.");
    System.out.println("To do so, change the code inside foo.c and create library.");
    System.out.println("After file is changed, call: make lib");

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String line = null;

    try {
      line = br.readLine();
    } catch (IOException ioe) {
      System.out.println("IO error trying to read string!");
      System.exit(1);
    }

    reloadLib.displayMessage();
  }
}
