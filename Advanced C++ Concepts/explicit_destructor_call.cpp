// Points
// --> Whenever we create an object, the object destructor is always called after main.
// --> By just calling the constructor ClassName(), the constructor and destructor will run conscutively.

#include <iostream>
using namespace std;

class BaseClass
{
private:
    int data;

public:
    BaseClass()
    {
        cout << "Constructor call" << endl;
    }

    ~BaseClass()
    {
        cout << "Destructor call" << endl;
    }
};

int main()
{
    // Just calling the constructor:
    cout << "Case 1" << endl;
    BaseClass();

    cout << "Case 2" << endl;
    // Calling constructor explicitly by creating object.
    BaseClass obj;
    cout << "Calling the destructor" << endl;
    obj.~BaseClass();
    cout << "End of main" << endl;

    return 0;
}