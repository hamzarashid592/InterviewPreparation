#include<stdio.h>
#include <stdbool.h>
#include<pthread.h>

/*  By making the following volatile we tell the compiler that do not make any 
    assumptions about it.
*/

volatile bool state=true; //Global var.

void *changeState(void *arg){
    sleep(2);
    state=false;
    return NULL;
}


int main(){

    pthread_t thread;
    pthread_create(&thread,NULL,changeState,NULL);

    printf ("Start of loop.\n");

    while (state){} /*In case of compiler optimizations this would be replaced
                    by while(true){}
                    */

    printf("Going forward\n");

    return 0;
}