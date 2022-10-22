//  Points
//  --> Like a virtual function a virtual destructor first calls the destructor of the derived class, then of the base class.
//  -->
//  -->
//  -->
//  -->

#include <iostream>
using namespace std;

class BaseClass
{
public:
    BaseClass()
    {
        cout << "Base class constructor." << endl;
    }
    virtual ~BaseClass()
    {
        cout << "Base class destructor." << endl;
    }
    virtual void printData()
    {
        cout << "In the base class" << endl;
    }
};

class Derived : public BaseClass
{

public:
    Derived()
    {
        cout << "Derived class constructor." << endl;
    }
    ~Derived()
    {
        cout << "Derived class destructor." << endl;
    }
    void printData()
    {
        cout << "In the base class" << endl;
    }
};

int main()
{
    BaseClass *baseOb2 = new Derived();

    cout << "Destructing" << endl;

    delete baseOb2;

    return 0;
}