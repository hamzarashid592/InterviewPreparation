# include <iostream>
# include <vector>
# include <string>
# include "singly_linked_list_3.cpp"
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

int main(){
    
    string str={"cdcd"};

    for (int i = 0; i < str.length(); i++)
    {
        string temp="";
        for (int j = i; j < str.length(); j++)
        {
            temp+=str[j];
            cout<<temp<<"\t";
            cout<<hashFunction(temp)<<endl;
        }
        
    }
    


    return 0;
}