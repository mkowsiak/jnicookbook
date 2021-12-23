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
	# This compilation pretends that we work with binary lib that we can't compile
	cc -g -shared -fpic c/extLib.c -o lib/libExtLib.$(EXT)

	# This is just a handler to exit (our new implementation of exit)
	cc -g -shared -fpic c/stopExit.c -o lib/libStopExit.$(EXT)
	
	# This compilation pretends that we work with library we can compile from the sources
	# We have to add -Dexit and we have to add library with new exit call handler
	cc -Dexit=stopExit -g -shared -fpic c/extLibCompiled.c -Llib -lStopExit -o lib/libExtLibCompiled.$(EXT)
	# This is the final library for JNI calls
	cc -Dexit=stopExit -g -shared -fpic -I${JAVA_HOME}/include -I${JAVA_HOME}/include/$(ARCH) c/recipeNo017_redux_SigTerm.c -Llib -lExtLib -lExtLibCompiled -lStopExit -o lib/libSigTerm.$(EXT)

compilejava:
	$(JAVA_HOME)/bin/javac -h c -d target java/recipeNo017/redux/SigTerm.java
	$(JAVA_HOME)/bin/javac -h c -d target java/recipeNo017/redux/SigTermExtLib.java

test:
	$(JAVA_HOME)/bin/java -Djava.library.path=$(LD_LIBRARY_PATH):./lib -cp target recipeNo017.redux.SigTerm
	$(JAVA_HOME)/bin/java -Djava.library.path=$(LD_LIBRARY_PATH):./lib -cp target recipeNo017.redux.SigTermExtLib

clean: clean-common
	$(call rm-test,c/recipeNo017_redux_SigTerm.h)
	$(call rm-test,c/recipeNo017_redux_SigTermExtLib.h)

include ../Makefile.clean
