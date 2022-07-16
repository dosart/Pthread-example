#ifndef COUNTER_H
#define COUNTER_H

#include "pthread_wrappers.h"

#include <pthread.h>
#include <stddef.h>

#define ERROR_INIT -10
#define ERROR_DESTROY -11

typedef struct __counter_t
{
    size_t value;
    pthread_mutex_t lock;
} counter_t;

int counter_init(counter_t* counter);

int counter_destroy(counter_t* counter);

void counter_increment(counter_t* counter);

void counter_decrement(counter_t* counter);

size_t counter_get_value(counter_t* counter);

#endif