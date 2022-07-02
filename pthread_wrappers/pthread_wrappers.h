#ifndef PTHREAD_WRAPPERS_H
#define PTHREAD_WRAPPERS_H

#include <pthread.h>
#include <errno.h>
#include <stdio.h>

int Pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);

int Pthread_join(pthread_t thread, void **retval);

#endif