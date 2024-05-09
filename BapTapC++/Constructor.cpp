#include <iostream> //is a standard library feature
#include <string>   //is a standard library

using namespace std;
class Player {
private:
	int age;
	char name[50], team[50];
public:
	Player() {
		cout << "Enter Name Player: ";
		cin.getline(name, 50);
		cout << "Enter Team Player: ";
		cin.getline(team, 50);
		cout << "Enter Age Player: ";
		cin >> age;
	}
	void input() {
		cout << "Enter Name Player: ";
		cin >> name;
		cout << "Enter Team Player: ";
		cin >> team;
		cout << "Enter Age Player: ";
		cin >> age;
	}
	void disPlay() {
		cout << "Name Player is: " << name << endl;
		cout << "Team Player is: " << team << endl;
		cout << "Age Payer is: " << age << endl;
	}
};
int main() {
	int choice;
	Player p;
	do {
		system("cls");
		cout << "_______Main Menu______" << endl;
		cout << "1. Input Player Data" << endl;
		cout << "2. Display player Data" << endl;
		cout << "3. Exit" << endl;
		cout << "Please Enter your chocie: ";
		cin >> choice;
		switch (choice) {
		case 1:
			p.input();
			break;
		case 2:
			p.disPlay();
		case 3:
			exit(1);
			break;
		default:
			cout << "Your Choice invalid!! please enter again";
		}
	} while(1);


	return 0;
}