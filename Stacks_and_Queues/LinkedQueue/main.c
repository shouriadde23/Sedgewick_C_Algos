#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// helper QueueNode linked list (implementation) class
struct QueueNode {
    struct QueueNode *QueueTop;
    struct QueueNode *QueueEnd;
    int length;
    int item;
    struct QueueNode *next;
} QueueNode;


/**
 * Initializes an empty stack.
*/
void QueueCreate(struct QueueNode* st) {
    st->QueueTop = NULL;
    st->QueueEnd = NULL;
    st->length = 0;
    st->next = NULL;
}

/**
 * Returns true if this stack is empty.
 * 
 * @return true if this stack is empty; false otherwise
*/
bool isEmpty(struct QueueNode* st) {
    return st->QueueTop == NULL;
}

/**
 * Returns the number of items in this stack.
 *
 * @return the number of items in this stack
*/
int length(struct QueueNode* st) {
    return st->length;
}

/**
 * Adds the item to this stack.
 *
 * @param  item the item to add
 */
void enqueue(struct QueueNode* st, int correctNum) {
    // creating a new oldLast which points to the previous last node
    struct QueueNode* oldLast = (struct QueueNode*)malloc(sizeof(QueueNode));
    oldLast = st->QueueEnd;
    // create the new last node
    st->QueueEnd = (struct QueueNode*)malloc(sizeof(QueueNode));
    // update the properties of the last node; its next pointer should point to NULL
    st->QueueEnd->item = correctNum;
    st->QueueEnd->next = NULL;
    // checking if st is empty; set the QueueTop value to the QueueEnd value
    if(isEmpty(st)) {
        st->QueueEnd = st->QueueTop;
    }
    // update the next pointer of the oldLast to point to the the newly allocated st0>QueueEnd
    else {
        oldLast->next = st->QueueEnd; 
    }
    // update the length properties!
    st->length++;
}

/**
 * Removes and returns the item most recently added to this stack.
 *
 * @return the item most recently added
 * @throws NoSuchElementException if this stack is empty
 */
int dequeue(struct QueueNode* st) {
    // checking for stack underflow
    if(isEmpty(st)) {
        printf("Stack underflow");
        return 0;
    }
    // save item to return
    int item = st->QueueTop->item;
    // remove the top of the queue        
    st->QueueTop = st->QueueTop->next;
    // decrement the length of queue
    st->length--;
    // to avoid loitering
    if (isEmpty(st)) {
        st->QueueEnd = NULL;   
    }
    // return the saved item
    return item;                   
}


/**
 * Returns (but does not remove) the item most recently added to this stack.
 *
 * @return the item most recently added to this stack
 * @throws NoSuchElementException if this stack is empty
 */
int peek(struct QueueNode* st) {
    if (isEmpty(st)) {
        printf("Stack underflow");
    }
    return st->QueueTop->item;
}

/**
 * Unit tests the {@code Stack} data type.
 *
 * @param args the command-line arguments
 */
int main() {
    int p, count, range;
    printf("Please enter a valid range of numbers you want to include in stack, and how attempts you want!\n");
	scanf("%d ", &range);
    scanf("%d", &count);
    struct QueueNode* queueMain = (struct QueueNode*)malloc(sizeof(QueueNode));
    while (count != 0) {
        scanf("%d\n", &queueMain->item);
        if(queueMain->item < range) {
            enqueue(queueMain, queueMain->item);
        }
        else if(isEmpty(queueMain) != true) {
            printf("%d\n", dequeue(queueMain));
        }
        count--;
    }
    printf("Thank you for running, there are now %d item(s) left on the queue!\n", length(queueMain));
    return 0;
}