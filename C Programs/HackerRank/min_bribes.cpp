# include <iostream>
# include <vector>
using namespace std;


void swap(int &a, int &b){
    a=a+b;
    b=a-b;
    a=a-b;
}

void minimumBribes(int q[],int len){
    
    // int arr_len=len;
    // int bribes=0;
    // for (int i = 0; i < arr_len; i++)
    // {
    //     if((q[i]-i)>3){
    //         cout<<"Too chaotic"<<endl;
    //         return;
    //     }
    //     if (q[i]<=i)
    //         continue;
    //     bribes+=(q[i]-(i+1));
    // }
    // int a=0;
    // for (int i = 0; i < arr_len; i++)
    // {
    //     if (q[i]<=i){
    //         if (q[i]>a)
    //             a=q[i];
    //         else
    //         {
    //             a=q[i];
    //             bribes+=1;
    //         }    
    //     }
    // }
    // cout<<bribes<<endl;
    
    int arr_len=len;
    int bribes=0;
    // Making a reference list.
    int *p=new int[arr_len];
    for (int i = 0; i < arr_len; i++)
        p[i]=i+1;
        
    //Now iterating the given list.
    for (int i = 0; i < arr_len; i++)
    {
        // Non bribers
        if (p[i]==q[i])
            continue;

        else
        {
            // Single bribers
            if (p[i+1]==q[i])
            {
                bribes+=1;
                swap(p[i],p[i+1]);
            }
            // Double bribers.
            else if (p[i+2]==q[i])
            {
                bribes+=2;
                swap(p[i+1],p[i+2]);
                swap(p[i],p[i+1]);
            }
            // Extreme bribers i.e. >2.
            else
            {
                cout<<"Too chaotic"<<endl;
                return;
            }   
        }
        
    }
    cout<<bribes<<endl;    
    delete[] p;
}

int main(){

    int q[]={ 1, 2,5, 3, 7,8,6,4 };

    int len=sizeof(q)/sizeof(q[0]);

    minimumBribes(q,len);
    
    return 0;
}