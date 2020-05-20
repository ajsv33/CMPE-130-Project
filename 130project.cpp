//============================================================================
// Name        : 130project.cpp
// Author      : Elizabeth Na
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <fstream>
#include "inventory.h"
#include "item.h"
using namespace std;

void readFromFile(inventory& A, string fileName) {
	ifstream fin(fileName);
	item element;
	while (!fin.eof()) {
		fin >> element;
		cout << "Inserting " << element.name << endl;
		A.insert(element);
	}
}

int main() {
	inventory sto, Atest;
	string name[30];
	int quantity, shelfLife, choice;

	//added for quicksort
	int arr[] = { 10, 7, 8, 9, 1, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	sto.quickSort(arr, 0, n - 1);
	cout << "Sorted array: \n";
	sto.printArray(arr, n);

	//added for binary search
	string empName;
	int results;

	ifstream file("Test.txt");
	if (file.is_open()) {
		for (int i = 0; i < 29; ++i) { //29 being the number of characters in the file
			file >> name[i];
		}
	}

	//added for binary search
	sto.sortArray(name, 29);
	cout << "Please enter the item's name: ";
	getline(cin, empName); //has to include the , after the word unless we use an extra space like Banana , Milk
	results = sto.binarySearch(name, 29, empName);

	if (results == -1)
		cout << "That item is not in your pantry.\n";
	else {
		cout << "Item " << empName << " was found in the pantry.";
		//cout << " in the array.\n";
	}

}

/*
 do {
 cout << "<--------Your Food Pantry---------->" << endl;
 cout << "<---------------Menu--------------->" << endl;
 cout << "(1) Insert an item to my Pantry." << endl;
 cout << "(2) Delete an item from my Pantry." << endl;
 cout << "(3) Search for an item." << endl;
 cout << "(4) Update my Pantry." << endl;
 cout << "(5) What is in my Pantry?" << endl;
 cout << "(6) Upload list." << endl;
 cout << "(7) Exit from my Pantry." << endl;
 cout << "Enter your choice: " << endl;
 cin >> choice;


 switch (choice) {
 case 1 :	cin.getline(name,80);
 cout << "Enter name of item: " << endl;
 cin.getline(name,80);
 cout << "Enter the quantity of item: " << endl;
 cin >> quantity;
 cout << "Enter the shelf life in days of item: " << endl;
 cin >> shelfLife;
 sto.insertItem(name, quantity, shelfLife);
 break;
 case 2 : 	cin.getline(name,80);
 cout << "Enter name of item: " << endl;
 cin.getline(name, 80);
 sto.deleteItem(name);
 break;
 case 3 :	//cin.getline(name,80);

 //added for binary search
 sto.sortArray(name, 29);
 cout << "Please enter the item's name: ";
 getline(cin, empName);
 results = sto.binarySearch(name, 29, empName);

 if (results == -1)
 cout << "That name does not exist in the array.\n";
 else {
 cout << "That name is found at element " << results;
 cout << " in the array.\n";
 }


 /*item *test;
 test = sto.searchi(name);
 if(test != NULL) {
 cout << "<------Searching Result-------->" << endl;
 cout << "ITEM FOUND: " << test->name << test->quantity << test->shelfLife << endl;
 } else {
 cout << "ITEM NOT FOUND" << endl;
 }
 break;


 case 4 : 	cout << "Enter details of item for update: " << endl;
 //		cin.getline(name,80);
 cout << "Enter name of item: " << endl;
 //					cin.getline(name, 80);
 cout << "Enter new quantity: " << endl;
 cin >> quantity;
 cout << "Enter new shelf life in days: " << endl;
 cin >> shelfLife;
 //					sto.updateItem(name, quantity, shelfLife);
 break;
 case 5 : 	sto.printItems();
 break;
 case 6 :	string fileName = "Test.txt";
 readFromFile(Atest, "Test.txt");
 Atest.printItems();


 }
 } while(choice != 7);

 return 0;
 }
 */
