#
# Copyright © 2021 Michal K. Owsiak. All rights reserved.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
#

include ../Makefile.common

all: compilejava compilec

compilec:
	cc -g -O0 -shared -fpic -I${JAVA_HOME}/include -I${JAVA_HOME}/include/$(ARCH) c/recipeNoD001_redux_HelloWorld.c -o lib/libJNIDebugCLion.$(EXT)

compilejava:
	$(JAVA_HOME)/bin/javac -h c -d target java/recipeNoD001/redux/HelloWorld.java

test:
	$(JAVA_HOME)/bin/java -Djava.library.path=./lib -cp target recipeNoD001.redux.HelloWorld

clean: clean-common
	$(call rm-test,c/recipeNoD001_redux_HelloWorld.h)

include ../Makefile.clean
