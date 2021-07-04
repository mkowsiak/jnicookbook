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

package recipeNo063.redux;

import recipeNo063.redux.OuterClass;

public class Main {

    static {
      System.loadLibrary("InnerClass");
    }

    private native int getInnerValueNative(OuterClass oc);
    
    public int getInnerValue(OuterClass oc) {
        return getInnerValueNative(oc);
    }

    public static void main(String [] arg) {

      Main obj = new Main();
      OuterClass oc = new OuterClass();

      System.out.println("Result: " + obj.getInnerValue(oc));
    }
}
