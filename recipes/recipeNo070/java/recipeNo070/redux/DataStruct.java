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
import com.sun.jna.Native;
import com.sun.jna.Structure;
import com.sun.jna.Pointer;
import java.util.List;

interface CLibrary extends Library {

  public int retrieveData(CLibrary.DataStruct.ByRef result);

  public class DataStruct extends Structure {

    public static final List<String> FIELDS 
      =  List.of("ptr", "data", "width", "height");

    public static class ByRef extends DataStruct 
                              implements Structure.ByReference { }

    public Pointer ptr;
    public Pointer data;
    public int width;
    public int height;

    @Override
    protected List<String> getFieldOrder() {
      return FIELDS;
    }

    public DataStruct() {
      super();
      setAlignType(ALIGN_NONE);
    }
    
  }

}
