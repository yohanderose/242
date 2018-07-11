#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int isPrime(int x) {
  int i;
  if (x == 2) return 1;
  if (x%2 == 0) return 0;
  for (i = 2; i < x/2; i++) {
    if (x%i == 0) {
      return 0;
    }
  }
  return 1;
}

int main(int argc, char const *argv[]) {
  int printed = 0;
  int cantidate = 2;
  while (printed < 100) {
    if (isPrime(cantidate)) {
      printf("%d\n", cantidate);
      printed++;
    }
    cantidate++;
  }

  return 0;
}
