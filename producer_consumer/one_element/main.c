#include "pthread_wrappers.h"

#include <assert.h>
#include <pthread.h>

#define COUNT 10

pthread_cond_t empty, fill;
pthread_mutex_t mutex;

unsigned int count = 0;
int buffer;

void put_value(int value)
{
    assert(count == 0);
    count = 1;
    buffer = value;
}

void* producer(void* arg)
{
    for (size_t i = 0; i < COUNT; i++)
    {
        Pthread_mutex_lock(&mutex);
        while (count == 1)
            Pthread_cond_wait(&empty, &mutex);

        put_value(10);

        Pthread_cond_signal(&fill);
        Pthread_mutex_unlock(&mutex);
    }
}

int get_value()
{
    assert(count == 1);
    count = 0;
    return buffer;
}

void* consumer(void* arg)
{
    for (size_t i = 0; i < COUNT; i++)
    {
        Pthread_mutex_lock(&mutex);
        while (count == 0)
            Pthread_cond_wait(&fill, &mutex);

        int value = get_value();

        Pthread_cond_signal(&empty);
        Pthread_mutex_unlock(&mutex);
    }
}

#define NUM_THREADS 4

int main()
{
    pthread_t producers[NUM_THREADS];
    for (size_t i = 0; i < NUM_THREADS; i++)
        Pthread_create(&producers[i], NULL, producer, NULL);

    pthread_t consumers[NUM_THREADS];
    for (size_t i = 0; i < NUM_THREADS; i++)
        Pthread_create(&consumers[i], NULL, consumer, NULL);

    for (size_t i = 0; i < NUM_THREADS; i++)
        Pthread_join(producers[i], NULL);

    for (size_t i = 0; i < NUM_THREADS; i++)
        Pthread_join(consumers[i], NULL);

    return 0;
}
