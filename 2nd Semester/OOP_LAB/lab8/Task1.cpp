#include <iostream>

using namespace std;

class Add{
    int x = 5, y = 20;

public:
    void display() // overridden function
    {
        cout << "Value of x is : " << x + y << endl;
    }
};

class Substract : public Add{
    int y = 10, z = 30;

public:
    void display() {// overridden function
        cout << "Value of y is : " << y - z << endl;
    }
};
int main()
{
    Add *m;      // base class pointer .it can only access the base class members
    Substract s; // making object of derived class
    m = &s;
    m->display(); // Accessing the function by using base class pointer
    return 0;
}