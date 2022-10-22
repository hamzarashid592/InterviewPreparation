#include <iostream>
using namespace std;

int main()
{
    int var = 10;

    int *ptr = &var;

    cout << "Var: " << var << endl;

    cout << "ptr: " << ptr << endl;

    cout << "*ptr: " << *ptr << endl;

    cout << "ptr[0]: " << ptr[0] << endl;

    cout << "ptr[1]: " << ptr[1] << endl;
}