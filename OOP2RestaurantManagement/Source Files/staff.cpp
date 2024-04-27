/*
* File: staff.h
* Author: Nguyen Thi Ngoc Quyen
* Date: 23/04/2024
* Description: This file contain original properties of staff objects
*/

#include "staff.h"
/*
* class: staff
* Function: getNumTable
* Description: add new table into list
* Input: 
*	numTable - an int datatype - number of table
* Output:
*	none
*/
void staff::getNumTable(int numTablee) {
	for (int i = 0; i < numTablee; i++) {
		table newTable;
		listTable.push_back(newTable);
	}
}
/*
* class: staff
* Function: displayTable
* Description: this function is used for displaying status of table is booked or available
* Input:
*	none
* Output:
*	none
*/
void staff::displayTable() {
	//print number Table
	cout << "ID Table" << "  " << endl;
	for (int i = 1; i < listTable.size(); i++) {
		cout << i << " ";
	}
	//print status
	cout << "Status" << "  " << endl;
	for (auto i : listTable) {
		if (i.getStatus() == available)
			cout << "O ";
		else
			cout << "X ";
	}
	cout << "_______________________________" << endl;
	cout << "  X: booked";
	cout << "  O: available";
}
/*
* class: staff
* Function: checkFull
* Descrption: check table is booked or available
* Input:
*	none
* Output:
*	return status of table
*/
bool staff::checkFull() {
	for (auto i : listTable) {
		if (i.getStatus() == available) return false;
	}
	return true;
}

void staff::choiceTable(int _choiceID) {
	for (auto& i : listTable) {
		if (i.getIDTable() == _choiceID) {
			i.setStatus(booked);
		}
	}
}
/*
*class : staff
* Function : getInforTable
* Descrption : task of staff objects
* Input :
*	_tableID - id of table want to serve
*	type - type want to staff serve
*	menu - dish list - list to operate 
* Output :
	none
*/
void staff::getInforTable(int _tableID, int type, list <dish> menu) {
	for (auto& i : listTable) {
		if (i.getIDTable() == _tableID) {
			switch (type) {
			case 1://call dish
				i.orderDish(_tableID, menu);
				break;
			case 2:
				i.cancleDish(_tableID);
				break;
			case 3:
				i.changeNum(_tableID);
				break;
			case 4:
				i.printListDish(_tableID);
				break;
			case 5:
				i.printBill(_tableID);
				break;
			default:
				break;
			}
		}
	}
}