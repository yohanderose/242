#include <stdlib.h>
#include <stdio.h>

int isPrime(int n) {
    int i;
    for (i=2; i<n; i++) {
        if (n%i==0) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    int c = 2, printed = 0;

    while (printed<200) {
        if (isPrime(c)) {
            if (printed%10==9) {
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
