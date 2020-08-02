#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int keys[100];
int vals[100];
int n = 0;
 

// resize the underlying arrays
void resize(int capacity) {
    int tempk[capacity];
    int tempv[capacity];
    for (int i = 0; i < n; i++) {
        tempk[i] = keys[i];
        tempv[i] = vals[i];
    }
    vals[capacity] = tempv[capacity];
    keys[capacity] = tempk[capacity];
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
bool isEmpty() {
    return size() == 0;
}



/**
 * Returns the number of keys in this symbol table strictly less than {@code key}.
 *
 * @param  key the key
 * @return the number of keys in the symbol table strictly less than {@code key}
 * @throws IllegalArgumentException if {@code key} is {@code null}
 */
int rank(int key) {
    if (key == '\0') {
        printf("argument to rank() is null");
        return 0;
    }  
    
    int lo = 0, hi = n-1; 
    while (lo <= hi) { 
        int mid = lo + (hi - lo) / 2; 
        if(key < keys[mid]) {
            hi = mid - 1;
        } 
        else if (key > keys[mid]) {
            lo = mid + 1;
        } 
        else {
            return mid;
        } 
    } 
    return lo;
} 


/**
 * Returns the value associated with the given key in this symbol table.
 *
 * @param  key the key
 * @return the value associated with the given key if the key is in the symbol table
 *         and {@code null} if the key is not in the symbol table
 * @throws IllegalArgumentException if {@code key} is {@code null}
 */
int get(int key) {
    if (key == '\0') {
        printf("argument to get() is null"); 
        return 0;
    }
    if (isEmpty()) {
        return 0;
    }
    int i = rank(key); 
    if (i < n && keys[i] == key) {
        return vals[i];
    }
    return 0;
} 


/**
 * Does this symbol table contain the given key?
 *
 * @param  key the key
 * @return {@code true} if this symbol table contains {@code key} and
 *         {@code false} otherwise
 * @throws IllegalArgumentException if {@code key} is {@code null}
 */
bool contains(int key) {
    if (key == '\0') {
        printf("argument to contains() is null");
        return false;
    }
    return get(key) != '\0';
}

/**
 * Removes the specified key and associated value from this symbol table
 * (if the key is in the symbol table).
 *
 * @param  key the key
 * @throws IllegalArgumentException if {@code key} is {@code null}
 */
void delete(int key, int length) {
    if (key == '\0') {
        printf("argument to delete() is null");
        return;
    }  
    if (isEmpty()) {
        return;
    }

    // compute rank
    int i = rank(key);

    // key not in table
    if (i == n || keys[i] != key) {
        return;
    }

    for (int j = i; j < n-1; j++)  {
        keys[j] = keys[j+1];
        vals[j] = vals[j+1];
    }

    n--;
    keys[n] = '\0';  // to avoid loitering
    vals[n] = '\0';

    // resize if 1/4 full
    if (n > 0 && n == length/4) {
        resize(length/2);
    }
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
void put(int key, int val, int length)  {
    if (key == '\0') {
        printf("first argument to put() is null"); 
    }

    if (val < 0) {
        delete(key, length);
        return;
    }

    int i = rank(key);

    // key is already in table
    if (i < n && keys[i] == key) {
        vals[i] = val;
        return;
    }

    // insert new key-value pair
    if (n == length) {
        resize(2*length);
    }

    for (int j = n; j > i; j--)  {
        keys[j] = keys[j-1];
        vals[j] = vals[j-1];
    }
    keys[i] = key;
    vals[i] = val;
    n++;
} 



/**
 * Returns the smallest key in this symbol table.
 *
 * @return the smallest key in this symbol table
 * @throws NoSuchElementException if this symbol table is empty
 */
int min() {
    if (isEmpty()) {
        printf("called min() with empty symbol table");
    }
    return keys[0]; 
}


/**
 * Returns the largest key in this symbol table.
 *
 * @return the largest key in this symbol table
 * @throws NoSuchElementException if this symbol table is empty
 */
int max() {
    if (isEmpty()) {
        printf("called max() with empty symbol table");
        return 0;
    } 
    return keys[n-1];
}


/**
 * Removes the smallest key and associated value from this symbol table.
 *
 * @throws NoSuchElementException if the symbol table is empty
 */
void deleteMin(int length) {
    if (isEmpty()) {
        printf("Symbol table underflow error");
        return;
    }
    delete(min(), length);
}


/**
 * Removes the largest key and associated value from this symbol table.
 *
 * @throws NoSuchElementException if the symbol table is empty
 */
void deleteMax(int length) {
    if (isEmpty()) {
        printf("Symbol table underflow error");
        return;
    }
    delete(max(), length);
}


/***************************************************************************
*  Ordered symbol table methods.
***************************************************************************/

    
/**
 * Return the kth smallest key in this symbol table.
 *
 * @param  k the order statistic
 * @return the {@code k}th smallest key in this symbol table
 * @throws IllegalArgumentException unless {@code k} is between 0 and
 *        <em>n</em>–1
 */
int select(int k) {
    if (k < 0 || k >= size()) {
        printf("called select() with invalid argument: %d", k);
        return 0;
    }
    return keys[k];
}

    
/**
 * Returns the largest key in this symbol table less than or equal to {@code key}.
 *
 * @param  key the key
 * @return the largest key in this symbol table less than or equal to {@code key}
 * @throws NoSuchElementException if there is no such key
 * @throws IllegalArgumentException if {@code key} is {@code null}
 */
int floorKey(int key) {
    if (key == '\0') {
        printf("argument to floor() is null");
        return 0;
    }
    int i = rank(key);
    if (i < n && key == keys[i]) {
        return keys[i];
    }
    if (i == 0) {
        return 0;
    }
    else {
        return keys[i-1];
    }
}

    
/**
 * Returns the smallest key in this symbol table greater than or equal to {@code key}.
 *
 * @param  key the key
 * @return the smallest key in this symbol table greater than or equal to {@code key}
 * @throws NoSuchElementException if there is no such key
 * @throws IllegalArgumentException if {@code key} is {@code null}
 */
int ceilingKey(int key) {
    if (key == '\0') {
        printf("argument to ceiling() is null"); 
        return 0;
    }
    int i = rank(key);
    if (i == n) {
        return 0;
    }
    else {
        return keys[i];
    }
}

/**
 * Returns the number of keys in this symbol table in the specified range.
 *
 * @param lo minimum endpoint
 * @param hi maximum endpoint
 * @return the number of keys in this symbol table between {@code lo} 
 *         (inclusive) and {@code hi} (inclusive)
 * @throws IllegalArgumentException if either {@code lo} or {@code hi}
 *         is {@code null}
 */
int sizeKeys(int lo, int hi) {
    if (lo == '\0') {
        printf("first argument to size() is null"); 
        return 0;
    }
    if (hi == '\0') {
        printf("second argument to size() is null"); 
        return 0;
    }
    
    if (lo > hi) {
        return 0;
    }
    if (contains(hi)) {
        return rank(hi) - rank(lo) + 1;
    }
    else {
        return rank(hi) - rank(lo);
    }
}


/**
 * Unit tests the {@code SequentialSearchST} data type.
 *
 * @param args the command-line arguments
 */
int main() {
    int p, count, range;
    int arr[100];
    // int size, i, j, count;
    printf("Please enter a valid range of integers you want to include!");
    printf("\n");
    scanf("%d", &count);
    printf("Now enter these integers each seperated by a space!");
    printf("\n");
    for (int i = 0; i < count; i++) {
        p = i;
        scanf("%d", &arr[i]);
        put(arr[i], p, i);
    }

    for (int i = 0; i < count; i++) {
        printf("%d %d\n", arr[i], get(arr[i]));
    }
    return 0;   
}