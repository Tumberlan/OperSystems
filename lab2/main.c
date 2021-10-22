#include "stdlib.h"
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define SUCCESSFUL_RESULT 0
#define ERROR_CODE 1
#define EXIT_SUCCESS 0
#define STRINGS_NUMBER 10
#define ERROR_BUFFER_LEN 120

void *print_strings() {
    for (int i = 0; i < STRINGS_NUMBER; i++) {
        fprintf(stdout,"new string inside thread\n");
    }
    return NULL;
}


int main() {
    pthread_t pthread_id;
    int pthread_create_result = pthread_create(&pthread_id, NULL, print_strings, NULL);
    if (pthread_create_result != SUCCESSFUL_RESULT) {
        char error_buffer[ERROR_BUFFER_LEN];
        strerror_r(errno, error_buffer, ERROR_BUFFER_LEN);
        write(STDERR_FILENO,error_buffer, strlen(error_buffer));
        pthread_exit(NULL);
    }
    int pthread_join_result = pthread_join(pthread_id, NULL);
    if (pthread_join_result != SUCCESSFUL_RESULT) {
        char error_buffer[ERROR_BUFFER_LEN];
        strerror_r(errno, error_buffer, ERROR_BUFFER_LEN);
        write(STDERR_FILENO,error_buffer, strlen(error_buffer));
        pthread_exit(NULL);
    }
    for (int i = 0; i < 10; i++) {
        fprintf(stdout,"new string in main thread\n");
    }
    pthread_exit(EXIT_SUCCESS);
}