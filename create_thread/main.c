#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ERROR_CREATE_THREAD -10
#define ERROR_JOIN_THREAD -11
#define SUCCESS 2

void *hello_world(void *args) {
  printf("Hello from child thread!\n");
  return SUCCESS;
}

int main() {
  int return_from_thread = 0;
  int status = 0;

  pthread_t new_thread;
  status = pthread_create(&new_thread, NULL, hello_world, NULL);
  if (status!=0) {
    printf("main error: can't create thread, status = %d\n", status);
    exit(ERROR_CREATE_THREAD);
  }

  status = pthread_join(new_thread, (void**)&return_from_thread);
  if (status!=0) {
    printf("main error: can't join thread, status = %d\n", status);
    exit(ERROR_JOIN_THREAD);
  }

  printf("Hello from main thread\n");
  printf("%d", return_from_thread);
  return 0;
}
