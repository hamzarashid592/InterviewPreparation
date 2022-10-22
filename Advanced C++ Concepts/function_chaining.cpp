// Points
// --> In order to impress upon the order of calling specific methods of a class, we use function chaining.
// --> The functions must return references of the object for function chaining to work.

#include <iostream>
using namespace std;

class BaseClass
{
private:
    int a, b, c, d;

public:
    BaseClass() {}

    // Method 1: Chaining by using pointers.

    BaseClass *setA(int a)
    {
        this->a = a;
        return this;
    }

    BaseClass *setB(int b)
    {
        this->b = b;
        return this;
    }

    void printData1()
    {
        cout << "a = " << a << " b = " << b << endl;
    }

    // Method 2: Chaining by using references.
    BaseClass &setC(int c)
    {
        this->c = c;
        return *this;
    }

    BaseClass &setD(int d)
    {
        this->d = d;
        return *this;
    }

    void printData2()
    {
        cout << "c = " << c << " d = " << d << endl;
    }
};

int main()
{
    BaseClass obj;

    // Method 1: Chaining by using pointers.
    obj.setA(10)->setB(30)->printData1();

    // Method 2: Chaining by using references.
    obj.setC(45).setD(55).printData2();

    return 0;
}