/*
 * HeapSort.h
 *
 * Header file for the Heap Sort
 *
 *  Created on: Apr 10, 2018
 *      Author: Drew
 */
#include <stdlib.h>

#ifndef HEAPSORT_H_
#define HEAPSORT_H_

void heapSort(int* arrayPtr, size_t length);
void heap(int* arrayPtr, int heapSize, int root);
void swaph(int* v1, int* v2);

#endif /* HEAPSORT_H_ */
