#include "counter.h"

#define NUM_THREADS 4

void* inc(void* arg)
{
    counter_t* counter = (counter_t*)arg;
    if (counter != NULL)
        counter_increment(counter);
    else
        printf("Counter is NULL\n");
}

int main()
{
    counter_t counter;
    counter_init(&counter);

    pthread_t threads[NUM_THREADS];
    for (size_t i = 0; i < NUM_THREADS; i++)
        Pthread_create(&threads[i], NULL, inc, (void*)&counter);

    for (size_t i = 0; i < NUM_THREADS; i++)
        Pthread_join(threads[i], NULL);

    printf("Sum = %li\n", counter_get_value(&counter));

    counter_destroy(&counter);
    return 0;
}