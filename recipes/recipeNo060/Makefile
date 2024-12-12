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
include ../Makefile.log4j

all: main.$(ARCH) download_log4j compilejava

dirs:
	mkdir -p jar

compilejava:
	$(JAVA_HOME)/bin/javac -cp ./jar/$(LOG4J_API_JAR):./jar/$(LOG4J_CORE_JAR) -d target java/recipeNo060/redux/Main.java

recipeNo060_redux_main.o: c/recipeNo060_redux_main.c
	$(CC) -g -o lib/recipeNo060_redux_main.o -c c/recipeNo060_redux_main.c \
    	-I${JAVA_HOME}/include \
    	-I${JAVA_HOME}/include/$(ARCH)/ \

download_log4j: dirs
	$(call download-log4j)

main.darwin: recipeNo060_redux_main.o
	ld -o lib/recipeNo060_redux_main \
	$(LD_FLAGS) \
	lib/recipeNo060_redux_main.o

main.linux: recipeNo060_redux_main.o
	$(CC) -g -o lib/recipeNo060_redux_main c/recipeNo060_redux_main.c \
	-I${JAVA_HOME}/include \
	-I${JAVA_HOME}/include/$(ARCH)/ \
	-pthread $(LD_FLAGS) 
	
test:
	lib/recipeNo060_redux_main

test_java:
	java -cp ./target:./conf:./jar/$(LOG4J_API_JAR):./jar/$(LOG4J_CORE_JAR) recipeNo060.redux.Main

clean: clean-common
	$(call rm-test,jar)

include ../Makefile.clean

