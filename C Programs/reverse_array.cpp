# include<iostream>
using namespace std;

void swap(int &a,int &b){
    a=a+b;
    b=a-b;
    a=a-b;
}

int main(){

    int arr[]={1,6,5,1,3,7,8,10};
    int len=sizeof(arr)/sizeof(arr[0]);
    
    int half=len/2;

    for (int i = 0; i < len; i++)
        cout<<arr[i]<<'\t';
    cout<<endl;

    for (int i = 0; i < half; i++)
    {
        int j=len-(i+1);
        swap(arr[i],arr[j]);
    }
    
    for (int i = 0; i < len; i++)
        cout<<arr[i]<<'\t';
    cout<<endl;
    

    return 0;
}