#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string str = "aaabcccdddddddddddddddddddddddd";

    string resultStr = "";

    char temp = str[0];
    int counter = 0;

    for (int i = 0; i < str.length(); i++)
    {

        if (str[i] == temp)
            counter++;
        else
        {
            resultStr += temp + to_string(counter);
            temp = str[i];
            counter = 1;
        }
    }
    resultStr += temp + to_string(counter);

    cout << resultStr << endl;

    return 0;
}