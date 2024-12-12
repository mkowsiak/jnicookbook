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

package recipeNo067.redux;

import java.util.List;
import java.util.ArrayList;

public class PassList {

  /* This is the native method we want to call */
  public static native void passObjectsAsList(java.util.List list);

  /* Inside static block we will load shared library */
  static {
    System.loadLibrary("PassList");
  }

  public static void main(String[] args) {
    /* 
      This message will help you determine whether
      java.library.path is correctly set
    */
    System.out.println("library: " + System.getProperty("java.library.path"));

    ArrayList list = new ArrayList<SimpleBean>();
    list.add(new SimpleBean("bean one"));
    list.add(new SimpleBean("bean two"));
    list.add(new SimpleBean("bean three"));

    /* Call to shared library */
    PassList.passObjectsAsList(list);
  }
}
