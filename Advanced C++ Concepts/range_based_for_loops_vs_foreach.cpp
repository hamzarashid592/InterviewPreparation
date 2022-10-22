// Points
// -->  Range based for loops can only used to iterate arrays and we cannot change the range.
// -->  For iterating vectors / maps we would used foreach. Range can be changed here.
// -->  foreach uses a lambda expression or a function to define its body i.e. applies a function to every element in the sequence.

#include <iostream>
#include <vector>
#include <algorithm> //For for_each loop.
using namespace std;

// CAN'T do this:
// template <typename T1>
// void print(T1 i)
// {
//     cout << i << "\t";
// }

void print(int i)
{
    cout << i << "\t";
}

int main()
{

    vector<int> vec;
    int arr[10];

    // Normal for loop to populate the data structures.
    for (int i = 0; i < 10; i++)
    {
        vec.push_back(i * 3);
        arr[i] = i * 2;
    }

    // Range based for loop:
    for (auto &&i : arr)
    {
        cout << i << "\t";
    }
    cout << endl;

    // For each with lambda:
    for_each(vec.begin(), vec.end(),
             [](int i)
             {
                 cout << i << "\t";
             });

    cout << endl;

    // For each with normal function:
    for_each(vec.begin(), vec.end(), print);

    cout << endl;

    return 0;
}