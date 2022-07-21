#ifndef LIST_H
#define LIST_H

#include "pthread_wrappers.h"

#include <pthread.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct __node_t
{
    int key;
    struct __node_t* next;
} node_t;

typedef struct __list_t
{
    node_t* head;
    pthread_mutex_t lock;
} list_t;

void list_init(list_t* list);

void list_destroy(list_t* list);

void list_insert(list_t* list, int key);

node_t* list_lookup(list_t* list, int key);

#endif