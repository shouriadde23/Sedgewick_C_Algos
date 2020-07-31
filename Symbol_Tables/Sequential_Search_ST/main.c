#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// a helper linked list data type
typedef struct Node {
    struct Node* head;
    struct Node* curr;
    char key;
    int val;
    struct Node* next;
} Node;


// helper QueueNode linked list (implementation) class
struct QueueNode {
    struct QueueNode *QueueTop;
    struct QueueNode *QueueEnd;
    int length;
    int item;
    struct QueueNode *next;
} QueueNode;

int n;           // number of key-value pairs
Node* first;     // the linked list of key-value pairs

void createNode(char key, int val, Node* next)  {
        first->key  = key;
        first->val  = val;
        first->next = next;
}
/**
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
int get(char cKey) {
    if (cKey == '\0') {
        printf("argument to get() is null");
        return 0;
    }
    for (Node* x = first; x != NULL; x = x->next) {
        if (cKey == x->key) {
            return x->val;
        }
        return 0;
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
bool contains(char key) {
    if (key == '\0') {
        printf("argument to contains() is null");
        return false;
    }
    return get(key) != NULL;
}



// delete key in linked list beginning at Node x
// warning: function call stack too large if table is large
Node* deleteKey(Node* x, char key) {
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
void delete(char key) {
    if (key == '\0') {
        printf("argument to delete() is null");
        return;
    } 
    first = deleteKey(first, key);
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
void put(char key, int val) {
    printf("%d", valf);
    printf("yoooo");
    printf("hi");
    
    if (key == '\0') {
        printf("first argument to put() is null"); 
        return;
    }
    if (val == NULL) {
        printf("fdnfbsd");
        delete(key);
        return;
    }

    for (Node* x = first; x != NULL; x = x->next) {
        if (key == (x->key)) {
            x->val = val;
            return;
        }
    }
    // first = (Node*)malloc(sizeof(Node));
    createNode(key, val, first);
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
 struct QueueNode* keys()  {
    struct QueueNode* queueMain = (struct QueueNode*)malloc(sizeof(QueueNode));
    // Queue<int> queue = new Queue<int>();
    for (Node* x = first; x != NULL; x = x->next) {
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
    printf("Please enter a valid range of chars you want to include!\n");
    scanf("%d\n", &count);
    struct Node* searchMain = (struct Node*)malloc(sizeof(Node));
    for (int i = 0; i < count; i++) {
        // printf("yoer");
        p = i;
        scanf("%c ", &searchMain->head->key);
        printf("%d", p);
        printf("%c", searchMain->head->key);
        printf("yoer\n");
       
        printf("%s %d", searchMain->key, i);
        put(searchMain->key, p);
    }

    for (Node* s = searchMain->head; s != NULL; s = s->next) {
        printf("%c %d", s, get(s));
    }
    return 0;
}
#if 0
    SequentialSearchST<String, Integer> st = new SequentialSearchST<String, Integer>();
    for (int i = 0; !StdIn.isEmpty(); i++) {
            String key = StdIn.readString();
            st.put(key, i);
        }
        for (String s : st.keys())
            StdOut.println(s + " " + st.get(s));
    }
#endif