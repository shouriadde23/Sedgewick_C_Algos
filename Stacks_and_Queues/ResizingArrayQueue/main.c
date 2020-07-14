#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* a[];         // array of items
int n;            // number of elements on queue
int first;
int last;

/**
 * Initializes an empty queue.
 */
void ResizingArrayQueue() {
    int* a = (int*)malloc(2 * sizeof(int));
    n = 0;
    first = 0;
    last = 0;
}

/**
 * Is this queue empty?
 * @return true if this queue is empty; false otherwise
 */
bool isEmpty() {
    return n == 0;
}

/**
 * Returns the number of items in the queue.
 * @return the number of items in the queue
 */
int size() {
    return n;
}

// resize the underlying array holding the elements
void resize(int capacity) {
    // textbook implementation
    int* copy = (int*)malloc(capacity * sizeof(int));
    for (int i = 0; i < n; i++) {
        copy[i] = a[(first + i) % size(a)];
    }
    int* a = copy;
    first = 0;
    last = n;
}

/**
 * Adds the item to this queue.
 * @param item the item to add
 */
void enqueue(int item) {
    // double size of array if necessary
    if (n == size(a)) {
        resize(2*size(a));
    } 
    // add item
    a[last++] = item;                            
    if(last == size(a)) {
        last = 0;
    }
    n++;
}

/**
 * Removes and returns the item most recently added to this queue.
 * @return the item most recently added
 * @throws java.util.NoSuchElementException if this queue is empty
 */
int dequeue() {
    if (isEmpty()) {
        printf("Queue underflow!");
        return 0;
    }
    int item = a[first];
    // to avoid loitering
    a[first] = NULL;                              
    n--;
    first++;
    if(first == size(a)) {
        first = 0;
    }
    // shrink size of array if necessary
    if (n > 0 && n == size(a)/4) {
        resize(size(a)/2);
    }
    return item;
}


/**
 * Returns (but does not remove) the item most recently added to this queue.
 * @return the item most recently added to this queue
 * @throws java.util.NoSuchElementException if this queue is empty
 */
int peek() {
    if (isEmpty()) {
        printf ("Queue underflow");
        return 0;
    }
    return a[first];
}

/**
 * Unit tests the {@code Queue} data type.
 *
 * @param args the command-line arguments
 */
int main() {
    int item, count, range;
    printf("Please enter a valid range of numbers you want to include in queue, and how attempts you want!\n");
    scanf("%d ", &range);
    scanf("%d", &count);
    int* queueMain = (int*)malloc(sizeof(int));
    while (count != 0) {
        scanf("%d\n", &item);
        if(item < range) {
            enqueue(item);
        }
        else if(isEmpty(queueMain) != true) {
            printf("%d\n", dequeue(queueMain));
        }
        count--;
    }
    printf("Thank you for running, there are now %d item(s) left on the queue!\n", size(queueMain));
    return 0;
}