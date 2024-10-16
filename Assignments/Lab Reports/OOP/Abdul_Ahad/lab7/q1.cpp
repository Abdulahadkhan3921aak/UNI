#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Address
{
private:
    string street;
    string city;
    string state;

public:
    Address() {}

    Address(string street, string city, string state)
    {
        this->street = street;
        this->city = city;
        this->state = state;
    }

    string getStreet() const
    {
        return street;
    }

    void setStreet(string street)
    {
        this->street = street;
    }

    string getCity() const
    {
        return city;
    }

    void setCity(string city)
    {
        this->city = city;
    }

    string getState() const
    {
        return state;
    }

    void setState(string state)
    {
        this->state = state;
    }
};

class Student
{
private:
    string name;
    Address *address = new Address("2c main", "Multan", "Punjab");
    ;

public:
    Student(string name)
    {
        this->name = name;
    }

    string getName() const
    {
        return name;
    }

    void setName(string name)
    {
        this->name = name;
    }

    string getAddress()
    {
        string S_address = "City is : " + address->getCity() + "\nSate is : " + address->getState() + "\nStreet is : " + address->getStreet();
        ;
        return S_address;
    }

    void setAddress(string City, string State, string Street)
    {
        this->address->setCity(City);
        this->address->setState(State);
        this->address->setStreet(Street);
    }

    int calculateYearOfBirth(int age) const
    {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        int currentYear = 1900 + ltm->tm_year;
        return currentYear - age;
    }
};

int main()
{

    Student student("Zain Ali");
    cout << "Name is : " << student.getName() << endl;
    cout << "Address is : \n"
         << student.getAddress() << endl;
    cout << "Year of birth is : " << student.calculateYearOfBirth(25) << endl;

    return 0;
}
