/*
* File: dish.h
* Author: Nguyen Thi Ngoc Quyen
* Date: 22/04/2024
* Description: This file contains original functions that manager use to manage
*/
#ifndef _DISH_H_
#define _DISH_H_

#include <iostream>
#include <list>
#include <string>
using namespace std;

/*
* Class: dish
* Decription: This class contains properties of dish such as Id,name,price. But the ID of the dish will increase staring from 1
*/
class dish {
private:
	int ID;
	string Name;
	int Price;
public:
	//constructor
	dish() {
		static int id = 1;
		this->ID = id;
		id++;

		this->Name = "";
		this->Price = 0;
	}

	void setID(int id);
	int getID();

	void setName(string name);
	string getName();

	void setPrice(int price);
	int getPrice();

	void setData();
	void getData();
};
	typedef struct {
		int num;
		dish Dish
	;
	}order;

#endif
