/*
 * main.h
 *
 * Header file for main.c
 *
 *  Created on: Apr 7, 2018
 *      Author: Drew
 */
#include <stdlib.h>

#ifndef MAIN_H_
#define MAIN_H_

void populateArray();
void printArray(int* arrayPtr);
double getTimeSpentOnSort(int* arrayPtr, void(*funcPtr)(int*, size_t));
void copyArray(int* dest, int* src);
void isSorted(int* arrayPtr);

#endif /* MAIN_H_ */
