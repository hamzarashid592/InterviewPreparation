//  Points
//  --> Static cast is used in the following cases.
//  --> Case 1: Performing implicit conversion between data types. Makes code analysis easier as C style casting is hard to find.
//  --> Case 2: Performing conversion between class objects.
//  --> Case 3: Fails wrong conversions like chat* to int* at compile time.
//  --> Case 4: In case of private inheritance upward casting is not allowed. static casting makes sure that this doesn't happen whereas C style casting does not.
//  --> Case 5: Should never be used for confused down casts as it doesn't detect them as dynamic_cast does.
//  --> Case 6: Conversion to/from void* should be done from static cast.

#include <iostream>
using namespace std;

class MyClass
{
private:
    int data;

public:
    MyClass(int x) : data(x)
    {
        cout << "Conversion constructor" << endl;
    }

    operator string() const
    {
        cout << "Conversion to string operator" << endl;
        return to_string(data);
    }
};

class Base
{
};

class Derived : private Base
{
};

class BaseA
{
public:
    void print()
    {
        cout << "In Base" << endl;
    }
};

class DerivedA : public BaseA
{
public:
    void print()
    {
        cout << "In derived A" << endl;
    }
};
class DerivedB : public BaseA
{
public:
    void print()
    {
        cout << "In derived B" << endl;
    }
};

int main()
{
    // ------------
    // CASE 1:
    // ------------
    cout << "Case 1:" << endl;

    int intNum = 20;

    float floatNum1 = (float)intNum;              // C style casting
    float floatNum2 = static_cast<float>(intNum); // static cast

    cout << typeid(floatNum1).name() << endl;
    cout << typeid(floatNum2).name() << endl;

    // ------------
    // CASE 2:
    // ------------
    cout << "Case 2:" << endl;

    MyClass classObj1 = 27;
    string str = static_cast<MyClass>(classObj1);

    MyClass classObj2 = static_cast<MyClass>(17);

    // ------------
    // CASE 3:
    // ------------
    cout << "Case 3:" << endl;

    // Casting a char ptr to int ptr in c style.
    // char *charPtr1;
    // // int *intPtr1 = (int *)charPtr1; // Invalid casting.
    // // *intPtr1 = 14;                 // This will pass at compile time due to c style casting. However it give segmentation fault at runtime.

    // Casting a char ptr to int ptr using static cast.
    // char *charPtr2;
    // int *intPtr2 = static_cast<int *>(charPtr2); // This is will fail at compile time.

    // ------------
    // CASE 4:
    // ------------
    cout << "Case 4:" << endl;

    Derived derivedObj;

    // C style casting
    Base *derivedToBase1 = (Base *)&derivedObj; // Invalid conversion due to private inheritance.

    // static cast.

    // Base *derivedToBase2 = static_cast<Base *>(&derivedObj); // Fails at compile time.

    // ------------
    // CASE 5:
    // ------------
    cout << "Case 5:" << endl;

    DerivedA derivedObjA;
    derivedObjA.print();

    // Casting to base.
    BaseA *derivedObjAToBase = static_cast<BaseA *>(&derivedObjA); // Valid cast.. DerivedA-->Base
    derivedObjAToBase->print();

    // Casting base to derived B.
    DerivedB *baseToDerivedObjB = static_cast<DerivedB *>(derivedObjAToBase); // Invalid case but this will work.
    baseToDerivedObjB->print();

    // ------------
    // CASE 6:
    // ------------
    cout << "Case 6:" << endl;
    int a = 17;
    void *voidPtr = static_cast<void *>(&a);

    // cout << *voidPtr << endl; // Not allowed

    int *intPtr = static_cast<int *>(voidPtr);
    cout << *intPtr << endl;

    return 0;
}