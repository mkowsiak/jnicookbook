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

all: main.$(ARCH) download_log4j compilejava

compilejava:
	$(JAVA_HOME)/bin/javac -cp jar/log4j-api-2.12.1.jar:jar/log4j-core-2.12.1.jar -d target java/recipeNo060/redux/Main.java

recipeNo060_redux_main.o: c/recipeNo060_redux_main.c
	$(CC) -g -o lib/recipeNo060_redux_main.o -c c/recipeNo060_redux_main.c \
    	-I${JAVA_HOME}/include \
    	-I${JAVA_HOME}/include/$(ARCH)/ \

download_log4j:
	curl -s -L -z jar/log4j-api-2.12.1.jar -o jar/log4j-api-2.12.1.jar https://repo.maven.apache.org/maven2/org/apache/logging/log4j/log4j-api/2.12.1/log4j-api-2.12.1.jar
	curl -s -L -z jar/log4j-core-2.12.1.jar -o jar/log4j-core-2.12.1.jar https://repo.maven.apache.org/maven2/org/apache/logging/log4j/log4j-core/2.12.1/log4j-core-2.12.1.jar

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

clean: clean-common
	$(call rm-test,jar/log4j-api-2.12.1.jar)
	$(call rm-test,jar/log4j-core-2.12.1.jar)

include ../Makefile.clean

