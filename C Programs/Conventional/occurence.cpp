# include<iostream>
using namespace std;

int bin_search(int arr[],int size,int val){
    int low=0;
    int high=size-1;
    int mid_index;
    while (low<=high)
    {
        mid_index=(high+low)/2;
        if(val==arr[mid_index])
            return mid_index;
        else if (val>arr[mid_index])
            // Taking the second half of the array.
            low=mid_index+1;
        else if (val<arr[mid_index])
            // Taking the first half of the array.
            high=mid_index-1;
    }
    return -1;
}

int first_occurence(int arr[],int size,int val){
    int low=0;
    int high=size-1;
    int mid_index;
    int res=-1;
    while (low<=high)
    {
        mid_index=(high+low)/2;
        if(val==arr[mid_index]){
            res=mid_index;
            // Taking the first half of the array.
            high=mid_index-1;
        }
        else if (val>arr[mid_index])
            low=mid_index+1;
        else if (val<arr[mid_index])
            high=mid_index-1;
    }
    return res;
}

int last_occurence(int arr[],int size,int val){
    int low=0;
    int high=size-1;
    int mid_index;
    int res=-1;
    while (low<=high)
    {
        mid_index=(high+low)/2;
        if(val==arr[mid_index]){
            res=mid_index;
            // Taking the second half of the array.
            low=mid_index+1;
        }
        else if (val>arr[mid_index])
            low=mid_index+1;
        else if (val<arr[mid_index])
            high=mid_index-1;
    }
    return res;
}

int main(){

    int arr[]={1,1,3,5,5,5,7,7,8,10};
    int value=1;
    int len=sizeof(arr)/sizeof(arr[0]);

    int idx=bin_search(arr,len,value);
    if(idx!=-1)
        cout<<"Element is at the "<<idx<<" index.\n";

    // Getting first occurence.
    idx=first_occurence(arr,len,value);
    if(idx!=-1)
        cout<<"First Occurence of the element is at the "<<idx<<" index.\n";

    // Getting last occurence.
    idx=last_occurence(arr,len,value);
    if(idx!=-1)
        cout<<"Last Occurence of the element is at the "<<idx<<" index.\n";

}