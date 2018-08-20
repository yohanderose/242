#include <stdlib.h>
#include <stdio.h>

void* emalloc(size_t s) {
  void *result = malloc(s);
  if (NULL == result) {
    fprintf(stderr, "Memory allocation failed!\n");
    exit(EXIT_FAILURE);
  }
  return result;
}

void* erealloc(void* a, size_t n) {
  void *result = realloc(a, n);
  if (NULL == result) {
    fprintf(stderr, "Memory allocation failed!\n");
    exit(EXIT_FAILURE);
  }
  return result;
}
