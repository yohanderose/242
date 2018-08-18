#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*2. use an emalloc function */
void * emalloc(size_t s) {
  void * result = malloc(s);
  if (result == NULL) {
    fprintf(stderr, "Memory allocation failed!\n");
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

  char *words[100];
  int i, n = 0;
  double sum = 0.00, avg;

  for (i = 0; i < 100; i++) {
    words[i] = emalloc(sizeof(char)*79);
  }

  
  while (1 == scanf("%s", words[n]) && n < 100) {
    n++;
  }
  /*3. calculate the average word length*/
  for (i = 0; i < n; i++) {
    sum += strlen(words[i]);
  }
  avg = sum/n;
  /*4. print all words > avg*/
  printArr(words, 0, n, avg);
  /*5. print to stderr, the average word length to two decimal places.*/
  fprintf(stderr, "%.2f\n", avg);

  /*6. free allocated memory*/
  for (i = 0; i < n; i++) {
    free(words[i]);
  }
  /*free(words);*/
  return 0;
}
