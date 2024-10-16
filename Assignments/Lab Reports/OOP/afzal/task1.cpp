#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    const int SIZE = 100;
    int arr[SIZE];

    srand(time(nullptr));

    for (int i = 0; i < SIZE; i++)
        arr[i] = rand() % 1000 + 1;

    int minVal = arr[0];
    int maxVal = arr[0];

    for (int i = 1; i < SIZE; i++)
    {
        if (arr[i] < minVal)
            minVal = arr[i];
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }

    cout << "Minimum value: " << minVal << endl;
    cout << "Maximum value: " << maxVal << endl;

    return 0;
}
