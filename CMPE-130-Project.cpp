//============================================================================
// Name        : CMPE-130-Project.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <string.h>
#include "inventory.h"
#include "item.h"
using namespace std;

void readFromFile(inventory& A, string fileName){
	ifstream fin;
	fin.open(fileName);
	item element;
	if(fin.fail()) {
	    cout << "File failed to open :(" << endl;
	}
	    string tempN, line, tempQ, tempS;
	    int quantity, shelflife;
	    
	    while(getline(fin, line))
		{
			stringstream ss(line);
			getline(ss, tempN, ',');
			char nstr[tempN.size()+1];
			strcpy(nstr, tempN.c_str());
			getline(ss, tempQ, ',');
			quantity = stoi(tempQ);
			getline(ss, tempS, ',');
			shelflife = stoi(tempS);
			A.insertItem(nstr, quantity, shelflife);
		}
	

    fin.close(); 

}

int main() {
	inventory sto, Atest;
	char name[30];
	int quantity, shelfLife, choice;

	do
	{
		cout << "<--------Your Food Pantry---------->" << endl;
		cout << "<---------------Menu--------------->" << endl;
		cout << "(1) Insert an item to my Pantry." << endl;
		cout << "(2) Delete an item from my Pantry." << endl;
		cout << "(3) Search for an item." << endl;
		cout << "(4) Update my Pantry." << endl;
		cout << "(5) What is in my Pantry?" << endl;
		cout << "(6) Prioritize my Pantry by shelf life." << endl;
		cout << "(7) Sort my Pantry by quantities." << endl;
		cout << "(8) Upload list." << endl;
		cout << "(9) Exit from my Pantry." << endl;
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
		case 3 :	cin.getline(name,80);
					cout << "Enter name of item: " << endl;
					cin.getline(name, 80);
					item *test;
					test = sto.searchi(name);
					if(test != NULL) {
						cout << "<------Searching Result-------->" << endl;
						cout << "ITEM FOUND: " << test->name << test->quantity << test->shelfLife << endl;
					} else {
						cout << "ITEM NOT FOUND" << endl;
					}
					break;
		case 4 : 	cout << "Enter details of item for update: " << endl;
					cin.getline(name,80);
					cout << "Enter name of item: " << endl;
					cin.getline(name, 80);
					cout << "Enter new quantity: " << endl;
					cin >> quantity;
					cout << "Enter new shelf life in days: " << endl;
					cin >> shelfLife;
					sto.updateItem(name, quantity, shelfLife);
					break;
		case 5 : 	sto.printItems();
					break;
		case 6:    	cout << "\nPantry items prioritized by shelf life:" << endl;
                			sto.heapsort();
                			sto.printItems();
                 			break;
		case 7: 	cout << "\nPantry items sorted by quantity."<< endl;
                   			sto.quickSort(0, sto.numItem -1);
                    			sto.printItems();
                    			break;
		case 8 :	string fileName = "Test.txt";
					readFromFile(sto, "Test.txt");
					sto.printItems();
					break;
		}
	} while(choice != 9);

	return 0;
}
