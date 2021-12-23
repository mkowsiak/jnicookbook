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

package recipeNo057.redux;

import com.sun.jna.Library;
import com.sun.jna.WString;
import com.sun.jna.Native;
import com.sun.jna.Structure;

public class Main {

  public static void main(String [] arg) {

    CLibrary clib = (CLibrary) Native.load("HelloWorld", CLibrary.class);
    CLibrary.Data.ByVal by_val = clib.GetDataValue();
    CLibrary.Data       by_ref = clib.GetDataAllocated();

    by_val.read();
    by_ref.read();

    System.out.println(
        "ByVal: field_1: " + by_val.field_1 + 
        " field_2: " + by_val.field_2 + 
        " a: " + by_val.b_1 + 
        " b: " + by_val.b_2
    );
    
    System.out.println(
        "ByRef: field_1: " + by_ref.field_1 + 
        " field_2: " + by_val.field_2 + 
        " a: " + by_ref.b_1 + 
        " b: " + by_ref.b_2
    );

  }
}
