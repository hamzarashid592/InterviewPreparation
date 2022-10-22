// Points
// -->  Why use the override keyword?
// -->  To emphasize upon a certain function that it is being overridden. This makes testing and code analysis easy and
//      compile time checks can be performed.

#include <iostream>
using namespace std;

class BaseClass
{
private:
    int data;

public:
    BaseClass() {}
    BaseClass(int x)
    {
        data = x;
    }
    ~BaseClass() {}
    virtual void print()
    {
        cout << "Base class" << endl;
    }
};

class Derived : public BaseClass
{
private:
    /* data */
public:
    Derived(/* args */)
    {
    }
    ~Derived()
    {
    }
    void print() override
    {
        cout << "Derived class" << endl;
    }
};

int main()
{
    BaseClass *a = new Derived();

    a->print();

    return 0;
}