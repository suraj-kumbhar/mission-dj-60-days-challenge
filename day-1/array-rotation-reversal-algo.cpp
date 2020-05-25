#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}



void leftRotate(int arr[], int k, int n) {
    for(int i=0;i<k/2;i++) {
        int t=arr[k-1-i];
        arr[k-1-i]=arr[i];
        arr[i]=t;
    }
    // printArray(arr, n);
    // cout<<"\n";
    for(int i=k;i<(k+n)/2;i++) {
        int  t=arr[i];
        arr[i]=arr[n-1-i+k];
        arr[n-1-i+k]=t;
    }
    // printArray(arr, n);
    // cout<<"\n";
    for(int i=0;i<n/2;i++) {
        int t=arr[i];
        arr[i]=arr[n-1-i];
        arr[n-1-i]=t;
    }
}

/* Driver program to test above functions */
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, n);
    cout<<"\n";
	// Function calling
	leftRotate(arr, 2, n);
	printArray(arr, n);

	return 0;
}