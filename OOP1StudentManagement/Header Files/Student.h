
/*
* File: Student.h
* Author: Nguyen Thi Ngoc Quyen
* Date: 21/04/2024
* Description: This file is used for storing original function to manage student information
*/

#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <iostream>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

typedef enum Gender {
    Male,
    Female
}Gender;

typedef enum Levels {
    Excellent,
    Good,
    Average,
    BelowAverage,
    Weak
}Levels;
/*
* Class: Person
* Description: This class contains basic information of each object
* Input:
*	None
* Output:
*	None
*/
class Person {
private:
    string name;
    short int age;
    Gender gender;
    short int id;
public:
    Person() {
        this->name = "";
        this->age = 0;
        this->gender = Male;
        this->id = 0;
    }

    void setName(string Name);
    string getName();

    void setAge(short int Age);
    short int getAge();

    void setGender(Gender Ggender);
    Gender getGender();

    void setID(short int ID);
    short int getID();
};
/*
* Class: Student
* Description: This class is a class that inherits from Person class to contains private information of members
* Input:
*	None
* Output:
*	None
*/
class Student : public Person {
private:
    float Math_score;
    float Chemical_score;
    float Physic_score;
    float Average_score;
    Levels level;

public:
    Student() : Person() {
        this->Math_score = 0;
        this->Chemical_score = 0;
        this->Physic_score = 0;
        this->Average_score = 0;
        this->level = Excellent;
    }
    static bool cmpName(const Student& a, const Student& b);

    void setData();
    void getData();

    void setMath(float mathScore);
    float getMath();

    void setPhysic(float physicScore);
    float getPhysic();

    void setChemical(float chemicalScore);
    float getChemical();

    float getAverageScore();

    Levels getLevel();
};

#endif
