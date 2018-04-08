/*
 * SimpleSorts.h
 *
 * Header file for sorting algorithms that require
 * very little external help / calculations.
 *
 *  Created on: Apr 7, 2018
 *      Author: Drew
 */
#include <stdlib.h>

#ifndef SORTS_H_
#define SORTS_H_

void swap(int* v1, int* v2);

void bubbleSort(int* arrayPtr, size_t length);
void selectionSort(int* arrayPtr, size_t length);

#endif /* SORTS_H_ */
