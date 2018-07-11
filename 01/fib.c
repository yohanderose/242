#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *argv[]) {
  int i;
  int fib = 1;
  int g = 0;
  int store = 0;

  for (i = 0; i < 40; i++) {
    printf("%d\n", fib);
    store = fib;
    fib += g;
    g = store;
  }
  return 0;
}
