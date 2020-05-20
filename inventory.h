/*
 * inventory.h
 *
 *  Created on: May 18, 2020
 *      Author: elizabeth-na
 */

#ifndef INVENTORY_H_
#define INVENTORY_H_

#include <string>
#include "item.h"
using namespace std;

class inventory {
public:
	int numItem;
	item db[100];
	inventory();
	void insert(item a);
	void insertItem(char itemName[], int itemQuantity, int itemShelflife);
	void deleteItem(char itemName[]);
	void updateItem(char itemName[], int itemQuantity, int itemShelflife);
	item * searchi(char itemName[]);
	void printItems();
	//sort()


	//added for quicksort
	int a, b, low, high, size;
	int arr[29];
	void swap(int* a, int* b);
	int partition (int arr[], int low, int high);
	void quickSort(int arr[], int low, int high);
	void printArray(int arr[], int size);



	//added for binarySearch
	string empName;
	int results;
	void sortArray(string [], int);
	int binarySearch(string [], int, string);
	//
};




#endif /* INVENTORY_H_ */
