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

all: compilejava lib/libHelloWorldASAN.$(EXT)

lib/libHelloWorldASAN.$(EXT): c/recipeNo082_redux_HelloWorldASAN.c
	cc -g -shared -fsanitize=address -fpic -I${JAVA_HOME}/include -I${JAVA_HOME}/include/$(ARCH) $< -o $@

compilejava:
	$(JAVA_HOME)/bin/javac -h c -d target java/recipeNo082/redux/HelloWorldASAN.java

test_asan:
	DYLD_INSERT_LIBRARIES=$(shell find "/Applications/Xcode.app" -name libclang_rt.asan_osx_dynamic.dylib) $(JAVA_HOME)/bin/java -Djava.library.path=$(LD_LIBRARY_PATH):./lib -cp target recipeNo082.redux.HelloWorldASAN

test:
	$(JAVA_HOME)/bin/java -Djava.library.path=$(LD_LIBRARY_PATH):./lib -cp target recipeNo082.redux.HelloWorldASAN


clean: clean-common
	$(call rm-test,c/recipeNo082_redux_HelloWorldASAN.h)

include ../Makefile.clean
