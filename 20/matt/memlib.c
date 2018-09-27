#include "memlib.h"

#include <stdio.h>

void *emalloc(size_t s)
{
    void *result = malloc(s);
    if (result == NULL)
    {
        fprintf(stderr, "Error allocating memory!\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

void *ecalloc(size_t n, size_t s)
{
    void *result = calloc(n, s);
    if (result == NULL)
    {
        fprintf(stderr, "Error allocating and clearing memory!\n");
        exit(EXIT_FAILURE);
    }
    return result;
}
