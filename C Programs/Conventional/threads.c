# include <stdio.h>
# include <pthread.h>

void* myTurn(void *arg){

    int i;
    int *val=(int *)arg;

    for(i=0;i<10;i++){
        printf("My turn at %d with parameter %d\n",i,++*val);
        sleep(1);
    }
    return NULL;
}

void yourTurn(){

    int i;
    for (i=0;i<5;i++){
        printf("Your turn at %d\n",i);
        sleep(1);
    }
}

void *threadReturn(void *arg){

    int *iptr=(int *)malloc(sizeof(int));
    *iptr=10;
    return iptr;
    // int a=15;
    // return a;
}

int main(){

    pthread_t myThread;
    pthread_t myThread2;
    
    int val=10;
    int *threadVal;
    
    // Passing parameter to functions.
    pthread_create(&myThread,NULL,myTurn, &val);
    pthread_create(&myThread2,NULL,threadReturn,NULL);

    yourTurn();

    pthread_join(myThread,NULL);
    pthread_join(myThread2,&threadVal);
    

    printf("The value of val %d..\n",val);
    printf("The value from thread %d..\n",*threadVal);

      return 0;
}