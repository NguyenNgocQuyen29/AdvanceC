#include <stdio.h>

int largestSequence(int a[], int n, int *num1, int *num2,int *num3) {
	int max = a[0] + a[1] + a[2];
	int cur = max;
	*num1 = a[0];
	*num2 = a[1];
	*num3 = a[2];
	for (int i = 3; i < n; i++) {
		cur = cur - a[i - 3] + a[i];
		if (cur > max) {
			max = cur;
			*num1 = a[i - 2];
			*num2 = a[i - 1];
			*num3 = a[i];
		}
	}return max;
}
int main() {
	int num1, num2, num3;
	int arr[] = { 2,9,1,0,2,1,9,7,-8,5,-70,80,16,-18};
	int n = sizeof(arr) / sizeof(arr[0]);

	int result = largestSequence(arr, n, &num1, &num2, &num3);
	printf("Day 3 so %d %d %d co tong lon nhat la: %d", num1,num2,num3,result);
}