#ifndef PTHREAD_WRAPPERS_H
#define PTHREAD_WRAPPERS_H

#include <errno.h>
#include <pthread.h>
#include <stdio.h>

int Pthread_create(pthread_t* thread, const pthread_attr_t* attr, void* (*start_routine)(void*), void* arg);

int Pthread_join(pthread_t thread, void** retval);

int Pthread_mutex_init(pthread_mutex_t* mutex, const pthread_mutexattr_t* attr);

int Pthread_mutex_destroy(pthread_mutex_t* mutex)

#endif