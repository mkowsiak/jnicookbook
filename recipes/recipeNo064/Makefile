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
	cc -g -shared -fpic -I${JAVA_HOME}/include -I${JAVA_HOME}/include/$(ARCH) c/recipeNo064_redux_HelloWorld.c -o lib/libHelloWorld.$(EXT)

compilejava:
	$(JAVA_HOME)/bin/javac -h c -d modules/recipeNo064_ java/recipeNo064_/recipeNo064/redux/HelloWorld.java java/recipeNo064_/module-info.java
	$(JAVA_HOME)/bin/javac -h c -d modules/client --module-path modules/recipeNo064_ java/client/client/redux/CallHelloWorld.java java/client/module-info.java

test: jar
	$(JAVA_HOME)/bin/java --module-path modules/recipeNo064_ \
		-Djava.library.path=$(LD_LIBRARY_PATH):./lib --module recipeNo064_/recipeNo064.redux.HelloWorld
	$(JAVA_HOME)/bin/java --module-path modules/recipeNo064_:modules/client \
		--add-modules recipeNo064_ -Djava.library.path=$(LD_LIBRARY_PATH):./lib \
		--module client/client.redux.CallHelloWorld
	$(JAVA_HOME)/bin/java --module-path modules/recipeNo064_:lib/client.jar \
		--add-modules recipeNo064_,client -Djava.library.path=$(LD_LIBRARY_PATH):./lib \
		--module client/client.redux.CallHelloWorld
	$(JAVA_HOME)/bin/java --module-path modules/recipeNo064_:modules/client \
		--add-modules recipeNo064_ -Djava.library.path=$(LD_LIBRARY_PATH):./lib \
		-jar lib/client.jar

jar:
	$(JAVA_HOME)/bin/jar --create --file lib/client.jar --main-class client.redux.CallHelloWorld -C modules/client .

clean: clean-common
	$(call rm-test,c/recipeNo064_redux_HelloWorld.h)
	$(call rm-test,modules/client)
	$(call rm-test,modules/recipeNo064_)

include ../Makefile.clean
