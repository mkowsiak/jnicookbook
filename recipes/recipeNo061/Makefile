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

all: main.$(ARCH) compilejava

compilejava:
	$(JAVA_HOME)/bin/javac -d target java/recipeNo061/redux/Main.java

main.darwin:
	clang++ -std=c++11 -stdlib=libc++ -g -o lib/recipeNo061_redux_main c/recipeNo061_redux_main.cc \
	$(JVM_INCLUDE) \
	$(LD_FLAGS_JAVA)

main.linux:
	g++ -std=c++14 -g -o lib/recipeNo061_redux_main c/recipeNo061_redux_main.cc \
	$(JVM_INCLUDE) \
	-pthread $(LD_FLAGS) 
	
test:
	lib/recipeNo061_redux_main

clean: clean-common

include ../Makefile.clean
