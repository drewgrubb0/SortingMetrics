/*
 * QuickSort.h
 *
 * Header file for Quick Sort
 *
 *  Created on: Apr 10, 2018
 *      Author: Drew
 */
#include <stdlib.h>

#ifndef QUICKSORT_H_
#define QUICKSORT_H_

void quickSort(int* arrayPtr, size_t length);
void partition(int* arrayPtr, int lowIndex, int highIndex);

#endif /* QUICKSORT_H_ */
