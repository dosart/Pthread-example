#include "pthread_wrappers.h"

int Pthread_create(pthread_t* thread, const pthread_attr_t* attr, void* (*start_routine)(void*), void* arg)
{
    int status = pthread_create(thread, attr, start_routine, arg);
    if (status != 0)
    {
        errno = status;
        perror("pthread_create");
        return -1;
    }
    return status;
}

int Pthread_join(pthread_t thread, void** thread_return)
{
    int status = pthread_join(thread, thread_return);
    if (status != 0)
    {
        errno = status;
        perror("pthread_join");
        return -1;
    }
    return status;
}

int Pthread_mutex_init(pthread_mutex_t* mutex, const pthread_mutexattr_t* attr)
{
    int status = pthread_mutex_init(mutex, attr);
    if (status != 0)
    {
        errno = status;
        perror("pthread_mutex_init");
        return -1;
    }
    return status;
}

int Pthread_mutex_destroy(pthread_mutex_t* mutex)
{
    int status = pthread_mutex_destroy(mutex);
    if (status != 0)
    {
        errno = status;
        perror("pthread_mutex_destroy");
        return -1;
    }
    return status;
}