#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define NUM_TRHREADS 100
int saldo;

void *printHola(void *arg){
    //printf("hola desde un hilo\n");
    /*while(1) {
        printf("Trabajando\n");
        sleep(1);
    }*/
    int saldolocal = saldo;
    saldolocal += 100;
    saldo = saldolocal;
    pthread_exit(NULL);
}

int main(){
    pthread_t threads[NUM_TRHREADS];
    saldo = 0;
    for (int i = 0; i < NUM_TRHREADS; i++) {
        pthread_create(&threads[i],NULL,printHola, NULL); 
    }
    for (int i = 0; i < NUM_TRHREADS; i++) {
        pthread_join(threads[i],NULL); 
    }
    printf("El valor del saldo es %d \n", saldo);
    pthread_exit(NULL); 
}