#include <stdio.h>
#include <stdlib.h>

int main(void) {
  printf("Enter contestants:\n");
  int winner = -1;
  int winnersScore = 0;
  int contestant = 0;
  double a, b, c;

  while (1 == scanf("%d %lg %lg %lg", &contestant, &a, &b, &c)) {
    int result = check(a, b, c);
    if (result > winnersScore) {
      winnersScore = result;
      winner = contestant;
    }
  }
  printf("Winner: %d", winner);
  return 0;
}

int check(double a, double b, double c) {
  int score = 0;
  if (a < b && a < c) {
    score = b + c;
  } else if (b < a && b < c) {
    score = a + c;
  } else {
    score = a + b;
  }
  return score;
}
