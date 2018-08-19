#include <stdlib.h>
#include <stdio.h>


int main() {
  int competitor, winner = 0;
  double j1, j2, j3,  winnerScore = 0;

  while(EOF!=scanf("%d%lg%lg%lg", &competitor, &j1, &j2, &j3)) {
    double score = 0;

    if (j1 < j2 && j1 < j3) {
      score = (j2+j3)/2;
    } else if (j2 < j1 && j2 < j3) {
      score = (j3 + j1)/2;
    } else {
      score = (j1 + j2)/2;
    }

    if (score > winnerScore) {
      winner = competitor;
      winnerScore = score;
    }
  }

  printf("%d\n", winner);
}
