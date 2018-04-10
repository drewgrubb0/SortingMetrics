/*
 * MergeSort.h
 *
 * Header file for the Merge Sort
 *
 *  Created on: Apr 10, 2018
 *      Author: Drew
 */
#include <stdlib.h>

#ifndef MERGESORT_H_
#define MERGESORT_H_

void mergeSort(int* arrayPtr, size_t length);
void merge(int* arrayPtr, int left, int middle, int right);

#endif /* MERGESORT_H_ */
