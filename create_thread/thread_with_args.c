#include "pthread_wrappers.h"

#include <stddef.h>
#include <stdio.h>
#include <string.h>

#define BAD_CAST -10
#define STRING_IS_NULL -11

typedef struct __args
{
    char* str;
    size_t str_len;
} args;

void* str_len(void* arg)
{
    args* arguments = (args*)arg;
    if (arguments == NULL)
        return (void*)BAD_CAST;
    if (arguments->str == NULL)
        return (void*)STRING_IS_NULL;

    arguments->str_len = strlen(arguments->str);
    return 0;
}

int main()
{
    args arg = { .str = "Hello World!", .str_len = 0 };
    pthread_t thread;
    Pthread_create(&thread, NULL, str_len, (void*)&arg);

    int returned_from_thread = 0;
    Pthread_join(thread, (void**)&returned_from_thread);

    printf("String length: %li\n", arg.str_len);
    printf("Returned from thread: %i\n", returned_from_thread);
    return 0;
}