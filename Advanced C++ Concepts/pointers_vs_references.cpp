// Points
// --> Pointers and references have the following differences.

#include <iostream>
using namespace std;

int main()
{
    int i = 10;

    // 1. Pointers have their own memory addresses whereas references don't. They simply point to the variable.

    int &r = i;  // reference.
    int *p = &i; // pointer.

    cout << "Memory Addresses:\n";
    cout << "i\tr\tp\n";
    cout << &i << "\t" << &r << "\t" << &p << endl
         << endl;

    cout << "Values:\n";
    cout << "i\tr\tp\n";
    cout << i << "\t" << r << "\t" << p << endl
         << endl;

    // 2. Reassignment with dereferencing is not possible with references whereas it is with pointers.
    int var = 15;
    r = var;
    r = 16;
    cout << var << endl;
    p = &var;
    *p = 20;
    cout << var << endl;

    // 3. Pointers can have null values whereas references can't.
    // 4. We can apply arithmetic operations with pointers but can't with references.

    // 5. We have indirection with pointers but not with references.
    int **ptr = &p;
    int ***ptr1 = &ptr;

    int &r1 = r;
    int &r2 = r1;
    cout << r << "\t" << r1 << "\t" << r2 << endl; // r,r1 and r2 are the same thing but p, ptr and ptr1 are three different entities.

    return 0;
}