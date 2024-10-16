#include <iostream>
#include <random>
#include <time.h>

using namespace std;

void Treverse(int A[], int element)
{

	for (int i = 0; i < element; i++)
	{

		if (i == element - 1)
			cout << " " << A[i] << endl;

		else
			cout << " " << A[i] << " ,";
	}
}

void Insert(int A[], int size, int &element, int k, int item)
{
	if (size == element)
		return;
	for (int i = element - 1; i >= k; i--)
	{
		A[i + 1] = A[i];
		if (i == k)
		{
			A[i] = item;
			element++;
		}
	}
}

int main()
{

	srand(time(0));

	int size = 10, element = size - (size / 2);

	int *A = new int[size];
	int k, item;

	cout << "The Aray is : ";

	for (int i = 0; i < element; i++)
	{

		A[i] = rand() % 6000;
	}

	while (true)
	{

		system("cls");
		int c = -1;

		cout << "Enter 1 to trevers the array" << endl;
		cout << "Enter 2 to insert an element" << endl;
		cout << "Enter 0 to exit" << endl;

		cout << "Enter An option : ";
		cin >> c;

		switch (c)
		{
		case 0:
			exit(1);
			break;

		case 1:
			Treverse(A, element);
			cout << "Press Enter to continue";
			break;
		case 2:

			cout << "Enter the value to add : ";
			cin >> item;
			cout << "Enter the index : ";
			cin >> k;
			if ((k >= size) && (k > -1))
			{
				cout << "Wrong index";
			}
			else
				Insert(A, size, element, k, item);
			cout << "Press Enter to continue";
			break;

		default:
			cout << "Enter the choice Again" << endl;
		}
		cin.ignore();
		cin.ignore();
	}

	return 0;
}
