//  Points
//  --> reinterpret_cast can be used for the following:
//  --> To convert pointer of one data type to another data type (dangerous).
//  --> To work bytewise (like going through a structure byte by byte).
//  -->
//  -->

#include <iostream>
using namespace std;

// --------------------------------
// --------------------------------
// Case 1: Changing pointer types.
// --------------------------------
// --------------------------------

class Bananas
{
private:
    int data;

public:
    Bananas() {}
    Bananas(int x)
    {
        data = x;
    }
    ~Bananas() {}
    void eatBananas()
    {
        cout << "I eat bananas" << endl;
    }
};

class Mangoes
{
private:
    int data;

public:
    Mangoes() {}
    Mangoes(int x)
    {
        data = x;
    }
    ~Mangoes() {}
    void eatMangoes()
    {
        cout << "I eat mangoes" << endl;
    }
};

// --------------------------------
// --------------------------------
// Case 2: Working Bytewise.
// --------------------------------
// --------------------------------
struct testStruct
{
    int a;
    int b;
    char c;
    bool d;
};

int main()
{
    // --------------------------------
    // Case 1: Changing pointer types.
    // --------------------------------

    Bananas banObj;
    banObj.eatBananas();

    Mangoes manObj;
    manObj.eatMangoes();

    // Casting bananss to mangoes.
    Mangoes *bananaToMango = reinterpret_cast<Mangoes *>(&banObj);

    bananaToMango->eatMangoes();

    // --------------------------------
    // Case 2: Working bytewise.
    // --------------------------------

    testStruct data = {5, 34, 'p', false};
    // data.a = 5;
    // data.b = 34;
    // data.c = 'p';
    // data.d = false;

    // Casting the above structure to an interger pointer.
    int *intPtr = reinterpret_cast<int *>(&data);

    cout << *intPtr << endl;
    intPtr++;
    cout << *intPtr << endl;
    intPtr++;

    // Casting the int pointer to char pointer so that we can iterate byte wise.
    char *charPtr = reinterpret_cast<char *>(intPtr);

    cout << *charPtr << endl;
    charPtr++;

    // Casting to bool ptr.
    bool *boolPtr = reinterpret_cast<bool *>(charPtr);

    cout << *boolPtr << endl;

    return 0;
}