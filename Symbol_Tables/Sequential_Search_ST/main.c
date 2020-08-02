#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// a helper linked list data type
typedef struct Node {
    int key;
    int val;
    struct Node* head;
    struct Node* next;
} ListNode;

// helper QueueNode linked list (implementation) class
struct QueueNode {
    struct QueueNode *QueueTop;
    struct QueueNode *QueueEnd;
    int length;
    int item;
    struct QueueNode *next;
} QueueNode;

int n;              // number of key-value pairs
ListNode* head;     // the linked list of key-value pairs

ListNode* createNode(int key, int val, ListNode* next)  {
        ListNode* temp = (struct Node*)malloc(sizeof(struct Node));
        temp->key  = key;
        temp->val  = val;
        temp->next = next;
        return temp;
}

/*
 * Returns the number of key-value pairs in this symbol table.
 *
 * @return the number of key-value pairs in this symbol table
*/
int size() {
    return n;
}


/**
 * Returns true if this symbol table is empty.
 *
 * @return {@code true} if this symbol table is empty;
 *         {@code false} otherwise
 */
bool isEmpty(struct QueueNode* st) {
    return size() == 0;
}


/**
 * Returns the value associated with the given key in this symbol table.
 *
 * @param  key the key
 * @return the value associated with the given key if the key is in the symbol table
 *     and {@code null} if the key is not in the symbol table
 * @throws IllegalArgumentException if {@code key} is {@code null}
 */
int get(ListNode* temp, int cKey) {
    ListNode* runner;
    if (cKey == '\0') {
        printf("argument to get() is null");
        return 0;
    }
    
    for (ListNode* runner = temp->head; runner != NULL; runner = runner->next) {
        if (cKey == runner->key) {
            return runner->val;
        }
    }
    return 0;
}


/**
 * Returns true if this symbol table contains the specified key.
 *
 * @param  key the key
 * @return {@code true} if this symbol table contains {@code key};
 *         {@code false} otherwise
 * @throws IllegalArgumentException if {@code key} is {@code null}
 */
bool contains(ListNode* temp, int key) {
    if (key == '\0') {
        printf("argument to contains() is null");
        return false;
    }
    return get(temp, key) != '\0';
}


// delete key in linked list beginning at Node x
// warning: function call stack too large if table is large
ListNode* deleteKey(ListNode* x, int key) {
    if (x == NULL) {
        return NULL;
    }
    if (key == x->key) {
        n--;
        return x->next;
    }
    x->next = deleteKey(x->next, key);
    return x;
}


/**
 * Removes the specified key and its associated value from this symbol table     
 * (if the key is in this symbol table).    
 *
 * @param  key the key
 * @throws IllegalArgumentException if {@code key} is {@code null}
 */
void delete(ListNode* x, int key) {
    if (key == '\0') {
        printf("argument to delete() is null");
        return;
    } 
    x->head = deleteKey(x->head, key);
}



/**
 * Inserts the specified key-value pair into the symbol table, overwriting the old 
 * value with the new value if the symbol table already contains the specified key.
 * Deletes the specified key (and its associated value) from this symbol table
 * if the specified value is {@code null}.
 *
 * @param  key the key
 * @param  val the value
 * @throws IllegalArgumentException if {@code key} is {@code null}
 */
void put(ListNode* temp, int key, int val) {
    ListNode* runner;
    
    if (key == '\0') {
        printf("first argument to put() is null"); 
        return;
    }
    if (val < 0) {
        delete(temp, key);
        return;
    }

    for (ListNode* runner = temp->head; runner != NULL; runner = runner->next) {
        if (key == (runner->key)) {
            runner->val = val;
            return;
        }
    }
    temp->head = createNode(key, val, temp->head);
    n++;
}


/**
 * Adds the item to this queue.
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
 * Returns all keys in the symbol table as an {@code Iterable}.
 * To iterate over all of the keys in the symbol table named {@code st},
 * use the foreach notation: {@code for (Key key : st.keys())}.
 *
 * @return all keys in the symbol table
 */
 struct QueueNode* keys(ListNode* temp)  {
    struct QueueNode* queueMain = (struct QueueNode*)malloc(sizeof(QueueNode));
    // Queue<int> queue = new Queue<int>();
    for (ListNode* x = temp->head; x != NULL; x = x->next) {
        enqueue(queueMain, x->key);
    }
    return queueMain;
}


/**
 * Unit tests the {@code SequentialSearchST} data type.
 *
 * @param args the command-line arguments
 */
int main() {
    int p, count, range;
    ListNode* searchMain = (struct Node*)malloc(sizeof(struct Node));
    printf("Please enter a valid range of integers you want to include!");
    printf("\n");
    scanf("%d", &count);
    printf("Now enter these integers each seperated by a space!");
    printf("\n");
    for (int i = 0; i < count; i++) {
        p = i;
        scanf("%d", &searchMain->key);
        put(searchMain, searchMain->key, p);
    }

    for (ListNode* s = searchMain->head; s != NULL; s = s->next) {
        printf("%d %d\n", s->key, s->val);
    }
    return 0;
}