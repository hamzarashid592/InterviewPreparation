# include<iostream>
# include<string>
using namespace std;

bool isPalindrome(string str){
    bool pal=true;
    for (int i = 0; i < str.length(); i++)
    {
        int j=str.length()-(i+1);
        if(str[i]==str[j])
            pal=pal&true;
        else
        {
            pal=pal&false;
            break;
        }
    }
    return pal;
}

int main(){

    string str="WOWY";

    if(isPalindrome(str))
        cout<<"We have a palindrome."<<endl;
    else
        cout<<"We DO NOT have a palindrome."<<endl;

    return 0;
}