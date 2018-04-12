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
void trueQuickSort(int* arrayPtr, int left, int right);
int partition(int* arrayPtr, int leftIndex, int rightIndex);
void swapc(int* v1, int* v2);

#endif /* QUICKSORT_H_ */
