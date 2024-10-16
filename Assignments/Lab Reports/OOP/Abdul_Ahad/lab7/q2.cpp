#include <iostream>
#include <string>
#include <vector>

class Department
{
public:
    std::string name;
};

class Student
{
public:
    std::string name;
    int age;

    Student(){

    }
    Student(std::string name, int age){
        this->name = name;
        this->age = age;
    }
};

class StudentRegistrationSystem
{
private:
    Student students;
    Department department;

public:

    StudentRegistrationSystem(){

    }

    StudentRegistrationSystem(std::string departmentName)
    {
        department.name = departmentName;
    }

    void registerStudent(Student student)
    {
        students = student;
    }

    Student getStudents() { return students; }
    Department &getDepartment() { return department; }
};

int main()
{
    StudentRegistrationSystem RegistrationSystem("Science");

    RegistrationSystem.registerStudent(Student("Muhammad Zain Ali", 20));

    Student students = RegistrationSystem.getStudents();
    std::cout << "Department: " << RegistrationSystem.getDepartment().name << std::endl;
    std::cout << "Students:" << std::endl;

    std::cout << students.name << " (" << students.age << ")" << std::endl;

    return 0;
}