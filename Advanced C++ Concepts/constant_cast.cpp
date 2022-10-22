// Points
// --> Constant cast is used to change the value of a constant pointer i.e. used to change a const pointer to a normal pointer.

#include <iostream>
using namespace std;

void thirdPartLibFunc(int *k)
{
    cout << "In the function\n";
    cout << *(k) + 10 << endl;
}

int main()
{
    // --------------- First Use: To modify contents pointed by constant pointers ---------------

    // Valid case.
    int a = 10;
    const int *b = &a;
    int *c = const_cast<int *>(b);
    *c = 20;
    cout << a << endl;
    cout << *c << endl; // both should be same.

    // Invalid case:
    const int d = 10;
    const int *e = &d;
    int *f = const_cast<int *>(e);
    *f = 20;
    cout << d << endl;
    cout << *f << endl; // This will give ambiguous results.

    // --------------- Second Use: To use thrid party libraries that do not accept const pointers ---------------

    const int x = 10;
    const int *px = &x;

    thirdPartLibFunc(const_cast<int *>(px));
    cout << x << endl;

    return 0;
}