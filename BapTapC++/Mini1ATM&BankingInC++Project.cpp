#include <iostream> //is a standard library feature
#include <string>   //is a standard library

using namespace std;
class Bank {
private:
	char name[40], actype[40];
	int bal, acno;
public:
	Bank() {
		cout << "Enter Account Name: ";
		cin.getline(name, 40);
		cout << "Enter account Type: ";
		cin.getline(actype, 40);
		cout << "Enter Account no: ";
		cin >> acno;
		cout << "Enter Openning Balance: ";
		cin >> bal;
	}
	void diposit(int atm) {
		bal = bal + atm;
		cout << "Balance after deposit: " << bal << endl;
		system("pause");
	}
	void withdraw(int atm) {
		if (atm > bal) {
			cout << "Sorry your balance is less than amount...." << endl;
		}
		else {
			bal = bal - atm;
			cout << "Balance after withdraw: " << bal << endl;
			system("pause");
		}
	}
	void display() {
		cout << "_________Account Detail_________" << endl;
		cout << "Account Name: " << name << endl;
		cout << "Account Type: " << actype << endl;
		cout << "Account No: " << acno << endl;
		cout << "Current BAlance: " << bal << endl;
		cout << "________________________________" << endl;
		system("pause");
	}
};

int main() {
	Bank B;
	int amount, choice;
	do {
		system("cls");
		cout << "________Main Menu_________" << endl;
		cout << "1. Deposit Money" << endl;
		cout << "2. Withdraw Money" << endl;
		cout << "3. Display Account Detail" << endl;
		cout << "4. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Enter Amount to deposit: ";
			cin >> amount;
			B.diposit(amount);
			break;
		case 2:
			cout << "Enter Amount to withdraw: ";
			cin >> amount;
			B.withdraw(amount);
			break;
		case 3:
			B.display();
			break;
		case 4:
			exit(0);
			break;
		default:
			cout << "Your choice is invalid.....";
			break;
		}
	} while (1);
	return 0;
}
