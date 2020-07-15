#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// implementing the random shuffle
void shuffle(int* arr[], int length) {
    int n = length;
    for (int i = 0; i < n; i++) {
        // choose index uniformly in [0, i]
        int r = i + rand() / (RAND_MAX / (n - i) + 1);
        // swap i with the chosen index value
        int swap = arr[r];
        arr[r] = arr[i];
        arr[i] = swap;
    }
}

// print array to standard output
void show(int* arr[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
}

/**
 * Reads in a sequence of ints from standard input;
 * shuffles and prints them to standard output in ascending order.
 *
 * @param args the command-line arguments
 */
int main() {
    // int* arr[];
    int count;
    printf("Please enter the number of values you would like sorted!\n");
    scanf("%d", &count);
    int* arr[count];
    printf("Please enter your values one by one!\n");
    for(int i = 0; i < count; i++) {
        printf("value - %d ", i);
        scanf("%d", &arr[i]);
    }
    shuffle(arr, count);
    show(arr, count);
    printf("\n");
    return 0;
}