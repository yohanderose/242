#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LENGTH 4

void insertion(int *x) {
  int i, j, temp;
  for (i = 1; i < ARRAY_LENGTH; i++) {
    for (j = i-1; j >= 0; j--) {
      if (*(x+j) > *(x+j+1)) {
        temp = *(x+j+1);
        *(x+j+1) = *(x+j);
        *(x+j) = temp;
      }
    }
  }
}

void selection(int *x) {
  int i, j, temp;
  for (i = 0; i < ARRAY_LENGTH-1; i++) {
    int smallest = i;
    for (j = i+1; j < ARRAY_LENGTH; j++) {
      if (*(x+smallest) > *(x+j)) {
        smallest = j;
      }
    }
    temp = *(x+smallest);
    *(x+smallest) = *(x+i);
    *(x+i) = temp;
  }
}



int main(void) {

  int i;
  int count = 0;
  int test[ARRAY_LENGTH];

  while (count < ARRAY_LENGTH && 1 == scanf("%d", &test[count])) {
    count++;
  }

  printf("Before:\t[ ");
  for (i = 0; i < ARRAY_LENGTH; i++) {
    printf("%d ", test[i]);
  }
  printf("]\n");

  insertion(test);
  /*selection(&test);*/

  printf("After:\t[ ");
  for (i = 0; i < ARRAY_LENGTH; i++) {
    printf("%d ", test[i]);
  }
  printf("]\n");

  return 0;
}
