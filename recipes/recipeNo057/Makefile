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

all: download_jna compilecc compilejava compilescala

dirs:
	mkdir -p jar

compilec:
	cc -Wpadded -g -O0 -shared -fpic -I${JAVA_HOME}/include -I${JAVA_HOME}/include/$(ARCH) c/HelloWorld.c -o lib/libHelloWorld.$(EXT)

compilecc:
	c++ -Wpadded -std=c++11 -g -O0 -shared -fpic -I${JAVA_HOME}/include -I${JAVA_HOME}/include/$(ARCH) c/HelloWorld.cc -o lib/libHelloWorld.$(EXT)

compilejava:
	$(JAVA_HOME)/bin/javac -cp "./jar/jna-5.4.0.jar:target" -d target java/recipeNo057/redux/Data.java
	$(JAVA_HOME)/bin/javac -cp "./jar/jna-5.4.0.jar:target" -d target java/recipeNo057/redux/Main.java

compilescala:
	scalac -d target -classpath "./jar/jna-5.4.0.jar:target" scala/recipeNo057/redux/HelloJNA.scala

download_jna: dirs
	curl -s -L -z jar/jna-5.4.0.jar -o jar/jna-5.4.0.jar https://repo1.maven.org/maven2/net/java/dev/jna/jna/5.4.0/jna-5.4.0.jar 

test:
	scala -Djna.library.path="./lib" -classpath "./target:jar/jna-5.4.0.jar" recipeNo057.redux.HelloJNA
	$(JAVA_HOME)/bin/java -Djna.library.path="./lib" -cp "./jar/jna-5.4.0.jar:target" recipeNo057.redux.Main

clean: clean-common
	$(call rm-test,jar)

include ../Makefile.clean
