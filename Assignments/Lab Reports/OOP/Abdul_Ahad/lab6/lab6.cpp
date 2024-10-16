#include <iostream>

using namespace std;

class A
{
public:
    void print()
    {
        cout << "Class A" << endl;
    }
};

class F
{
public:
    void print()
    {
        cout << "Class F" << endl;
    }
};

class C : public A
{
public:
    void print()
    {
        cout << "Class C" << endl;
    }
};

class D : public C
{
public:
    void print()
    {
        cout << "Class D" << endl;
    }
};

class E : public C
{
public:
    void print()
    {
        cout << "Class E" << endl;
    }
};

class B : public A, public F
{
public:
    void print()
    {
        cout << "Class B" << endl;
    }
};

int main()
{
    A a;
    B b;
    C c;
    D d;
    E e;
    F f;

    a.print();
    b.A::print();
    b.F::print();
    c.print();
    d.print();
    e.print();
    f.print();

    return 0;
}