#include <iostream>

class D
{
public:
    virtual void print()
    {
        std::cout << "D";
    }
};

class E : public D
{
public:
    void print()
    {
        std::cout << "E";
    }
};

int main()
{
    D d, *d1;
    E e;

    d.print();
    d1 = &e;
    c->print();
    e.print();

    return 0;
}