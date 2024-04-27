/*
* File: table.h
* Author: Nguyen Thi Ngoc Quyen
* Date: 22/04/2024
* Descriptionn: This file contains all functions to store table's properties
*/
#include "table.h"

/*
* Class: table
* Function: setStatus
* Description: This function is used for setting status of table
* Input:
*	status - a Status datatype - status of table
* Output:
*	none
*/
void table::setStatus(Status statuss) {
	status = statuss;
}
/*
* Class: table
* Function: getStatus
* Description: This function is used for getting status of table
* Input:
*	none
* Output:
*	return status of table
*/
Status table::getStatus() {
	return status;
}
/*
* Class: table
* Function: setIDTable
* Description: This function is used for setting IDTable of table
* Input:
*	idTable - a int datatype - ID of table
* Output:
*	none
*/
void table::setIDTable(int idTable) {
	IDTable = idTable;
}
/*
* Class: table
* Function: getIDTable
* Description: This function is used for getting ID of table
* Input:
*	none
* Output:
*	return ID of table
*/
int table::getIDTable() {
	return IDTable;
}
/*
* Class: table
* Function: orderDish
* Desription: This function is used for order dish , it include ID,Name,Price and quanlity of dish
* Input:
*	id - an int datatype - id of dish
*	menu - a dish datatype - list to save dish
*/
void table::orderDish(int id, list <dish> menu) {
	int _id;
	cout << "Enter id of dish you want to order: ";
	cin >> _id;

	order newOrder;
	list <dish>::iterator var;
	for(var = menu.begin(); var != menu.end(); ++var){
		if (var->getID() == _id) {
			newOrder.Dish.setID(var->getID());
			newOrder.Dish.setName(var->getName());
			newOrder.Dish.setPrice(var->getPrice());
			break;
		}
	}
	cout << "Enter quality that you want: ";
	int _num;
	cin >> _num;
	newOrder.num = _num;

	//add into the list
	listOrder.push_back(newOrder); //listOrder include: ID, Name, Price and num of dish
}
/*
* Class: Table
* Function: cancleTable
* Description: This function is used for canceling dish
* Input:
*	id - an int datatype - id of dish
* Output:
*	none
*/
void table::cancleDish(int id) {//hủy mon an trong don dat hang
	list <order>::iterator var;
	for (var = listOrder.begin(); var != listOrder.end(); ++var) {
		if (var->Dish.getID() == id) {
			cout << "Dish is founded " << endl;
			cout << "ID:    " << var->Dish.getID() << endl;
			cout << "Name:  " << var->Dish.getName() << endl;
			cout << "Price: " << var->Dish.getPrice() << endl;

			cout << "\t Are you sure you want to delete this item?" << endl;
			int ans = 0;
			do {
				cout << "\t \t 1. Yes" << endl;
				cout << "2. No" << endl;
				cout << "Please Enter Your Choice: " << endl;
				cin >> ans;

				if (ans == 2)return;
			} while (ans != 1);

			listOrder.erase(var); //erase: xoa phan tu
			return;
		}
	}
}
/*
* Class: table
* Function: changeNum
* Description: This function is used for  changing quantity of ordered dish
* Input:
*	id - an int datatype - id of dish
* Output:
*	none return
*/
void table::changeNum(int id) { //doi so luong thi dung list order
	list <order>::iterator var;
	for (var = listOrder.begin(); var != listOrder.end(); ++var) {
		if (var->Dish.getID() == id) {
			cout << "Dish is founded " << endl;
			cout << "ID:    " << var->Dish.getID() << endl;
			cout << "Name:  " << var->Dish.getName() << endl;
			cout << "Price: " << var->Dish.getPrice() << endl;

			int cnt;
			cout << "\t \t Please enter quanlity of dish you want to change: " << endl;
			cin >> cnt;

			var->num = cnt; //change quantity = cnt
			return;
		}
	}
}
/*
* Class: table
* Function: printListDish
* Description: This function is used for printting list of ordered dishes
* Input: 
* Output:
*	none return
*/
void table::printListDish(int id) {
	int cnt = 0;
	cout << endl;
	cout << "List of your order dishes" << endl;
	cout << "STT" << "\t\tID" << "\t\tName" << "\t\tPrice" << "\t\tQuantity" << endl;
	for (auto i : listOrder) {
		cnt++;
		cout << cnt << "\t\t" << i.Dish.getID() << "\t\t" << i.Dish.getName() << "\t\t" << i.Dish.getPrice() << "\t\t" << i.num << endl;
	}
}
/*
* Class: table
* Funtion: resetTable
* Description: This functionn is used for reseting status table
* Input
* Output
*/
void table::resetTable() {
	setStatus(available);
	listOrder.clear();
}
/*
* Class: table
* Function: printBill
* Description: This function is used for printting bill
* Input:
* Output:
* 
*/
void table::printBill(int id){
	int bill = 0;
	for (auto i : listOrder) {
		bill += i.Dish.getPrice() * i.num;//money = cost per one * quantity
	}
	printListDish(id);
	cout << endl;
	cout << "Bill: " << bill << endl;
	cout << "VAT: 10%" << endl;
	cout << "Total: " << bill + bill / 10 << endl; //total money pay

	int c;
	do {
		cout << endl;
		cout << "1. Pay away" << endl;
		cout << "2. Turn back" << endl;
		cout << "Please Enter Your Choice: " << endl;
		cin >> c;
	} while (c != 1);

	resetTable();
}

