/*
* File: manager.h
* Author: Nguyen Thi Ngoc Quyen
* Date: 23/04/2024
* Description: This file is origital funtions that program is used for manager 
*/
#ifndef _MANAGER_H_
#define _MANAGER_H_

#include "table.h"


/*
* Class: manager
* Description: This class contais basic properties of a manager object 
*/
class manager {
private:
	list <dish> menu;
	int numTable;
public:
	manager() {
		this->numTable = 0;
	}
	list <dish> getMenu();

	void setupNumTable(int numTablee);
	int setupNumTable();

	void addDish();
	void editDish(int id);
	void deleteDish(int id);
	void showMenu();
};

#endif
