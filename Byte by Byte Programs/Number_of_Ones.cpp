#include <iostream>
using namespace std;

//To get the number of ones in the binary representation.

int numberOfOnes(int num)
{
    int count = 0;
    while (num != 0)
    {
        count += num % 2; //To get the last bit of the number.
        num = num >> 1;   //To divide the number by 2.
    }
    return count;
}

int main()
{
    cout << numberOfOnes(9) << endl;
    cout << numberOfOnes(10) << endl;
    cout << numberOfOnes(18) << endl;
    cout << numberOfOnes(29) << endl;
    cout << numberOfOnes(35) << endl;
    cout << numberOfOnes(75) << endl;

    return 0;
}