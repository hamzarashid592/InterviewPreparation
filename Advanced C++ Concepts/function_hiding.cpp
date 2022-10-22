// Points
// -->  Function hiding happens because of function overriding.
// -->  Base and derived classes have a same named function but they differ in the parameters. Whenever we'll invoke
// -->  function from derived object, the derived class function would be called irrespective of the params passed.
// -->  This is function hiding. We avoid this by using the using keyword.

#include <iostream>
using namespace std;

class BaseClass
{

public:
    BaseClass() {}

    void printData(int i)
    {
        cout << "In the base class" << endl;
    }
};

class Derived : public BaseClass
{
public:
    using BaseClass::printData;

    void printData(char c)
    {
        cout << "In the derived class" << endl;
    }
};

int main()
{
    Derived d;
    d.printData(20);
    d.printData('2');

    return 0;
}