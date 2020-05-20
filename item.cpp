/*
 * item.cpp
 *
 *  Created on: May 18, 2020
 *      Author: elizabeth-na
 */
#include <iostream>
#include <string>
#include "item.h"
using namespace std;

item::item() {
	quantity = 0;
	shelfLife = 0;
}

item::item(char n[], int q, int SL)
{
	quantity = q;
	shelfLife = SL;
}

bool item::operator >(const item & other) {
	return ((this->quantity) > (other.quantity));
}

bool item::operator >=(const item & other) {
	return ((this->quantity) >= (other.quantity));
}

bool item::operator <(const item & other) {
	return ((this->quantity) < (other.quantity));
}

bool item::operator <=(const item & other) {
	return ((this->quantity) <= (other.quantity));
}

bool item::operator ==(const item & other) {
	return ((this->quantity) == (other.quantity));
}

bool item::operator >(const int & otherSL) {
	return ((this->shelfLife) > (otherSL));
}

bool item::operator >=(const int & otherSL) {
	return ((this->shelfLife) >= (otherSL));
}

bool item::operator <(const int & otherSL) {
	return ((this->shelfLife) < (otherSL));
}

bool item::operator <=(const int & otherSL) {
	return ((this->shelfLife) <= (otherSL));
}

bool item::operator ==(const int & otherSL) {
	return ((this->shelfLife) == (otherSL));
}

ostream& operator <<(ostream& os, const item& item) {
	os << "name" << item.name << ", " << "Quantity: " << item.quantity << ", " << "Shelflife: " << item.shelfLife;
	return os;
}

istream& operator >>(istream& is, item& item) {
	char temp_char; //Read ','
	cin.getline(item.name,80);
	is >> skipws >> item.quantity >> temp_char >> skipws >> item.shelfLife;
	if(temp_char != ','){
		throw "Input is not formatted correctly";
	}
	return is;
}



