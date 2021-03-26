// C++ program to print all  
// permutations with duplicates allowed  
#include <bits/stdc++.h> 
using namespace std; 
  
// Geek for Geeks method.
// Function to print permutations of string  
// This function takes three parameters:  
// 1. String  
// 2. Starting index of the string  
// 3. Ending index of the string.  
void permute(string a, int l, int r)  
{  
    // Base case  
    if (l == r)  
        cout<<a<<endl;  
    else
    {  
        // Permutations made  
        for (int i = l; i <= r; i++)  
        {  
  
            // Swapping done  
            swap(a[l], a[i]);  
            cout<<"The string "<<a<<endl;
            // Recursion called  
            permute(a, l+1, r);  
  
            //backtrack  
            swap(a[l], a[i]);  
        }  
    }  
}  
  
// My method.
void stringPermutation(string str,int last_index){
    
    string orig_str=str;
    while (1)
    {
        for (int i = 0; i <= last_index-1; i++)
        {
            swap(str[i],str[i+1]);
            cout<<str<<endl;
        }
        if (str==orig_str)
            break;
    }
}

int main()  
{  
    string str = "ABCD";  
    int n = str.size();  
    // permute(str, 0, n-1);  

    int last_index=str.length()-1;
    stringPermutation(str,last_index);

    return 0;  
}  