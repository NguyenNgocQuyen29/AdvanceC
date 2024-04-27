/*
* File: dish.cpp
* Author: Nguyen Thi Ngoc Quyen
* Date: 22/04/2024
* Decription: This file contains all functions to store properties of dish
*/
#include "dish.h"

/*
* Class: dish
* Function: setID
* Description: This function is used for setting ID of dish
* Input:
*	ID - a int datatype - ID of dish
* Output:
*	none return
*/
void dish::setID(int id) {
	ID = id;
}
/*
* Class: dish
* Function: getID
* Description: This function is used for getting ID of dish
* Input:
*	none
* Output:
*	return ID of dish
*/
int dish::getID() {
	return ID;
}
/*
* Class: dish
* Function: setName
* Description: This function is used for setting Name of dish
* Input:
*	name - a string datatype - name of dish
* Output:
*	none return
*/
void dish::setName(string name) {
	Name = name;
}
/*
* Class: dish
* Function: getName
* Description: This function is used for getting Name of dish
* Input:
*	none
* Output:
*	return Name of dish
*/
string dish::getName() {
	return Name;
}
/*
* Class: dish
* Function: setPrice
* Description: This function is used for setting Price of dish
* Input:
*	price - a int datatype - price of dish
* Output:
*	none return
*/
void dish::setPrice(int price) {
	Price = price;
}
/*
* Class: dish
* Function: getPrice
* Description: This function is used for getting Price of dish
* Input:
*	none
* Output:
*	return Price of dish
*/
int dish::getPrice() {
	return Price;
}
/*
* Class: dish
* Function: setData
* Description: This function is used for setting data of dish include enter name & price of dish
* Input:
*	none
* Output:
*	none
*/
void dish::setData() {
	string name;
	int price;

	cout << "\t Enter name of dish: ";
	cin.ignore();;
	cin >> name;
	setName(name);

	cout << "\t Enter price of dish: ";
	cin.ignore();
	cin >> price;
	setPrice(price);
}
/*
* Class: dish
* Function: getData
* Description: This function is used for getting data of fish
* Input:
*	none
* Output:
*	none
*/
void dish::getData() {
	cout << "ID: " << "\t Name: " << "\t Price: " << endl;
	cout << getID() << "\t " << getName() << "\t " << getPrice() << endl;
}
