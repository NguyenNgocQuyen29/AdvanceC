/*
* File: menu.cpp
* Author: Nguyen Thi Ngoc Quyen
* Date: 24/04/2024
* Description: This files contains properties to manage restaurant include manager & staff
*/

#include "menu.h"

void mainMenu(Data &data) {
	while (1) {
	menu_start:
		Work work;
		do {
			cout << "_________________________________" << endl;
			cout << "      RESTAURANT MANAGEMENT      " << endl;
			cout << "_________________________________" << endl;
			cout << "            1. Manager           " << endl;
			cout << "            2. Staff             " << endl;
			cout << "            3. Exit Program      " << endl;
			cout << "_________________________________" << endl;
			cout << "Please enter your choice: ";
			cin >> choice;

			if (choice == 3) exit(0);
		} while (choice != 1 && choice != 2);
		if (choice == 1) work = managerWork;
		else work = staffWork;
		switch (work) {
		case managerWork:
			menuManager(data);
			break;
		case staffWork:
			menuStaff(data);
			break;
		default:
			break;
		}

	}
}
void menuManager(Data& data) {
M:
	do {
		cout << "_________________________________" << endl;
		cout << "         MANAGER WORKING         " << endl;
		cout << "_________________________________" << endl;
		cout << "          1. Setup Table         " << endl;
		cout << "          2. Add dish            " << endl;
		cout << "          3. Edit dish           " << endl;
		cout << "          4. List dish           " << endl;
		cout << "          5. Delete dish         " << endl;
		cout << "          0. Turn back main menu " << endl;
		cout << "_________________________________" << endl;
		cout << "Please Enter Your Choice: ";
		cin >> choice;
	} while (choice < 0 || choice > 8);
	switch (choice) {
	case 1:
		cout << "____________________________________________" << endl;
		cout << "               1. Setup Table               " << endl;
		cout << " Enter quantity of table you want to setup: ";
		cin >> data.numTable;
		data.dataManager.setupNumTable(data.numTable); //manager setup => staff get
		data.dataStaff.getNumTable(data.numTable);
		cout << "____________________________________________" << endl;
		cout << "      Setup number tables successsfully     " << endl;
		do {
			cout << "              1. Turn back              " << endl;
			cout << "              2. Exit program           " << endl;
			cout << "       Please Enter Your Choice: ";
			cin >> choice;
			if (choice == 2) exit(0);
		} while (choice != 1);
		goto M;
		break;
	case 2:
	add_dish:
		cout << "____________________________________________" << endl;
		cout << "                2. Add dish                 " << endl;
		data.dataManager.addDish();
		cout << "____________________________________________" << endl;
		data.dataManager.showMenu();
		do {
			cout << "       Continue add another dishes?      " << endl;
			cout << "           1. Add another dish           " << endl;
			cout << "           2. Turn back                  " << endl;
			cout << "   Enter your choice: ";
			cin >> choice;
		} while (choice != 1 && choice != 2);
		if (choice == 1) goto add_dish;
		else goto M;
		break;
	case 3:
	edit_menu:
		cout << "                Menu                     " << endl;
		data.dataManager.showMenu();
		cout << endl << endl;
		cout << "____________________________________________" << endl;
		cout << "                3. Edit dish                " << endl;
		cout << "       Enter ID of dish you want to edit: ";
		int id; cin >> id;

		data.dataManager.editDish(id);
		do {
			cout << endl;
			cout << "   You want to change another dishes information?   " << endl;
			cout << "   1. Changing another dish information   " << endl;
			cout << "   2. Turn back " << endl;
			cout << "   Please enter your choice: ";
			cin >> choice;
		} while (choice != 1 && choice != 2);
		if (choice == 1) goto edit_menu;
		else goto M;
		break;
	case 4:
		cout << "____________________________________________" << endl;
		cout << "                   List dish                " << endl;
		data.dataManager.showMenu();

		do {
			cout << "           1. Turn back          " << endl;
			cout << "           2. Exit               " << endl;
			cout << "   Enter your choice: ";
			cin >> choice;
			if (choice == 2) exit(0);
		} while (choice != 1);
		goto M;
		break;
	case 5:
	delete_dish:
		cout << "____________________________________________" << endl;
		cout << "                   List dish                " << endl;
		data.dataManager.showMenu();

		cout << endl;
		cout << "Enter ID of dish you want to delete: ";
		int _id; cin >> _id;
		data.dataManager.deleteDish(_id);
		do {
			cout << endl;
			cout << "1. Continue Deleting Another Dish " << endl;
			cout << "2. Turn back" << endl;
			cout << "Please Enter your choice: ";
			cin >> choice;
		} while (choice != 1 && choice != 2);
		if (choice == 1) goto delete_dish;
		else goto M;
		break;
	case 0:
		goto M;
		break;
	default:
		break;
	}
}
void menuStaff(Data& data) {
S:
	int idTablee;
	cout << "_________________________________" << endl;
	cout << "          STAFF WORKING          " << endl;
	cout << "_________________________________" << endl;

	data.dataStaff.displayTable();
	cout << endl;
	cout << "_________________________________" << endl;
	cout << "  Please choose one of these Table ID: ";
	cin >> idTablee;
	data.dataStaff.choiceTable(idTablee);

order_S:
	do {
		cout << "_________________________________" << endl;
		cout << "             1. Add dish         " << endl;
		cout << "             2. Cancle dish      " << endl;
		cout << "             3. Edit dish        " << endl;
		cout << "             4. List of dish     " << endl;
		cout << "             5. Pay the bill     " << endl;
		cout << "             0. Turn back        " << endl;
		cout << "_________________________________" << endl;
		cout << "Please Enter Your Choice: ";
		cin >> choice;
	} while (choice < 0 || choice > 8);
	switch (choice) {
	case 1:
	add_order:
		cout << "_________________________________" << endl;
		data.dataManager.showMenu();
		cout << endl;

		cout << "____________Add dish____________";
		data.dataStaff.getInforTable(idTablee, 1, data.dataManager.getMenu());

		do {
			cout << "    1. Continue Adding Another Order " << endl;
			cout << "    2. Turn back Order menu" << endl;
			cout << "    3. Turn back Staff menu" << endl;
			cout << "    4. Exit program" << endl;
			cout << " Please Enter Your Choice: ";
			cin >> choice;

			if (choice == 4) exit(0);

		} while (choice != 1 && choice != 2 && choice != 3);
		if (choice == 1) goto add_order;
		else if (choice == 2) goto order_S;
		else goto S;
		break;
	case 2: 
	delete_order:
		cout << "_________________________________" << endl;
		data.dataManager.showMenu();
		cout << endl;

		cout << "Enter ID of order you want delete: ";
		int __id; cin >> __id;
		data.dataStaff.getInforTable(idTablee, 2, data.dataManager.getMenu());
		do {
			cout << "   1. Continue Deleting Another Order " << endl;
			cout << "   2. Turn back Order menu" << endl;
			cout << "   3. Turn back Staff menu" << endl;
			cout << "   4. Exit program" << endl;
			cout << "   Please Enter Your Choice: ";
			cin >> choice;

			if (choice == 4) exit(0);

		} while (choice != 1 && choice != 2 && choice != 3);

		if (choice == 1) goto delete_order;
		else if (choice == 2) goto order_S;
		else goto S;
		break;
	case 3: { 
	edit_order:
		cout << "_________________________________" << endl;
		data.dataManager.showMenu();
		cout << endl;

		cout << "_________________________________" << endl;
		cout << " Enter ID of Dish you want to edit: ";
		int ___id = 0; cin >> ___id;

		data.dataStaff.getInforTable(idTablee, 3, data.dataManager.getMenu());

		do {
			cout << "   1. Continue Editing Another Order " << endl;
			cout << "   2. Turn back Order menu" << endl;
			cout << "   3. Turn back Staff menu" << endl;
			cout << "   4. Exit program" << endl;
			cout << "   Please Enter Your Choice: ";
			cin >> choice;

			if (choice == 4) exit(0);

		} while (choice != 1 && choice != 2 && choice != 3);

		if (choice == 1) goto edit_order;
		else if (choice == 2) goto order_S;
		else goto S;
		break;
	}

	case 4: // 4. Danh sách món đã đặt
		cout << "_________________________________" << endl;
		data.dataStaff.getInforTable(idTablee, 4, data.dataManager.getMenu());

		do {
			cout << "  1. Turn back Order menu" << endl;
			cout << "  2. Turn back Staff menu" << endl;
			cout << "  3. Exit program" << endl;
			cout << " Please Enter Your Choice: ";
			cin >> choice;

			if (choice == 3) exit(0);

		} while (choice != 1 && choice != 2);

		if (choice == 1) goto order_S;
		else goto S;
		break;

	case 5:
		cout << "_________________________________" << endl;
		data.dataStaff.getInforTable(idTablee, 5, data.dataManager.getMenu());
		cout << "_________________________________" << endl;
		break;

	case 0:
		goto S;
		break;

	default:
		break;
	}
}