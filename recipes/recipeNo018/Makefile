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

ifeq ($(ARCH),darwin)
  CFLAGS=-rpath @loader_path
  SHARED=-install_name libReloadLib.$(EXT)
else
  CFLAGS=
  SHARED=
endif

all: compilejava compilec

reloadlib:
	cc -g -shared -fpic c/foo.c -o lib/libReloadLib.$(EXT) $(SHARED)

compilec:
	# This is the final library for JNI calls
	cc -g -shared -fpic -I${JAVA_HOME}/include -I${JAVA_HOME}/include/$(ARCH) $(CFLAGS) c/recipeNo018_redux_ReloadLib.c -o lib/libReloadLibJNI.$(EXT) 

compilejava:
	$(JAVA_HOME)/bin/javac -h c -d target java/recipeNo018/redux/ReloadLib.java

test:	reloadlib
	$(JAVA_HOME)/bin/java -Djava.library.path=$(LD_LIBRARY_PATH):./lib -cp target recipeNo018.redux.ReloadLib

clean: clean-common
	$(call rm-test,c/recipeNo018_redux_ReloadLib.h)

include ../Makefile.clean
