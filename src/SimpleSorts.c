/*
 * sorts.c
 *
 * A file that contains different "Simple" sorting algorithms
 * and algorithm tools like swap() to be used
 * for the Sorting Metrics project.
 *
 * "Simple" is defined by anything that requires very little calculating
 * IE can be done in a single function without taking up a large amount of space.
 * That is of course a subjective definition but I'm sure you understand :)
 *
 *  Created on: Apr 7, 2018
 *      Author: Drew
 */
#include <stdbool.h>

#include "SimpleSorts.h"

/*
 * Function that swaps 2 int values in memory.
 * Useful in many sorting algorithms.
 */
void swap(int* v1, int* v2)
{
	int temp = *v1;
	*v1 = *v2;
	*v2 = temp;
}

/*
 * A simple sort that goes through the array, switching adjacent elements if they are in the wrong
 * order. Continues to iterate through the array until the array is sorted.
 *
 * Best case : O(n)
 * Worst case : O(n^2)
 * Average case : O(n^2)
 */
void bubbleSort(int* arrayPtr, size_t length)
{
	bool hasSwapped = false;

	for(int x = 0 ; x < length - 1 ; x++)
	{
		hasSwapped = false;
		for(int y = 0 ; y < length - x - 1; y++)
		{
			if(arrayPtr[y] > arrayPtr[y+1])
			{
				swap(&arrayPtr[y], &arrayPtr[y+1]);
				hasSwapped = true;
			}
		}

		if(!hasSwapped)
			break;
	}
}

/*
 * A sorting algorithm that puts the minimum element within the unsorted portion of the array
 * at the beginning of that unsorted portion until the array is sorted.
 *
 * Best case : O(n^2)
 * Worst case : O(n^2)
 * Average case : O(n^2)
 */
void selectionSort(int* arrayPtr, size_t length)
{
	int min;

	for(int x = 0 ; x < length - 1 ; x++)
	{
		min = x;
		for(int y = x+1 ; y < length ; y++)
		{
			if(arrayPtr[y] < arrayPtr[min])
				min = y;
		}
		swap(&arrayPtr[x], &arrayPtr[min]);
	}
}
