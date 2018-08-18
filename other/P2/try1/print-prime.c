#include <stdlib.h>
#include <stdio.h>

int isPrime(int c) {
  int i;

  for (i=1; i<c; i++) {
    if (c%i == 0 && i!=1) {
      return 0;
    }
  }
  return 1;
}

int main() {
  
  int c = 2;
  int printed = 0;
  
  while (printed < 200) {
    if (isPrime(c)) {
      if (printed%10 == 9 && printed!=0) {
	printf("%5d\n", c);
	printed++;
      } else {
	printf("%5d", c);
	printed++;
      }
    }
    c++;
  }
}
