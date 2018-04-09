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
 * A sorting algorithm that sorts the array as elements are found/added.
 * Places the found element in its designated position relative to the sorted elements before it
 *
 * Best case : O(n^2)
 * Worst case : O(n^2)
 * Average case : O(n^2)
 */
void insertionSort(int* arrayPtr, size_t length)
{
	int currentValue, y;
	for(int x = 1 ; x < length ; x++)
	{
		currentValue = arrayPtr[x];

		for(y = x-1 ; y >= 0 && arrayPtr[y] > currentValue ; y--)
		{
			arrayPtr[y+1] = arrayPtr[y];
		}

		arrayPtr[y+1] = currentValue;
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

/*
 * A sorting algorithm that splits the array and creates subsets based off the split,
 * sorting the subset arrays using a modified insertion sort.
 * Reduces the gap size with each iteration until the gap == 0 IE the array is sorted.
 *
 * Best case : O(n^2)
 * Worst case : O(n^2)
 * Average case : O(n^2)
 */
void shellSort(int* arrayPtr, size_t length)
{
	for(int split = length / 2 ; split > 0 ; split/=2)
	{
		for(int x = split; x < length ; x++)
		{
			int temp = arrayPtr[x];
			int y;
			
			for(y = x ; y >= split && arrayPtr[y - split] > temp ; y-=split)
			    arrayPtr[y] = arrayPtr[y - split];
			arrayPtr[y] = temp;
		}

	}
}

/*
 * A sorting algorithm that traverses through the array and swaps out of place values, similar to the bubble sort.
 * However, the sort then traverses through the array backwards, performing the same swaps of out of order values.This is
 * faster than bubble sort because the method places numbers that are far away from their correct position faster.
 * 
 * Best case : O(n)
 * Worst case : O(n^2)
 * Average case : O(n^2)
 */
void cocktailSort(int* arrayPtr, size_t length)
{
	bool hasSwapped = false;
	int ending = 1;
	
	while(hasSwapped)
	{	
		hasSwapped = false;
		
		for(int x = 0 ; x < length - ending ; x++)
			if(arrayPtr[x] > arrayPtr[x+1])
			{
				swap(&arrayPtr[x], &arrayPtr[x+1]);
				hasSwapped = true;
			}
		
		if(!hasSwapped)
			return;
		hasSwapped = false;
		ending++;
		
		for(int x = length - ending ; x > 0 ; x--)
			if(arrayPtr[x] > arrayPtr[x+1])
			{
				swap(&arrayPtr[x], &arrayPtr[x+1]);
				hasSwapped = true;
			}
	}
}
