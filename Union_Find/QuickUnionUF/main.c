#include <stdio.h>

#include <string.h>
#include <stdbool.h>

#include "QuickUnionUF.h"
#include "QuickUnionUF.c"

    /**
     * Reads an integer {@code n} and a sequence of pairs of integers
     * (between {@code 0} and {@code n-1}) from standard input, where each integer
     * in the pair represents some element;
     * if the elements are in different sets, merge the two sets
     * and print the pair to standard output.
     * 
     * @param args the command-line arguments
     */
    int main() {
        int p, n, q;
		scanf("%d", &n);
		printf("%d", n);
        QuickUnionUF(n);
        while ( count != 0) {
            scanf("%d", &p);
            scanf("%d", &q);
			if( p >= n || q >= n) {
				printf("Wrong indices provided!\n");
				return 0;
			}
            if (find(p) == find(q)) continue;
            unionF(p, q);
            printf("%d %d\n", p, q);
        }
        printf("%d", countNum(), " components");
    }
