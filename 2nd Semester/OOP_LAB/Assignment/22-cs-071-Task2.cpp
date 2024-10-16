#include <iostream>
#include <string>

using namespace std;

struct students
{
    string name;
    float marks;
    char grade;
};

char Calculate(float _marks)
{
    char G;
    switch (int(_marks / 10))
    {
    case 10:
        G = 'A';
        break;
    case 9:
        G = 'A';
        break;
    case 8:
        G = 'B';
        break;
    case 7:
        G = 'C';
        break;
    case 6:
        G = 'D';
        break;
    default:
        G = 'F';
        break;
    }

    return G;
}

int main()
{
    students s[5];

    cout << "Collecting Data : \n";
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter the name of student " << i + 1 << " : ";
        getline(cin, s[i].name);
        cout << "Enter the marks of student " << i + 1 << " : ";
        cin >> s[i].marks;
        cin.ignore();
        s[i].grade = Calculate(s[i].marks);
    }

    cout << "Printing Data : \n";
    for (int i = 0; i < 5; i++)
    {
        cout << "The name of student " << i + 1 << " is : " << s[i].name << endl;
        cout << "The marks of student " << i + 1 << " are  : " << s[i].marks << endl;
        cout << "The Grade of student " << i + 1 << " is  : " << s[i].grade << endl;
    }

    return 0;
}