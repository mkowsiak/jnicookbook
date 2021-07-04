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
	cc -g -shared -fpic -I${JAVA_HOME}/include -I${JAVA_HOME}/include/$(ARCH) c/recipeNo015_redux_SigSegv.c -o lib/libSigSegv.$(EXT)

compilejava:
	$(JAVA_HOME)/bin/javac -h c -d target java/recipeNo015/redux/SigSegv.java
	$(JAVA_HOME)/bin/javac -h c -d target java/recipeNo015/redux/SigSegvNoHandler.java

test:
	$(JAVA_HOME)/bin/java -Djava.library.path=$(LD_LIBRARY_PATH):./lib -cp target recipeNo015.redux.SigSegv
	$(JAVA_HOME)/bin/java -Djava.library.path=$(LD_LIBRARY_PATH):./lib -cp target recipeNo015.redux.SigSegvNoHandler

clean: clean-common
	$(call rm-test,c/recipeNo015_redux_SigSegv.h)
	$(call rm-test,c/recipeNo015_redux_SigSegvNoHandler.h)
	$(call rm-test,"hs_err*")

include ../Makefile.clean
