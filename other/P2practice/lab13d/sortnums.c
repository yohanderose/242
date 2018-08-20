#include <stdio.h>
#include <stdlib.h>
#include "flexarray.h"

int main(void) {
    int in;
    flexarray f = flexarray_new();
    
    while (1 == scanf("%d", &in)) {
        flexarray_append(f, in);
    }
    flexarray_sort(f);
    flexarray_print(f);
    flexarray_free(f);
    
    return EXIT_SUCCESS;
}
