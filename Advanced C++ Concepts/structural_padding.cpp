#include <iostream>
using namespace std;

struct StructA
{
    int a;
    int b;
    double c;
};

struct StructB
{
    char a;
    StructA c;
    char b;
};

int main()
{
    cout << sizeof(StructA) << endl;
    cout << sizeof(StructB) << endl;

    return 0;
}