#include <iostream>

class test
{

private:
    float a;
    float b;

public:
    test(float a = 0, float b = 0)
    {
        this->a = a;
        this->b = b;
    }

    void print()
    {
        std::cout << "The value of " << this << " a is " << this->a << " and b is " << this->b << std::endl;
    }
};

int main()
{

    test *T1 = new test, T2(45, 78);
    T1->print();
    T2.print();
    return 0;
}