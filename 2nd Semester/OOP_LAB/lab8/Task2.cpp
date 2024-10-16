#include <iostream>
using namespace std;

class Add
{
private:
    int x = 5, y = 20;

public:
    virtual void display()
    {
        cout << "Value of x is: " << x + y << endl;
    }
};

class Subtract : public Add
{
private:
    int y = 10, z = 30;

public:
    void display()
    {
        cout << "Value of y is: " << y - z << endl;
    }
};

class Animal
{
public:
    virtual void show() = 0; // Pure virtual function declaration.
};

class Man : public Animal
{
public:
    void show()
    {
        cout << "Man is a part of animal husbandry." << endl;
    }
};

int main()
{
    Add addObj;
    addObj.display();

    Animal *animalPtr;
    Man manObj;
    animalPtr = &manObj;
    animalPtr->show();

    Add *addPtr;
    Subtract subtractObj;
    addPtr = &subtractObj;
    addPtr->display();
    addPtr->Add::display();

    return 0;
}
