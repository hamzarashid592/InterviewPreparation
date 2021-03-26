# include<iostream>
using namespace std;

int char_to_int(char str[]){

    int num=0;
    int start,end;
    if (str[0]==45){
        start=1;
        end=5;
    }
    else
    {
        start=0;
        end=4;
    }
    
    for (int i =start; i < end; i++)
    {
        num=num*10;
        num=num+(str[i]-48);
        cout<<num<<endl;
    }
    if (str[0]==45)
        num=num*-1;
    return num;

}
int main(){

    char str[]="-1234";
    int ans=char_to_int(str);
    cout<<"The answer is "<<ans<<endl;
    

}