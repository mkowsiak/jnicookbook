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

package recipeNo026.redux;

public class PassArray {

  /* 
    These are the native methods we want to call
  	note that each of them has array as argument.
  	All arrays contain primitive types.
  */
  public static native void passBooleanArray(boolean[][] array);

  public static native void passByteArray(byte[][] array);

  public static native void passCharArray(char[][] array);

  public static native void passShortArray(short[][] array);

  public static native void passIntArray(int[][] array);

  public static native void passLongArray(long[][] array);

  public static native void passFloatArray(float[][] array);

  public static native void passDoubleArray(double[][] array);

  /* Inside static block we will load shared library */
  static {
    System.loadLibrary("PassArray");
  }

  public static void main(String[] args) {
    
    /* 
      This message will help you determine whether
    	java.library.path is correctly set
    */
    System.out.println("library: " + System.getProperty("java.library.path"));

    /* Arrays declared inside Java */
    boolean[][] boolArray   = { 
                                {true, true, true}, 
                                {false, false, false} 
                              };
    byte[][]    byteArray   = { 
                                {0, 1, 2},
                                {-128, -127, -126} 
                              };
    char[][]    charArray   = { 
                                {'a', 'b', 'c'},
                                {'x', 'y', 'z'} 
                              };
    short[][]   shortArray  = {
                                {1, 2, 3}, 
                                {(short) 0xfffd, (short) 0xfffe, (short) 0xffff}
                              };
    int[][]     intArray    = {
                                {1, 2, 3}, 
                                {0xfffffffd, 0xfffffffe, 0xffffffff}
                              };
    long[][]    longArray   = {
                                {1, 2, 3}, 
                                {0, 1, 0xffffffffffffffffL}
                              };
    float[][]   floatArray  = {
                                {1.1f, 1.2f, 1.3f}, 
                                {2.1f, 2.2f, 2.3f}
                              };
    double[][]  doubleArray = {
                                {1.1d, 1.2d, 1.3d}, 
                                {2.1d, 2.2d, 2.3d}
                              };

    /* Call to shared library */
    passBooleanArray(boolArray);
    passByteArray(byteArray);
    passCharArray(charArray);
    passShortArray(shortArray);
    passIntArray(intArray);
    passLongArray(longArray);
    passFloatArray(floatArray);
    passDoubleArray(doubleArray);

  }
}
