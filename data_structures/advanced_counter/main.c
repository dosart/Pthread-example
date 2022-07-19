#include "counter.h"

#define THREASHOLD 1000000

typedef struct __args_t
{
    counter_t* counter;
    int thread_id;

} args_t;

void* inc(void* arg)
{
    args_t* args = (args_t*)arg;
    if (args != NULL)
        for (size_t i = 0; i < THREASHOLD; i++)
            counter_update(args->counter, args->thread_id, 1);
}

int main()
{
    counter_t counter;
    counter_init(&counter, THREASHOLD);

    args_t args[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++)
    {
        args[i].counter = &counter;
        args[i].thread_id = i;
    }

    pthread_t threads[NUM_THREADS];
    for (size_t i = 0; i < NUM_THREADS; i++)
        Pthread_create(&threads[i], NULL, inc, (void*)&args[i]);

    for (size_t i = 0; i < NUM_THREADS; i++)
        Pthread_join(threads[i], NULL);

    printf("Sum = %li\n", counter_get_value(&counter));

    counter_destroy(&counter);
    return 0;
}