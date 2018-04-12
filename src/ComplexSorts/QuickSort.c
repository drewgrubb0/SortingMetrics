/*
 * QuickSort.c
 *
 * The file that holds all functions associated with the Quick Sort
 *
 *  Created on: Apr 10, 2018
 *      Author: Drew
 */
#include "QuickSort.h"

/*
 * A divide and conquer sorting algorithm that modifies the array based off
 * "pivot" elements, recursively accomplishing this until the array is sorted.
 *
 * Best Case: (nLogn)
 * Worst Case: O(n^2)
 * Average Case: O(nLogn)
 */
void quickSort(int* arrayPtr, size_t length)
{
	trueQuickSort(arrayPtr, 0, length - 1);
}

/*
 * Function in charge of handling the recursive parts of the algorithm, telling
 * it when to stop and what values to partition.
 */
void trueQuickSort(int* arrayPtr, int left, int right)
{
	if(left < right)
	{
		int partIndex = partition(arrayPtr, left, right);

		trueQuickSort(arrayPtr, left, partIndex - 1);
		trueQuickSort(arrayPtr, partIndex + 1, right);
	}
}

/*
 * Function that chooses a pivot and moves elements to their corresponding place in
 * relation to the pivot.
 * Because the list is randomized, the pivot is the last element of the partition.
 */
int partition(int* arrayPtr, int leftIndex, int rightIndex)
{
	int pivot = arrayPtr[rightIndex];
	int low = leftIndex - 1;

	for(int x = leftIndex ; x <= rightIndex - 1 ; x++)
	{
		if(arrayPtr[x] <= pivot)
		{
			low++;
			swapc(&arrayPtr[low], &arrayPtr[x]);
		}
	}

	swapc(&arrayPtr[low + 1], &arrayPtr[rightIndex]);
	return (low + 1);
}

/*
 * Function that swaps 2 int values in memory.
 * Useful in many sorting algorithms.
 */
void swapc(int* v1, int* v2)
{
	int temp = *v1;
	*v1 = *v2;
	*v2 = temp;
}
