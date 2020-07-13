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

// stably merge a[lo .. mid] with a[mid+1 ..hi] using aux[lo .. hi]
void merge(int* arr[], int* aux[], int lo, int mid,int hi) {
    // copy to aux[]
    for (int k = lo; k <= hi; k++) {
        aux[k] = arr[k]; 
    }

    // merge back to a[]
    int i = lo, j = mid+1;
    // filling out the k array
    for (int k = lo; k <= hi; k++) {
        // if low is greater than mid, add head of greater half (j), increment
        if (i > mid) {
            arr[k] = aux[j++];
        }          
        // if head of greater is bigger than high, then add the smaller half and increment  
        else if (j > hi) {
            arr[k] = aux[i++];
        }
        // if head of bigger half is bigger than smaller, add bigger half head, increment             
        else if (less(aux[j], aux[i])) {
            arr[k] = aux[j++];
        }
        // add smaller half head, increment
        else {
            arr[k] = aux[i++];
        }
    }
}

// mergesort a[lo..hi] using auxiliary array aux[lo..hi]
void sort(int* arr[], int* aux[], int lo, int hi) {
    // the base case where high is less than low which marks the end of sorting
    if (hi <= lo) return;
    // set up the middle point
    int mid = lo + (hi - lo) / 2;
    // call sort recursively on both halves
    sort(arr, aux, lo, mid);
    sort(arr, aux, mid + 1, hi);
    // merge both halves
    merge(arr, aux, lo, mid, hi);
}

/**
 * Rearranges the array in ascending order, using the natural order.
 * @param a the array to be sorted
 */
void sortNew(int* arr[], int length) {
    int* aux[length];
    sort(arr, aux, 0, length-1);
    // assert isSorted(a);
}

// print array to standard output
void show(int* arr[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
}

/**
 * Reads in a sequence of strings from standard input; mergesorts them; 
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
    sortNew(arr, count);
    show(arr, count);
    printf("\n");
    return 0;
}