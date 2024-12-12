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

ifeq ($(ARCH),darwin)
SHARED_OPTION=-dynamiclib
CC_LIB=$(CURDIR)/lib/libAnotherFunction.$(EXT)
else
SHARED_OPTION=-shared
CC_LIB=-L./lib -lAnotherFunction
endif

compilec:
	cc -g $(SHARED_OPTION) c/recipeNo023_AnotherFunction.c -o lib/libAnotherFunction.$(EXT)
	cc -g $(SHARED_OPTION) -fpic -I${JAVA_HOME}/include -I${JAVA_HOME}/include/$(ARCH) c/recipeNo023_redux_HelloWorld.c $(CC_LIB) -o lib/libHelloWorld.$(EXT)

compilejava:
	$(JAVA_HOME)/bin/javac -h c -d target java/recipeNo023/redux/HelloWorld.java

test:
	$(JAVA_HOME)/bin/java -Djava.library.path="$(CURDIR)/lib:$(CURDIR)/" -cp target recipeNo023.redux.HelloWorld

clean: clean-common
	$(call rm-test,c/recipeNo023_redux_HelloWorld.h)

include ../Makefile.clean
