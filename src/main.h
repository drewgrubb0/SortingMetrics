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

void populateArray(int* arrayPtr, size_t length);
void printArray(int* arrayPtr, size_t length);
double getTimeSpentOnSort(int* arrayPtr, size_t length, void(*funcPtr)(int*, size_t));

#endif /* MAIN_H_ */
