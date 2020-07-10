 #include <stdio.h>

#include <string.h>
#include <stdbool.h>
#include "WeightedQuickUnionUF.h"

	/**
     * Initializes an empty union-find data structure with
     * {@code n} elements {@code 0} through {@code n-1}. 
     * Initially, each elements is in its own set.
     *
     * @param  n the number of elements
     * @throws IllegalArgumentException if {@code n < 0}
     */
    void QuickUnionUF(int n) {
        parent[n];
        size[n];
        count = n;
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
			length++;
        }
    }

    /**
     * Returns the number of sets.
     *
     * @return the number of sets (between {@code 1} and {@code n})
     */
    int countNum() {
        return count;
    }
  
    /**
     * Returns the canonical element of the set containing element {@code p}.
     *
     * @param  p an element
     * @return the canonical element of the set containing {@code p}
     * @throws IllegalArgumentException unless {@code 0 <= p < n}
     */
    int find(int p) {
        // validate(p);
        while (p != parent[p]) 
            p = parent[p];
        return p;
    }

    // validate that p is a valid index
#if 0
	void validate(int p) {
		// size_t n = sizeof(parent) / sizeof(int);
        // int size = *(&parent + 1) - parent;
        if (p < 0 || p >= length) {
            printf("index %d is not between 0 and %d", p, (length-1));
			return;
        }
    }
#endif

    /**
     * Returns true if the two elements are in the same set.
     * 
     * @param  p one element
     * @param  q the other element
     * @return {@code true} if {@code p} and {@code q} are in the same set;
     *         {@code false} otherwise
     * @throws IllegalArgumentException unless
     *         both {@code 0 <= p < n} and {@code 0 <= q < n}
     * @deprecated Replace with two calls to {@link #find(int)}.
     */
    bool connected(int p, int q) {
        return find(p) == find(q);
    }

    /**
     * Merges the set containing element {@code p} with the 
     * the set containing element {@code q}.
     *
     * @param  p one element
     * @param  q the other element
     * @throws IllegalArgumentException unless
     *         both {@code 0 <= p < n} and {@code 0 <= q < n}
     */
    void unionF(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ) return;

        // make smaller root point to larger one
        if (size[rootP] < size[rootQ]) {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
        else {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        }
        count--;
    }