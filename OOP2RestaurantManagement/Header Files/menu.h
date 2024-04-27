/*
* File: menu.h
* Author: Nguyen Thi Ngoc Quyen
* Date: 24/04/2024
* Description: This files contains original properties to manage restaurant include manager & staff
*/
#ifndef _MENU_H_
#define _MENU_H_

#include "manager.h"
#include "staff.h"

typedef enum {
	managerWork,
	staffWork
}Work;
typedef struct {
	int numTable;
	manager dataManager;
	staff dataStaff;
}Data;
static int choice;

void mainMenu(Data &data);
void menuManager(Data &data);
void menuStaff(Data& data);


#endif