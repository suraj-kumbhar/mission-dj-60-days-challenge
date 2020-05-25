#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}



void leftRotate(int arr[], int k, int n) {
    k = k % n;
    int gcd = __gcd(n, k);
    int j = 0;
    int d = 0;
    for (int i = 0; i < gcd; i++) {
        j = i;
        int temp = arr[j];
        while (1) {
            d = (j + k) % n;
            if (d == i) {
                break;
            }
            arr[j] = arr[d];
            j = d;
        }
        arr[j] = temp;
    }
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