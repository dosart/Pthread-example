#include "pthread_wrappers.h"

int Pthread_create(pthread_t* thread, const pthread_attr_t* attr, void* (*start_routine)(void*), void* arg)
{
    int status = pthread_create(thread, NULL, start_routine, NULL);
    if (!status)
    {
        errno = status;
        perror("pthread_create");
        return -1;
    }
}

int Pthread_join(pthread_t thread, void** retval)
{
    int status = pthread_join(thread, NULL);
    if (status)
    {
        errno = status;
        perror("pthread_join");
        return -1;
    }
}