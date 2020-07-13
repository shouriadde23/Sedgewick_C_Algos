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

// print array to standard output
void show(int* arr[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
} 


/***************************************************************************
*  Helper sorting functions.
***************************************************************************/

// partition the subarray a[lo..hi] so that a[lo..j-1] <= a[j] <= a[j+1..hi]
// and return the index j.
// We want the repeat this process until the i and j pointers cross:
// Scan i from left to right so long as (a[i] < a[lo]).
// Scan j from right to left so long as (a[j] > a[lo]).
// Then, exchange a[i] with a[j].
int partition(int* a[], int lo, int hi) {
    int i = lo;
    int j = hi + 1;
    // this will be our partitioned element
    int v = a[lo];
    while (true) { 
        // find item on left to swap
        while (less(a[++i], v)) {
            if (i == hi) break;
        }
        
        // find item on right to swap
        while (less(v, a[--j])) {
            if (j == lo) break;      // redundant since a[lo] acts as sentinel
        }

        // check if pointers cross
        if (i >= j) {
            break;
        }
        // perform the swap
        exch(a, i, j);
    }

    // put partitioning item v at a[j]
    exch(a, lo, j);

    // return the index of item which we have now sorted in place
    return j;
}

// randomly shuffling the array; used to optimize the sorting algo
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

// quicksort a[lo..hi] using the partition method
void sort(int* arr[], int lo, int hi) {
    // the base case where high is less than low which marks the end of sorting
    if (hi <= lo) return;
    // set up the partition for the entire array
    int j = partition(arr, lo, hi);
    // call sort recursively on both halves of the partitioned element
    sort(arr, lo, j - 1);
    sort(arr, j + 1, hi);
}


/**
     * Rearranges the array in ascending order, using the natural order.
     * @param a the array to be sorted
     */
void sortNew(int* arr[], int length) {
    shuffle(arr, length);
    sort(arr, 0, length - 1);
}




/**
 * Rearranges the array so that {@code a[k]} contains the kth smallest key;
 * {@code a[0]} through {@code a[k-1]} are less than (or equal to) {@code a[k]}; and
 * {@code a[k+1]} through {@code a[n-1]} are greater than (or equal to) {@code a[k]}.
 *
 * @param  a the array
 * @param  k the rank of the key
 * @return the key of rank {@code k}
 * @throws IllegalArgumentException unless {@code 0 <= k < a.length}
 */
int select(int* arr[], int k, int length) {
    // check for validity
    if (k < 0 || k >= length) {
        printf("index is not between 0 and %d!", length);
    }
    // first shuffle the array given the kth value
    shuffle(arr, length);
    // set upper and lower bounds
    int lo = 0, hi = length - 1;
    // if high is greater than low, begin partitioning
    while (hi > lo) {
        // use partition to get the element we need to perform sort on both upper and lower halves
        int i = partition(arr, lo, hi);
        // decrement high pointer; making sure right of k is larger
        // if arr[k] is here, then set the hi to i - 1 (we are looking in the half smaller than partition element)
        if(i > k) {
            hi = i - 1;
        }
        // increment the low pointer; making sure left of k is smaller
        // if we are here, then set the low pointer to i + 1 (looking in the half greater than the partition element)
        else if(i < k) {
            lo = i + 1;
        } 
        // once j equals k, we've sorted correctly 
        else {
            return arr[i];
        }
    }
    // return the final sorted position of lowest element (element we've sorted)
    return arr[lo];
}
  

/**
 * Reads in a sequence of integers from standard input; quicksorts them; 
 * and prints them to standard output in ascending order. 
 * Shuffles the array and then prints the strings again to
 * standard output, but this time, using the select method.
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
    // quicksorting the array of provided integer values
    sortNew(arr, count);
    show(arr, count);

    // shuffle
    printf("\n");
    shuffle(arr, count);
    show(arr, count);

    // display results again using select
    printf("\n");
    for (int i = 0; i < count; i++) {
        int ith = select(arr, i, count);
        printf("%d ", ith);
    }
    printf("\n");
    return 0;
}
