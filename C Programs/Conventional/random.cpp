# include <iostream>
# include <ctime>
# include <stdlib.h>
using namespace std;

// This function returns a random number between 20 and 50.
int randomGenerator(){
    int num=20+(rand()%(50-20+1));
    return num;
}


int main(){

    // Seeding the random number.
    srand(time(0));

    cout<<randomGenerator()<<endl;

    return 0;
}