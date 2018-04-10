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

#endif /* HEAPSORT_H_ */
