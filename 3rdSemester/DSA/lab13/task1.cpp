#include <iostream>

struct Student {
    int id;
    std::string name;
    // Add other fields as needed
};

int partition(Student arr[], int low, int high) {
    int pivot = arr[high].id;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].id < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(Student arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    // Test the quickSort function
    const int size = 5;
    Student students[size] = {
        {3, "Alice"},
        {1, "Bob"},
        {4, "Charlie"},
        {2, "David"},
        {5, "Eve"}
    };

    std::cout << "Before sorting:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << students[i].id << ": " << students[i].name << std::endl;
    }

    quickSort(students, 0, size - 1);

    std::cout << "After sorting:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << students[i].id << ": " << students[i].name << std::endl;
    }

    return 0;
}
