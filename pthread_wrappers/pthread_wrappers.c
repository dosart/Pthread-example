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

int Pthread_mutex_lock(pthread_mutex_t* mutex)
{
    int status = pthread_mutex_lock(mutex);
    if (status != 0)
    {
        errno = status;
        perror("pthread_mutex_lock");
        return -1;
    }
    return status;
}

int Pthread_mutex_unlock(pthread_mutex_t* mutex)
{
    int status = pthread_mutex_unlock(mutex);
    if (status != 0)
    {
        errno = status;
        perror("pthread_mutex_unlock");
        return -1;
    }
    return status;
}

int Pthread_cond_init(pthread_cond_t* cond, const pthread_condattr_t* attr)
{
    int status = pthread_cond_init(cond, attr);
    if (status != 0)
    {
        errno = status;
        perror("pthread_cond_init");
        return -1;
    }
    return status;
}

int Pthread_cond_destroy(pthread_cond_t* cond)
{
    int status = pthread_cond_destroy(cond);
    if (status != 0)
    {
        errno = status;
        perror("pthread_cond_destroy");
        return -1;
    }
    return status;
}

int Pthread_cond_wait(pthread_cond_t* cond, pthread_mutex_t* mutex)
{
    int status = pthread_cond_wait(cond, mutex);
    if (status != 0)
    {
        errno = status;
        perror("pthread_cond_wait");
        return -1;
    }
    return status;
}

int Pthread_cond_signal(pthread_cond_t* cond)
{
    int status = pthread_cond_signal(cond);
    if (status != 0)
    {
        errno = status;
        perror("pthread_cond_signal");
        return -1;
    }
    return status;
}