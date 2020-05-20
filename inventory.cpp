/*
 * inventory.cpp
 *
 *  Created on: May 18, 2020
 *      Author: elizabeth-na
 */
#include "inventory.h"
#include <string.h>
#include <iostream>
#include <string>
#include "item.h"
using namespace std;

inventory::inventory() {
	numItem = 0;
	results = 0;
}

void inventory::insert(item a) {
	strcpy(db[numItem].name, a.name);
		db[numItem].quantity = a.quantity;
		db[numItem].shelfLife = a.shelfLife;
		cout << "ITEM INSERTED SUCCESFULLY" << endl;
		numItem++;
}

void inventory::insertItem(char itemName[], int itemQuantity, int itemShelflife) {
	strcpy(db[numItem].name, itemName);
	db[numItem].quantity = itemQuantity;
	db[numItem].shelfLife = itemShelflife;
	cout << "ITEM INSERTED SUCCESFULLY" << endl;
	numItem++;

}

void inventory::deleteItem(char itemName[]) {
	for(int i = 0; i < numItem; i++) {
		if(strcmp(itemName, db[i].name) == 0) {
			db[i].quantity--;
			cout << "ITEM DELETED SUCCESFULLY" << endl;
			return;
		}
	}
	cout << "ITEM NOT FOUND" << endl;
}

item *inventory::searchi(char itemName[]) {
	for(int i = 0; i < numItem; i++) {
		if(strcmp(itemName, db[i].name)==0) {
			return &db[i];
		}
	}
	return NULL;
}

void inventory::updateItem(char itemName[], int itemQuantity, int itemShelflife) {
	item *i = searchi(itemName);
	if(i == NULL) {
		cout << "ITEM NOT FOUND" << endl;
		return;
	}
	i->quantity = itemQuantity;
	i->shelfLife = itemShelflife;
}

void inventory::printItems() {
	if(numItem == 0) {
		cout << "There is nothing in your Pantry." << endl;
	} else {
		for(int i = 0; i < numItem; i++) {
		cout << i+1 << ". " << "Name: " << db[i].name << "\t\tQuantity: " << db[i].quantity << "\tShelf life: " << db[i].shelfLife << " days"<< endl;
		}
	}
}




//added for QUICKSORT
void inventory::swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int inventory::partition (int arr[], int low, int high) {
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void inventory::quickSort(int arr[], int low, int high) {
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* Function to print an array */
void inventory::printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
//





//added for binary search
void inventory::sortArray(string name[], int size) {
    int startScan, minIndex;
    string minValue;

    for (startScan = 0; startScan < (size - 1); startScan++)
    {
        minIndex = startScan;
        minValue = name[startScan];
        for(int index = startScan + 1; index < size; index++)
        {
            if (name[index] < minValue)
            {
                minValue = name[index];
                minIndex = index;
            }
        }
        name[minIndex] = name[startScan];
        name[startScan] = minValue;
    }
   /* for(int i=0; i < size; i++){
    	cout << name[i] << endl;
    }*/ //outputs the sorted array
}

int inventory::binarySearch(string name[], int size, string value) {
    int first = 0,
        last = size - 1,
        middle,
        position = -1;
    bool found = false;        //Flag

    while (!found && first <= last)
    {
        middle = (first + last) / 2;
        if (name[middle] == value)      //If value is found at mid
        {
            found = true;
            position = middle;
        }
        else if (name[middle] > value)  //If value is in lower half
            last = middle - 1;
        else
            first = middle + 1;           //If value is in upper half
    }
    return position;
}
//
