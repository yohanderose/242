#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void * emalloc(size_t s) {
  void *result = malloc(s);
  if (result == NULL) {
    fprintf(stderr, "Memory allocation failure.\n");
    exit(EXIT_FAILURE);
  }
  return result;
}

void printArr(char *words[], int i, int n, double avg) {
  if (i < n) {
    if (strlen(words[i]) > avg) {
      printf("%s\n", words[i]);
    }
    printArr(words, ++i, n, avg);
  }
}

int main(void) {
  int i, n=0;
  double sum=0.00, avg;
  char *words[100];
  char temp[79];

  while (1 == scanf("%s", temp) && n<100) {
    words[n] = emalloc(strlen(temp)*sizeof(char));
    strcpy(words[n], temp);
    n++;
  }

  for (i=0; i<n; i++) {
    sum += strlen(words[i]);
  }
  avg = sum/n;

  printArr(words, 0, n, avg);
  fprintf(stderr, "%.2f\n", avg);


  for (i=0; i<n; i++) {
    free(words[i]);
  }
  
  return 0;
}
