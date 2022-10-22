//  Points
//  --> This phenomenon occurs in cases in which classes worl internally on pointers instead of variables.
//  --> When we invoke the default copy constructor for an object, the memory pointers within the class would point towards
//  --> the same address for all instances of the class. Therefore, modifying the contents of one pointer of an object would
//  -->  result in the modification of all the objects. This is shallow copy.
//  --> To avoid this we have to define our own copy constructor in which we allocate separate memories to the pointers. This is deep copy.

#include <iostream>
using namespace std;

class BaseClass
{
private:
    int *ptr;
    int data;

public:
    BaseClass() : data{0}, ptr{new int(0)}
    {
    }

    // Defining copy constructor. This will result in deep copy. Comment this to observe shallow copy.
    BaseClass(const BaseClass &baseObj)
    {
        ptr = new int();     // Declaring a separate memory for the pointer.
        *ptr = *baseObj.ptr; // Assgining value.
        data = baseObj.data;
    }

    void setPtr(int x)
    {
        *ptr = x;
    }

    void setData(int x)
    {
        data = x;
    }
    ~BaseClass()
    {
    }
    void printData()
    {
        cout << "data = " << data << " and *ptr = " << *ptr << endl;
    }
};

int main()
{
    BaseClass baseObj;
    baseObj.setData(10);
    baseObj.setPtr(20);
    cout << "Base Obj 1 data:" << endl;
    baseObj.printData();

    // Making a copy of the above.
    BaseClass baseObj2 = baseObj;

    baseObj2.setPtr(15);
    baseObj2.setData(36);

    cout << "Base Obj 1 data after changes:" << endl;
    baseObj.printData();

    cout << "Base Obj 2 data after changes:" << endl;
    baseObj2.printData();

    return 0;
}