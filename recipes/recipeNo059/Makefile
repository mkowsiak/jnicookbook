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

all: compilejava static_lib shared_lib

static_lib:
	cc -c c/recipeNo059_redux_AnotherFunction.c -o lib/recipeNo059_redux_AnotherFunction.o
	ar -rvs lib/libAnotherFunction.a lib/recipeNo059_redux_AnotherFunction.o

shared_lib:
	cc -g -shared -fpic -I${JAVA_HOME}/include -I${JAVA_HOME}/include/$(ARCH) c/recipeNo059_redux_HelloWorld.c -Llib -lAnotherFunction -o lib/libHelloWorld.$(EXT)

compilejava:
	$(JAVA_HOME)/bin/javac -h c -d target java/recipeNo059/redux/HelloWorld.java

test:
	$(JAVA_HOME)/bin/java -Djava.library.path="$(CURDIR)/lib:$(CURDIR)/" -cp target recipeNo059.redux.HelloWorld

clean: clean-common
	$(call rm-test,c/recipeNo059_redux_HelloWorld.h)

include ../Makefile.clean
