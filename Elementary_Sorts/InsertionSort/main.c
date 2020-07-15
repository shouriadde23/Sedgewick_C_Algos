#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/***************************************************************************
*  Helper sorting functions.
***************************************************************************/
    
// is v < w ?
bool less(int v, int w) {
    if(v < w) {
        return true;
    }
    return false;
}

// exchange a[i] and a[j]  (for use while sorting)
void exch(int* arr[], int i, int j) {
    int swap = arr[i];
    arr[i] = arr[j];
    arr[j] = swap;
}

/**
 * Rearranges the array in ascending order, using the natural order.
 * @param a the array to be sorted
 */
void sort(int* arr[], int length) {
    // printf("kjkj");
    int n = length;
    // loop through the entire array
    for (int i = 0; i < n; i++) {
        // loop from current i till the end of the array
        for(int j = i; j > 0; j--) {
            // if j is smaller than j - 1 value, swap two values
            if(less(arr[j], arr[j - 1])) {
                exch(arr, j, j - 1);
            }
            // in the end everything to the left of element will be sorted, but right won't be seen yet!
            else {
                break;
            }
        }
    }
}

// print array to standard output
void show(int* arr[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
}

/**
 * Reads in a sequence of strings from standard input; insertion sorts them;
 * and prints them to standard output in ascending order.
 *
 * @param args the command-line arguments
 */
int main() {    
    int count;
    printf("Please enter the number of values you would like sorted!\n");
    scanf("%d", &count);
    int* arr[count];
    printf("Please enter your values one by one!\n");
    for(int i = 0; i < count; i++) {
        printf("value - %d ", i);
        scanf("%d", &arr[i]);
    }
    sort(arr, count);
    show(arr, count);
    printf("\n");
    return 0;
}