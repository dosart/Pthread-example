#include "counter.h"

int counter_init(counter_t* counter, size_t threshold)
{
    if (counter == NULL)
        return ERROR_INIT;

    counter->global_counter = 0;
    Pthread_mutex_init(&counter->global_lock, NULL);

    for (size_t i = 0; i < NUM_THREADS; i++)
    {
        counter->local_counter[i] = 0;
        Pthread_mutex_init(&counter->local_lock[i], NULL);
    }
    counter->threshold = threshold;
    return SUCCESS_INIT;
}

int counter_destroy(counter_t* counter)
{
    if (counter == NULL)
        return ERROR_DESTROY;

    counter->global_counter = 0;
    Pthread_mutex_destroy(&counter->global_lock);

    for (size_t i = 0; i < NUM_THREADS; i++)
    {
        counter->local_counter[i] = 0;
        Pthread_mutex_destroy(&counter->local_lock[i]);
    }
    counter->threshold = 0;
    return SUCCESS_DESTROY;
}

void counter_update(counter_t* counter, int thread_id, size_t value)
{
    if (counter == NULL)
        return;

    size_t cpu = thread_id % NUM_THREADS;
    Pthread_mutex_lock(&counter->local_lock[cpu]);

    counter->local_counter[cpu] += value;
    if (counter->local_counter[cpu] >= counter->threshold)
    {
        Pthread_mutex_lock(&counter->global_lock);
        counter->global_counter += counter->local_counter[cpu];
        Pthread_mutex_unlock(&counter->global_lock);

        counter->local_counter[cpu] = 0;
    }

    Pthread_mutex_unlock(&counter->local_lock[cpu]);
}

size_t counter_get_value(counter_t* counter)
{
    if (counter == NULL)
        return 0;

    Pthread_mutex_lock(&counter->global_lock);
    int value = counter->global_counter;
    Pthread_mutex_unlock(&counter->global_lock);

    return value;
}