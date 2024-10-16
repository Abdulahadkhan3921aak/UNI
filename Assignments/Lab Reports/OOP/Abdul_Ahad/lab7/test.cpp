#include <string>
#include <iostream>

using namespace std;

class Department
{

private:
    std::string name_;

public:
    Department(std::string name)
    {
        name_ = name;
    }
    std::string GetName()
    {
        return name_;
    }
};

class Student
{
private:
    std::string name_;
    Department *department_;

public:
    Student(std::string name = "someone", Department *department = new Department("NULL"))
    {
        name_ = name;
        department_ = department;
    }
    std::string GetName()
    {
        return name_;
    }
    string GetDepartment()
    {
        return department_->GetName();
    }
};

class StudentRegistrationSystem
{

private:
    Student *student_;

public:
    void RegisterStudent(std::string name, Department *department)
    {
        student_ = new Student(name, department);
    }
    Student GetRegisteredStudent()
    {
        return *student_;
    }
};

int main()
{
    Student S;
    Department *D = new Department("Computer Science");
    StudentRegistrationSystem SR;
    SR.RegisterStudent("Abdul Ahad", D);
    S = SR.GetRegisteredStudent();
    cout << S.GetDepartment() << endl;
    cout << S.GetName() << endl;
    return 0;
}
