# include<iostream>
# include<cmath>
using namespace std;

void swap(int &a, int &b){
    a=a+b;
    b=a-b;
    a=a-b;
}

// My entropy version of the problem.
int minimumSwaps1(int arr[],int len)
{
    int *ref_arr=new int[len];
    int *diff_arr=new int[len];
    int num_swaps=0;

    // for initializing the reference array.
    for (int i = 0; i < len; i++)
        ref_arr[i]=i+1;
    
    // Calculating the difference array.
    for (int i = 0; i < len; i++)
        diff_arr[i]=arr[i]-ref_arr[i];

    while (1)
    {

        for (int i = 0; i < len; i++)
            cout<<diff_arr[i]<<"\t";
        cout<<endl;            
        
        // Finding index of the max element if diff array
        int max_index;
        int max=0;
        
        for (int i = 0; i < len; i++)
            if (diff_arr[i]>max){
                max=diff_arr[i];
                max_index=i;
            }

        // Fnding index of min element in the diff array.
        int min_index;
        int min=max;
        for (int i = max_index; i < len; i++)
            if (diff_arr[i]<min){
                min=diff_arr[i];
                min_index=i;
            }   
        
        // Swapping the elements in arr.
        swap(arr[max_index],arr[min_index]);

        // Incrementing swap counter.
        num_swaps++;

        // Recalculating diff array.
        diff_arr[max_index]=arr[max_index]-ref_arr[max_index];
        diff_arr[min_index]=arr[min_index]-ref_arr[min_index];

        // Checking status of diff array.
        int reduction_sum=0;
        for (int i = 0; i < len; i++){
            reduction_sum+=diff_arr[i];
            if (diff_arr[i]!=0)
                break;
        }
        if (reduction_sum==0)
            break;
        // Pausing the loop
        int aa;
        cin >> aa;
    }

    // num_swaps=num_swaps-1;//A little catch to this :->
    return num_swaps;
}

int minimumSwaps2(int arr[],int len){

    int num_swaps=0;

    // Making a dictionary array that will map array values to indices.
    int *dict=new int[len+1];
    for (int i = 0; i < len; i++)
        dict[arr[i]]=i;
     

    // Now iterating through the array.
    for (int i = 0; i < len; i++)
        if (arr[i]!=i+1){
            int current_element=arr[i];
            swap(arr[i],arr[dict[i+1]]);
            swap(dict[current_element],dict[i+1]);

            num_swaps++;
            for (int  j = 0; j < len; j++)
                cout<<arr[j]<<"\t";
            cout<<endl;    
        }
    return num_swaps;
}

int main(){

    // int arr[]={7,1,3,2,4,5,6};
    int arr[]={1, 3, 5, 2, 4, 6, 7};
    int len=sizeof(arr)/sizeof(arr[0]);

    int answer=minimumSwaps2(arr,len);

    cout<<"Min swaps "<<answer<<endl;

    return 0;
}