/*
 * RadixSort.c
 *
 * The file that holds all functions associated with the Radix Sort
 *
 *  Created on: Apr 10, 2018
 *      Author: Drew
 */
#include "RadixSort.h"

/*
 * Sorting algorithm that sorts indices based off thier significant values, or the value
 * of the tens, hundreds, thousands, etc.
 *
 * Best Case: (n)
 * Worst Case: O(n)
 * Average Case: O(n)
 */
void radixSort(int* arrayPtr, size_t length)
{
	int max = getMaxNumber(arrayPtr, length);

	for(int exp = 1 ; max/exp > 0 ; exp*=10)
	{
		int count[10] = {0};

	    for (int i = 0; i < length; i++)
	        count[ (arrayPtr[i]/exp)%10 ]++;

	    for (int i = 1; i < 10; i++)
	        count[i] += count[i - 1];

	    for (int i = length - 1; i >= 0; i--)
	    {
	        arrayPtr[count[ (arrayPtr[i]/exp)%10 ] - 1] = arrayPtr[i];
	        count[ (arrayPtr[i]/exp)%10 ]--;
	    }
	}
}

int getMaxNumber(int* arrayPtr, size_t length)
{
	int max = arrayPtr[0];
	for(int x = 0 ; x < length ; x++)
		if(arrayPtr[x] > max)
			max = arrayPtr[x];
	return max;
}
