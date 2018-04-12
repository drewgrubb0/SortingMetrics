/*
 * HeapSort.c
 *
 * The file that holds all functions associated with the Heap Sort
 *
 *  Created on: Apr 10, 2018
 *      Author: Drew
 */
#include "HeapSort.h"

/*
 * An in-place sorting algorithm that takes advantage of the heap data structure to determine
 * the configuration of the array from the highest number to the lowest number.
 *
 * Best Case: O(nLogn)
 * Worst Case: O(nLogn)
 * Average Case: O(nLogn)
 */
void heapSort(int* arrayPtr, size_t length)
{
	for(int x = (length / 2) - 1 ; x >= 0 ; x--)
		heap(arrayPtr, length, x);

	for(int x = length - 1 ; x>=0 ; x--)
	{
		swaph(&arrayPtr[0], &arrayPtr[x]);
		heap(arrayPtr, x, 0);
	}
}

/*
 * Builds an array representation of a max heap
 */
void heap(int* arrayPtr, int heapSize, int root)
{
	int largestNum = root;
	int left = 2*root + 1;
	int right = 2*root + 2;

	if(left < heapSize && arrayPtr[left] > arrayPtr[largestNum])
		largestNum = left;

	if(right < heapSize && arrayPtr[right] > arrayPtr[largestNum])
		largestNum = right;

	if(largestNum != root)
	{
		swaph(&arrayPtr[root], &arrayPtr[largestNum]);
		heap(arrayPtr, heapSize, largestNum);
	}
}

/*
 * Function that swaps 2 int values in memory.
 * Useful in many sorting algorithms.
 */
void swaph(int* v1, int* v2)
{
	int temp = *v1;
	*v1 = *v2;
	*v2 = temp;
}
