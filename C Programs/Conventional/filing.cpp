// This file is to format hacker rank test cases to run in my laptop.
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
fstream new_file; 
new_file.open("buffer.txt",ios::in);   
if(!new_file) 
    cout<<"No such file";
else 
{
    char ch;
    cout<<"{\"";
    while (!new_file.eof()) 
    { 
        new_file >>std::noskipws>>ch; 
        
        // if ((int)ch==32)
        //     cout<<"\",\"";
        if ((int)ch==10)
            cout<<"\"}"<<endl<<"{\"";
        else
            cout << ch;
    }
    cout<<"\"}";
}
new_file.close();    
return 0;
}