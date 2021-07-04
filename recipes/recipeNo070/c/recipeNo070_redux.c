/*
 * Copyright © 2021 Michal K. Owsiak. All rights reserved.
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

#include <stdio.h>
#include <stdlib.h>
#include "data_struct.h"

/* 
  All we are doing here is allocating data
  inside structure passed as argument 
*/

int retrieveData(struct DataStruct *ptr) {
 
  int *array = malloc(sizeof(int) * 4);

  if( array == NULL ) {

    return 1;

  }

  array[0] = 1;
  array[1] = 2;
  array[2] = 3;
  array[3] = 4;
 
  ptr->data   = (void*) array;
  
  ptr->width  = 2;
  ptr->height = 2;

  return 0;

}

