#include <iostream>

using namespace std;

int main()
{
    system("cls");

    int size;

    cout << "Enter the size of Array : ";
    cin >> size;

    int *A = new int[size];

    for (int i = 0; i < size; i++)
    {
        cout << "\nEntre the Value for the Array at index " << i << " : ";
        cin >> A[i];
    }

    for (int i = 0; i < size - 1; i++)
    {
        int temp1;

        for (int j = i + 1; j < size; j++)
        {
            if (A[j] < A[i])
            {
                temp1 = A[j];
                A[j] = A[i];
                A[i] = temp1;
            }
        }
    }

    int median = (size % 2 != 0) ? size / 2 : -1;
    if (median == -1)
    {
        median = (A[size / 2] + A[(size / 2) - 1]) / 2;
    }
    else
    {
        median = A[median];
    }

    cout << "\n\nThe Array is : { ";
    for (int i = 0; i < size; i++)
    {

        if (i == size - 1)
        {
            cout << A[i] << " }\n\n"
                 << endl;
        }
        else
        {
            cout << A[i] << " , ";
        }
    }

    cout << "The median of the array is : " << median << endl
         << endl;
    return 0;
}