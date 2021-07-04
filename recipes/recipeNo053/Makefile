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
	cc -g -shared -fpic -I${JAVA_HOME}/include -I${JAVA_HOME}/include/$(ARCH) c/recipeNo053_redux_Main.c -o lib/libMain.$(EXT)

compilejava:
	$(JAVA_HOME)/bin/javac -h c -d target java/recipeNo053/redux/MainPrimitiveArray.java
	$(JAVA_HOME)/bin/javac -h c -d target java/recipeNo053/redux/MainArrayElements.java

test:
	time $(JAVA_HOME)/bin/java -Djava.library.path=$(LD_LIBRARY_PATH):./lib -cp target recipeNo053.redux.MainPrimitiveArray
	time $(JAVA_HOME)/bin/java -Djava.library.path=$(LD_LIBRARY_PATH):./lib -cp target recipeNo053.redux.MainArrayElements

clean: clean-common
	$(call rm-test,c/recipeNo053_redux_MainPrimitiveArray.h)
	$(call rm-test,c/recipeNo053_redux_MainArrayElements.h)

include ../Makefile.clean
