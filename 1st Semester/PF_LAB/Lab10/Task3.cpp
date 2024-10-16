#include<iostream>
#include <string>
#include<iomanip>

using namespace std;

struct Employee {

	string Fristname;
	string LastName;
	string Designation;
	string DoB;
	string city;
	float Salary = 0.0;
};

int main() {

	Employee E[10];
	
	for (int i = 0; i < 10; i++) {

		cout << "Enter The Information of the " << i + 1 << " Employee";

		cout << "Enter you First Name : ";
		getline(cin, E[i].Fristname);

		cout << "Enter you Last Name : ";
		getline(cin, E[i].LastName);

		cout << "Enter you Designation : ";
		getline(cin, E[i].Designation);

		cout << "Enter your Date of birth : ";
		getline(cin, E[i].DoB);

		cout << "Enter your City : ";
		getline(cin, E[i].city);

		cout << "Enter your Salary : ";
		cin >> (E[i].Salary);
	}

	for(int i = 0; i <10 ;i++){
	// Print The gathered info
	cout << endl << endl;
	cout << "Your information is of "<< i+1 <<" Employee: \n\n";
	cout << "First Name : " << E[i].Fristname << endl;
	cout << "Last Name :" << E[i].LastName << endl;
	cout << "Designation : " << E[i].Designation << endl;
	cout << "Salary :" << setprecision(15) << E[i].Salary << endl;
	cout << "Date of Birth : " << E[i].DoB << endl;
	cout << "City :" << E[i].city << endl;
}


	return 0;
}