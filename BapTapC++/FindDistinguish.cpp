#include <iostream>

#define MAX 100
using namespace std;

void enter_array(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "enter value of a [" << i << "] = ";
		cin >> a[i];
	}
}
void print_array(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}
void findDistinguish(int a[], int b[], int n, int &m) {
	m = 0;
	b[m] = a[0];//the first distinguish element
	m++;

	for (int i = 1; i < n; i++) {
		bool check = true;
		for (int j = i - 1; j >= 0; j--) {
			if (a[i] == a[j]) {
				check = false;
				break;
			}

		}
		if (check == true) {
			b[m] = a[i];
			m++;
		}
	}
}
void count(int a[], int b[], int n, int &m) {
	findDistinguish(a, b, n, m);
	for (int j = 0; j < m; j++) {
		int dem = 0;
		for (int i = 0; i < n; i++) {
			if (b[j] == a[i]) {
				dem++;
			}
		}
		cout << endl;
		cout << "Elements " << b[j] << " appear " << dem << " time";
	}
}



int main() {
	int m, n, a[MAX], b[MAX];
	/*cout << "enter number elements of array: ";
	cin >> n;
	cout << "Enter array" << endl;
	enter_array(a, n);
	cout << "_____________________________" << endl;
	cout << "Print array" << endl;
	print_array(a, n);*/
	int k = 5;
	int c[5] = { 1,2,3,4,2};

	count(c, b, k, m);

	return 0;


}