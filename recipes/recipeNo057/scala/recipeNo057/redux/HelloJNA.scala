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

package recipeNo057.redux

import com.sun.jna.Library
import com.sun.jna.WString
import com.sun.jna.Native
import com.sun.jna.Structure

object HelloJNA {

  def main(args:Array[String]) : Unit = {

    val libc       = Native.load( "HelloWorld", classOf[CLibrary] )
   
    var result_val = libc.GetDataValue()
    println(
        "ByVal: field_1: " + result_val.field_1 + 
        " field_2: " + result_val.field_2 + 
        " a: " + result_val.b_1 + 
        " b: " + result_val.b_2 
    );

    var result_ref = libc.GetDataAllocated()
    println(
        "ByRef: field_1: " + result_ref.field_1 + 
        " field_2: " + result_val.field_2 + 
        " a: " + result_ref.b_1 + 
        " b: " + result_ref.b_2 );

  }
  
}

