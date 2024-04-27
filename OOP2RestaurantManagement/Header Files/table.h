/*
* File: table.h
* Author: Nguyen Thi Ngoc Quyen
* Date: 22/04/2024
* Description: This file is a original properties functions of table is ID, status,bill
*/
#ifndef _TABLE_H_
#define _TABLE_H_

#include "dish.h"

typedef enum {
	booked,
	available
}Status;
/* Class: table
* Description: This class contains properties of table object
*/
class table {
private:
	int IDTable;
	Status status;
	list <order> listOrder;
	int Bill;
public:
	table() {
		static int idTable = 1;
		this->IDTable = idTable;
		idTable++;

		status = available;
		this->Bill = 0;
	}
	void setStatus(Status statuss);
	Status getStatus();

	void setIDTable(int idTable);
	int getIDTable();

	void orderDish(int id, list <dish> menu); //id with dish

	void cancleDish(int id);
	void changeNum(int id);

	void printListDish(int id);

	void printBill(int id);

	void resetTable();

};

#endif