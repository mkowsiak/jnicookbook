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

all: main.$(ARCH) compilejava jar

compilejava:
	$(JAVA_HOME)/bin/javac -d target java/recipeNo050/redux/Main.java

recipeNo050_redux_main.o: c/recipeNo050_redux_main.c
	$(CC) -g -o lib/recipeNo050_redux_main.o -c c/recipeNo050_redux_main.c \
    	-I${JAVA_HOME}/include \
    	-I${JAVA_HOME}/include/$(ARCH)/ \

main.darwin: recipeNo050_redux_main.o
	ld -o lib/recipeNo050_redux_main \
	$(LD_FLAGS) \
	lib/recipeNo050_redux_main.o

main.linux:
	$(CC) -g -o lib/recipeNo050_redux_main c/recipeNo050_redux_main.c \
	-I${JAVA_HOME}/include \
	-I${JAVA_HOME}/include/$(ARCH)/ \
	-pthread $(LD_FLAGS) 
	
test:
	lib/recipeNo050_redux_main

jar:
	$(JAVA_HOME)/bin/jar cfm lib/libjava.jar Manifest.txt -C target recipeNo050/redux/Main.class
	

clean: clean-common

include ../Makefile.clean

