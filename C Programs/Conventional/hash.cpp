# include <iostream>
# include <vector>
# include <string>
# include "singly_linked_list_3.cpp"
using namespace std;




int hashFunction(string str){
    int hash=0;
    for (int i = 0; i < str.length(); i++)
    {
        hash+=((int)str[i]*(i+1));
    }
    return hash%100;
}

int main(){
    
    // string str={"cdcd"};

    // for (int i = 0; i < str.length(); i++)
    // {
    //     string temp="";
    //     for (int j = i; j < str.length(); j++)
    //     {
    //         temp+=str[j];
    //         cout<<temp<<"\t";
    //         cout<<hashFunction(temp)<<endl;
    //     }
        
    // }

    int a=12345;
    int sum=0;
    
    while (a!=0)
    {
        sum+=a%10;
        a=a/10;
    }
    
    cout<<sum<<endl;



    return 0;
}