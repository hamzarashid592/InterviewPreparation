// Points
// --> Friend functions can be used to test a class.
// --> A friend function can only access a particular class, not its parents or children.

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
    void printData()
    {
        cout << data << endl;
    }
    // Making the function func friend to this class so that private members can be accessed by it.
    friend void func(BaseClass &);
};

// Making a function that would access private members of BaseClass object.
void func(BaseClass &obj)
{
    obj.data = 20;
}

int main()
{
    BaseClass obj(10);
    obj.printData();
    func(obj);
    obj.printData();

    return 0;
}