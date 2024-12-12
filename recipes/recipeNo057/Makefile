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
include ../Makefile.jna

all: download_jna compilecc compilejava compilescala

dirs:
	mkdir -p jar

compilec:
	cc -Wpadded -g -O0 -shared -fpic -I${JAVA_HOME}/include -I${JAVA_HOME}/include/$(ARCH) c/HelloWorld.c -o lib/libHelloWorld.$(EXT)

compilecc:
	c++ -Wpadded -std=c++11 -g -O0 -shared -fpic -I${JAVA_HOME}/include -I${JAVA_HOME}/include/$(ARCH) c/HelloWorld.cc -o lib/libHelloWorld.$(EXT)

compilejava:
	$(JAVA_HOME)/bin/javac -cp "./jar/jna.jar:target" -d target java/recipeNo057/redux/Data.java
	$(JAVA_HOME)/bin/javac -cp "./jar/jna.jar:target" -d target java/recipeNo057/redux/Main.java

compilescala:
	scalac -d target -classpath "./jar/jna.jar:target" scala/recipeNo057/redux/HelloJNA.scala

download_jna: dirs
	$(call download-jna)

test:
	scala -Djna.library.path="./lib" -classpath "./target:jar/jna.jar" recipeNo057.redux.HelloJNA
	$(JAVA_HOME)/bin/java -Djna.library.path="./lib" -cp "./jar/jna.jar:target" recipeNo057.redux.Main

clean: clean-common
	$(call rm-test,jar)

include ../Makefile.clean
