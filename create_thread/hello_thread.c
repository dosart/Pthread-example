#include "pthread_wrappers.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sysinfo.h>

void* hello_world(void* args)
{
    printf("Hello from child thread!\n");
    return 0;
}

int main()
{
    pthread_t thread;
    Pthread_create(&thread, NULL, hello_world, NULL);
    printf("Hello from main!\n");

    int returned_from_thread = 0;
    Pthread_join(thread, (void**)&returned_from_thread);

    printf("Returned from thread: %i\n", returned_from_thread);
    return 0;
}
