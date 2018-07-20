#include <stdio.h>
#include <stdlib.h>

#define ARRAY_MAX 10

void insertion_sort(int *a, int n) {
  int i, j, temp;
  for (i = 1; i < n; i++) {
    for (j = i-1; i >= 0; i--) {
      if (*(a+j) > *(a+j+1)) {
        temp = *(a+j+1);
        *(a+j+1) = *(a+j);
        *(a+j) = temp;
      }
    }
  }
}

int main(void) {
  int my_array[ARRAY_MAX];
  int i;
  int count = 0;

  while (count < ARRAY_MAX && 1 == scanf("%d", &my_array[count])) {
    count++;
  }

  insertion_sort(my_array, count);

  for (i = 0; i < count; i++) {
    printf("%d\n", my_array[i]);
  }
  return EXIT_SUCCESS;
}
