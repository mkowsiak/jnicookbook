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
	cc -shared -fpic -I${JAVA_HOME}/include -I${JAVA_HOME}/include/$(ARCH) c/recipeNo042_redux_PassSet.c -o lib/libPassSet.$(EXT)


compilejava:
	$(JAVA_HOME)/bin/javac -h c -cp target -d target java/recipeNo042/redux/PassSet.java

test:
	$(JAVA_HOME)/bin/java -Djava.library.path=$(LD_LIBRARY_PATH):./lib -cp target recipeNo042.redux.PassSet

clean: clean-common
	$(call rm-test,c/recipeNo042_redux_PassSet.h)

include ../Makefile.clean
