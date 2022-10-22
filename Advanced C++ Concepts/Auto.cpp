// Points
// --> The auto keyword is used for type deuction i.e. to automatically get the data type.

#include <iostream>
#include <typeinfo>
using namespace std;

class BaseClass
{
public:
    BaseClass(int x, int y) {}
    BaseClass() {}
};

int main()
{

    auto w = 64;
    auto x = 20.3;
    auto y = 20.365;
    auto z = new BaseClass();

    // Using the typeid function to get the datatype.
    cout << typeid(w).name() << endl;
    cout << typeid(x).name() << endl;
    cout << typeid(y).name() << endl;
    cout << typeid(z).name() << endl; // This would print something like P9BaseClass. The P indicates a pointer.

    return 0;
}