#include <iostream>
#include <vector>

struct Employee {
    std::string name;
    int salary;
};

int partition(std::vector<Employee>& arr, int low, int high) {
    int pivot = arr[high].salary;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].salary >= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::vector<Employee>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    std::vector<Employee> employees = {
        {"John", 5000},
        {"Alice", 3000},
        {"Bob", 7000},
        {"David", 4000},
        {"Eva", 6000}
    };

    int n = employees.size();
    quickSort(employees, 0, n - 1);

    std::cout << "Sorted employees based on salary in descending order:\n";
    for (const auto& employee : employees) {
        std::cout << "Name: " << employee.name << ", Salary: " << employee.salary << std::endl;
    }

    return 0;
}
