#include <iostream>
using namespace std;
/*SẮP XẾP CHỌN
Gồm  2 vòng lặp:
		vòng 1: lặp qua mảng 1 lần tìm phần được vị trí của phần tử nhỏ nhất
		đổi chỗ vị trí của phần tử đó với phần tử đầu của mảng
*/
void sortSelection(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int pos_min = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[pos_min]) {
				pos_min = j;
			}
		}
		swap(a[i], a[pos_min]);
	}
}
/*
* Bubble Sort
* So sánh 2 phần tử liền kề, phần tử nào nhỏ hơn thì swap luôn, sau mỗi vòng lặp sẽ có 1 phần tử đưa về đầu (cuối) dãy.
*/
void bubleSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) { //sau mỗi bước sẽ đưa phần tử lớn hơn về vị trí cuôii cùng , tức là sau i lần sẽ có i cái, nên không cần duyện i phânf tử đó nữa
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
			}
		}
	}
}
/*
* Insertion Sort
* Tư tưởng: ở mỗi bước của thuật toán sẽ cố gắng đưa phần tử ở vị trí hiện tại về đúng vị trí bằng cách chèn nó vào dãy các phần tử đứng trước nó sao cho đúng thứ tự
*/
void insertSort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		int x = a[i], pos = i - 1;
		while (pos >= 0 && x < a[pos]) {
			a[pos + 1] = a[pos];
			--pos;
		}
		a[pos + 1] = x;
	}
}
int main() {
	int a[1000], n;
	cout << "Please enter number elements: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	bubleSort(a, n);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}

