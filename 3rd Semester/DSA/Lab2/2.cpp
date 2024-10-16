#include <iostream>
#include <random>
#include <time.h>

using namespace std;

int main()
{

	srand(time(0));

	int size = 5;

	int *A = new int[size];

	cout << "The Aray is : ";

	for (int i = 0; i < size; i++)
	{

		A[i] = rand() % 6000;

		if (i == size - 1)
		{
			cout << " " << A[i] << endl;
		}
		else
			cout << " " << A[i] << " ,";
	}

	int max = -INT_MAX, min = INT_MAX;

	for (int i = 0; i < size; i++)
	{
		if (A[i] > max)
		{
			max = A[i];
		}

		if (A[i] < min)
		{
			min = A[i];
		}
	}

	cout << "The Minimum Value in the Array is : " << min << endl;
	cout << "The Maximum Value in the Array is : " << max << endl;

	return 0;
}
