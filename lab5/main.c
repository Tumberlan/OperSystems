#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define STATUS_SUCCESS 0
#define ERROR_CODE 1
#define SLEEP_TIME 2
#define CLEANUP_POP_ARG 0
#define ERROR_BUFFER_LEN 120

void cleaner(void *arg) {
    fprintf(stdout, "cleaner was called: %s\n", (char *) arg);
}

void *print_strings() {
    pthread_cleanup_push(cleaner, "child thread start");

        for (int i = 1; i <= 10; ++i) {
            fprintf(stdout, "string %d (child)\n", i);
        }

    pthread_cleanup_pop(CLEANUP_POP_ARG);

    pthread_exit((void *) 1);
    return NULL;
}


int main() {
    pthread_t pthread_id;
    long long pthread_create_result = pthread_create(&pthread_id, NULL, print_strings, NULL);
    if (pthread_create_result != STATUS_SUCCESS) {
        char error_buffer[ERROR_BUFFER_LEN];
        strerror_r(errno, error_buffer, ERROR_BUFFER_LEN);
        write(STDERR_FILENO,error_buffer, strlen(error_buffer));
        pthread_exit(NULL);
    }

    sleep(SLEEP_TIME);

    int pthread_cancel_result = pthread_cancel(pthread_id);
    if (pthread_cancel_result != STATUS_SUCCESS) {
        char error_buffer[ERROR_BUFFER_LEN];
        strerror_r(errno, error_buffer, ERROR_BUFFER_LEN);
        write(STDERR_FILENO,error_buffer, strlen(error_buffer));
        pthread_exit(NULL);
    }

    pthread_exit(EXIT_SUCCESS);
}