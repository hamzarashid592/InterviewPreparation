#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{

    string str1 = "boRed";
    string str2 = "rObEdw";

    bool indicator = true;

    int hashArray[26];
    for (int i = 0; i < 26; i++)
        hashArray[i] = 0;

    for (int i = 0; i < str1.length(); i++)
    {

        // For lower case letters.
        if (str1[i] >= 'a' && str1[i] <= 'z')
        {

            hashArray[int(str1[i]) - 97] += int(str1[i]);
            cout << int(str1[i]) - 97 << "\t";
        }
        // For upper case letters.
        else if (str1[i] >= 'A' && str1[i] <= 'Z')
        {

            hashArray[int(str1[i]) - 65] += int(str1[i] + 32); // Converting to lower case.
            cout << int(str1[i]) - 65 << "\t";
        }
    }

    cout << endl;

    for (int i = 0; i < str2.length(); i++)
    {

        // For lower case letters.
        if (str2[i] >= 'a' && str2[i] <= 'z')
        {

            hashArray[int(str2[i]) - 97] -= int(str2[i]);
            cout << int(str2[i]) - 97 << "\t";
        }
        // For upper case letters.
        else if (str2[i] >= 'A' && str2[i] <= 'Z')
        {
            hashArray[int(str2[i]) - 65] -= int(str2[i] + 32); // Converting to lower case.
            cout << int(str2[i]) - 65 << "\t";
        }
    }

    for (int i = 0; i < 26; i++)
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