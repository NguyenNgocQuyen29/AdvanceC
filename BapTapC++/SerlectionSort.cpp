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

int main() {
	int a[1000], n;
	cout << "Please enter number elements: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sortSelection(a, n);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}
