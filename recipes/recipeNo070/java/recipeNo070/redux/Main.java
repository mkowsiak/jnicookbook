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

package recipeNo070.redux;

import com.sun.jna.Library;
import com.sun.jna.WString;
import com.sun.jna.Native;
import com.sun.jna.Structure;

public class Main {

  public static void main(String [] arg) {

    CLibrary clib = (CLibrary) Native.load("recipeNo070", CLibrary.class);
    CLibrary.DataStruct.ByRef by_ref = new CLibrary.DataStruct.ByRef();

    if(clib.retrieveData(by_ref) == 0) {

      by_ref.read();

      System.out.println(
          "ByRef: data: " 
        + by_ref.data
        + " width: " 
        + by_ref.width
        + " height: " 
        + by_ref.height);

      int total_size = by_ref.width * by_ref.width;
      int [] result = by_ref.data.getIntArray(0, total_size);
      for(int i=0; i < total_size; i++) {
        System.out.println("Idx: " + i + " value: " + result[i]);
      }
    }
  }
}
