#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/// MAKE SURE TO COMMENT EVERYTHING!!!!

typedef struct Node {
    /* data */
    int key;           // sorted by key
    int val;          // associated data  
    TreeNode* left;
    TreeNode* right;  // left and right subtrees
    int size;       // number of nodes in subtree
} TreeNode;

TreeNode* root;   // root of BST

TreeNode* NodeCreate(int key, int val, int size) {
    TreeNode* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key = key;
    temp->val = val;
    temp->right = temp->left = NULL;
    temp->size = size;
    return temp;
}

// return number of key-value pairs in BST rooted at x
int sizePairs(TreeNode* x) {
    if (x == NULL) {
        return 0;
    } 
    else {
        return x->size;
    }
}

/**
 * Returns the number of key-value pairs in this symbol table.
 * @return the number of key-value pairs in this symbol table
 */
int size() {
    return sizePairs(root);
}

/**
 * Returns true if this symbol table is empty.
 * @return {@code true} if this symbol table is empty; {@code false} otherwise
 */
bool isEmpty() {
    return size(root) == 0;
}

/**
 * Returns the value associated with the given key.
 *
 * @param  key the key
 * @return the value associated with the given key if the key is in the symbol table
 *         and {@code null} if the key is not in the symbol table
 * @throws IllegalArgumentException if {@code key} is {@code null}
 */

int getVal(TreeNode* x, int key) {
    if (key == NULL) {
        printf("calls get() with a null key");
        return 0;
    }
    if (x == NULL) {
        return NULL;
    }
    if(key < x->key) {
        return getVal(x->left, key);
    } 
    else if(key > x->key) {
        return getVal(x->right, key);
    }
    else {
        return x->val;
    }
}

int get(int key) {
    return getVal(root, key);
}


/**
 * Does this symbol table contain the given key?
 *
 * @param  key the key
 * @return {@code true} if this symbol table contains {@code key} and
 *         {@code false} otherwise
 * @throws IllegalArgumentException if {@code key} is {@code null}
 */
bool contains(TreeNode* curr, int key) {
    if (key == NULL) {
        printf("argument to contains() is null");
        return false;
    } 
    return getVal(curr, key) != NULL;
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

TreeNode* insert(TreeNode* x, int key, int val) {
    if (x == NULL) { 
        return NodeCreate(key, val, 1);
    }
    if(key < x->key) {
        x->left = insert(x->left, key, val);
    } 
    else if(key > x->key) {
        x->right = insert(x->right, key, val);
    }
    else {
        x->val = val;
    }
    x->size = 1 + size(x->left) + size(x->right);
    return x;
}

void put(int key, int val) {
    if (key == NULL) {
        printf("calls put() with a null key");
    }
    if (val == NULL) {
        delete(key);
        return;
    }
    root = insert(root, key, val);
}


/**
 * Returns the smallest key in the symbol table.
 *
 * @return the smallest key in the symbol table
 * @throws NoSuchElementException if the symbol table is empty
 */

TreeNode* min(TreeNode* x) { 
    if (x->left == NULL) { 
        return x;
    } 
    return min(x->left); 
} 

int minKey() {
    if (isEmpty()) {
        printf("calls min() with empty symbol table");
        return 0;
    }
    return min(root)->key;
} 


/**
 * Returns the largest key in the symbol table.
 *
 * @return the smallest key in the symbol table
 * @throws NoSuchElementException if the symbol table is empty
 */

TreeNode* max(TreeNode* x) { 
    if (x->right == NULL) { 
        return x;
    } 
    return min(x->right); 
} 

int maxKey() {
    if (isEmpty()) {
        printf("calls min() with empty symbol table");
        return 0;
    }
    return max(root)->key;
}
    

/**
 * Removes the smallest key and associated value from the symbol table.
 *
 * @throws NoSuchElementException if the symbol table is empty
 */
TreeNode* deleteMinNode(TreeNode* x) {
    if (x->left == NULL) {
        return x->right;
    }
    x->left = deleteMinNode(x->left);
    x->size = size(x->left) + size(x->right) + 1;
    return x;
}

void deleteMin() {
    if (isEmpty()) { 
        printf("Symbol table underflow");
        return;
    }
    root = deleteMinNode(root);
}


/**
 * Removes the largest key and associated value from the symbol table.
 *
 * @throws NoSuchElementException if the symbol table is empty
 */
TreeNode* deleteMaxNode(TreeNode* x) {
    if (x->right == NULL) {
        return x->left;
    }
    x->right = deleteMaxNode(x->right);
    x->size = size(x->left) + size(x->right) + 1;
    return x;
}

void deleteMin() {
    if (isEmpty()) { 
        printf("Symbol table underflow");
        return;
    }
    root = deleteMaxNode(root);
}   


/**
 * Removes the specified key and its associated value from this symbol table     
 * (if the key is in this symbol table).    
 *
 * @param  key the key
 * @throws IllegalArgumentException if {@code key} is {@code null}
 */
TreeNode* deleteKey(TreeNode* x, int key) {
    if (x == NULL) {
        return NULL;
    }

    if(key < x->key) {
        x->left = deleteKey(x->left, key);
    } 
    else if(key > x->key) {
        x->right = deleteKey(x->right, key);
    }
    else {
        if (x->right = NULL) {
            return x->left;
        }
        if(x->left = NULL) {
            return x->right;
        }

        //////// YOUFSoasfbdjfsdjfdslfsdf hereererrerer
        // understand this part correctly
        TreeNode* t = x;
        x = min(t->right);
        x->right = deleteMinNode(t->right);
        x->left = t->left;
    }
    x->size = size(x->left) + size(x->right) + 1;
    return x;
} 

void delete(int key) {
    if (key == NULL) { 
        printf("calls delete() with a null key");
        return;
    }
    root = deleteKey(root, key);
}

/**
 * Returns the largest key in the symbol table less than or equal to {@code key}.
 *
 * @param  key the key
 * @return the largest key in the symbol table less than or equal to {@code key}
 * @throws NoSuchElementException if there is no such key
 * @throws IllegalArgumentException if {@code key} is {@code null}
 */
TreeNode* floorKey(TreeNode* x, int key) {
    if (x == NULL) {
        return NULL;
    }
    if(key == x->key) {
        return x;
    }
    if(key < x->key) {
        return floorKey(x->left, key);
    }
    TreeNode* t = floorKey(x->right, key); 
    if (t != NULL) {
        return t;
    }
    else {
        return x;
    }  
} 

int floor(int key) {
    if (key == NULL) {
        printf("argument to floor() is null");
        return 0;
    }                             
    if(isEmpty()) {
        printf("calls floor() with empty symbol table");
        return 0;
    }
    TreeNode* x = floorKey(root, key);
    if (x == NULL) {
        printf("argument to floor() is too small");
    }
    else {
        return x->key;
    }
} 


/**
 * Returns the smallest key in the symbol table greater than or equal to {@code key}.
 *
 * @param  key the key
 * @return the smallest key in the symbol table greater than or equal to {@code key}
 * @throws NoSuchElementException if there is no such key
 * @throws IllegalArgumentException if {@code key} is {@code null}
 */
 
TreeNode* ceilingKey(TreeNode* x, int key) {
    if (x == NULL) { 
        return NULL;
    }
    if(key == x->key) {
        return x;
    }
    if(key < x->key) {
        TreeNode* t = ceilingKey(x->left, key); 
        if (t != NULL) {
            return t;
        }
        else {
            return x;
        }
    }
    return ceilingKey(x->right, key); 
} 
 
 int ceiling(int key) {
    if (key == NULL) {
        printf("argument to ceiling() is null");
        return 0;
    } 
    if (isEmpty()) {
        printf("calls ceiling() with empty symbol table");
        return 0;
    }
    TreeNode* x = ceilingKey(root, key);
    if (x == NULL) {
        printf("argument to floor() is too large");
        return 0;
    }
    else {
        return x->key;
    }
}


/**
 * Return the key in the symbol table of a given {@code rank}.
 * This key has the property that there are {@code rank} keys in
 * the symbol table that are smaller. In other words, this key is the
 * ({@code rank}+1)st smallest key in the symbol table.
 *
 * @param  rank the order statistic
 * @return the key in the symbol table of given {@code rank}
 * @throws IllegalArgumentException unless {@code rank} is between 0 and
 *        <em>n</em>–1
 */

// Return key in BST rooted at x of given rank.
// Precondition: rank is in legal range.
int selectKey(TreeNode* x, int rank) {
    if (x == NULL) {
        return NULL;
    }
    int leftSize = size(x->left);
    if (leftSize > rank) {
        return selectKey(x->left, rank);
    }
    else if(leftSize < rank) {
        return selectKey(x->right, (rank - leftSize - 1));
    } 
    else {
        return x->key;
    }
}

int select(int rank) {
    if (rank < 0 || rank >= size()) {
        printf("argument to select() is invalid: " + rank);
        return 0;
    }
    return selectKey(root, rank);
}

    

/**
 * Return the number of keys in the symbol table strictly less than {@code key}.
 *
 * @param  key the key
 * @return the number of keys in the symbol table strictly less than {@code key}
 * @throws IllegalArgumentException if {@code key} is {@code null}
 */

// Number of keys in the subtree less than key.
int rankKey(int key, TreeNode* x) {
    if (x == NULL) {
        return 0;
    } 
    if (key < x->key) {
        return rankKey(key, x->left);
    } 
    else if (key > x->key) {
        return 1 + size(x->left) + rankKey(key, x->right);
    } 
    else {
        return size(x->left);
    } 
}
int rank(int key) {
    if (key == NULL) {
        printf("argument to rank() is null");
        return 0;
    }
    return rankKey(key, root);
} 

     

    /**
     * Returns all keys in the symbol table as an {@code Iterable}.
     * To iterate over all of the keys in the symbol table named {@code st},
     * use the foreach notation: {@code for (Key key : st.keys())}.
     *
     * @return all keys in the symbol table
     */
    int keys() {
        if (isEmpty()) {
            return new Queue<Key>();
        return keys(min(root), max(root));
    }

    /**
     * Returns all keys in the symbol table in the given range,
     * as an {@code Iterable}.
     *
     * @param  lo minimum endpoint
     * @param  hi maximum endpoint
     * @return all keys in the symbol table between {@code lo} 
     *         (inclusive) and {@code hi} (inclusive)
     * @throws IllegalArgumentException if either {@code lo} or {@code hi}
     *         is {@code null}
     */
    public Iterable<Key> keys(int lo, int hi) {
        if (lo == null) throw new IllegalArgumentException("first argument to keys() is null");
        if (hi == null) throw new IllegalArgumentException("second argument to keys() is null");

        Queue<Key> queue = new Queue<Key>();
        keys(root, queue, lo, hi);
        return queue;
    } 

    private void keys(Node x, Queue<Key> queue, Key lo, Key hi) { 
        if (x == null) return; 
        int cmplo = lo.compareTo(x.key); 
        int cmphi = hi.compareTo(x.key); 
        if (cmplo < 0) keys(x.left, queue, lo, hi); 
        if (cmplo <= 0 && cmphi >= 0) queue.enqueue(x.key); 
        if (cmphi > 0) keys(x.right, queue, lo, hi); 
    } 

    /**
     * Returns the number of keys in the symbol table in the given range.
     *
     * @param  lo minimum endpoint
     * @param  hi maximum endpoint
     * @return the number of keys in the symbol table between {@code lo} 
     *         (inclusive) and {@code hi} (inclusive)
     * @throws IllegalArgumentException if either {@code lo} or {@code hi}
     *         is {@code null}
     */
    public int size(Key lo, Key hi) {
        if (lo == null) throw new IllegalArgumentException("first argument to size() is null");
        if (hi == null) throw new IllegalArgumentException("second argument to size() is null");

        if (lo.compareTo(hi) > 0) return 0;
        if (contains(hi)) return rank(hi) - rank(lo) + 1;
        else              return rank(hi) - rank(lo);
    }

    /**
     * Returns the height of the BST (for debugging).
     *
     * @return the height of the BST (a 1-node tree has height 0)
     */
    public int height() {
        return height(root);
    }
    private int height(Node x) {
        if (x == null) return -1;
        return 1 + Math.max(height(x.left), height(x.right));
    }

    /**
     * Returns the keys in the BST in level order (for debugging).
     *
     * @return the keys in the BST in level order traversal
     */
    public Iterable<Key> levelOrder() {
        Queue<Key> keys = new Queue<Key>();
        Queue<Node> queue = new Queue<Node>();
        queue.enqueue(root);
        while (!queue.isEmpty()) {
            Node x = queue.dequeue();
            if (x == null) continue;
            keys.enqueue(x.key);
            queue.enqueue(x.left);
            queue.enqueue(x.right);
        }
        return keys;
    }


    /**
     * Unit tests the {@code BST} data type.
     *
     * @param args the command-line arguments
     */
    public static void main(String[] args) { 
        BST<String, Integer> st = new BST<String, Integer>();
        for (int i = 0; !StdIn.isEmpty(); i++) {
            String key = StdIn.readString();
            st.put(key, i);
        }

        for (String s : st.levelOrder())
            StdOut.println(s + " " + st.get(s));

        StdOut.println();

        for (String s : st.keys())
            StdOut.println(s + " " + st.get(s));
    }
}