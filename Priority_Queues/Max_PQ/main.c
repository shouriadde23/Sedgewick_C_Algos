#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// store items at indices 1 to n    
int* pq[];                    
// number of items on priority queue
int n;                       

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
 * Initializes an empty priority queue with the given initial capacity.
 *
 * @param  initCapacity the initial capacity of this priority queue
 */
void MaxPQ(int* pq[], int initCapacity) {
    pq[initCapacity + 1];
    n = 0;
}

/***************************************************************************
* Helper functions to restore the heap invariant.
***************************************************************************/
// used for when we want to traverse up the heap
void swim(int* pq[], int k) {
    // if k is greater than its parent (k/2), swap and set parent to k
    while (k > 1 && less(k/2, k)) {
        exch(pq, k, k/2);
        k = k/2;
    }
}

// used when we want to traverse down the heap
void sink(int* pq[], int k) {
    // loop while atleast one parent's two children is in bounds
    while (2*k <= n) {
        // find the larger of the two children + exchange if old parent is smaller
        int j = 2*k;
        if (j < n && less(j, j+1)) {
            j++;
        } 
        if (!less(k, j)) {
            break;
        }
        exch(pq, k, j);
        k = j;
    }
}

// is subtree of pq[1..n] rooted at k a max heap?
// properties of max heap - parent needs to >= all (max both) of its children
bool isMaxHeapOrdered(int k) {
    if (k > n) return true;
    int left = 2*k;
    int right = 2*k + 1;
    if (left  <= n && less(k, left))  return false;
    if (right <= n && less(k, right)) return false;
    return isMaxHeapOrdered(left) && isMaxHeapOrdered(right);
} 
/**
 * Returns true if this priority queue is empty.
 *
 * @return {@code true} if this priority queue is empty;
 *         {@code false} otherwise
 */
bool isEmpty(int* pq[]) {
    return n == 0;
}

/**
 * Returns the number of keys on this priority queue.
 *
 * @return the number of keys on this priority queue
 */
int size(int* pq[]) {
    return n;
}

/**
 * Returns a largest key on this priority queue.
 *
 * @return a largest key on this priority queue
 * @throws NoSuchElementException if this priority queue is empty
 */
int max(int* pq[]) {
    if (isEmpty(pq)) {
        printf("Priority queue underflow");
        return 0;
    } 
    return pq[1];
}

// helper function to double the size of the heap array
void resize(int capacity) {
    int temp[capacity];
    for (int i = 1; i <= n; i++) {
        temp[i] = pq[i];
    }
    *pq = temp;
}


/**
 * Adds a new key to this priority queue.
 *
 * @param  x the new key to add to this priority queue
 */
void insert(int* pq[], int x, int length) {
    // double size of array if necessary
    if (n == length - 1) {
        resize(2 * length);
    } 
    // add x, and percolate it up to maintain heap invariant
    pq[++n] = x;
    swim(pq, n);
}

/**
 * Removes and returns a largest int on this priority queue.
 *
 * @return a largest key on this priority queue
 * @throws NoSuchElementException if this priority queue is empty
 */
int delMax(int* pq[], int length) {
    if (isEmpty(pq)) {
        printf("Priority queue underflow");
        return 0;
    }
    // swap max with node at very end of tree
    int max = pq[1];
    exch(pq, 1, n--);
    // sink the swapped node down; check is inside sink
    sink(pq, 1);
    // to avoid loitering and help with garbage collection
    pq[n+1] = NULL;
    // variants for resizing of array  
    if ((n > 0) && (n == (length - 1) / 4)) resize(length / 2);
    return max;
}

// is pq[1..n] a max heap?
bool isMaxHeap(int length) {
    for (int i = 1; i <= n; i++) {
        if (pq[i] == NULL) {
            return false;
        }
    }
    for (int i = n+1; i < length; i++) {
        if (pq[i] != NULL) {
            return false;
        }
    }
    if (pq[0] != NULL) {
        return false;
    } 
    return isMaxHeapOrdered(1);
}

int main() {
    int index, count, range;
    printf("Please enter a valid upper bound on the numbers you want to include in stack, and how attempts you want!\n");
	scanf("%d ", &range);
    scanf("%d", &count);
    
    int* maxPQ[count + 1];
    while (count != 0) {
        scanf("%d\n", &index);
        if(index < range) {
            insert(maxPQ, index, count);
        }
        else if(isEmpty(maxPQ) != true) {
            printf("%d\n", delMax(maxPQ, count));
        }
        count--;
    }
    printf("Thank you for running, there are now %d item(s) left on the priority queue!\n", size(maxPQ));
    return 0;   
}
