#include <iostream>
#include <string>

using namespace std;

struct Course
{
    int Course_ID;
    string Course_Name;
    int Marks;
    Course *Head = this, *Tail = this, *Next = NULL;
};

struct Student
{
    int Student_ID;
    string Student_Name;
    string Department;
    int Semester;
    int Courses;
    Course course;
    int Marks;
};

void SetData(Student &S)
{
    cout << "\n\nCollecting Student Data" << endl
         << endl;
    cout << "Enter Student ID : ";
    cin >> S.Student_ID;
    cout << "Enter Student Name : ";
    cin.ignore();
    getline(cin, S.Student_Name);
    cout << "Enter Department : ";
    getline(cin, S.Student_Name);
    cout << "Enter Student Semester : ";
    cin >> S.Semester;
    cout << "Enter the number of Courses : ";
    cin >> S.Courses;

    for (int i = 0; i < S.Courses; i++)
    {
        cout << endl
             << endl;
        cout << "Course : " << i + 1 << endl
             << endl;

        cout << "Enter Course ID : ";
        cin >> S.course.Tail->Course_ID;
        cout << "Enter Course Name : ";
        cin.ignore();
        getline(cin, S.course.Tail->Course_Name);
        cout << "Enter Course Marks : ";
        cin >> S.course.Tail->Marks;
        S.course.Tail->Next = new Course;
        S.course.Tail = S.course.Tail->Next;
    }

    cout << endl
         << endl;
    cout << "Enter Marks : ";
    cin >> S.Marks;
    cout << endl;
}

void GetData(Student &S)
{
    cout << "\n\nDisplaying Student Data" << endl
         << endl;
    cout << "Student ID : " << S.Student_ID << endl;
    cout << "Student Name : " << S.Student_Name << endl;
    cout << "Department : " << S.Student_Name << endl;
    cout << "Student Semester : " << S.Semester << endl;
    cout << "Number of Courses : " << S.Courses << endl;

    for (int i = 0; i < S.Courses; i++)
    {
        cout << endl
             << endl;
        cout << "Course : " << i + 1 << endl
             << endl;
        cout << "Course ID : " << S.course.Head->Course_ID << endl;
        cout << "Course Name : " << S.course.Head->Course_Name << endl;
        cout << "Course Marks : " << S.course.Head->Marks << endl;
        S.course.Head = S.course.Head->Next;
    }
    cout << endl
         << endl;
    cout << "Marks : " << S.Marks << endl
         << endl;
}

int main()
{
    Student S;

    SetData(S);

    GetData(S);

    return 0;
}
