// Points
// --> Friend functions can be used to test a class.
// --> A friend function can only access a particular class, not its parents or children.

#include <iostream>
using namespace std;

class BaseClass
{

public:
    static int data;
    BaseClass()
    {
        cout << "Iteration Number: " << data << endl;
        data++;
    }
    BaseClass(int x)
    {
        data = x;
    }
    ~BaseClass()
    {
        data--;
        cout << "Reverse Iteration " << data << endl;
    }
    void printData()
    {
        cout << data << endl;
    }
};

int BaseClass::data = 0;

int main()
{
    BaseClass objArr[10];

    return 0;
}