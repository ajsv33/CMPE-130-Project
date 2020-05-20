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

	void heapify (int n, int i);
   	void heapsort();
};



#endif /* INVENTORY_H_ */
