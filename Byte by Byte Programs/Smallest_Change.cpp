#include <iostream>
using namespace std;

int smallestChange(int amount)
{
    int numCoins = 0;

    while (amount > 0)
    {

        if (amount >= 5)
        {
            amount = amount - 5;
            numCoins++;
        }
        else if (amount >= 2)
        {
            amount = amount - 2;
            numCoins++;
        }
        else if (amount >= 1)
        {
            amount = amount - 1;
            numCoins++;
        }
    }
    return numCoins;
}

int main()
{
    cout << "Min number of coins " << smallestChange(23) << endl;
    cout << "Min number of coins " << smallestChange(18) << endl;

    return 0;
}