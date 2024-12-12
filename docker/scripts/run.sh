#!/bin/bash

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

cd $HOME

cat << EOF


      ****************************************************
            https://github.com/mkowsiak/jnicookbook
      ****************************************************

        This Docker container provides easy way of
        running JNI Cookbook samples.

        ------------------------------------------------
        
        Once started, you can go inside jnicookbook
        directory and run sample codes.

        It's realy simple. All you have to do, is to
        choose recipe and run it. Container's 
        environment is prepared to run all the samples.

        > cd jnicookbook/recipes
        > cd recipe001
        > make; make test
 
        ------------------------------------------------


EOF

/bin/bash
