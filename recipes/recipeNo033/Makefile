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

RECIPE=./recipeNo033
ifneq "$(wildcard $(RECIPE) )" ""
  RECIPE_LOCATION=recipeNo033
else
  RECIPE_LOCATION=
endif

.PHONY:
	@echo $(RECIPE_LOCATION)
	@echo $(wildcard $(RECIPE) )

all: download_jna compilejava compilec

dirs:
	mkdir -p jar

compilec:
	cc -shared -fpic -I${JAVA_HOME}/include -I${JAVA_HOME}/include/$(ARCH) c/recipeNo033_redux_HelloWorldJNI.c -o lib/libHelloWorldJNI.$(EXT)
	cc -shared -fpic -I${JAVA_HOME}/include -I${JAVA_HOME}/include/$(ARCH) c/recipeNo033_redux_HelloWorldJNA.c -o lib/libHelloWorldJNA.$(EXT)
	cc c/main.c -o lib/main

compilejava:
	$(JAVA_HOME)/bin/javac -d target -cp ./jar/jna.jar java/recipeNo033/redux/HelloWorldJNA.java
	$(JAVA_HOME)/bin/javac -h c -d target java/recipeNo033/redux/HelloWorldJNI.java
	$(JAVA_HOME)/bin/javac -d target java/recipeNo033/redux/HelloWorldProcess.java

test: testprocess testjni testjna

testprocess:
	$(JAVA_HOME)/bin/java -Drecipe033=$(RECIPENO33) -Djava.library.path=$(LD_LIBRARY_PATH):./lib -cp target recipeNo033.redux.HelloWorldProcess $(RECIPE_NO_033_ITER)

testjni:
	$(JAVA_HOME)/bin/java -Djava.library.path=$(LD_LIBRARY_PATH):./lib -cp target recipeNo033.redux.HelloWorldJNI $(RECIPE_NO_033_ITER)

testjna:
	$(JAVA_HOME)/bin/java -Djava.library.path=$(LD_LIBRARY_PATH):./lib -cp ./lib:target:./jar/jna.jar recipeNo033.redux.HelloWorldJNA $(RECIPE_NO_033_ITER)

download_jna: dirs
	$(call download-jna)

clean: clean-common
	$(call rm-test,c/recipeNo033_redux_HelloWorldJNI.h)
	$(call rm-test,jar)

include ../Makefile.clean
