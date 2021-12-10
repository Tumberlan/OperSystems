#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>


/*
    errno = 0;
    int threads_count = sysconf(_SC_THREAD_THREADS_MAX);
    fprintf(stdout, "%d\n", threads_count);

   int r_limit_result = getrlimit(RLIMIT_DATA, rlp);
    errno = 0;
    int threads_count = sysconf(_SC_THREAD_THREADS_MAX);
    fprintf(stdout, "%d\n", threads_count);

    struct rlimit *rlp;
    rlim_t max_bytes;
    int r_limit_result = getrlimit(RLIMIT_DATA, rlp);
    //max_bytes = rlp->rlim_max;
    //printf("Hard limit: %lu bytes\n", max_bytes);
    //fprintf(stdout, "Hard limit: %ju bytes\n", max_bytes);

 */

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

    pthread_t *threads = (pthread_t*)malloc(sizeof(pthread_t) * number_of_threads);
    if (threads == NULL){
        fprintf(stderr, "Unable to allocate memory for threads\n");
        return EXIT_FAILURE;
    }
    struct thread_data *thread_data = (struct thread_data *)malloc(sizeof(struct thread_data ) * number_of_threads);
    if (thread_data == NULL){
        fprintf(stderr, "Unable to allocate memory for threads\n");
        return EXIT_FAILURE;
    }
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
            free(threads);
            free(thread_data);
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
            free(threads);
            free(thread_data);
            pthread_exit(NULL);
        }
        sum += thread_data[i].piPart;
        i++;
    }

    fprintf(stdout, "pi done - %.15g\n", sum);
    fprintf(stdout, "compare - 3.14159265358979\n");

    free(threads);
    free(thread_data);

    return EXIT_SUCCESS;
}