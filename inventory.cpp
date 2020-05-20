#include "inventory.h"
#include <string.h>
#include <iostream>
#include <string>
#include "item.h"
using namespace std;

inventory::inventory() {
	numItem = 0;
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

void inventory::heapify (int n, int i){
    int largest = i; // start index as largest
    int l = 2*i + 1; // left child
    int r = 2*i + 2; // right child
    
    if (l < n && db[l].shelfLife > db[largest].shelfLife)// If left child is greater than root
        largest = l;
    
    if (r < n && db[r].shelfLife > db[largest].shelfLife)// If right child is greater than largest
        largest = r;
    
    if (largest != i)// If largest is not at root
    {
        swap(db[i], db[largest]); //swap the largest with the root
        heapify(n, largest);// Recursive 
    }
}

void inventory::heapsort(){
    for (int i = (numItem/2) - 1; i >= 0; i--)//build heap
        heapify(numItem, i);

    for (int i=numItem-1; i>0; i--)//get elements from heap
    {
        swap(db[0], db[i]);// Move current root to end
        heapify(i, 0);//heapify current heap sort
    }  
}

int inventory::partition(int low, int high){
    int pivot = db[high].quantity;    //pivot set to last quantity element in db
    int i = (low - 1);  //low element index
  
    for (int j = low; j <= high- 1; j++)
    {
        if (db[j].quantity <= pivot)
        {
            i++;    // increment low element index
            swap(db[i], db[j]);
        }
    }
	
    swap(db[i + 1], db[high]);
    return (i + 1);
}

void inventory::quickSort(int low, int high)
{
    if (low < high)
    {
        int pi = partition(low, high);//pi is partitioning index
        quickSort(low, pi - 1);//recursive call before p1
        quickSort(pi + 1, high);//recursive call after p1
    }
}
