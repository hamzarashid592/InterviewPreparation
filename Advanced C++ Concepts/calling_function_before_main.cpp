// Points
// --> There are two methods to call a function before main:
// --> 1:   Create an object of a class globally and invoke function in the class's constructor.
// --> 2:   Create a static attribute in a class and assign value to that attribute using the function.

#include <iostream>
using namespace std;

// ----------
// ----------
// Method 1:
// ----------
// ----------

// void func1()
// {
//     cout << "Inside the function." << endl;
// }

// class BaseClass
// {
// private:
//     int data;

// public:
//     BaseClass()
//     {
//         func1(); // Invoking function in constructor.
//     }
//     BaseClass(int x)
//     {
//         data = x;
//     }
//     ~BaseClass() {}
//     void printData()
//     {
//         cout << data << endl;
//     }
// };

// // Creating object globally.
// BaseClass baseObj1;

// ----------
// ----------
// Method 2:
// ----------
// ----------

class BaseClass
{
public:
    static int staticAttr; // Creating static attribute
    BaseClass(/* args */);
    ~BaseClass();
};

int func2()
{
    cout << "Inside the function" << endl;
    return 10;
}

int BaseClass::staticAttr = func2();

int main()
{

    cout << "Inside Main" << endl;

    return 0;
}