/*
* File: manager.cpp
* Author: Nguyen Thi Ngoc Quyen
* Date: 23/04/2024
* Description: This file is funtions that program is used for manager
*/
#include "manager.h"
/*
* class: manager
* Function: getMenu
* Description: this function is used return menu
*/
list <dish> manager::getMenu() {
	return menu;
}
/*
* class: table
* Function: setupNumTable
* Description: This function is used setup table number
* Input:
*	numTable - an int datatype - number of table
* Output:
*	none return
*/
void manager::setupNumTable(int numTablee) {
	numTable = numTablee;
}
/*
* class: manager
* Function: setupNumTable
* Input:
*	none
* Output:
*	return number of table
*/
int manager::setupNumTable() {
	return numTable;
}
/*
* class: manager
* Function: addDish
* Description: this function is used for add dish into menu
* Input:
*	none
* Output:
*	none
*/
void manager::addDish() {
	dish newDish;

	string name;
	cout << "Enter name of dish you want order: ";
	cin.ignore(); cin >> name;
	//set newly added name 
	newDish.setName(name);



	int price;
	cout << "Enter price: ";
	cin.ignore();
	cin >> price;
	newDish.setPrice(price);


	//newDish include : name & price, add newDish into menu
	menu.push_back(newDish);
}
/*
* class: manager
* Function: editDish
* Description: This function is used for editting dish in menu include name & price
* Input:
*	id - an int datatype - id of list dish
* Output:
*	none
*/
void manager::editDish(int id) {
	for (auto &i : menu) {
		if (i.getID() == id) {
			cout << endl;
			cout << "____________________________________________" << endl;
			cout << "ID" << "\t\t\tName" << "\t\t\tPrice" << endl;
			cout << i.getID() << "\t\t\t" << i.getName() << "\t\t\t" << i.getPrice();

			int price;
			cout << endl;
			cout << "Enter new price: ";
			cin >> price;
			i.setPrice(price);
			cout << "____________________________________________" << endl;
			cout << " Update price successfully";
			return;
		}
	}
}
/*
* class: manager
* Function: deleteDish
* Description: This function is used for deleting dish in menu 
* Input:
*	id - an int datatype - id of list dish
* Output:
*	none
*/
void manager::deleteDish(int id) {
	list<dish>::iterator var;
	for (var = menu.begin(); var != menu.end(); ++var) {
		if (var->getID() == id) {
			cout << "Dishes is founded" << endl << endl;
			cout << "ID" << "\t\t\tName" << "\t\t\tPrice" << endl;
			cout << var->getID() << "\t\t\t" << var->getName() << "\t\t\t" << var->getPrice();
			cout << endl;
			cout << "are you sure want to delete this item?" << endl;
			int c;
			do {
				cout << "1. Yes" << endl;
				cout << "2. No" << endl;
				cout << "Please Enter Your Choice: ";
				cin >> c;

				if (c == 2) return;
			} while (c != 1);

			menu.erase(var);; //delete this dish
			return;
		}
	}
}
/*
* class: manager
* Function: showMenu
* Description: This function is used for showing dish in menu
* Input:
*	id - an int datatype - id of list dish
* Output:
*	none
*/
void manager::showMenu() {
	int cnt = 0;
	cout << "List of order you want to dishes" << endl;
	cout << endl;
	cout << "No" << "\t\t\tID" << "\t\t\tName" << "\t\t\tPrice" << endl;
	for (auto i : menu) {
		cnt++;
		cout << cnt << "\t\t\t" << i.getID() << "\t\t\t" << i.getName() << "\t\t\t" << i.getPrice() << endl;
	}
}