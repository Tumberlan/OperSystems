#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

#define STATUS_SUCCESS 0
#define ERROR_CODE 1
#define SLEEP_TIME 2
#define CLEANUP_POP_ARG 0

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
        perror("error in pthread_create");
        pthread_exit(NULL);
        exit(ERROR_CODE);
    }

    sleep(SLEEP_TIME);

    int pthread_cancel_result = pthread_cancel(pthread_id);
    if (pthread_cancel_result != STATUS_SUCCESS) {
        perror("error in pthread_cancel");
        pthread_exit(NULL);
        exit(ERROR_CODE);
    }

    pthread_exit(NULL);
    return EXIT_SUCCESS;
}