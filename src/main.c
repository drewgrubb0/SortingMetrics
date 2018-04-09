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

#define ARRAY_LENGTH 100000
#define ARRAY_SIZE (sizeof(numArray) / sizeof(numArray[0]))

/*
 * Driver for the program
 */
int main()
{
	int numArray[ARRAY_LENGTH];
	int arrayCopy[ARRAY_LENGTH];
	double timeSpent;

	populateArray(numArray, ARRAY_SIZE);
	memcpy(arrayCopy, numArray, sizeof(arrayCopy));

	timeSpent = getTimeSpentOnSort(numArray, ARRAY_SIZE, &bubbleSort);
	printf("BubbleSort: %.3f \n", timeSpent);
	memcpy(numArray, arrayCopy, sizeof(numArray));

	timeSpent = getTimeSpentOnSort(numArray, ARRAY_SIZE, &selectionSort);
	printf("Selection Sort: %.3f \n", timeSpent);
	memcpy(numArray,  arrayCopy, sizeof(numArray));

	timeSpent = getTimeSpentOnSort(numArray, ARRAY_SIZE, &insertionSort);
	printf("Insertion Sort: %.3f \n", timeSpent);
	memcpy(numArray,  arrayCopy, sizeof(numArray));
}

/*
 * Fills the given array (via pointer) with random integer values
 * using srand() and time()
 */
void populateArray(int* arrayPtr, size_t length)
{
	srand(time(NULL));

	for(size_t x = 0 ; x < length ; x++)
		arrayPtr[x] = rand();
}

/*
 * Performs the sort function given and returns the amount
 * of time spent on that sort in (double) seconds to the millionths place.
 */
double getTimeSpentOnSort(int* arrayPtr, size_t length, void (*funcPtr)(int*, size_t))
{
	clock_t start, end;

	start = clock();
	funcPtr(arrayPtr, length);
	end = clock();
	return ((double) (end - start)) / CLOCKS_PER_SEC;
}

/*
 * Prints the given array (via pointer) using printf
 * from index 0 to size-1
 */
void printArray(int* arrayPtr, size_t length)
{
	for(size_t x = 0 ; x < length ; x++)
		printf("[%d] ", arrayPtr[x]);
	printf("\n");
}

