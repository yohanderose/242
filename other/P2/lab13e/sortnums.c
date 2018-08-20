#include <stdio.h>
#include <stdlib.h>
#include "flexarray.h"

int main(void) {

  int input;
  flexarray f = flexarray_new();
  
  while(1==scanf("%d", &input)) {
    flexarray_append(f, input);
  }

  flexarray_sort(f);
  flexarray_print(f);
  flexarray_free(f);
 
  return EXIT_SUCCESS;
}
