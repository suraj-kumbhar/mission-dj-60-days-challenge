/* C++ Program to search an element
   in a sorted and pivoted array*/
#include <bits/stdc++.h>
using namespace std;

/* Standard Binary Search function*/
int binarySearch(int arr[], int low,
                 int high, int key)
{
  int mid = low + (high - low) / 2;
  if (arr[mid] == key) {
    return mid;
  }
  if (arr[mid] > key)  {
    return binarySearch(arr, low, mid - 1, key);
  }
  else {
    return binarySearch(arr, mid + 1, high, key);
  }
  return -1;
}

/* Function to get pivot. For array 3, 4, 5, 6, 1, 2
   it returns 3 (index of 6) */
int findPivot(int arr[], int low, int high)
{
  if (low >= high) {
    return -1;
  }
  int mid = low + (high - low) / 2;
  if (mid < high && arr[mid] > arr[mid + 1]) {
    return mid;
  }

  if (mid > low && arr[mid] < arr[mid - 1]) {
    return mid - 1;
  }

  if (arr[mid] > arr[low]) {
    return findPivot(arr, mid + 1 ,  high);
  }
  else {
    return findPivot(arr,  low, mid - 1);
  }

}

/* Searches an element key in a pivoted
   sorted array arr[] of size n */
int pivotedBinarySearch(int arr[], int n, int key)
{
  int pivot = findPivot(arr, 0, n - 1);
  if (pivot == -1) {
    return binarySearch(arr, 0, n - 1,  key);
  }
  if (arr[pivot] == key) {
    return pivot;
  }
  if (arr[pivot] > key && arr[0] < key) {
    return binarySearch(arr, 0, pivot - 1, key);
  }
  else {
    return binarySearch(arr, pivot + 1, n,  key);
  }
  return -1;

}

/* Driver program to check above functions */
int main()
{
  // Let us search 3 in below array
  int arr1[] = {1, 2, 3, 4, 5};
  int n = sizeof(arr1) / sizeof(arr1[0]);
  int key = 3;

  // Function calling
  cout << "Index of the element is : " <<
       pivotedBinarySearch(arr1, n, key);

  return 0;
}