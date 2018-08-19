#include <stdio.h>
#include <stdlib.h>

void printFreq(int *my_array, int array_size) {
    int *freq = malloc(array_size * sizeof my_array[0]);
    int i;
    if (NULL == freq) {
        fprintf(stderr, "memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    for (i=0; i<array_size; i++) {
        freq[my_array[i]]++;
    }
    for (i=0; i<array_size; i++) {
        if (freq[i]>0) {
            printf("%d occurs %d times\n", i, freq[i]);
        }
    }
    free(freq); 
}

int main(void) {
    int array_size = 0;
    int *my_array = NULL;
    int i = 0;
    printf("Enter the size of the array:\n");
    scanf("%d", &array_size);
    my_array = malloc(array_size * sizeof my_array[0]);
    if (NULL == my_array) {
        fprintf(stderr, "memory allocation failed!\n");
        return EXIT_FAILURE;
    }
    for (i = 0; i < array_size; i++) {
        my_array[i] = rand() % array_size;
    }
    printf("What’s in the array:\n");
    for (i = 0; i < array_size; i++) {
        printf("%d ", my_array[i]);
    }
    printf("\n");

    printFreq(my_array, array_size);
    
    free(my_array);
    return EXIT_SUCCESS;
}
