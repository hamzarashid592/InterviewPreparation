// Points
// -->  Explicit constructor prevents implicit call to the constructor.
// -->  Whenever some constructor takes only a single variable as parameter, we can initilize the object by passing the parameter
//      using the assignment operator. This is implicit call to the constructor.

#include <iostream>
using namespace std;

class BaseClass
{
private:
    int data;

public:
    BaseClass() {}
    /*explicit*/ BaseClass(int x)
    {
        data = x;
    }

    BaseClass(int x, int y);

    ~BaseClass() {}
    void printData()
    {
        cout << data << endl;
    }
};

void func(BaseClass obj)
{
    obj.printData();
}

int main()
{
    // Normal call to the constructor.
    BaseClass baseObj1(10);
    baseObj1.printData();

    // Implicit call to the constructor.
    BaseClass baseObj2 = 30;
    baseObj2.printData();

    // Normal call to the constructor.
    func(baseObj1);

    // Implicit call.
    func(55);

    return 0;
}