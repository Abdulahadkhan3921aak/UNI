#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int countOnes(int *arr, int size)
{
    int count = 0;
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == 1)
        {
            count = size - mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return count;
}

int main()
{
    srand(time(0)); // Seed the random number generator with current time

    const int SIZE = 15; // Change the size of the array as per your requirement
    int *arr = new int[SIZE];

    // Generate random binary digits
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % 2;
    }

    int onesCount = countOnes(arr, SIZE);

    cout << "\n\n";

    cout << "Number of 1's in the array: " << onesCount << endl;

    cout << "\n\n";

    return 0;
}
