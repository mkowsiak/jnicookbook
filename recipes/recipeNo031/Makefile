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
	cc -g -shared -fpic -I${JAVA_HOME}/include -I${JAVA_HOME}/include/$(ARCH) c/recipeNo031_redux_HelloWorld.c -o lib/libHelloWorld.lib

compilejava:
	$(JAVA_HOME)/bin/javac -h c -d target java/recipeNo031/redux/HelloWorld.java
	$(JAVA_HOME)/bin/javac -cp target -d target java/recipeNo031/redux/Main.java

jar:
	$(JAVA_HOME)/bin/jar cfe recipeNo031-redux.jar recipeNo031.redux.Main -C target . lib	

test: compilejava compilec jar
	$(JAVA_HOME)/bin/java -jar recipeNo031-redux.jar

clean: clean-common
	$(call rm-test,recipeNo031-redux.jar)
	$(call rm-test,c/recipeNo031_redux_HelloWorld.h)

include ../Makefile.clean
