/*
 * main.c
 *
 * A simple educational program to measure the speeds of different
 * sorting algorithms when given an array of random values.
 *
 *  Created on: Apr 6, 2018
 *      Author: Drew Grubb
 */
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "main.h"
#include "SimpleSorts.h"
#include "ComplexSorts/CountingSort.h"
#include "ComplexSorts/RadixSort.h"
#include "ComplexSorts/MergeSort.h"
#include "ComplexSorts/QuickSort.h"
#include "ComplexSorts/HeapSort.h"

#define ARRAY_SIZE (sizeof(numArray) / sizeof(numArray[0]))

/*Global variable because only one size is used*/
static int arrayLength;

/*
 * Driver for the program
 */
int main()
{
	setbuf(stdout, NULL);
	printf("Please input the size of the Array to measure: ");
	scanf("%d", &arrayLength);

	printf("Running performance metric with array length %d...\n\n", arrayLength);

	int numArray[arrayLength];
	int arrayCopy[arrayLength];
	double timeSpentOnBubble;
	double timeSpent;

	populateArray(numArray);
	copyArray(arrayCopy, numArray);

	timeSpentOnBubble = getTimeSpentOnSort(numArray, &bubbleSort);
	printf("%-20s %.3f | ", "Bubble Sort: ", timeSpentOnBubble);
	printf("1x\n");
	copyArray(numArray, arrayCopy);

	timeSpent = getTimeSpentOnSort(numArray, &cocktailSort);
	printf("%-20s %.3f | ", "Cocktail Sort: ", timeSpent);
	printf("%f Speedup on Bubble Sort\n", (timeSpentOnBubble / timeSpent));
	copyArray(numArray, arrayCopy);

	timeSpent = getTimeSpentOnSort(numArray, &selectionSort);
	printf("%-20s %.3f | ", "Selection Sort: ", timeSpent);
	printf("%f Speedup on Bubble Sort\n", (timeSpentOnBubble / timeSpent));
	copyArray(numArray, arrayCopy);

	timeSpent = getTimeSpentOnSort(numArray, &insertionSort);
	printf("%-20s %.3f | ", "Insertion Sort: ", timeSpent);
	printf("%f Speedup on Bubble Sort\n", (timeSpentOnBubble / timeSpent));
	copyArray(numArray, arrayCopy);

	timeSpent = getTimeSpentOnSort(numArray, &shellSort);
	printf("%-20s %.3f | ", "Shell Sort: ", timeSpent);
	printf("%f Speedup on Bubble Sort\n", (timeSpentOnBubble / timeSpent));
	copyArray(numArray, arrayCopy);

	timeSpent = getTimeSpentOnSort(numArray, &mergeSort);
	printf("%-20s %.3f | ", "Merge Sort: ", timeSpent);
	printf("%f Speedup on Bubble Sort\n", (timeSpentOnBubble / timeSpent));
	isSorted(numArray);
	copyArray(numArray, arrayCopy);

	timeSpent = getTimeSpentOnSort(numArray, &radixSort);
	printf("%-20s %.3f | ", "Radix Sort: ", timeSpent);
	printf("%f Speedup on Bubble Sort\n", (timeSpentOnBubble / timeSpent));
	copyArray(numArray, arrayCopy);

	timeSpent = getTimeSpentOnSort(numArray, &countingSort);
	printf("%-20s %.3f | ", "Counting Sort: ", timeSpent);
	printf("%f Speedup on Bubble Sort\n", (timeSpentOnBubble / timeSpent));
	copyArray(numArray, arrayCopy);
}

/*
 * Fills the given array (via pointer) with random integer values
 * using srand() and time().
 */
void populateArray(int* arrayPtr)
{
	srand(time(NULL));

	for(size_t x = 0 ; x < arrayLength ; x++)
		arrayPtr[x] = rand();
}

/*
 * Performs the sort function given and returns the amount
 * of time spent on that sort in (double) seconds to the thousandths place.
 */
double getTimeSpentOnSort(int* arrayPtr, void (*funcPtr)(int*, size_t))
{
	clock_t start, end;

	start = clock();
	funcPtr(arrayPtr, arrayLength);
	end = clock();
	return ((double) (end - start)) / CLOCKS_PER_SEC;
}

/*
 * Uses memcpy to copy 2 arrays.
 * Created to improve the readability flow of the program.
 */
void copyArray(int* dest, int* src)
{
	memcpy(dest, src, arrayLength * sizeof(int));
}

//TESTING FUNCTIONS

/*
 * Prints the given array (via pointer) using printf
 * from index 0 to size-1.
 * Used for testing.
 */
void printArray(int* arrayPtr)
{
	for(size_t x = 0 ; x < arrayLength ; x++)
		printf("[%d] ", arrayPtr[x]);
	printf("\n");
}

/*
 * prints whether or not the given array is incrementally sorted.
 * Used for testing.
 */
void isSorted(int* arrayPtr)
{
	for(int x = 0 ; x < arrayLength - 1 ; x++)
		if(arrayPtr[x] > arrayPtr[x+1])
		{
			printf("This array is not sorted - [%d] = Val %d\n", x, arrayPtr[x]);
			return;
		}
	printf("This array is sorted :)\n");
}
