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

package recipeNo034.redux;

/* 
   In this sample we call native code from both - enclosing class
   and inner class. Pay attention to method signatures in
   native code!
*/

public class HelloWorld {

  /* 
    It is possible to load library either inside static block or inside 
    constructor. In fact, it really doesn't matter where you load library 
    itself. The only thing that matters is that library must be loaded before 
    first call to native code.
  */
  public HelloWorld() {
    System.loadLibrary("HelloWorld");
  }

  private native void displayMessage();

  /* Inner class that has it's own displayMessage */
  class NativeWrapper {

    void callNative() {
      displayMessage();
    }

    private native void displayMessage();
    
  }

  public void callDisplayMessageFromInnerClass() {

    NativeWrapper hwnw = new NativeWrapper();
    hwnw.callNative();

  }

  public static void main(String[] args) {

    /* 
      Note that instantiating object of class HelloWorld
      loads the library as well.
    */
    HelloWorld hw = new HelloWorld();
    hw.displayMessage();
    hw.callDisplayMessageFromInnerClass();

  }
}
