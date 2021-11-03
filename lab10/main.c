#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define PHILO 5
#define DELAY 30000
#define FOOD 50
#define AFTER_EATING_SLEEP_TIME 5000000

pthread_mutex_t forks[PHILO];
pthread_t phils[PHILO];
void *philosopher (void *id);
int food_on_table ();
void get_fork (int, int, char *);
void down_forks (int, int);
pthread_mutex_t foodlock;

int sleep_seconds = 4;

int
main (int argn,
      char **argv)
{
    int i;

    if (argn == 2)
        sleep_seconds = atoi (argv[1]);

    pthread_mutex_init (&foodlock, NULL);
    for (i = 0; i < PHILO; i++)
        pthread_mutex_init (&forks[i], NULL);
    for (i = 0; i < PHILO; i++) {
        int* tmp_arr = malloc(sizeof(int));
        tmp_arr[0] = i;
        pthread_create(&phils[i], NULL, philosopher, (void*)tmp_arr);
        free(tmp_arr);
    }
    for (i = 0; i < PHILO; i++)
        pthread_join (phils[i], NULL);
    return 0;
}

void *
philosopher (void *num)
{
    int id;
    int left_fork, right_fork, f, food_eaten_amount = 0;
    int* tmp_arr = (int*)num;

    id = tmp_arr[0];
    printf ("Philosopher %d sitting down to dinner.\n", id);
    right_fork = id;
    left_fork = id + 1;

    if (left_fork == PHILO)
        left_fork = 0;

    while (f = food_on_table ()) {

        pthread_mutex_t entry_point = PTHREAD_MUTEX_INITIALIZER; //added
        printf ("Philosopher %d: get dish %d.\n", id, f);
        pthread_mutex_lock(&entry_point); // added
        get_fork (id, right_fork, "right");
        get_fork (id, left_fork, "left ");
        pthread_mutex_unlock(&entry_point); // added

        food_eaten_amount++;
        printf ("Philosopher %d: eating.\n", id);
        usleep (DELAY * (FOOD - f));
        down_forks (left_fork, right_fork);
        usleep (AFTER_EATING_SLEEP_TIME);
    }
    printf ("Philosopher %d is done eating. He eaten %d dishes\n", id, food_eaten_amount);
    return (NULL);
}

int
food_on_table ()
{
    static int food = FOOD+1;
    int myfood;

    pthread_mutex_lock (&foodlock);
    if (food > 0) {
        food--;
    }
    myfood = food;
    pthread_mutex_unlock (&foodlock);
    return myfood;
}

void
get_fork (int phil,
          int fork,
          char *hand)
{
    pthread_mutex_lock (&forks[fork]);
    printf ("Philosopher %d: got %s fork %d\n", phil, hand, fork);
}

void
down_forks (int f1,
            int f2)
{
    pthread_mutex_unlock (&forks[f1]);
    pthread_mutex_unlock (&forks[f2]);
}
