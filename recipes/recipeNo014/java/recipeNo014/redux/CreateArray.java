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

package recipeNo014.redux;

public class CreateArray {

  /* 
    These are the native methods we want to call
  	note that each of them has array as return type
  	All arrays contain primitive types
  */
  public static native boolean[] createBooleanArray(int size);

  public static native byte[] createByteArray(int size);

  public static native char[] createCharArray(int size);

  public static native short[] createShortArray(int size);

  public static native int[] createIntArray(int size);

  public static native long[] createLongArray(int size);

  public static native float[] createFloatArray(int size);

  public static native double[] createDoubleArray(int size);

  public static final int arraySize = 5;

  /* Inside static block we will load shared library */
  static {
    System.loadLibrary("CreateArray");
  }

  public static void main(String[] args) {
    /* 
      This message will help you determine whether
    	java.library.path is correctly set
    */
    System.out.println("library: " + System.getProperty("java.library.path"));

    /* Arrays declared inside Java */
    boolean[] boolArray   = null;
    byte[]    byteArray   = null;
    char[]    charArray   = null;
    short[]   shortArray  = null;
    int[]     intArray    = null;
    long[]    longArray   = null;
    float[]   floatArray  = null;
    double[]  doubleArray = null;

    /* Call to shared library */
    boolArray   = createBooleanArray(arraySize);
    byteArray   = createByteArray(arraySize);
    charArray   = createCharArray(arraySize);
    shortArray  = createShortArray(arraySize);
    intArray    = createIntArray(arraySize);
    longArray   = createLongArray(arraySize);
    floatArray  = createFloatArray(arraySize);
    doubleArray = createDoubleArray(arraySize);

    /* Print content created inside C code */
    for (int i = 0; i < boolArray.length; i++) {
      System.out.println("boolArray[" + i + "] = " + boolArray[i]);
    }

    for (int i = 0; i < byteArray.length; i++) {
      System.out.println("byteArray[" + i + "] = " + byteArray[i]);
    }

    for (int i = 0; i < charArray.length; i++) {
      System.out.println("charArray[" + i + "] = " + charArray[i]);
    }

    for (int i = 0; i < shortArray.length; i++) {
      System.out.println("shortArray[" + i + "] = " + shortArray[i]);
    }

    for (int i = 0; i < intArray.length; i++) {
      System.out.println("intArray[" + i + "] = " + intArray[i]);
    }

    for (int i = 0; i < longArray.length; i++) {
      System.out.println("longArray[" + i + "] = " + longArray[i]);
    }

    for (int i = 0; i < floatArray.length; i++) {
      System.out.println("floatArray[" + i + "] = " + floatArray[i]);
    }

    for (int i = 0; i < doubleArray.length; i++) {
      System.out.println("doubleArray[" + i + "] = " + doubleArray[i]);
    }
  }
}
