#include "counter.h"

int counter_init(counter_t* counter)
{
    if (counter == NULL)
        return ERROR_INIT;

    counter->value = 0;
    return Pthread_mutex_init(&counter->lock, NULL);
}

int counter_destroy(counter_t* counter)
{
    if (counter == NULL)
        return ERROR_DESTROY;

    counter->value = 0;
    return Pthread_mutex_destroy(&counter->lock);
}

void counter_increment(counter_t* counter)
{
    if (counter == NULL)
        return;

    Pthread_mutex_lock(&counter->lock);
    counter->value++;
    Pthread_mutex_unlock(&counter->lock);
}

void counter_decrement(counter_t* counter)
{
    if (counter == NULL)
        return;

    Pthread_mutex_lock(&counter->lock);
    counter->value--;
    Pthread_mutex_unlock(&counter->lock);
}

size_t counter_get_value(counter_t* counter)
{
    if (counter == NULL)
        return 0;

    Pthread_mutex_lock(&counter->lock);
    int value = counter->value;
    Pthread_mutex_unlock(&counter->lock);

    return value;
}
