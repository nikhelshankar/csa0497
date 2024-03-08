#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
void *myThreadFun(void *vargp) {
    sleep(1);
    printf("Printing GeeksQuiz from Thread %lu\n", pthread_self());
    return NULL;
}
int main() {
    pthread_t thread_id1, thread_id2;
    printf("Before Threads:\n");
    pthread_create(&thread_id1, NULL, myThreadFun, NULL);
    pthread_create(&thread_id2, NULL, myThreadFun, NULL);
	printf("After Threads:\n");
    pthread_join(thread_id1, NULL);
    pthread_join(thread_id2, NULL);

    exit(0);
}

