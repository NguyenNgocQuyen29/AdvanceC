/*
* File: Menu.cpp
* Author: Nguyen Thi Ngoc Quyen
* Description: This file contains opitons GUI and work with selections
*/

#include "Menu.h"

/*
* Function: menu
* Description: This function is GUI , is displayed for a user to perform tasks related to student data.
* Input:
*	reference to a list of student objects 
* Output:
*	none
*/
void menu(list <Student>& data) {
	static int choice;
MENU:
	do {
		cout << " STUDENT MANAGEMENT SYSTEM " << endl;
		cout << "_____________________________" << endl;
		cout << " 1. Add New Student " << endl;
		cout << " 2. Modify Student Information" << endl;
		cout << " 3. Delete Student " << endl;
		cout << " 4. Search Student " << endl;
		cout << " 5. Sort Student " << endl;
		cout << " 6. Print Student List " << endl;
		cout << " 7. Save into database_sv.cvs " << endl;
		cout << " 0. Exit " << endl;
		cout << "______________________________" << endl;
		cout << "Please enter your choice: ";

		cin >> choice;
	} while (choice < 0 || choice > 7);

	switch (choice) {
	case 1: {
	insert_newStudent: //goto 
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "___________Add Details Information__________" << endl;

		insert(data);
		do {
			cout << "1. Continue Adding Another Student Information " << endl;
			cout << "2. Exit " << endl;
			cout << "Please Enter Your Choice: ";

			cin >> choice;
		} while (choice != 1 && choice != 2);
		if (choice == 1) goto insert_newStudent;

		break;
	}
	case 2: {
	modify_Student:
		short int ID_edit;
		cout << "______________________________________________" << endl;
		cout << "Enter ID of Student you want to modify: ";
		cin >> ID_edit;

		modify(data, ID_edit);

		do {
			cout << "\t 1. Continue modifying another student information " << endl;
			cout << "\t 2. Exit " << endl;
			cout << "\t Please enter your choice: ";
			cin >> choice;
		} while (choice != 1 && choice != 2);

		if (choice == 1) goto modify_Student;
		break; //else
	}
	case 3: {
	delete_Student:
		short int ID_delete;
		cout << "\t Enter ID of student that you want to delete: ";
		cin >> ID_delete;

		deleteStudent(data, ID_delete);

		do {
			cout << "\t 1.Continue deleting another student information " << endl;
			cout << "\t 2. Exit" << endl;
			cout << "Please Enter Your Choice: ";
			cin >> choice;
		} while (choice != 1 && choice != 2);

		if (choice == 1) goto delete_Student;
		break;
	}
	case 4: {
	search_Student:
		do {
			cout << "\t 1. Search By Name" << endl;
			cout << "\t 2. Search By ID" << endl;
			cout << "\t 3. Exit" << endl;

			cout << "Please Enter Your Choice: ";
			cin >> choice;
		} while (choice < 1 && choice > 3);
		switch (choice) {
		case 1: {
			string name_search;
			cout << "\t Enter name of Student that you want to search: ";
			cin >> name_search;

			searchByName(data, name_search);
			break;
		}
		case 2: {
			short int id_search;
			cout << "\t Enter id of student that you want to search: ";
			cin >> id_search;

			searchByID(data, id_search);
			break;
		}
		case 3:
			return;

		default:
			break;
		}

		do {
			cout << "\t 1. Continue searching another student information" << endl;
			cout << "\t 2. Exit" << endl;
			cout << "\t Please Enter Your Choice:";

			cin >> choice;
		} while (choice != 1 && choice != 2);
		if (choice == 1) goto search_Student;
		break;
	}
	case 5: {
	sort_Student:
		do {
			cout << "1. Sort by name" << endl;
			cout << "2. Sort by math score" << endl;
			cout << "3. Sort by physic score" << endl;
			cout << "4. Sort by chemical score" << endl;
			cout << "5. Sort by average score" << endl;
			cout << "0. Exit" << endl;
		} while (choice < 0 && choice > 5);
		if (choice == 0) break;
		switch (choice) {
		case 1: {
			sortName(data);
			//cout << data.getName();
			break;
		}
		case 2: {
			auto mathh = sortStudents(data, &Student::getMath);
			break;
		}
		case 3: {
			break;
		}
		case 4: {
			break;
		}
		case 5: {
			break;
		}
		}
		do {
			cout << "\t 1. Continue to sorting Student Information " << endl;
			cout << "\t 2. Exit" << endl;
			cout << "Please enter your choice: ";
			cin >> choice;
		} while (choice != 1 && choice != 2);
		if (choice == 1) goto sort_Student;
		break;
	}
	case 6: {
		printList(data);

		do {
			cout << "\t Enter 0 if you want to return" << endl;
			cout << "Enter Your Choice: ";
			cin >> choice;
		} while (choice != 0);

		break;
	}
	case 7: {
		saveCSV(data);
		cout << "____________Save Data Successfully______________";
		do {
			cout << "\t Enter 0 if you want to exit" << endl;
			cout << "\t Please Enter Your Choice: ";
			cin >> choice;
		} while (choice != 0);
		break;
	}
	case 0: {
		cout << "__________________Program Is Exit________________" << endl;
		exit(0);
	}
	default: {
		cout << "________________Please Try Again_________________" << endl;
		goto MENU;
	}
	}
}
		
	/*
	* Function: insert
	* Description: This function is used for inserting a new student
	* Input:
	*	reference to a list of Student objects
	* Output
	*	 none
	*/
	void insert(list <Student>&data) {
		Student newStudent; //used to store new information will be added into list

		newStudent.setData(); //enter data into newStudent

		data.push_back(newStudent);//add objects into the last list "data"
	}
	/*
	* Function: editInfor
	* Description: This function is used for ediiting details of student
	* Input:
	*	reference to a list of Student objects
	*	it - a iterator datatype - is used to iterate through each element in the list
	* Output:
	*	none return
	*/
	void editInfor(list <Student>& data, list <Student>::iterator var) {
		cout << "_________________________________________________" << endl;
		cout << "______________What you want to edit______________" << endl;
		uint8_t choice;
		do {
			cout << "1. Name" << endl;
			cout << "2. Age" << endl;
			cout << "3. Gender" << endl;
			cout << "4. Math Score" << endl;
			cout << "5. Physic Score" << endl;
			cout << "6. Chemical Score" << endl;
			cout << "0. Exit" << endl;
			cout << "Please enter your choice: ";
			cin >> choice;
		} while (choice < 0 || choice > 6);


		switch (choice) {
		case 0:
			break;

		case 1: {
			cout << "\t Enter the name you want to change: " << endl;
			string name = "";
			cin.ignore();
			cin >> name;
			var->setName(name);
			break;
		}
		case 2: {
			cout << "\t Enter the age you want to change: " << endl;
			short int age;
			cin >> age;
			var->setAge(age);
			break;

		}
		case 3: {
			uint8_t cnt;
			do {
				cout << "\t Enter 1 for male and 2 for female" << endl;
				cout << "Enter Gender: ";
				cin >> cnt;
			} while (cnt != 1 && cnt != 2);
			Gender gender;
			if (cnt == 1) gender = Male;
			else gender = Female;

			var->setGender(gender);
			break;
		}
		case 4: {
			float math;
			cout << "\t Enter the score of math you want to change: ";
			cin >> math;
			var->setMath(math);
			break;
		}
		case 5: {
			float physic;
			cout << "\t Enter the score of physic you want to change: ";
			cin >> physic;
			var->setPhysic(physic);
			break;
		}
		case 6: {
			float chemical;
			cout << "\t Enter the score of chemical you want to change: ";
			cin >> chemical;
			var->setChemical(chemical);
			break;
		}
		default: {
			break;
		}
		}
	}
	/*
	* Function: modify
	* Description: This function is used for editing details of student by student's ID
	* Input
	*	reference to Student list
	*	ID_edit - a short int datatype - ID of student want to edit
	* Output:
	*	none
	*/
	void modify(list <Student>&data, short int ID_edit) {
		list<Student>::iterator var;
		//iterate each element in the list 
		for (var = data.begin(); var != data.end(); ++var) {
			if (var->getID() == ID_edit) {
				cout << "Information is founded " << endl;
				var->getData();

				editInfor(data, var);//edit infỏ with data just get

				cout << "____________Information after editting___________" << endl;
				var->getData(); //get the newly edited information

				return;

			}
			else {
				cout << "\t No information is founded" << endl;
			}
		}
	}
	/*
	* Function: deleteStudent
	* Description:This function is used for deleting student information
	* Input:
	*	reference to list Student
	*	ID_edit - a short int datatype - ID of the student want to delete information
	* Output:
	*	none return
	*/
	void deleteStudent(list <Student>&data, short int ID_edit) {
		list <Student> ::iterator var;
		for (var = data.begin(); var != data.end(); ++var) {//iterate from first list to last list
			if (var->getID() == ID_edit) {
				cout << "Information is founded" << endl;
				var->getData();//get data into var

				cout << "\t Are you sure want to delete this student? " << endl;
				uint8_t choice;
				do {
					cout << "\t 1. Yes " << endl;
					cout << "\t 2. No" << endl;
					cin >> choice;
				} while (choice != 1 && choice != 2);
				if (choice == 1) data.erase(var);

				return;
			}

		}
		cout << "\t No student is founded" << endl;
	}
	/*
	* Function: searchByName
	* Description: This function is used for search details of student by student's name
	* Input:
	*	reference to Student list
	*	name_Search - a string datatype - name of student want to search
	*/
	void searchByName(list <Student>&data, string name_Search) {
		list<Student>::iterator var;
		for (var = data.begin(); var != data.end(); ++var) {
			if (var->getName() == name_Search) {
				cout << "\t Information is founded" << endl;
				var->getData(); //get data from var (var include name_Search)

				return;
			}
			cout << "t No Student Information is founded " << endl;
		}
	}
	/*
	* Function: searchByID
	* Description: This function is used for search details of student by student's ID
	* Input:
	*	reference to Student list
	*	ID_Search - a short int datatype - ID of student want to search
	*/
	void searchByID(list <Student>&data, short int ID_Search) {
		list <Student>::iterator var;
		for (var = data.begin(); var != data.end(); ++var) {
			if (var->getID() == ID_Search) {
				cout << "\t Information is founded " << endl;
				var->getData();
				return;
			}
			cout << "\t No Information is founded" << endl; //else
		}
	}
	/*
	* Function: printList
	* Description: This function is used to print list
	* Input:
	*	name of list - because just print, không làm gì nên không cần reference
	* Output:
	*	none return
	*/
	void printList(list <Student> data) {
		for (auto x : data) {
			x.getData();
		}
	}
	/*
	* Function: saveCSV
	* Description: This function is used to save file CSV
	* Input:
	*	name of the list
	* Output:
	*	none return
	*/
	void saveCSV(list <Student>&data) {
		ofstream file; //used for writing data to a text file
		file.open("database_sv.csv");
		for (auto& var : data) {
			file << var.getName() << ',' << var.getMath() << ',' << var.getPhysic() << ',' << var.getChemical() << ',' << var.getAverageScore() << endl; //write name, math physic chemical score, average into file
		}
	}
	/*
	* Function: cmpName
	* Description: This function is used for comparing two student's name
	* Input:
	*	elements in the list
	* Output
	*	return student have the larger name
	*/
	bool cmpName(const Student &a, const Student &b) {
    return a.getName() < b.getName();
}
	/*
	* Funtion: sortName
	* Description: this function is used for sorting student's name in the list
	* Input: 
	*	reference to Student list
	* Output:
	*	none return
	*/
	void sortName(list <Student>& data) {
		data.sort(cmpName); 
	}
	/*
	* Template Function: 
	* Description: create compared functions with other datatype
	* Input:
	*	two members in data
	* Output:
	*	return element with large size
	*/
	template <typename T> bool cmpScore(const Student& a, const Student& b, T(Student::* gett)()) {
		return (a.*get)() < (b.*get)();
	}
	/*
	* 
	* Description: this function is used for sorted elements into list
	* Input:
	* Output:
	* 
	*/
	template <typename T>
	void sortStudents(list<Student>& data, T(Student::* gett)() const) {
		sort(data.begin(), data.end(), [gett](const Student& a, const Student& b) {
			return cmpScore(a, b, gett);
			});
	}