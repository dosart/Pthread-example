#include "pthread_wrappers.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BAD_CAST -10;
#define STRING_IS_NULL -11;

const int NUM_MESSAGES = 4;
const int NUM_THREADS = 4;

typedef struct __args_t_t
{
    const char* str;
    size_t str_len;
    int returned_from_thread;
} args_t;

void* str_len(void* args);
args_t* make_args_t(size_t num_args);

int main()
{
    args_t* arguments = make_args_t(NUM_THREADS);

    pthread_t threads[NUM_MESSAGES];
    for (size_t i = 0; i < NUM_THREADS; i++)
        Pthread_create(&threads[i], NULL, str_len, (void*)&arguments[i]);

    for (size_t i = 0; i < NUM_THREADS; i++)
        Pthread_join(threads[i], (void**)&arguments[i].returned_from_thread);

    for (size_t i = 0; i < NUM_THREADS; i++)
        printf("Strig: %s, String length: %li, Returned from thread: %i\n", arguments[i].str, arguments[i].str_len, arguments[i].returned_from_thread);

    free(arguments);
    return 0;
}

void* str_len(void* args)
{
    args_t* arguments = (args_t*)args;
    if (arguments == NULL)
        return (void*)BAD_CAST;
    if (arguments->str == NULL)
        return (void*)STRING_IS_NULL;

    arguments->str_len = strlen(arguments->str);
    return 0;
}

args_t* make_args_t(size_t num_args)
{
    const char* messages[] = { "Hello", "World!", NULL, "name" };
    args_t* result = malloc(num_args * sizeof(args_t));

    for (size_t i = 0; i < num_args; i++)
    {
        result[i].str = messages[i % num_args];
        result[i].str_len = 0;
        result[i].returned_from_thread = 0;
    }

    return result;
}
