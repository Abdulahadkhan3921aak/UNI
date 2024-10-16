#include <iostream>
#include <string>

using namespace std;

struct student
{
    string name;
    string reg;
    float m1, m2, m3, m4, m5;
    int sum;
    string CGPA;
};

int main()
{

    student s[3];

    for (int i = 0; i < 3; i++)
    {
        cout << "Enter Your Name : ";
        if(i > 0)
            cin.ignore();
        getline(cin,s[i].name);
        cout << "Enter Your Registraion Number : ";
        getline(cin,s[i].reg);
        cout << "Enter marks for subject 1 : ";
        cin >> s[i].m1;
        cout << "Enter marks for subject 2 : ";
        cin >> s[i].m2;
        cout << "Enter marks for subject 3 : ";
        cin >> s[i].m3;
        cout << "Enter marks for subject 4 : ";
        cin >> s[i].m4;
        cout << "Enter marks for subject 5 : ";
        cin >> s[i].m5;
        s[i].sum = float(s[i].m1 + s[i].m2 + s[i].m3 + s[i].m4 + s[i].m5) / 500 * 100 / 10;
        switch (s[i].sum)
        {
        case 10:
        case 9:
            s[i].CGPA = 'A';
            break;
        case 8:
            s[i].CGPA = "B+";
            break;
        case 7:
            s[i].CGPA = 'B';
            break;
        case 6:
            s[i].CGPA = "C+";
            break;
        case 5:
            s[i].CGPA = 'C';
            break;
        default:
            s[i].CGPA = 'F';
        }
    }

    for (int i = 0; i < 3; i++)
    {
        cout << "The CGAP of student " << s[i].name <<" registraion number "<< s[i].reg << " is : " << s[i].CGPA << endl;
    }

    return 0;
}