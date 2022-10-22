//  Points
//  --> Instead of defining all the constructors in case of many parameterized constructor we define as ingle constructor
//  --> and use that constructor in other constructors.
//  --> Hence, we're delegating a single constructor.
//  -->
//  -->

#include <iostream>
using namespace std;

class BaseClass
{
private:
    int data1, data2;

public:
    BaseClass();

    BaseClass(int x);

    BaseClass(int x, int y);

    ~BaseClass();
};

BaseClass::BaseClass() : BaseClass(0)
{
    cout << "Default constructor" << endl;
}

BaseClass::BaseClass(int x) : BaseClass(x, 0)
{
    cout << "Single parameter constructor" << endl;
}

BaseClass::BaseClass(int x, int y) : data1{x}, data2{y}
{
    cout << "Double parameter constructor" << endl;
}

BaseClass::~BaseClass()
{
}

int main()
{
    BaseClass baseObj;

    return 0;
}