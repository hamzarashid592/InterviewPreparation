# include <iostream>
# include<string>
using namespace std;


int hourglass(int arr[][6]){
    int hour_sum[16];
    int hour_count=0;
    for (int i = 0; i < 16; i++)
        hour_sum[i]=0;
    
    int temp[3][3];
    
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++){
            for (int k = 0; k < 3; k++)
                for (int l = 0; l < 3; l++){
                    if ((k==1 && l==0)||(k==1 && l==2))
                        continue;
                    hour_sum[hour_count]+=arr[k+i][l+j];
                }
        hour_count+=1;
        }
    int max=hour_sum[0];
    for (int i = 1; i < 16; i++){
        if (hour_sum[i]>max)
            max=hour_sum[i];
    }
    
    return max;
}

int main(){

    int arr[][6]={{1, 1, 1, 0, 0, 0},{0, 1, 0, 0, 0, 0},{1, 1, 1, 0, 0, 0},
                {0, 0, 2, 4, 4, 0},{0, 0, 0, 2, 0, 0},{0, 0, 1, 2, 4, 0}};

    int ans=hourglass(arr);
    
    cout<<"The max hourglass is "<<ans<<endl;
    
    return 0;
}