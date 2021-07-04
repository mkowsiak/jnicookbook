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

package recipeNo053.redux;

public class MainPrimitiveArray {

  public static native void getPrimitiveArray(byte [] input, long [] output);

  /* Inside static block we will load shared library */
  static {
    System.loadLibrary("Main");
  }

  public static void main(String [] args) {
 
    byte [] input  = new byte[64000000];
    long [] output = new long[64000000]; 

    System.out.println("Access via PrimitiveArray");
    
    for(int i=0; i<100; i++) {
      MainPrimitiveArray.getPrimitiveArray(input, output);
    }

  }

}
