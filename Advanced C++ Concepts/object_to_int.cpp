// Points
// --> Changing an object to primitive data types like int, float etc.
// --> Overload the int(), float() etc. operators.

#include <iostream>
using namespace std;

class BaseClass
{
private:
    int data;
    float dd;

public:
    BaseClass() {}
    BaseClass(int x)
    {
        data = x;
    }

    BaseClass(int x, float y)
    {
        data = x;
        dd = y;
    }

    void printData()
    {
        cout << data << endl;
    }

    // Overloading the int() operator.
    operator int() const
    {
        return data;
    }
    // Overloading the float() operator
    operator float() const
    {
        return dd;
    }
};

int main()
{
    BaseClass classObj(35, 20.69);

    cout << typeid(classObj).name() << endl;

    int a = classObj;

    cout << typeid(a).name() << "\t" << a << endl;

    float b = classObj;

    cout << typeid(b).name() << "\t" << b << endl;

    return 0;
}