//  Points
//  --> Namespaces are used to group entities like variables, functions and classes in a specific scope
//  -->
//  -->
//  -->
//  -->

#include <iostream>
using namespace std;

namespace ns1
{
    int intVal;
    void func();

    class A
    {
    private:
        /* data */
    public:
        void classFunc()
        {
            cout << "Class inside namespace" << endl;
        }
    };

} // namespace ns1

// Defining function outside namespace.
void ns1::func()
{
    cout << "Namespace function" << endl;
}

// Bringing one identifier outside namespace globally.
using ns1::A;

int main()
{
    int intVal = 14;
    ns1::intVal = 58;

    cout << intVal << endl;
    cout << ns1::intVal << endl;

    ns1::func();

    A objA;
    objA.classFunc();

    return 0;
}