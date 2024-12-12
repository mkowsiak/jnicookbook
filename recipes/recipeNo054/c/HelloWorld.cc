/*
 * Copyright © 2015-2022 Michal K. Owsiak. All rights reserved.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#include <string>
#include <iostream>

class HelloWorld {
  public:
    bool displayMessageW(const std::wstring &str);
    bool displayMessage(const std::string &str);
};

bool HelloWorld::displayMessageW(const std::wstring &str)
{
  std::wcout << str << std::endl; 
  return true;
}

bool HelloWorld::displayMessage(const std::string &str)
{
  std::cout << str << std::endl; 
  return true;
}

extern "C" {

bool displayMessageWWrapper(wchar_t *str)
{
  HelloWorld hw;
  return hw.displayMessageW(std::wstring(str));
}

bool displayMessageWrapper(char *str)
{
  HelloWorld hw;
  return hw.displayMessage(std::string(str));
}



}

