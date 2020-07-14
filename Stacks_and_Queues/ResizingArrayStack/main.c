#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* a[];         // array of items
int n;            // number of elements on stack

/**
 * Initializes an empty stack.
 */
void ResizingArrayStack() {
    int* a = (int*)malloc(2 * sizeof(int));
    n = 0;
}

/**
 * Is this stack empty?
 * @return true if this stack is empty; false otherwise
 */
bool isEmpty() {
    return n == 0;
}

/**
 * Returns the number of items in the stack.
 * @return the number of items in the stack
 */
int size() {
    return n;
}


// resize the underlying array holding the elements
void resize(int capacity) {
    // textbook implementation
    int* copy = (int*)malloc(capacity * sizeof(int));
    for (int i = 0; i < n; i++) {
        copy[i] = a[i];
    }
    int* a = copy;
}

/**
 * Adds the item to this stack.
 * @param item the item to add
 */
void push(int item) {
    // double size of array if necessary
    if (n == size(a)) resize(2*size(a));
     // add item
    a[n++] = item;                           
}

/**
 * Removes and returns the item most recently added to this stack.
 * @return the item most recently added
 * @throws java.util.NoSuchElementException if this stack is empty
 */
int pop() {
    if (isEmpty()) {
        printf("Stack underflow!");
        return 0;
    }
    int item = a[n-1];
    // to avoid loitering
    a[n-1] = NULL;                              
    n--;
    // shrink size of array if necessary
    if (n > 0 && n == size(a)/4) {
        resize(size(a)/2);
    }
    return item;
 }

/**
 * Returns (but does not remove) the item most recently added to this stack.
 * @return the item most recently added to this stack
 * @throws java.util.NoSuchElementException if this stack is empty
 */
int peek() {
    if (isEmpty()) {
        printf ("Stack underflow");
        return 0;
    }
    return a[n-1];
}

/**
 * Unit tests the {@code Stack} data type.
 *
 * @param args the command-line arguments
 */
int main() {
    int item, count, range;
    printf("Please enter a valid range of numbers you want to include in stack, and how attempts you want!\n");
    scanf("%d ", &range);
    scanf("%d", &count);
    int* stackMain = (int*)malloc(sizeof(int));
    while (count != 0) {
        scanf("%d\n", &item);
        if(item < range) {
            push(item);
        }
        else if(isEmpty(stackMain) != true) {
            printf("%d\n", pop(stackMain));
        }
        count--;
    }
    printf("Thank you for running, there are now %d item(s) left on the stack!\n", size(stackMain));
    return 0;
}