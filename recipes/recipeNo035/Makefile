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

all: compilejava compilec jar

compilec:
	cc -shared -fpic c/shared_lib.c -o lib/libSharedLib.so
	cc -shared -fpic -I${JAVA_HOME}/include -I${JAVA_HOME}/include/$(ARCH) c/recipeNo035_redux_Chdir.c -o lib/libChdir.so
	cc -shared -fpic -I${JAVA_HOME}/include -I${JAVA_HOME}/include/$(ARCH) -Llib -lSharedLib c/recipeNo035_redux_HelloWorld.c -o lib/libHelloWorld.lib

compilejava:
	$(JAVA_HOME)/bin/javac -h c -d target java/recipeNo035/redux/HelloWorld.java
	$(JAVA_HOME)/bin/javac -h c -d target java/recipeNo035/redux/Chdir.java
	$(JAVA_HOME)/bin/javac -cp target -d target java/recipeNo035/redux/Main.java

jar:
	$(JAVA_HOME)/bin/jar cfe recipeNo035-redux.jar recipeNo035.redux.Main -C target . lib	

test: compilejava compilec jar
	$(JAVA_HOME)/bin/java -jar recipeNo035-redux.jar

clean: clean-common
	$(call rm-test,recipeNo035-redux.jar)
	$(call rm-test,c/recipeNo035_redux_HelloWorld.h)
	$(call rm-test,c/recipeNo035_redux_Chdir.h)

include ../Makefile.clean
