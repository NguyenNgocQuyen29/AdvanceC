/*
* File: staff.h
* Author: Nguyen Thi Ngoc Quyen
* Date: 23/04/2024
* Description: This file contain original properties of staff objects
*/
#ifndef _STAFF_H_
#define _STAFF_H_

#include "table.h"
#include <vector>
class staff {
public:
	vector <table> listTable;
	staff(){}

	void getNumTable(int numTablee);
	void displayTable(); //display all setted up tables
	bool checkFull();

	void choiceTable(int _choiceID); //display available tables and can choice table ID
	void getInforTable(int _tableID, int type, list <dish> menu);
};

#endif