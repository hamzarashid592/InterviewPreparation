#include <iostream>
using namespace std;

int main()
{

    int arr1[] = {1, 3, 6, 10, 14, 19};
    int arr2[] = {2, 4, 11, 21};

    int len1 = sizeof(arr1) / sizeof(int);
    int len2 = sizeof(arr2) / sizeof(int);

    int l = len1 + len2;

    int m1, m2;

    for (int i = 0; i <= l / 2; i++)
    {
        if (arr1[i] < arr2[i])
        {
            m1 = arr1[i];
            m2 = arr2[i];
        }
        else
        {
            m1 = arr2[i];
            m2 = arr1[i];
        }
    }
    if (l % 2 == 0)
        cout << "Median of two arrays is " << (m1 + m2) / 2.0 << endl;
    else
        cout << "Median of two arrays is " << m2 << endl;

    return 0;
}