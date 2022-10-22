// Points
// --> Like a normal pointer, a function pointer is used to point to a function.
// -->
#include <iostream>
using namespace std;

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

// Function which takes a function ptr as a parameter along with some other interger params.
int genericFunc(int a, int b, int (*someFunc)(int, int))
{
    // Applying the passed function (someFunc) to the passed params (a and b).
    int c = someFunc(a, b);

    // Returning the result.
    return c;
}

// Function which returns a function ptr.
int (*funcGenerator(int type))(int, int)
{
    if (type == 1)
        return add;
    else
        return subtract;
}

// Making a function ptr as a typedef
typedef int (*arithFunc)(int, int);

// Making the compare function for the qsort function.
int compare(const void *a, const void *b)
{
    int l = *(const int *)a;
    int r = *(const int *)b;
    return l < r;
}

int main()
{
    // Normal call
    int c = add(2, 3);

    cout << "Normal function call: " << c << endl;

    // Declaring a function pointer.
    int (*funcPtr)(int, int) = add;

    // Call to function ptr.
    c = funcPtr(3, 4);

    cout << "Pointer function call: " << c << endl;

    // Passing a function as a paramter.
    cout << "Generic function call (add): " << genericFunc(2, 5, add) << endl;
    cout << "Generic function call (sub): " << genericFunc(6, 1, subtract) << endl;

    // Function which returns a function ptr.
    int (*someGenericFunc)(int, int);

    someGenericFunc = funcGenerator(1);
    cout << "Generated function result 1: " << someGenericFunc(4, 5) << endl;
    someGenericFunc = funcGenerator(2);
    cout << "Generated function result 2: " << someGenericFunc(4, 5) << endl;

    // Making an array of function pointers.
    int (*funcArray[2])(int, int);

    funcArray[0] = add;
    funcArray[1] = subtract;

    cout << "Function array 0: " << funcArray[0](4, 6) << endl;
    cout << "Function array 1: " << funcArray[1](4, 6) << endl;

    // Can also do this by using typedef
    arithFunc funcArray2[2] = {add, subtract};

    cout << "Function array typedef 0: " << funcArray2[0](10, 6) << endl;
    cout << "Function array typedef 1: " << funcArray2[1](10, 6) << endl;

    // The qsort function.
    int Arr[6] = {44, 68, 3, 94, 46, 3};
    int arrSize = sizeof(Arr) / sizeof(Arr[0]);

    qsort(Arr, arrSize, sizeof(Arr[0]), compare);

    cout << "Sorted array from the qsort function:\n";

    for (int i = 0; i < arrSize; i++)
    {
        cout << Arr[i] << "\t";
    }

    return 0;
}