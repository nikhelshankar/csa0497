#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

void *myThreadFun(void *vargp) {
    sleep(1);
    printf("Printing GeeksQuiz from Thread\n");
    return NULL;
}

int main() {

    int shmid;
    void *shared_memory;
    char buff[100];

    printf("Key of shared memory is %d\n", shmid);

    printf("Process attached at %p\n", shared_memory);

    printf("Enter some data to write to shared memory:\n");
    read(0, buff, 100);
    strcpy(shared_memory, buff);

    printf("You wrote: %s\n", (char *)shared_memory);

    pthread_t thread_id;

    printf("Before Thread\n");
    pthread_create(&thread_id, NULL, myThreadFun, NULL);
    pthread_join(thread_id, NULL);
    printf("After Thread\n");

    return 0;
}

