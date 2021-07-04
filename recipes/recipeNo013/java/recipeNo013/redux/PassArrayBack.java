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

package recipeNo013.redux;

public class PassArrayBack {

  /* 
    These are the native methods we want to call
  	note that each of them has array as argument.
  	All arrays contain primitive types.
  */
  public static native void passBooleanArray(boolean[] array);

  public static native void passByteArray(byte[] array);

  public static native void passCharArray(char[] array);

  public static native void passShortArray(short[] array);

  public static native void passIntArray(int[] array);

  public static native void passLongArray(long[] array);

  public static native void passFloatArray(float[] array);

  public static native void passDoubleArray(double[] array);

  /* Inside static block we will load shared library */
  static {
    System.loadLibrary("PassArrayBack");
  }

  public static void main(String[] args) {
    /* 
      This message will help you determine whether
    	java.library.path is correctly set
    */
    System.out.println("library: " + System.getProperty("java.library.path"));

    /* Arrays declared inside Java */
    boolean[] boolArray   = { true, true, false };
    byte[]    byteArray   = { -128, 127, 0 };
    char[]    charArray   = { 'a', 'b', 'c' };
    short[]   shortArray  = { 1, 2, (short) 0xffff };
    int[]     intArray    = { 1, 2, 0xffffffff };
    long[]    longArray   = { 1, 2, 0xffffffffffffffffL };
    float[]   floatArray  = { 1.1f, 1.2f, 1.3f };
    double[]  doubleArray = { 1.1d, 1.2d, 1.3d };

    /* Call to shared library */
    passBooleanArray(boolArray);
    passByteArray(byteArray);
    passCharArray(charArray);
    passShortArray(shortArray);
    passIntArray(intArray);
    passLongArray(longArray);
    passFloatArray(floatArray);
    passDoubleArray(doubleArray);

    for (int i = 0; i < 3; i++) {
      System.out.println(
          "boolArray["
              + i
              + "] = "
              + boolArray[i]
              + "\n"
              + "byteArray["
              + i
              + "] = "
              + byteArray[i]
              + "\n"
              + "charArray["
              + i
              + "] = "
              + charArray[i]
              + "\n"
              + "shortArray["
              + i
              + "] = "
              + shortArray[i]
              + "\n"
              + "intArray["
              + i
              + "] = "
              + intArray[i]
              + "\n"
              + "longArray["
              + i
              + "] = "
              + longArray[i]
              + "\n"
              + "floatArray["
              + i
              + "] = "
              + floatArray[i]
              + "\n"
              + "doubleArray["
              + i
              + "] = "
              + doubleArray[i]
              + "\n");
    }
  }
}
