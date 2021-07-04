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

package recipeNo031.redux;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.nio.file.Files;

/*
  In this sample I will create jar file with dynamic library.
  This library will be extracted from a file stored inside JAR.
  Due to the fact we want to be cross system compatible we are
  creating ".lib" file instead of dylib (macOS) or so (Linux).
*/
public class Main {

  /*
    We are extracting library file and provide location of this
    file inside temporary location
  */
  private String extractLibrary() {
    try {
      // Create temporary file
      File file = File.createTempFile("libHelloWorld", ".lib");

      // In case it worked, we can extract lib
      if (file.exists()) {
        // First of all, let's show where do we plan to extract it
        System.out.println("Temporary file: " + file.getAbsoluteFile().toPath());

        // Now, we can get the lib file from JAR and put it inside temporary location
        InputStream link = (getClass().getResourceAsStream("/lib/libHelloWorld.lib"));

        // We want to overwrite existing file. This is why we are using
        //
        // java.nio.file.StandardCopyOption.REPLACE_EXISTING
        Files.copy(
            link,
            file.getAbsoluteFile().toPath(),
            java.nio.file.StandardCopyOption.REPLACE_EXISTING);
        return file.getAbsoluteFile().toPath().toString();
      }
      // In case something goes wrong, we will simply return null
      return null;

    } catch (IOException e) {
      // The same goes for exception - we are passing null back
      e.printStackTrace();
      return null;
    }
  }

  /*
    This is main method that
    - extracts library from JAR
    - calls native method declared inside HelloWorld class
  */
  public static void main(String[] arg) {

    // First of all, we need to extrac library file
    Main main = new Main();
    String libLocation = main.extractLibrary();

    // Once it is extracted, we can call native code
    // We are passing library location as argument
    // for HelloWorld constructor
    if (libLocation != null) {
      HelloWorld helloWorld = new HelloWorld(libLocation);
      helloWorld.callNativeMethod();
    }
  }
}
