#include <stdio.h>

int main(int argc, char const *argv[]) {
  int i;
  printf("Welcome to the C program\n");
  printf("Lets print out some numbers\n");

  for (i = 0; i < 5; i++) {
    printf("%d\n", i);
  }

  printf("%s\n", "Finished");
  return -1;
}
