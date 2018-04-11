/*
 * CountingSort.c
 *
 * The file that holds all functions associated with the Counting Sort
 *
 *  Created on: Apr 10, 2018
 *      Author: Drew
 */
#include "CountingSort.h"
#include <stdio.h>

/*
 * A sort that counts the number of numbers that have a distinct value,
 * arithmetically calculating the position of each number in the final array.
 *
 * Not as efficient when the size of the array is less than the range input given.
 *
 * Best Case: O(n)
 * Worst Case: O(n)
 * Average Case: O(n)
 */
void countingSort(int* arrayPtr, size_t length)
{
	//RAND_MAX
	int max = 32768;
	static int counts[32768];

	for(int x = 0 ; x < length ; x++)
		counts[arrayPtr[x]]++;

	int currentIndex = 0;

	for(int x = 0 ; x < max ; x++)
	{
		int numberOfIndex = counts[x];
		for(int y = 0 ; y < numberOfIndex ; y++)
		{
			arrayPtr[currentIndex] = x;
			currentIndex++;
		}
	}
}
