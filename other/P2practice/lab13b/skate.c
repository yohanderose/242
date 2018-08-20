#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int n, winner=0;
    double a, b, c, winnerScore=0;

    while (EOF!=scanf("%d%lg%lg%lg", &n, &a, &b, &c)) {
        double score=0;
        if (a<b && a<c) {
            score = (b+c)/2;
        } else if (b<a && b<c) {
            score = (a+c)/2;
        } else {
            score = (a+b)/2;
        }
        
        if (score > winnerScore) {
            winner = n;
            winnerScore = score;
        }
    }

    printf("%d\n", winner);
}
