#include <stdio.h>
#include <pthread.h>
#define array_size 1000
#define no_threads 10

float a[array_size];
int global_index = 0;
int sum = 0;
pthread_mutex_t mutex1;

void *slave(void *ignored)
{
    int local_index, partial_sum = 0;
    do {
        pthread_mutex_lock(&mutex1);
        local_index = global_index;
        global_index++;
        pthread_mutex_unlock(&mutex1);

        if (local_index < array_size)
            partial_sum += *(a + local_index);
    }
    while(local_index < array_size);

    pthread_mutex_lock(&mutex1);
    sum += partial_sum;
    pthread_mutex_unlock(&mutex1);

    return 0;
}

main()
{
    int i;
    pthread_t thread_x[10];
    pthread_mutex_init(&mutex1, NULL);

    for (i = 0; i < array_size; i++)
        a[i] = i+1;

    for (i = 0; i < no_threads ; i++)
        pthread_create(&thread_x[i] , NULL, slave,NULL);

    for (i = 0; i < no_threads; i++)
        pthread_join(thread_x[i] , NULL);

    printf("The sum of 1 to %d is %d\n", array_size, sum);
}