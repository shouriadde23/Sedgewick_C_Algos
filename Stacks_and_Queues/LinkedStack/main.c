#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// helper linked list class
struct StackNode {
    struct StackNode *stackTop;
    int length;
    int item;
    struct StackNode *next;
} StackNode;


/**
 * Initializes an empty stack.
*/
void stackCreate(struct StackNode* st) {
    st->stackTop = st;
    st->length = 0;
    st->next = NULL;
}

/**
 * Returns true if this stack is empty.
 * 
 * @return true if this stack is empty; false otherwise
*/
bool isEmpty(struct StackNode* st) {
    return st->stackTop == NULL;
}

/**
 * Returns the number of items in this stack.
 *
 * @return the number of items in this stack
*/
int length(struct StackNode* st) {
    return st->length;
}

/**
 * Adds the item to this stack.
 *
 * @param  item the item to add
 */
void push(struct StackNode* st, int correctNum) {
    // create a node which will point to the original top of stack
    struct StackNode* oldFirst = (struct StackNode*)malloc(sizeof(StackNode));
    oldFirst = st->stackTop;
    // create the new stack top node
    st->stackTop = (struct StackNode*)malloc(sizeof(StackNode));
    // update properties of this new stack top; its next should point to the oldFirst
    st->stackTop->item = correctNum;
    st->stackTop->next = oldFirst;
    // update length of stack after new node was added!
    st->length++;
}

/**
 * Removes and returns the item most recently added to this stack.
 *
 * @return the item most recently added
 * @throws NoSuchElementException if this stack is empty
 */
int pop(struct StackNode* st) {
    if (isEmpty(st)) {
        printf("Stack underflow");
        return 0;
    }
    // save item to return
    int item = st->stackTop->item;
    // delete the top of stack
    st->stackTop = st->stackTop->next;
    // decrement length of stack
    st->length--;
    // return the saved item
    return item;                   
}


/**
 * Returns (but does not remove) the item most recently added to this stack.
 *
 * @return the item most recently added to this stack
 * @throws NoSuchElementException if this stack is empty
 */
int peek(struct StackNode* st) {
    if (isEmpty(st)) {
        printf("Stack underflow");
    }
    return st->stackTop->item;
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
    struct StackNode* stackMain = (struct StackNode*)malloc(sizeof(StackNode));
    while (count != 0) {
        scanf("%d\n", &stackMain->item);
        if(stackMain->item < range) {
            push(stackMain, stackMain->item);
        }
        else if(isEmpty(stackMain) != true) {
            printf("%d\n", pop(stackMain));
        }
        count--;
    }
    printf("Thank you for running, there are now %d item(s) left on the stack!\n", length(stackMain));
    return 0;
}