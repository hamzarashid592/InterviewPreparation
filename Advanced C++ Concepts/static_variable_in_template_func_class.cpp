// Points
// --> Behavior of static variable in template function
// --> Behavior of static variable in template class

#include <iostream>
using namespace std;

// Template function
template <typename T1>
void func(T1 x)
{
    static int var = 0;
    cout << var++ << endl;
}

// Template class.
template <typename T>
class BaseClass
{
public:
    static T var;
    void printData()
    {
        cout << ++var << endl;
    }
};

// Initializing static var.
template <class T>
T BaseClass<T>::var = 0;

int main()
{
    //---------------------- Behavior for template function ----------------------//

    cout << "Integer param" << endl;
    func(2);
    func(3);
    func(13);

    cout << "Float param" << endl;
    func(3.2);
    func(5.63);

    //---------------------- Behavior for template class ----------------------//
    cout << "-------Behavior for template class-------" << endl;

    cout << "Integer object" << endl;
    BaseClass<int> intOb1;
    intOb1.printData();
    intOb1.printData();
    BaseClass<int> intOb2;
    intOb2.printData();
    intOb2.printData();

    cout << "Float object" << endl;
    BaseClass<float> floatOb1;
    floatOb1.printData();
    floatOb1.printData();
    BaseClass<float> floatOb2;
    floatOb2.printData();
    floatOb2.printData();

    return 0;
}