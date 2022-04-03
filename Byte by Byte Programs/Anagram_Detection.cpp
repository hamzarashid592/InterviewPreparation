#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{

    string str1 = "bored";
    string str2 = "robede";

    bool indicator = true;

    int hashArray[23];
    for (int i = 0; i < 23; i++)
        hashArray[i] = 0;

    for (int i = 0; i < str1.length(); i++)
        hashArray[int(str1[i]) - 96] += str1[i];

    for (int i = 0; i < str2.length(); i++)
        hashArray[int(str2[i]) - 96] -= str2[i];

    for (int i = 0; i < 23; i++)
        if (hashArray[i] != 0)
        {
            indicator = indicator * false;
            break;
        }

    if (indicator == true)
        cout << "Anagram" << endl;
    else
        cout << "Not an Anagram" << endl;

    return 0;
}