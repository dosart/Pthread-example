#ifndef ADVANCED_COUNTER_H
#define ADVANCED_COUNTER_H

#include "pthread_wrappers.h"

#include <pthread.h>
#include <stddef.h>

#define NUM_THREADS 4

#define ERROR_INIT -10
#define SUCCESS_INIT 10

#define ERROR_DESTROY -11
#define SUCCESS_DESTROY 11

typedef struct __counter_t
{
    size_t global_counter;
    pthread_mutex_t global_lock;

    size_t local_counter[NUM_THREADS];
    pthread_mutex_t local_lock[NUM_THREADS];
    size_t threshold;
} counter_t;

int counter_init(counter_t* counter, size_t threshold);

int counter_destroy(counter_t* counter);

void counter_update(counter_t* counter, int thread_id, size_t value);

size_t counter_get_value(counter_t* counter);

#endif