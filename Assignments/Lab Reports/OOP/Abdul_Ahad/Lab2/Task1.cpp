#include <iostream>
#include <string>
#include <random>
#include <time.h>

using namespace std;

int main()
{

    srand(time(0));

    int A[100];

    for (int i = 0; i < 100; i++)
    {
        A[i] = rand();
    }

    int max = A[0], min = A[0];

    for (int i = 0; i < 100; i++)
    {

        if (A[i] > max)
            max = A[i];

        if (A[i] < min)
            min = A[i];
    }

    cout<<"Max number is : "<<max<<endl;
    cout<<"Min number is : "<<min<<endl;
    return 0;
}