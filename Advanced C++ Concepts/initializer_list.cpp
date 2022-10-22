// Points
//  --> Initializer lists are used in the following cases:
//      --> To initialize a constant attribute.
//      --> To initialize a reference attribute.
//      --> Initializing attributes which are themselves class objects.
//      --> Initialzing an attribute with the same variable name as the passed parameter.

#include <iostream>
using namespace std;

// Case 1: Initializing a constant attribute.
class BaseClass1
{
private:
    const int data;

public:
    BaseClass1() : data{0}
    {
        // data = 0;
    }
    BaseClass1(int x) : data{x}
    {
        // data = x;
    }
    void printData()
    {
        cout << data << endl;
    }
};

// Case 2: Initializing a reference attribute.
class BaseClass2
{
private:
    int &data;

public:
    BaseClass2(int x) : data{x}
    {
        // data = x;
    }
    void printData()
    {
        cout << data << endl;
    }
};

// Case 3: Initializing attributes which are themselves class objects.
class One
{
private:
    int data;

public:
    One(int x)
    {
        data = x;
    }
};

class Two
{
private:
    One oneData;

public:
    Two(One x) : oneData{x}
    {
        // oneData = x;
        // We can do this without initializer list by creating a default constructor in One.
    }
};

// Case 4: Initializing private attribute of a parent class from child class constructor.
class BaseClass3
{
private:
    int data1;

public:
    BaseClass3()
    {
    }

    BaseClass3(int x)
    {
        data1 = x;
    }
};

class ChildClass : public BaseClass3
{
private:
    int data2;

public:
    ChildClass(int x, int y) : BaseClass3{x}, data2{y}
    {
        // data1 = x;
        // data2 = y;
    }
};

// Case 5: Initialzing an attribute with the same variable name as the passed parameter.
class BaseClass4
{
private:
    int data;

public:
    BaseClass4(int data) : data{data}
    {
        // data = data;
    }
    void printData()
    {
        cout << data << endl;
    }
};

// Analyzing the sequence of constructors.
class BaseClass5
{
private:
    int data;

public:
    BaseClass5()
    {
        cout << "Base default constructor" << endl;
    }
    BaseClass5(int x)
    {
        data = x;
        cout << "Base parameterized constructor" << endl;
    }

    BaseClass5(const BaseClass5 &obj)
    {
        this->data = obj.data;
        cout << "Base copy constructor" << endl;
    }

    BaseClass5 &operator=(const BaseClass5 obj)
    {
        cout << "Base assignment operator" << endl;
        return *this;
    }
};

class SomeClass
{
private:
    BaseClass5 classObj;

public:
    SomeClass()
    {
        cout << "SomeClass default constructor" << endl;
    }
    SomeClass(BaseClass5 obj) : classObj{obj}
    {
        // classObj = obj;
        cout << "SomeClass parameterized constructor" << endl;
    }
};

int main()
{
    // Case 1:
    BaseClass1 baseObj1(20);
    baseObj1.printData();

    // Case 2:
    BaseClass2 baseObj2(30);
    baseObj2.printData();

    // Case 3:
    One oneObj(15);
    Two twoObj(oneObj);

    // Case 4:
    ChildClass childObj(25, 35);

    // Case 5:
    BaseClass4 baseObj4(68);
    baseObj4.printData();

    // Analyzing the sequence of constructors.
    cout << "Constructor Sequence:" << endl;

    BaseClass5 baseObj5(37);
    SomeClass someObj(baseObj5);

    return 0;
}