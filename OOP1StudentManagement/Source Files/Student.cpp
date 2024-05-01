/*
* File: Student.cpp
* Author: Nguyen Thi Ngoc Quyen
* Date: 21/04/2024
* Description: This file contais function used to establish and get information.
*/

#include "Student.h"

/*
* Class: Person
* Person: setName
* Description: This class is used for setting name of student
* Input
*	name - a string datatype - name of the student
* Ouput
*	none return
*/
void Person::setName(string Name) {
	name = Name;
}
/*
* Class: Person
* Function: getName
* Description: This class is used for getting name of student
* Input
*	none
* Ouput
*	return name - name of the student
*/
string Person::getName() {
	return name;
}
/*
* Class: Person
* Function: setAge
* Description: This class is used for setting age of student
* Input
*	age - a short in datatype - age of student
* Output
*	none return
*/
void Person::setAge(short int Age) {
	age = Age;
}
/*
* Class: Person
* Function: getAge
* Description: This class is used for getting age of student
* Input
*	none
* Output
*	none age of student
*/
short int Person::getAge() {
	return age;
}
/*
* Class: Person
* Function: setGender
* Description: This class is used for setting gender of student
* Input
*	gender - a Gender datatype - gender of student
* Output
*	none return
*/
void Person::setGender(Gender Ggender) {
	gender = Ggender;
}
/*
* Class: Person
* Function: getGender
* Description: This class is used for getting gender of student
* Input
*	none
* Output
*	return gender of student
*/
Gender Person::getGender() {
	return gender;
}
/*
* Class: Person
* Function: setID
* Description: This class is used for setting ID of student
* Input
*	ID - a short int datatype - ID of student
* Output
*	none return
*/
void Person::setID(short int ID) {
	id = ID;
}
/*
* Class: Person
* Function: getID
* Description: This class is used for getting ID of student
* Input
*	none
* Output
*	return ID of student
*/
short int Person::getID() {
	return id;
}
/*
* Class: Student - inherits class of person
* Function: setMath
* Description: This function is used fpr setting Math score of student
* Input:
*	mathScore - a float datatype - math score of student
* Output:
*	none return
*/
void Student::setMath(float mathScore) {
	Math_score = mathScore;
}
/*
* Class: Student - inherits class of person
* Function: getMath
* Description: This function is used fpr getting Math score of student
* Input:
*	none
* Output:
*	return math socre of student
*/
float Student::getMath() {
	return Math_score;
}
/*
* Class: Student - inherits class of person
* Function: setPhysic
* Description: This function is used fpr getting Physic score of student
* Input:
*	physicScore - a float datatype - physic score of student
* Output:
*	none return
*/
void Student::setPhysic(float physicScore) {
	Physic_score = physicScore;
}
/*
* Class: Student - inherits class of person
* Function: getPhysic
* Description: This function is used fpr getting Physic score of student
* Input:
*	none
* Output:
*	return physic socre of student
*/
float Student::getPhysic() {
	return Physic_score;
}
/*
* Class: Student - inherits class of person
* Function: setChemical
* Description: This function is used fpr getting Chemical score of student
* Input:
*	physicScore - a float datatype - chemical score of student
* Output:
*	none return
*/
void Student::setChemical(float chemicalScore) {
	Chemical_score = chemicalScore;
}
/*
* Class: Student - inherits class of person
* Function: getChemical
* Description: This function is used fpr getting Chemicsl score of student
* Input:
*	none
* Output:
*	return chemical socre of student
*/
float Student::getChemical() {
	return Chemical_score;
}
/*
* Class: Student - inherits class of person
* Function: getAverage
* Description: This function is used for getting Average score of student
* Input:
*	none
* Output:
*	return average socre of student(include math,physic, chemical)
*/
float Student::getAverageScore() {
	Average_score = (Math_score+ Chemical_score+ Physic_score)/3;
	return Average_score;
}
/*
* Class: Student - inherits class of person
* Function: getLevel
* Description: This function is used for getting level of student(exellent,good,average,below average,weak)
* Input:
*	none
* Output
*	return level of student
*/
Levels Student::getLevel() {
	if (getAverageScore() >= 8.0 && getAverageScore() <= 10.0) return Excellent;
	else if (getAverageScore() >= 6.5 && getAverageScore() < 8.0) return Good;
	else if (getAverageScore() >= 5.0 && getAverageScore() < 6.5) return Average;
	else if (getAverageScore() >= 4.0 && getAverageScore() < 5.0) return BelowAverage;
	else return Weak;
}
/*
* Class: Student - inherits class of person
* Function: setData
* Description: This function is used for enterstudent information
* Input & Output
*	none
*/
void Student::setData() {
	//1. Information such as Name,Age,Gender and  ID
	string Name;
	cout << "Enter Name: ";
	cin.ignore();
	cin >> Name;
	setName(Name);

	short int Age;
	cout << "Enter Age: ";
	cin.ignore();
	cin >> Age;
	setAge(Age);

	short int cnt = 0;
	do {
		cout << "<_____Enter 1 for male and 2 for female_____> " << endl;
		cout << "Enter Gender: ";
		cin >> cnt;
	} while (cnt != 1 && cnt != 2);
	Gender Ggender;
	if (cnt == 1) Ggender = Male;
	else Ggender = Female;
	setGender(Ggender);

	short int ID;
	cout << "Enter ID: ";
	cin >> ID;
	cin.ignore();
	setID(ID);

	//2. Information about score
	float mathScore, physicScore, chemicalScore;
	cout << "<________________Enter Score_________________>" << endl;
	cout << "\t Enter Math Score: "; cin >> mathScore; setMath(mathScore);
	cout << "\t Enter Physic Score: "; cin >> physicScore; setPhysic(physicScore);
	cout << "\t Enter Chemical Score: "; cin >> chemicalScore; setChemical(chemicalScore);
}
/*
* Class: Student - inherits class of person class
* Function: getData
* Description: This function is used for getting data of student
* Input & Output:
*	none
*/
void Student::getData() {
	cout << "ID: " << getID() << endl;
	cout << "Name: " << getName() << endl;
	cout << "Age: " << getAge() << endl;
	
	getGender();
	if (getGender() == Male) { cout << "Male" << endl; }
	else cout << "Female" << endl;

	cout << "Maths\t | \tPhysics | \tChemistry" << endl;
	cout << getMath() << "\t\t" << getPhysic() << "\t\t" << getChemical() << endl;

	cout << "Average Score: " << getAverageScore() << endl;

	cout << "Level: " << getLevel() << endl;
	switch (getLevel()) {
	case Excellent:
		cout << "Excellent" << endl;
		break;
	case Good:
		cout << "Good" << endl;
		break;
	case Average:
		cout << "Average" << endl;
		break;
	case BelowAverage:
		cout << "BelowAverage" << endl;
		break;
	case Weak:
		cout << "Weak" << endl;
		break;
	default:
		break;
	}
}
