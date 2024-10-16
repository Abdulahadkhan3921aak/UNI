#include <iostream>
#include <string>

using namespace std;

class SUM
{

	long double *a;

public:
	void setSize(int size)
	{
		delete[] a;
		a = new long double[size];
	}

	void display()
	{
		cout << "He is walking\n";
	}

	float sum(float a, float b)
	{
		return a + b;
	}

	float sum(float a, float b, float c)
	{
		return a + b + c;
	}

	long double sum(long double t[], int size)
	{
		long double ADD = 0;
		for (int i = 0; i < size; i++)
		{
			ADD += t[i];
		}
		return ADD;
	}

	void parse(string s)
	{
		int index = 0;
		for (int i = 0; i <= s.length(); i++)
		{
			if (s[i] == '+' ||  s[i] == '\0')
			{
				index++;
			}
		}
		setSize(index + 1);
		string e;
		int in;
		for (int i = 0; i <= s.length(); i++)
		{
			if (s[i] == '+' || s[i] == '\0')
			{
				a[in] = std::stof(e);
				in++;
				cout<<e<<endl;
				e = "";
			}
			else
			{
				e += s[i];
			}
		}

		cout << "The sum is : " << sum(a, index + 1) << endl;
	}
};

int main()
{

	SUM s;

	string str;

	cout << "Enter a string to perform summition on : \n";

	getline(cin, str);

	s.parse(str);

	return 0;
}
