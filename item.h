/*
 * item.h
 *
 *  Created on: May 18, 2020
 *      Author: elizabeth-na
 */
#ifndef ITEM_H_
#define ITEM_H_
#include <string>
using namespace std;

struct item {
	int quantity;
	char name[30];
	int shelfLife;
	item();
	item(char n[], int q, int SL);
	bool operator>(const item &other);
	bool operator>=(const item &other);
	bool operator<(const item &other);
	bool operator<=(const item &other);
	bool operator==(const item &other);
	bool operator>(const int &otherSL);
	bool operator>=(const int &otherSL);
	bool operator<(const int &otherSL);
	bool operator<=(const int &otherSL);
	bool operator==(const int &otherSL);

	friend ostream& operator << (ostream &, const item&);
	friend istream& operator >> (istream &, item&);


};



#endif /* ITEM_H_ */
