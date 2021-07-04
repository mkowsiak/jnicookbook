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

package recipeNo075.redux;

/*
  This class will hold String and int value. We will return object
  of that class from JNI.
*/

public class Wrapper {

  private int    intVal    = 0;
  private String stringVal = null;

  public Wrapper(int intVal, String stringVal) {

    this.intVal    = intVal;
    this.stringVal = stringVal;

  }

  public int getIntVal()       { return intVal; }

  public String getStringVal() { return stringVal; }

  public void setIntVal(int intVal)          { this.intVal = intVal; }

  public void setStringVal(String stringVal) { this.stringVal = stringVal; }
  
}
