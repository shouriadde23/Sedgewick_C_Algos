#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>                    

// exchange a[i] and a[j]  (for use while sorting)
void exch(int arr[], int i, int j) {
    int swap = arr[i];
    arr[i] = arr[j];
    arr[j] = swap;
}

void sink(int heap[],int i)
{
	int j, temp, n;
	n = heap[0];
    // loop while atleast one parent's two children is in bounds
	while(2 * i <= n)
	{
		j = 2 * i;
        // find the larger of the two children + exchange if old parent is smaller
		if(j + 1 <= n && heap[j+1] > heap[j])
			j = j + 1;
		if(heap[i] > heap[j])
			break;
		else
		{
			exch(heap, i , j);
			i = j;
		}
	}
}


void create(int heap[])
{
	int i, n;
    //n will hold the number of elements in heap
	n = heap[0]; 
	// go through all elements and create complete heap
    for(i = n/2; i >= 1; i--)
		sink(heap,i);
}

void sort(int heap[], int n) {
    int last,temp;
    //create a heap
	heap[0]=n;
	create(heap);

	//sorting until we cover every element in the heap
	while(heap[0] > 1)
	{
		//swap heap[1] and heap[last], then sink the newly swapped node
		last = heap[0];
		temp = heap[1];
		heap[1]= heap[last];
		heap[last] = temp;
		heap[0]--;
		sink(heap, 1);
	}
}

void show(int heap[], int n) {
    //print sorted data
	printf("\nArray after sorting:\n");
	for(int i = 1; i <= n; i++) {
		printf("%d ", heap[i]);
    }
    printf("\n");
}


int main()
{
	int heap[300], n, i, last, temp;

	printf("Enter no. of elements: ");
	scanf("%d",&n);

	printf("\nEnter elements: ");
	for(i = 1; i <= n; i++) {
		scanf("%d", &heap[i]);
    }
	sort(heap, n);
    show(heap, n);
	return 0;
}
