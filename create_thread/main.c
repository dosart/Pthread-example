#include "pthread_wrappers.h"
#include <stdio.h>
#include <stdlib.h>

void* hello_world(void* args)
{
    printf("Hello from child thread!\n");
    return 0;
}

int main()
{
    pthread_t new_thread;
    Pthread_create(&new_thread, NULL, hello_world, NULL);

    int return_from_thread = 0;
    Pthread_join(new_thread, (void**)&return_from_thread);

    printf("Hello from main thread\n");
    printf("%d", return_from_thread);
    return 0;
}
