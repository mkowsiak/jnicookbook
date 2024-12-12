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

package recipeNo054.redux

import com.sun.jna.Library
import com.sun.jna.WString
import com.sun.jna.Native

trait HelloWorld extends Library {

  def displayMessageWWrapper(m: WString) : Boolean
  def displayMessageWrapper(m: String)  : Boolean

}

object HelloJNA {

  def main(args:Array[String]) : Unit = {

    val libc   = Native.load( "HelloWorld", classOf[HelloWorld] )
   
    var result = libc.displayMessageWWrapper( new WString("Hello from Scala!") )
    println("Result: " + result);
    
    result     = libc.displayMessageWrapper( new String("Hello from Scala!") )
    println("Result: " + result);

  }

}

