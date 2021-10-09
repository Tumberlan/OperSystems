#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define SUCCESSFUL_RESULT 0
#define THREADS_NUMBER 4
#define ERROR_CODE 1
#define STRINGS_NUMBER 2
#define ERROR_BUFFER_LEN 120

void *print_strings(void *arg) {
    const char **strings = (const char **) arg;

    for (int i = 0; i < STRINGS_NUMBER; i++) {
        write(STDOUT_FILENO, strings[i], strlen((const char *) strings[i]));
    }
    return NULL;
}

int main() {
    errno = 0;
    pthread_t pthread_id_array[THREADS_NUMBER];
    int pthread_create_result;
    char *strings[THREADS_NUMBER][STRINGS_NUMBER] = {{"first",  " thread\n"},
                                                     {"second", " thread\n"},
                                                     {"third",  " thread\n"},
                                                     {"fourth", " thread\n"}};

    for (int i = 0; i < THREADS_NUMBER; ++i) {
        pthread_create_result = pthread_create(&pthread_id_array[i], NULL, print_strings, (void *) &strings[i]);

        if (pthread_create_result != SUCCESSFUL_RESULT) {
            char error_buffer[ERROR_BUFFER_LEN];
            strerror_r(errno, error_buffer, ERROR_BUFFER_LEN);
            write(STDERR_FILENO,error_buffer, strlen(error_buffer));
            pthread_exit(NULL);
        }
    }
    pthread_exit(EXIT_SUCCESS);
}