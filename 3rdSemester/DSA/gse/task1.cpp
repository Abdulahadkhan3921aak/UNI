#include <iostream>

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main() {
    const int size = 7;
    int arr[size] = {64, 34, 25, 12, 22, 11, 90};

    std::cout << "Unsorted array: ";
    printArray(arr, size);

    bubbleSort(arr, size);

    std::cout << "Sorted array: ";
    printArray(arr, size);

    return 0;
}

