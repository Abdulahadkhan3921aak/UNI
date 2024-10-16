#include <iostream>

using namespace std;

int binary_search(int arr[], int low, int high, int target)
{
    if (low > high)
    {
        return -1;
    }

    int mid = (low + high) / 2;

    if (arr[mid] == target)
    {
        return mid;
    }
    else if (arr[mid] > target)
    {
        return binary_search(arr, low, mid - 1, target);
    }
    else
    {
        return binary_search(arr, mid + 1, high, target);
    }
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int target = 7;

    int index = binary_search(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1, target);
    cout << "\n\n";
    if (index != -1)
    {
        cout << "The target element is found at index " << index << endl;
    }
    else
    {
        cout << "The target element is not found in the array" << endl;
    }

    cout << "\n\n";

    return 0;
}
