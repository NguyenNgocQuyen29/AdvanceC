#include <iostream>
#include <math.h>
#include <cstdio>

using namespace std;
//1. Liet ke phan tu: duyêt tat ca phan tu cua mang va goi ham de kiem tra phan tu do co thoa man tinh chat hay khhong
//a. Tim so nguyen to trong mang
/*
* Function: checkNt
* Decrition: to check element in array is prime number or not
* Input:
*	n - an interger datatype - value of number want to check
* Output:
*	return true if number is prime number
*/
bool checkNt(int n) {
	if (n < 2) return false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return true;
}
//2. tim max & min trong mang
/*
* Function: findMaxMin
* Description: this function is used to find max or min in array.
* Input:
*	a - array want to find max or min
*	n - number of elements of array
* Ouput:
*	return max or min in array
*/
void findMaxMin(int a[], int n) {
	int max = a[0], min = a[0];
	for (int i = 0; i < n; i++) {

		if (a[i] > max) {
			max = a[i];
		}
		if (a[i] < min) {
			min = a[i];
		}
	}
	cout << "Max is:" << max << " Min is: " << min;
}
//3. Tim so cap trong mang thoa man dieu kien
//a. Co tong bang mot so cho truoc
/*
* Funtion: findSum
* Description: this function is used to find the number of pairs in the array ,their sum is K
* Input:
*	a - array
*	n - number of elements in array
*	K
* Output:
*	dem - number of pairs in the array that their sum is K
*/
void findSum(int a[], int n, int k) {
	int dem = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] + a[j] == k) {
				++dem;
			}
		}
	}
	cout << "So cap co tong la K la: " << dem;
}
//4. Day Fabonacci va mang 1 chieu
//a. In ra n so Fabonacci đầu tiên
/*
* Function: printFabonacci
* Description: this function is used to print n first number of fibonacci series in array
* Input:
*	F - 
*	n - number of element
* Output:
*	n number of fibonacci series in array.
*/
void printFabonacci(int n) {
	long long F[100];
	F[0] = 0, F[1] = 1;
	for (int i = 2; i <= 92; i++) {
		F[i] = F[i - 1] + F[i - 2];
	}
	for (int i = 0; i < n; i++) {
		cout << F[i] << " ";
	}
}
//b. Kiem tra 1 so co phai la Fabonacci hay khong
/*
* Function: checkFabonacci
* Description: check any a number is Fabonacci number or not
* Input:
*	n - number want to check
* Output:
*	return YES if this number is Fabonacci number, No if this number isn't Fabonacci number
*/
void checkFabonacci(long long n) {
	long long F[100];
	F[0] = 0, F[1] = 1;
	for (int i = 2; i <= 92; i++) {
		F[i] = F[i - 1] + F[i - 2];
	}
	for (int i = 0; i <= 92; i++) {
		if (F[i] == n) {
			cout << "YES\n"; return;
		}
	}
	cout << "NO\n";
}
//5. Mảng đối xứng, lật ngược mảng 
//a. Kiem tra mang doi xung
bool checkSymmetry(int a[], int n) {
	int left = 0, right = n - 1;
	while (left <= right) {
		if (a[left] != a[right]) {
			return false;
		}
		++left, --right;
	}
	return true;
}
//b. Lật ngược mảng
void reserve(int a[], int n) {
	int left = 0, right = n - 1;
	while (left <= right) {
		swap(a[left], a[right]);
		++left, --right;
	}
}
//6. Liệt kê, đếm giá trị khác nhau
//a. Liet ke cac gia tri khac nhau trong mang theo thu tu xuat hien
void listArray(int a[], int n) {
	for (int i = 0; i < n; i++) {
		bool check = false;
		for (int j = 0; j < i; j++) {
			if (a[i] == a[j]) { check = true;}
		}
		if (!check) cout << a[i] << " ";
	}
}
//b. Đếm số giá trị khác nhau trong mảng
void countArray(int a[], int n) {
	int dem = 0;
	for (int i = 0; i < n; i++) {
		bool check = false;
		for (int j = 0; j < i; j++) {
			if (a[i] == a[j]) { check = true; }
		}
		if (!check) { ++dem; }
	}

	cout << "So gia tri khac nhau trong mang la: " << dem;
}
//c. Đêm so lan xuat hien cac phan tu trong mang
int cnt[10000001];
void count() {
	int a[100], n;
	cin >> n;
	int m = INT_MIN;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
		m = max(m, a[i]);
	}
	for (int i = 0; i <= m; i++) {
		if (cnt[i] != 0) {
			cout << "So lan xuat hien cua: " << i << " la " << cnt[i] << " lan" << endl;
		}
	}
}
//7. Xóa phần tử của mảng
//từ vị trí k + 1 tới cuối mảng dịch trái => khi xóa thì số lượng phần tử của mảng sẽ giảm 1
void deleteArray(int a[], int &n, int k) {
	for (int i = k; i < n; i++) {
		a[i] = a[i + 1];
	}
	--n;
}
//8. Thêm phần tử ở vị trí thứ k của mảng với giá trị a
//dịch phải từ vị trí k 1 đơn vị , rồi tăng kích thước của mảng, thêm giá trị vào
void addArray(int a[], int& n, int k, int o) {
	for (int i = n - 1; i >= k; i--) {
		a[i + 1] = a[i];
	}
	a[k] = o;
	++n;
}
//9. Trộn 2 dãy con đã sắp xếp thành dãy sắp xếp tăng dần
//dùng chỉ số i cho mảng a, j cho mảng b, m và n là phần tử của mảng a và b
void merge(int a[], int b[], int m, int n) {
	int i = 0, j = 0;
	while (i < m && j < n) {
		if (a[i] < b[j]) {
			cout << a[i] << " "; i++;
		}
		else {
			cout << b[j] << " "; j++;
		}
	}
	while (i < m) { cout << a[i] << " "; ++i; }
	while (j < n) { cout << b[j] << " "; ++j; }
}
//10. Dãy con liên tiếp 
// tìm dãy con liên tiếp các số giống nhau dầi nhất, dãy tăng dài nhất, dãy con liên tiêp liền kề là các phần tử nguyên tố

