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

	Employee E1 , E2;

	cout << "Enter you First Name : ";
	getline(cin, E1.Fristname);
	
	cout << "Enter you Last Name : ";
	getline(cin, E1.LastName);
	
	cout << "Enter you Designation : ";
	getline(cin, E1.Designation);
	
	cout << "Enter your Date of birth : ";
	getline(cin, E1.DoB);
	
	cout << "Enter your City : ";
	getline(cin, E1.city);

	cout << "Enter your Salary : ";
	cin >> (E1.Salary);

	// Print The gathered info
	cout << endl << endl;
	cout << "Your information in Variable E1 is : \n\n";
	cout << "First Name : " << E1.Fristname << endl;
	cout << "Last Name :" << E1.LastName << endl;
	cout << "Designation : " << E1.Designation << endl;
	cout << "Salary :" <<setprecision(15) << E1.Salary << endl;
	cout << "Date of Birth : " << E1.DoB << endl;
	cout << "City :" << E1.city << endl;

	E2 = E1;

	cout << endl << endl;
	cout << "Your information in E2  is : \n\n";
	cout << "First Name : " << E1.Fristname << endl;
	cout << "Last Name :" << E1.LastName << endl;
	cout << "Designation : " << E1.Designation << endl;
	cout << "Salary :" << setprecision(15) << E1.Salary << endl;
	cout << "Date of Birth : " << E1.DoB << endl;
	cout << "City :" << E1.city << endl;

	return 0;
}