#include <bits/stdc++.h> 
using namespace std; 

int hashFunction(string str){
    int hash=0;
    int sum=0;
    for (int i = 0; i < str.length(); i++)
    {
        hash+=((int)str[i]);
    }
    
    // while (hash!=0)
    // {
    //     sum+=hash%10;
    //     hash=hash/10;
    // }
    // return sum;
    return hash;
}

// Function to print all sub-strings of a given string.
void subStrings(string str){
    int length=str.length();
    // Here length-1 is the last index of the string.
    for (int j = 1; j < length-1; j++)
    {
        for (int i = 0; i <= length-j; i++)
        {
            cout<<str.substr(i,j)<<"\t"<<hashFunction(str.substr(i,j))<<endl;
        }
    }
    
}

int main(){

    string str="hamza_rashid";
    subStrings(str);

    return 0;
}