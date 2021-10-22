#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define STATUS_SUCCESS 0
#define ERROR_CODE 1
#define STRINGS_NUMBER 100000000
#define SLEEP_TIME 2
#define ERROR_BUFFER_LEN 120

void *print_strings() {
    for (int i = 0; i < STRINGS_NUMBER; i++) {
        fprintf(stdout,"new string inside thread\n");
    }
    return NULL;
}


int main() {
    pthread_t pthread_id;
    void *thread_res;
    long long pthread_create_result = pthread_create(&pthread_id, NULL, print_strings, NULL);
    if(pthread_create_result != STATUS_SUCCESS){
        char error_buffer[ERROR_BUFFER_LEN];
        strerror_r(errno, error_buffer, ERROR_BUFFER_LEN);
        write(STDERR_FILENO,error_buffer, strlen(error_buffer));
        pthread_exit(NULL);
    }

    sleep(SLEEP_TIME);

    long long pthread_cancel_result = pthread_cancel(pthread_id);
    if(pthread_cancel_result != STATUS_SUCCESS){
        char error_buffer[ERROR_BUFFER_LEN];
        strerror_r(errno, error_buffer, ERROR_BUFFER_LEN);
        write(STDERR_FILENO,error_buffer, strlen(error_buffer));
        pthread_exit(NULL);
    }
    thread_res = (void *) pthread_cancel_result;
    if (thread_res == PTHREAD_CANCELED) {
        fprintf(stdout,"thread was cancelled\n");
    } else {
        fprintf(stdout,"thread was joined\n");
    }

    pthread_exit(EXIT_SUCCESS);
}