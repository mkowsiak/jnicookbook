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

package recipeNo071.redux;

import java.io.*;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.Files;

public class ErrnoGenerator {

  public native void generateErrno(boolean shouldIFail);
  public native int getErrno();

  static {
    System.loadLibrary("ErrnoGenerator");
  }

  public static class ErrnoGeneratorThread implements Runnable {

    boolean shouldIFail = false;
    ErrnoGenerator errnoGenerator = null;
 
    public ErrnoGeneratorThread(
              ErrnoGenerator errnoGenerator, boolean shouldIFail) {
      this.errnoGenerator = errnoGenerator;
      this.shouldIFail = shouldIFail;
    }

    public void run() {
      try {
        if(shouldIFail) {
          errnoGenerator.generateErrno( shouldIFail );
          Thread.sleep(1000);
          System.out.println(
                        "[J] true : expected == 2: " + 
                        errnoGenerator.getErrno() ); 
        } else {
          Thread.sleep(500);
          errnoGenerator.generateErrno( shouldIFail );
          // there is no sense to look for errno as it might be misleaing
          // system call didn't produce error 
        }
      } catch (InterruptedException e) {
        // I don't care about exceptions
      }
    }
  }

  public static void main(String[] args) {
    ErrnoGenerator gen = new ErrnoGenerator();

    // Possible race condition with threads calling the same
    // JNI based routine 
    Thread t1 = new Thread(new ErrnoGeneratorThread(gen, true));
    Thread t2 = new Thread(new ErrnoGeneratorThread(gen, false));
    t1.start();
    t2.start();
    while(t1.isAlive() || t2.isAlive());

    // Possible race condition with mixed JNI/Java libraries
    // calls to system routines
    gen.generateErrno( true );
    try {
      // Be careful here - I am writing inside your file system
      Path file = Paths.get("/tmp/path-to-file");
      byte[] buf = "Hello from Java!".getBytes();
      Files.write(file, buf);
    } catch(Exception ex) {
      // I don't care about exceptions
    }
    System.out.println("[J] true : expected == 2: " + gen.getErrno());
  }
}
