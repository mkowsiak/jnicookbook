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

package recipeNo048.redux;

import java.util.HashMap;
import java.lang.Integer;

public class MapOfInts {

  /* This is the native method we want to call */
  public static native HashMap<Integer, Integer> getMap();

  /* Inside static block we will load shared library */
  static {
    System.loadLibrary("MapOfInts");
  }

  public static void main(String[] args) {
    /* 
      This message will help you determine whether
    	java.library.path is correctly set
    */
    System.out.println("library: " + System.getProperty("java.library.path"));

    /* Call to shared library */
    HashMap<Integer, Integer> result = getMap();
    
    result.entrySet()
      .stream()
      .map(map -> String.format(
                          "key: %s value: %s", map.getKey(), map.getValue()
                          )).forEach(System.out::println);
  }
}
