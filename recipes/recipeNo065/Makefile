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

compilejava:
	$(JAVA_HOME)/bin/javac -d target java/recipeNo065/redux/Main.java

recipeNo065_redux_main.o: c/recipeNo065_redux_main.m
	$(CC) -g -o lib/recipeNo065_redux_main.o -c c/recipeNo065_redux_main.m \
    	-I${JAVA_HOME}/include \
    	-I${JAVA_HOME}/include/$(ARCH)/ \

main.darwin: compilejava recipeNo065_redux_main.o
	ld -o lib/recipeNo065_redux_main \
	$(LD_FLAGS) \
	$(FOUNDATION_FRAMEWORK) \
	lib/recipeNo065_redux_main.o

main.linux:
	@echo "Nothing to be done here. Sorry. This one is macOS specific."
	
test:
	lib/recipeNo065_redux_main

clean: clean-common

include ../Makefile.clean


