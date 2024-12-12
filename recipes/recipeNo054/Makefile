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

all: download_jna compilec compilescala

dirs:
	mkdir -p jar

download_jna: dirs
	$(call download-jna)

compilec:
	c++ -std=c++11 -g -shared -fpic -I${JAVA_HOME}/include -I${JAVA_HOME}/include/$(ARCH) c/HelloWorld.cc -o lib/libHelloWorld.$(EXT)

compilescala:
	scalac -d target -classpath "./jar/jna.jar" scala/recipeNo054/redux/HelloJNA.scala

test:
	scala -Djna.library.path="./lib" -classpath "./target:jar/jna.jar" recipeNo054.redux.HelloJNA

clean: clean-common
	$(call rm-test,jar)

include ../Makefile.clean
