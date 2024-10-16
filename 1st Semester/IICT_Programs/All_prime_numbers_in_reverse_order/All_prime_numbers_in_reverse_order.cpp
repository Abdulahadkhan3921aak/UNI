// All_prime_numbers_in_reverse_order.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
	int S, E ,Sum = 0 , counter = 0;
	float Avg;
	bool prime = false;
	
take:
	cout << "Enter the start point : ";
	cin >> S;

	cout << "Enter the end point : ";
	cin >> E;
	if (S > E) {
		cout << "The Start is greater then End\n";
		goto take;
	}

	for (int i = E; i >= S; i--) {
		prime = true;
		for (int j = 2; j <= (i / 2); j++) {

			
			if (i % j == 0 || i == 1) {
				prime = false;
				break;
			}
		}
	

		if (prime) {
			counter++;
			Sum += i;
			cout << i << endl;
		}

	}
	Avg = float(Sum / counter);
	cout <<"Average is : "<< Avg;

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
