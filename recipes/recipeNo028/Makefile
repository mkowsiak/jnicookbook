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
	$(JAVA_HOME)/bin/javac -h c -d target java/recipeNo028/redux/Main.java
	$(JAVA_HOME)/bin/javac -h c -cp target -d target java/Main.java

recipeNo028_redux_main.o: c/recipeNo028_redux_main.c
	$(CC) -g -o lib/recipeNo028_redux_main.o -c c/recipeNo028_redux_main.c \
    	-I${JAVA_HOME}/include \
    	-I${JAVA_HOME}/include/$(ARCH) \

main.darwin: recipeNo028_redux_main.o
	ld -o lib/recipeNo028_redux_main \
        $(LD_FLAGS) \
	lib/recipeNo028_redux_main.o

main.linux:
	$(CC) -g -o lib/recipeNo028_redux_main c/recipeNo028_redux_main.c \
    	-I${JAVA_HOME}/include \
    	-I${JAVA_HOME}/include/$(ARCH) \
	$(LD_FLAGS)

test:
	lib/recipeNo028_redux_main	

clean: clean-common

include ../Makefile.clean

