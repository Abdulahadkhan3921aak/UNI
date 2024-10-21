#include <iostream>
using namespace std;

// Function to merge two sorted subarrays and count inversions
int merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left; // Index for left subarray
    int j = mid + 1; // Index for right subarray
    int k = left; // Index for merged subarray
    int inversions = 0; // Count of inversions

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inversions += (mid - i + 1); // Count inversions
        }
    }

    // Copy the remaining elements of left subarray
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy the remaining elements of right subarray
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy the merged elements back to the original array
    for (int p = left; p <= right; p++) {
        arr[p] = temp[p];
    }

    return inversions;
}

// Function to perform merge sort and count inversions
int mergeSort(int arr[], int temp[], int left, int right) {
    int inversions = 0;

    if (left < right) {
        int mid = (left + right) / 2;

        // Recursive calls to divide the array into subarrays
        inversions += mergeSort(arr, temp, left, mid);
        inversions += mergeSort(arr, temp, mid + 1, right);

        // Merge the sorted subarrays and count inversions
        inversions += merge(arr, temp, left, mid, right);
    }

    return inversions;
}

int main() {
    int arr[] = {5, 3, 2, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int *temp = new int[n]; // Temporary array for merging

    int inversions = mergeSort(arr, temp, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Number of inversions: " << inversions << endl;

    return 0;
}
