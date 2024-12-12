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

compilec:
	cc -g -shared -fpic c/externalLib.c -o lib/libExternalLib.$(EXT)
	cc -g -shared -fpic -I${JAVA_HOME}/include -I${JAVA_HOME}/include/$(ARCH) -o lib/libSigTerm.$(EXT) c/recipeNo016_redux_SigTerm.c -Wl,-rpath,lib -Llib -lExternalLib 

compilejava:
	$(JAVA_HOME)/bin/javac -h c -d target java/recipeNo016/redux/SigTerm.java
	$(JAVA_HOME)/bin/javac -h c -d target java/recipeNo016/redux/SigTermNoHandler.java

test:
	$(JAVA_HOME)/bin/java -Djava.library.path=$(LD_LIBRARY_PATH):./lib -cp target recipeNo016.redux.SigTerm
	$(JAVA_HOME)/bin/java -Djava.library.path=$(LD_LIBRARY_PATH):./lib -cp target recipeNo016.redux.SigTermNoHandler

clean: clean-common
	$(call rm-test,c/recipeNo016_redux_SigTerm.h)
	$(call rm-test,c/recipeNo016_redux_SigTermNoHandler.h)

include ../Makefile.clean
