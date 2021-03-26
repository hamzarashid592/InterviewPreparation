# include<iostream>
using namespace std;

long func(int y, int z){
    long x=1;
    for (int i = 1; i <= z; i++)
        x=x*y;
    return x;
}

int main(){

    int y=5;
    int z=5;

    long ans=func(y,z);

    cout<<"The answer is "<<ans<<endl;


    return 0;
}