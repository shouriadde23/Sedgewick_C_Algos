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

    // set up the 3x + 1 increment sequence
    int h = 1;
    while(h < n/3) {
        h = 3*h + 1;
    }
    // h-sort the array
    while(h >= 1) {
        // loop from current h pointer till the end of the array
        for (int i = h; i < n; i++) {
        // loop from current i till the end of the h pointer
            for(int j = i; j >= h && less(arr[j], arr[j - h]); j-= h) {
                // if the h pair distanced elements are lesser than one another, exchange them!
                exch(arr, j, j - h);
            }
        }
        // make sure to restore the h-pointer after the swap has been completed
        h /= 3;   
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