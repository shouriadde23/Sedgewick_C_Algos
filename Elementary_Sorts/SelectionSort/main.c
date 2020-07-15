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
    int n = length;
    // loop through all values
    for (int i = 0; i < n; i++) {
        // initially set the minimum value to current value
        int min = i;
        // loop from current i value to the end of the array
        for(int j = i + 1; j < n; j++) {
            // if we find a smaller element than current 'j' value
            if(less(arr[j], arr[min])) {
                // set the min value to 'j'
                min = j;
            }
        }
        // once we've found the minimum most value, we can swap with i value!
        exch(arr, i, min);
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