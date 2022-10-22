//  Points
//  --> dynamic_cast is a runtime cast which is used to find out the correct down cast at runtime.
//  --> requires polymorphic base class (atleast one virtual function)
//  --> Different from static cast in the way that it detects wrong cast at runtime whereas static cast does not have this feature.
//  --> Reduces performance asit does checking at runtime.
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
    virtual void printData()
    {
        cout << "In the BaseClass" << endl;
    }
};

class Derived1 : public BaseClass
{
private:
    int data1;

public:
    Derived1()
    {
    }
    Derived1(int x) : data1{x}
    {
    }
    ~Derived1() {}

    void printData()
    {
        cout << "In Derived1" << endl;
    }
};

class Derived2 : public BaseClass
{
private:
    int data2;

public:
    Derived2()
    {
    }
    Derived2(int x) : data2{x}
    {
    }

    ~Derived2() {}

    void printData()
    {
        cout << "In Derived2" << endl;
    }
};

int main()
{
    Derived1 d1(10);
    Derived2 d2(13);

    BaseClass *derived1ToBase = dynamic_cast<BaseClass *>(&d1); // Upcasting Derived --> Base
    BaseClass *derived2ToBase = dynamic_cast<BaseClass *>(&d2); // Upcasting Derived --> Base

    derived1ToBase->printData();

    // Some work done here.

    // Doing a valid downcast i.e. Derived1-->Base then Base-->Derived1
    Derived1 *basetoDerived1 = dynamic_cast<Derived1 *>(derived1ToBase); // Downcasting Base --> Derived

    if (basetoDerived1 == NULL)
        cout << "NULL";
    else
        cout << "Successful cast" << endl;

    // Doing a invalid downcast i.e. Derived2-->Base then Base-->Derived1
    Derived1 *basetoDerived2 = dynamic_cast<Derived1 *>(derived2ToBase); // Downcasting Base --> Derived

    if (basetoDerived2 == NULL)
        cout << "NULL" << endl;
    else
        cout << "Successful cast" << endl;

    // Casting to a reference type.
    Derived1 derived1Obj(18);

    try
    {
        Derived2 &derived2Obj = dynamic_cast<Derived2 &>(d1); // Invalid cast.
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}