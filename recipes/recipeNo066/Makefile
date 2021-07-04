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

all: main.$(ARCH)

remove_dirs:
	rm -rf recipeNo066-redux.app

create_dirs: remove_dirs
	mkdir -p recipeNo066-redux.app/Contents/Resources
	mkdir -p recipeNo066-redux.app/Contents/MacOS
	cp Info.plist recipeNo066-redux.app/Contents
	
compilejava: create_dirs
	$(JAVA_HOME)/bin/javac -d target java/recipeNo066/redux/Main.java

lib/recipeNo066_redux_main.o: compilejava c/recipeNo066_redux_main.m 
	$(CC) -g -o lib/recipeNo066_redux_main.o -c c/recipeNo066_redux_main.m \
    	-I${JAVA_HOME}/include \
    	-I${JAVA_HOME}/include/$(ARCH)/ \

main.darwin: lib/recipeNo066_redux_main.o
	ld -o lib/recipeNo066_redux_main  \
	$(LD_FLAGS) \
	$(FOUNDATION_FRAMEWORK) \
	lib/recipeNo066_redux_main.o

main.linux:
	@echo "Nothing to be done here. Sorry. This one is macOS specific."

install: main.darwin compilejava
	-cp lib/recipeNo066_redux_main recipeNo066-redux.app/Contents/MacOS/recipeNo066
	-cp -r target recipeNo066-redux.app/Contents/Resources/target
	-$(JAVA_HOME)/bin/jlink --add-modules java.base --output recipeNo066-redux.app/Contents/Resources/jvm
	-install_name_tool -add_rpath @executable_path/../Resources/jvm/lib/server recipeNo066-redux.app/Contents/MacOS/recipeNo066

test: install
	./recipeNo066-redux.app/Contents/MacOS/recipeNo066

clean: clean-common
	$(call rm-test,recipeNo066-redux.app)

include ../Makefile.clean

