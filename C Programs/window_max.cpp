# include<iostream>
using namespace std;

int main(){

    int arr[]={1,6,5,1,3,7,8};
    int len=sizeof(arr)/sizeof(arr[0]);
    int window_size=3;

    int num_cols=len-window_size+1;
    int *sum_arr=new int[num_cols];
    int sum;

    for (int i = 0; i < num_cols; i++)
    {
        sum=0;
        for (int j = 0; j < window_size; j++)
            sum+=arr[i+j];
        sum_arr[i]=sum;
    }
    
    for (int i = 0; i < num_cols; i++)
        cout<<sum_arr[i]<<'\t';
    cout<<endl;

    return 0;
}