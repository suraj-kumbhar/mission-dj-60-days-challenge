#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

void swap(int arr[], int p, int q, int k) {
    for (int i = 0; i < k; i++) {
        int t = arr[p];
        arr[p] = arr[q];
        arr[q] = t;
        p++;
        q++;
    }
}


void leftRotate(int arr[], int k, int n) {
    int i = k;
    int j = n - k;
    while (i != j) {
        if (i < j) {
            swap(arr, k - i, k - i + j, k);
            j -= i;
        }
        else {
            swap(arr, k - i, k, k);
            i -= j;
        }
    }
    swap(arr, k - i, k, k);
}

/* Driver program to test above functions */
int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, n);
    cout << "\n";
    // Function calling
    leftRotate(arr, 2, n);
    printArray(arr, n);

    return 0;
}