#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define NUM_STEPS 200000000
#define SUCCESSFUL_RESULT 0
#define ERROR_BUFFER_LEN 120
#define RIGHT_ARGUMENTS_NUMBER 2

struct thread_data {
    int index;
    int numOfThreads;
    double piPart;
};

void *calculate_pi_thread(void *param) {
    struct thread_data *data = (struct thread_data *) param;

    int index = data->index;
    int numOfThreads = data->numOfThreads;

    double pi = 0;
    int i = index;

    while (i < NUM_STEPS) {
        pi += 1.0 / (i * 4.0 + 1.0);
        pi -= 1.0 / (i * 4.0 + 3.0);
        i += numOfThreads;
    }
    pi = pi * 4.0;

    data->piPart = pi;
}

int main(int argc, char **argv) {
    if (argc != RIGHT_ARGUMENTS_NUMBER) {
        fprintf(stdout, "Wrong number of arguments\n");
        return EXIT_FAILURE;
    }
    char *end;
    int number_of_threads = strtol(argv[1], &end, 10);

    if (number_of_threads <= 0) {
        fprintf(stderr, "Wrong number of threads\n");
        return EXIT_FAILURE;
    }
    fprintf(stdout, "Using %d threads\n", number_of_threads);

    pthread_t threads[number_of_threads];
    struct thread_data thread_data[number_of_threads];
    int i = 0;
    while (i < number_of_threads) {
        thread_data[i].index = i;
        thread_data[i].numOfThreads = number_of_threads;
        int pthread_create_result = pthread_create(&threads[i], NULL, calculate_pi_thread,
                                                 &thread_data[i]);
        if (pthread_create_result != SUCCESSFUL_RESULT) {
            int j = 0;
            while (j < i) {
                pthread_cancel(threads[j]);
                j++;
            }
            char error_buffer[ERROR_BUFFER_LEN];
            strerror_r(errno, error_buffer, ERROR_BUFFER_LEN);
            write(STDERR_FILENO, error_buffer, strlen(error_buffer));
            pthread_exit(NULL);
        }
        i++;
    }

    double sum = 0;
    i = 0;
    while (i < number_of_threads) {
        int pthreadJoinResult = pthread_join(threads[i], NULL);
        if (pthreadJoinResult != SUCCESSFUL_RESULT) {
            char error_buffer[ERROR_BUFFER_LEN];
            strerror_r(errno, error_buffer, ERROR_BUFFER_LEN);
            write(STDERR_FILENO, error_buffer, strlen(error_buffer));
            pthread_exit(NULL);
        }
        sum += thread_data[i].piPart;
        i++;
    }

    printf("pi done - %.15g\n", sum);
    printf("compare - 3.14159265358979\n");

    return EXIT_SUCCESS;
}