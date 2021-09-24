#include <stdio.h>
#include <pthread.h>

#define SUCCESSFUL_RESULT 0
#define ERROR_CODE 1
#define EXIT_SUCCESS 0

void *print_strings() {
    for (int i = 0; i < 10; i++) {
        printf("new string in side thread\n");
    }
    return NULL;
}

int main() {
    pthread_t pthread_id;
    int pthread_create_result = pthread_create(&pthread_id, NULL, print_strings, NULL);
    if (pthread_create_result != SUCCESSFUL_RESULT) {
        perror("error in pthread_create");
        exit(ERROR_CODE);
    }
    for (int i = 0; i < 10; i++) {
        printf("new string in main thread\n");
    }
    pthread_exit(&pthread_id);
    return EXIT_SUCCESS;
}
