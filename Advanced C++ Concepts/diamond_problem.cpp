//  Points
//  --> Friend functions can be used to test a class.
//  --> A friend function can only access a particular class, not its parents or children.
//  -->
//  -->
//  -->

#include <iostream>
using namespace std;

class A
{
public:
    int a;
};

class B : virtual public A
{
public:
    int b;
};

class C : virtual public A
{
public:
    int c;
};

class D : public B, public C
{
public:
    int d;
};

int main()
{
    D objD;
    objD.a = 10;

    cout << objD.a << endl;

    return 0;
}