#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}


void leftRotateByOne(int arr[], int n) {
	int x = arr[0];
	for (int i = 0; i < n - 1; i++) {
		arr[i] = arr[i + 1];
	}
	arr[n - 1] = x;
}

void leftRotate(int arr[], int k, int n) {
	for (int i = 0; i < k; i++) {
		leftRotateByOne(arr, n);
	}
	// printArray(arr, n);
}

/* Driver program to test above functions */
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);

	// Function calling
	leftRotate(arr, 2, n);
	printArray(arr, n);

	return 0;
}