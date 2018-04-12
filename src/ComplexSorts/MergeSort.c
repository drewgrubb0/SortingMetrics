/*
 * MergeSort.c
 *
 * The file that holds all functions associated with the Merge Sort
 *
 *  Created on: Apr 10, 2018
 *      Author: Drew
 */
#include "MergeSort.h"
#include <stdio.h>

static int* tempArray;

/*
 * A sorting algorithm that recursively sorts an array by using a
 * "divide and conquer" strategy. Splits the array until it gets to
 * 1 or 2 values to sort, then merges them all.
 *
 * Downside is the space of O(n)
 *
 * Best Case: O(nlogn)
 * Worse Case: O(nlogn)
 * Average Case: O(nlogn)
 */
void mergeSort(int* arrayPtr, size_t length)
{
	tempArray = calloc(length, sizeof(int));
	sort(arrayPtr, 0, length - 1);
	free(tempArray);
}

/*
 * Handles the recursive part of the sort, breaking up the
 * arraysets to be handled until they are at 1 or 2.
 */
void sort(int* arrayPtr, int left, int right)
{
	if(left < right)
	{
		int middle = (right + left) / 2;

		sort(arrayPtr, left, middle);
		sort(arrayPtr, middle + 1, right);

		merge(arrayPtr, left, middle, right);
	}
}

/*
 * Sorts pieces of the array before "merging" them back together
 * as the recursion is unwinded.
 */
void merge(int* arrayPtr, int left, int middle, int right)
{
	int leftIndex = left;
	int rightIndex = middle + 1;
	int tempIndex = 0;

	while(leftIndex <= middle && rightIndex <= right)
	{
		if(arrayPtr[leftIndex] <= arrayPtr[rightIndex])
		{
			tempArray[tempIndex] = arrayPtr[leftIndex];
			tempIndex++;
			leftIndex++;
		}
		else
		{
			tempArray[tempIndex] = arrayPtr[rightIndex];
			tempIndex++;
			rightIndex++;
		}
	}

	while(leftIndex <= middle)
	{
		tempArray[tempIndex] = arrayPtr[leftIndex];
		tempIndex++;
		leftIndex++;
	}

	while(rightIndex <= right)
	{
		tempArray[tempIndex] = arrayPtr[rightIndex];
		tempIndex++;
		rightIndex++;
	}

	for(int x = 0, y = left ; y <= right ; x++, y++)
		arrayPtr[y] = tempArray[x];
}
