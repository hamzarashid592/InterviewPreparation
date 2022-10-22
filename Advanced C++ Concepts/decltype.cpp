// Points
// --> The decltype checks the datatype of the entire expression in case of template functions.
// --> Rather than returning the value based on the datatype of a single parameter it returns based on the expression.

#include <iostream>
using namespace std;

template <typename T1, typename T2>
T1 add(T1 a, T2 b)
{
    return a + b;
}

template <typename T1, typename T2>
auto addWithDecltype(T1 a, T2 b) -> decltype(a + b)
{
    return a + b;
}

int main()
{
    // The datatype of the result is based on the datatype of the first parameter here i.e. T1.
    cout << "Without decltype" << endl;
    cout << add(1, 3.54) << endl;
    cout << add(3.54, 1) << endl;

    // The datatype of the result is based on the datatype of the expression a+b.
    cout << "With decltype" << endl;
    cout << addWithDecltype(1, 3.54) << endl;
    cout << addWithDecltype(3.54, 1) << endl;

    return 0;
}