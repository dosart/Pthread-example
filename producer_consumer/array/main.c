#include "pthread_wrappers.h"

#include <assert.h>
#include <pthread.h>

#define MAX 1000000
#define COUNT 10000
int buffer[MAX] = { 0 };

pthread_cond_t empty = PTHREAD_COND_INITIALIZER;
pthread_cond_t fill = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

size_t fill_ptr = 0;
size_t empty_ptr = 0;
size_t count = 0;

void put_value(int value)
{
    buffer[fill_ptr] = value;
    fill_ptr = (fill_ptr + 1) % MAX;
    count++;
}

void* producer(void* arg)
{
    for (size_t i = 0; i < COUNT; i++)
    {
        Pthread_mutex_lock(&mutex);
        while (count == MAX)
            Pthread_cond_wait(&empty, &mutex);

        put_value(10);

        Pthread_cond_signal(&fill);
        Pthread_mutex_unlock(&mutex);
    }
}

int get_value()
{
    int tmp = buffer[empty_ptr];
    empty_ptr = (empty_ptr + 1) % MAX;
    count--;
    return tmp;
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

    printf("done!\n");

    return 0;
}
