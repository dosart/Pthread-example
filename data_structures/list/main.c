#include "list.h"

#define NUM_THREADS 4

void* add(void* arg)
{
    list_t* list = (list_t*)arg;
    list_insert(list, 10);
}

int main()
{
    list_t list;
    list_init(&list);

    pthread_t threads[NUM_THREADS];
    for (size_t i = 0; i < NUM_THREADS; i++)
        Pthread_create(&threads[i], NULL, add, (void*)&list);

    for (size_t i = 0; i < NUM_THREADS; i++)
        Pthread_join(threads[i], NULL);

    list_destroy(&list);
}