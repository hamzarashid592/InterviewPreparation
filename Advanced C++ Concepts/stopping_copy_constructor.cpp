// Points
// --> There are three methods for stopping a copy constructor in a class.

#include <iostream>
using namespace std;

// ------------- Method 1: Overloading the copy constructor and = operator in the private specifier.
// class BaseClass
// {
// private:
//     int data;

//     BaseClass(const BaseClass &obj) // copy constructor overload
//     {
//         data = obj.data;
//         // Can have some more code here.
//     }

//     BaseClass &operator=(const BaseClass rhs) // operator = overload
//     {
//         data = rhs.data;
//         return *this;
//     }

// public:
//     BaseClass() {}
//     BaseClass(int x)
//     {
//         data = x;
//     }
//     ~BaseClass() {}
// };

// ------------- Method 2: Overloading the copy constructor and = operator in the private specifier of a class and inheriting from that class.

// class StopCopy
// {
//     StopCopy(const StopCopy &obj)
//     {
//     }

//     StopCopy &operator=(const StopCopy obj)
//     {
//     }

// public:
//     StopCopy() {}
// };

// class BaseClass : public StopCopy
// {
// private:
//     int data;

// public:
//     BaseClass() {}
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

// ------------- Method 3: Deleting the copy constructor and = operator methods from the class.
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

    BaseClass(const BaseClass &obj) = delete;
    BaseClass &operator=(const BaseClass obj) = delete
};

int main()
{
    BaseClass obj1(10);
    BaseClass obj2(obj1);  // error due to deletion of copy constructor
    BaseClass obj3 = obj1; // error due to deletion of copy constructor
    BaseClass obj4(20);

    obj1 = obj4; // error due to deletion of assignment operator

    return 0;
}