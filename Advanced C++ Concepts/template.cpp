//  Points
//  --> Friend functions can be used to test a class.
//  --> A friend function can only access a particular class, not its parents or children.
//  -->
//  -->
//  -->

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
    void printData()
    {
        cout << data << endl;
    }
};

int main()
{

    return 0;
}