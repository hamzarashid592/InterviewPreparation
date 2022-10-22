//  Points
//  --> There are two methods to count the number of set bits in a number.
//  --> Simple way in which we iterate the entire number and count ones.
//  --> This is tedios and numebr of iterations equal number of binary digits.
//  --> Brian Kernighan's Way in which we do the binary AND of a number with number-1.
//  --> In the second method the total number of iterations are very less i.e. equal to the number of ones in the number.

#include <iostream>
using namespace std;

int main()
{
    int number = 1025;
    int count = 0;
    int iterations = 0;

    // Simple way.
    // while (number)
    // {
    //     count = count + (number & 1);
    //     number = number >> 1;
    //     iterations++;
    // }
    // cout << "Number of ones are " << count << endl;
    // cout << "Total iterations " << iterations << endl;

    // Brian Kernighan's Way.
    while (number)
    {
        number = number & (number - 1);
        count++;
        iterations++;
    }
    cout << "Number of ones are " << count << endl;
    cout << "Total iterations " << iterations << endl;

    return 0;
}