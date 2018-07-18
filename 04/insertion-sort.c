#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_MAX 30000

void insertion_sort(int *a, int n) {
  int i, j, temp;
  for (i = 0; i < n; i++) {
    for (j = i-1; j >=0; j--) {
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
  int i, count = 0;
  clock_t start, end;

  while (count < ARRAY_MAX && 1 == scanf("%d", &my_array[count])) {
    count++;
  }

  start = clock();
  insertion_sort(my_array, count);
  end = clock();

  for (i = 0; i < count; i++) {
    printf("%d\n", my_array[i]);
  }
  fprintf(stderr, "%d %f\n", count, (end - start) / (double)CLOCKS_PER_SEC);
  return EXIT_SUCCESS;
}
