#include <iostream>
using namespace std;

class Test

{

    static int x;

    int *ptr;

    int y;
};

int main()
{

    Test t;

    cout << sizeof(t) << " ";

    cout << sizeof(Test *);

    cout << endl;
    int a;
    cout << sizeof(a) << endl;
}

// #include <iostream>

// class Test

// {

// public:
//     int i;

//     void get();
// };

// void Test::get()

// {

//     std::cout << "Enter the value of i: ";

//     std::cin >> i;
// }

// Test t; // Global object

// int main()

// {

//     Test t; // local object

//     t.get();

//     std::cout << "value of i in local t: " << t.i << 'n';

//     ::t.get();

//     std::cout << "value of i in global t: " << ::t.i << 'n';

//     return 0;
// }

// #include <iostream>
// using namespace std;

// int main()
// {
//     // local variable declaration:
//     int x = 1;

//     switch (x)
//     {
//     case 1:
//         cout << "Hi!" << endl;
//         break;
//     default:
//         cout << "Hello!" << endl;
//     }
// }

// #include <iostream>

// using namespace std;
// main()
// {
//     int i;

//     char s[] = "hello";

//     for (i = 0; s[i]; ++i)
//         ;
//     cout << i << endl;

//     i = 0;

//     while (s[i++])
//         ;
//     cout << i;
// }

#include <iostream>
using namespace std;
// int main()
// {

//     int i = 0;

// lbl:

//     cout << "Afiniti";

//     i++;

//     if (i < 5)

//     {

//         goto lbl;
//     }

//     return 0;
// }

// int main()

// {

//     for (int i = 1; i <= 2; i++)

//     {

//         for (int j = i; j <= 2; j++)

//             cout << i << '@';
//     }
// }

// #include <iostream>

// using namespace std;

// class Empty
// {
// };

// int main()

// {

//     cout << sizeof(Empty);

//     return 0;
// }

// #include <iostream>
// using namespace std;
// int main()
// {
//     int a = 5;
//     auto check = [&]()
//     {
//         a = 10;
//     };
//     check();
//     cout << "Value of a: " << a << endl;
//     return 0;
// }

// #include <iostream>
// using namespace std;
// int main()
// {
//     int a = 5;
//     auto check = [=]()
//     {
//         a = 10;
//     };
//     check();
//     cout << "Value of a: " << a << endl;
//     return 0;
// }

// #include <iostream>
// using namespace std;
// int main()
// {
//     int a = 5;
//     auto check = [](int x)
//     {
//         if (x == 0)
//             return false;
//         else
//             return true;
//     };
//     cout << check(a) << endl;
//     return 0;
// }

// #include <iostream>
// using namespace std;
// int main()
// {
//     int a = 5;
//     int b = 5;
//     auto check = [&a]()
//     {
//         a = 10;
//         b = 10;
//     } check();
//     cout << "Value of a: " << a << endl;
//     cout << "Value of b: " << b << endl;
//     return 0;
// }