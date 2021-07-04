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

FROM ubuntu:20.04

LABEL author="michal@owsiak.org"
LABEL description="Environment for running JNI Cookbook samples"

ENV TZ=Europe/Warsaw
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt-get update
RUN apt-get install -y vim
RUN apt-get install -y tree
RUN apt-get install -y curl
RUN apt-get install -y git
RUN apt-get install -y make
RUN apt-get install -y gcc
RUN apt-get install -y g++
RUN apt-get install -y libpthread-stubs0-dev
RUN apt-get install -y gdb
RUN apt-get install -y openjdk-13-jdk
RUN apt-get install -y scala

RUN mkdir -p /opt
COPY scripts/run.sh /opt/run.sh
RUN chmod +x /opt/run.sh

RUN useradd -ms /bin/bash jnicoder

USER jnicoder
WORKDIR /home/jnicoder

RUN echo 'export PS1="[\u@jnicookbook-docker:\w ] $ "' >> /home/jnicoder/.bashrc
RUN echo 'export JAVA_HOME=`dirname $(dirname $(readlink -f $(which javac)))`' >> /home/jnicoder/.bashrc

RUN git clone https://github.com/mkowsiak/jnicookbook.git

CMD /opt/run.sh
