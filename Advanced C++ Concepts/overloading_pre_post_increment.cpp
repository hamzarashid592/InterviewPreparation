// Points
// --> Friend functions can be used to test a class.
// --> A friend function can only access a particular class, not its parents or children.

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

    // Overloading the pre increment operator.
    BaseClass &operator++()
    {
        data = data + 1;
        return *this;
    }

    // Overloading the post increment operator.
    BaseClass operator++(int dummy)
    {
        BaseClass temp = *this;
        this->data = this->data + 1;
        return temp;
    }
};

int main()
{

    BaseClass baseObj(12);

    baseObj.printData();

    ++baseObj;

    cout << "After the pre increment operation" << endl;
    baseObj.printData();

    baseObj++;

    cout << "After the post increment operation" << endl;
    baseObj.printData();

    return 0;
}