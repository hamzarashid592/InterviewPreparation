#include <iostream>
using namespace std;

int own_atoi(char *str)
{

    int res = 0;
    int i = 0;
    int sign = 1;

    for (; str[i] != '\0'; i++)
    {
        if (str[i] == '-')
        {
            sign = -1;
            continue;
        }
        res = res * 10 + (str[i] - '0');
    }

    return res * sign;
}

int main()
{
    char str[256] = "-9872";

    int num = own_atoi(str);
    cout << "Integer: " << num << endl;
}