/*
* File: Menu.h
* Author: Nguyen Thi Ngoc Quyen
* Date: 21/04/2024
* Description: This files contains original options to manage student information.
*/
#ifndef _MENU_H_
#define _MENU_H_

#include "Student.h"
#include <fstream>

void menu(list < Student>& data);
void insert(list <Student>& data);
void editInfor(list <Student>& data, list <Student>::iterator var);
void modify(list <Student>& data, short int ID_edit);
void deleteStudent(list <Student>& data, short int ID_edit);
void searchByName(list <Student>& data, string name_Search);
void searchByID(list <Student>& data, short int ID_Search);
void saveCSV(list <Student>& data);
void printList(list <Student> data);
bool cmpName(const Student& a, const Student& b);
void sortName(list <Student>& data);
template <typename T> bool cmpScore(const Student& a, const Student& b, T(Student::* gett)());
template <typename T> void sortStudents(list<Student>& data, T(Student::* gett)() const);

///template <typename T> bool cmpScore(const Student & a, const Student & b, T (Student:: * get() const)


#endif
