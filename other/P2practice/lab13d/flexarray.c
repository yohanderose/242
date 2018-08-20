#include <stdio.h>
#include <stdlib.h>
#include "flexarray.h"

struct flexarrayrec {
    int capacity;
    int itemcount;
    int *items;
};

void* emalloc(size_t s) {
    void *result = malloc(s);
    if (result == NULL) {
        exit(EXIT_FAILURE);
    }
    return result;
}

void* erealloc(void *a, int n) {
    void *result = realloc(a, n);
    if (result == NULL) {
        exit(EXIT_FAILURE);
    }
    return result;
}

flexarray flexarray_new() {
    flexarray f = emalloc(sizeof *f);
    f->capacity = 2;
    f->itemcount = 0;
    f->items = emalloc(f->capacity* sizeof f->items[0]);
    return f;
}
void flexarray_append(flexarray f, int num) {
    if (f->itemcount == f->capacity) {
        f->capacity *= 2;
        f->items = erealloc(f->items, f->capacity*sizeof f->items[0]);
    }
    f->items[f->itemcount++] = num;
}
void flexarray_print(flexarray f) {
    int i;
    for (i=0; i<f->itemcount; i++) {
        printf("%d\n", f->items[i]);
    }
}
void flexarray_printERR(flexarray f) {
    int i;
    for (i=0; i<f->itemcount; i++) {
        fprintf(stderr, "%d\n", f->items[i]);
    }
}
void flexarray_sort(flexarray f) {
    int i, j, key;
    for (i=0; i<f->itemcount; i++) {
        if (i==f->itemcount/2) {
            flexarray_printERR(f);
        }
        key = f->items[i];
        j = i-1;
        while (j>=0 && key < f->items[j]) {
            f->items[j+1] = f->items[j];
            j--;
        }
        f->items[j+1] = key;
    }
}
void flexarray_free(flexarray f) {
    free(f->items);
    free(f);
}
