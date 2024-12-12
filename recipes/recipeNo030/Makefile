#
# Copyright © 2015-2022 Michal K. Owsiak. All rights reserved.
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
	cc -g -shared -fpic -I${JAVA_HOME}/include -I${JAVA_HOME}/include/$(ARCH) c/recipeNo030_redux_HelloWorldNativeA.c -o lib/libHelloWorldNativeA.$(EXT)
	cc -g -shared -fpic -I${JAVA_HOME}/include -I${JAVA_HOME}/include/$(ARCH) c/recipeNo030_redux_HelloWorldNativeB.c -o lib/libHelloWorldNativeB.$(EXT)

compilejava:
	$(JAVA_HOME)/bin/javac -d target java/recipeNo030/redux/AbstractHelloWorld.java
	$(JAVA_HOME)/bin/javac -h c -cp target -d target java/recipeNo030/redux/HelloWorldNativeA.java
	$(JAVA_HOME)/bin/javac -h c -cp target -d target java/recipeNo030/redux/HelloWorldNativeB.java
	$(JAVA_HOME)/bin/javac -cp target -d target java/recipeNo030/redux/Main.java

test:
	$(JAVA_HOME)/bin/java -Djava.library.path=$(LD_LIBRARY_PATH):./lib -cp target recipeNo030.redux.Main

clean: clean-common
	$(call rm-test,c/recipeNo030_redux_HelloWorldNativeA.h)
	$(call rm-test,c/recipeNo030_redux_HelloWorldNativeB.h)

include ../Makefile.clean
