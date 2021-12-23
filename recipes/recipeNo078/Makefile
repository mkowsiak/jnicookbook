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

all: compilejava lib/libHelloWorld.$(EXT) lib/main

lib/libHelloWorld.$(EXT): c/recipeNo078_redux_HelloWorld.c c/huge_static.c
	cc -g -shared -fpic -I${JAVA_HOME}/include -I${JAVA_HOME}/include/$(ARCH) $^ -o $@

lib/main: c/main.c
	cc -g -I${JAVA_HOME}/include -I${JAVA_HOME}/include/$(ARCH) -Llib -lHelloWorld $< -o $@

compilejava:
	$(JAVA_HOME)/bin/javac -h c -d target java/recipeNo078/redux/HelloWorld.java

test: test_ok test_fail

test_fail:
	$(JAVA_HOME)/bin/java -Djava.library.path=$(LD_LIBRARY_PATH):./lib -cp target recipeNo078.redux.HelloWorld

test_ok:
	$(JAVA_HOME)/bin/java -Xss2m -Djava.library.path=$(LD_LIBRARY_PATH):./lib -cp target recipeNo078.redux.HelloWorld	

clean: clean-common
	$(call rm-test,c/recipeNo078_redux_HelloWorld.h)
	$(call rm-test,"hs_err*")

include ../Makefile.clean
