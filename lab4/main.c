#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

#define STATUS_SUCCESS 0
#define ERROR_CODE 1
#define SLEEP_TIME 2

void *print_strings() {
    for (int i = 0; i < 10; i++) {
        fprintf(stdout,"new string inside thread\n");
    }
    return NULL;
}


int main() {
    pthread_t pthread_id;
    void *thread_res;
    long long pthread_create_result = pthread_create(&pthread_id, NULL, print_strings, NULL);
    if(pthread_create_result != STATUS_SUCCESS){
        perror("error in pthread_create");
        pthread_exit(NULL);
        exit(ERROR_CODE);
    }

    sleep(SLEEP_TIME);

    long long pthread_cancel_result = pthread_cancel(pthread_id);
    if(pthread_cancel_result != STATUS_SUCCESS){
        perror("error in pthread_cancel");
        pthread_exit(NULL);
        exit(ERROR_CODE);
    }
    pthread_cancel_result = pthread_cancel(pthread_id);

    thread_res = (void *) pthread_cancel_result;
    if (thread_res == PTHREAD_CANCELED) {
        fprintf(stdout,"thread was cancelled\n");
    } else {
        fprintf(stdout,"thread was joined\n");
    }

    pthread_exit(NULL);
    return EXIT_SUCCESS;
}