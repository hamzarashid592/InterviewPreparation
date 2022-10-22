//  Points
//  --> We can return multiple values from a function through a struct.
//  --> We can also do it via a tuple.
//  -->
//  -->
//  -->

#include <iostream>
#include <tuple>
using namespace std;

struct MyStruct1
{
    int a;
    string b;
    char c;
};

MyStruct1 func1()
{
    return {14, "hamza", 'i'};
}

tuple<int, string, char> func2()
{
    return make_tuple(25, "Bilal", 'q');
}

int main()
{
    cout << "Structure method" << endl;
    MyStruct1 testStruct1 = func1();
    cout << testStruct1.a << "\t" << testStruct1.b << "\t" << testStruct1.c << "\n";

    cout << "Tuple method" << endl;

    int num;
    string name;
    char code;

    tie(num, name, code) = func2();
    cout << num << "\t" << name << "\t" << code << "\n";

    return 0;
}