#include <iostream>
using namespace std;
int main()
{
    // ------------------
    // Checking even/odd.
    // ------------------
    // int num = 9;
    // int num2 = num & 1;

    // if (num2 == 0)
    //     cout << "Even number" << endl;
    // else
    //     cout << "Odd number" << endl;

    // --------------------
    // Multiplication by 2.
    // --------------------
    int num = 3;
    int num2 = num << 1;
    cout << num << " * 2 = " << num2 << endl;
    num2 = num << 2;
    cout << num << " * 4 = " << num2 << endl;
}