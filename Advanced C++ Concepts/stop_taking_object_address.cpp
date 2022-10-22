// Points
// --> There are 2 methods to do so.

#include <iostream>
using namespace std;

// Method 1: Overloading & operator in the private specifier.

// class BaseClass
// {
// private:
//     int data;

//     BaseClass *operator&()
//     {
//         return this;
//     }

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

// Method 2: Deleting the & operator from the class.

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

    BaseClass *operator&() = delete;
};

int main()
{
    BaseClass obj(10);

    BaseClass *ptr = &obj;

    return 0;
}