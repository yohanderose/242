#include <stdlib.h>
#include <stdio.h>
#include "mylib.h"

int main(void) {
  int cap = 2, count = 0, item, i;
  int *a = emalloc(cap * sizeof a[0]);

  while (1==scanf("%d", &item)) {
    if (count == cap) {
      cap *= 2;
      a = erealloc(a, cap);
    }
    a[count++] = item;
  }

  for (i=0; i<count; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}
