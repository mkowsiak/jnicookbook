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

all: download_jna compilec compilejava

dirs:
	mkdir -p jar

compilec:
	cc -Wpadded -g -O0 -shared -fpic -I${JAVA_HOME}/include -I${JAVA_HOME}/include/$(ARCH) c/recipeNo070_redux.c -o lib/libRecipeNo070.$(EXT)

compilejava:
	$(JAVA_HOME)/bin/javac -cp "./jar/jna-5.4.0.jar:target" -d target java/recipeNo070/redux/DataStruct.java
	$(JAVA_HOME)/bin/javac -cp "./jar/jna-5.4.0.jar:target" -d target java/recipeNo070/redux/Main.java

download_jna: dirs
	curl -s -L -z jar/jna-5.4.0.jar -o jar/jna-5.4.0.jar https://repo1.maven.org/maven2/net/java/dev/jna/jna/5.4.0/jna-5.4.0.jar 

test:
	$(JAVA_HOME)/bin/java -Djava.library.path=$(LD_LIBRARY_PATH):./lib -cp ./lib:target:./jar/jna-5.4.0.jar recipeNo070.redux.Main

clean: clean-common
	$(call rm-test,jar)

include ../Makefile.clean
