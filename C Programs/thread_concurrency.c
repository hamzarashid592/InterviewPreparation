# include <stdio.h>
#include <pthread.h>

#define VAR 1000000

int counter=0; //Shared resource
pthread_mutex_t tala = PTHREAD_MUTEX_INITIALIZER; //This should be global.

void *threeDoorsDown(void *arg){

    

    for (int i = 0; i < VAR; i++)
    {
        pthread_mutex_lock(&tala); //Locking the mutex
        counter++;  //Critical section.
        pthread_mutex_unlock(&tala); //Unlocking the mutex.
    }
    return NULL;
}

int main(){

    pthread_t thread;

    pthread_create(&thread,NULL,threeDoorsDown,NULL);
    threeDoorsDown(NULL);
    printf("The counter %d.\n",counter);

    return 0;
}