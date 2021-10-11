#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define NUM_TRHREADS 20

void *printHola(void *arg){
    printf("hola desde un hilo\n");
    while(1) {
        printf("Trabajando\n");
        sleep(1);
    }
    pthread_exit(NULL);
}

int main(){
    pthread_t threads[NUM_TRHREADS];
for (int i = 0; i < NUM_TRHREADS; i++) {
    pthread_create(&threads[i],NULL,printHola, NULL); 
}
    pthread_exit(NULL); 
}