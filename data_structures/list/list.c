#include "list.h"

void list_init(list_t* list)
{
    if (list == NULL)
        return;

    list->head = NULL;
    Pthread_mutex_init(&list->lock, NULL);
}

void list_destroy(list_t* list)
{
    if (list == NULL)
        return;

    list_t* cur = list->head;
    list_t* tmp = NULL;
    while (cur)
    {
        tmp = cur->next;
        free(cur);
        cur = tmp;
    }
}

void list_insert(list_t* list, int key)
{
    if (list == NULL)
        return;

    node_t* new = malloc(sizeof(node_t));
    if (new == NULL)
    {
        perror("list");
        return;
    }

    new->key = key;

    Pthread_mutex_lock(&list->lock);
    new->next = list->head;
    list->head = new;
    Pthread_mutex_unlock(&list->lock);
}

node_t* list_lookup(list_t* list, int key)
{
    if (list == NULL)
        return NULL;

    Pthread_mutex_lock(&list->lock);

    list_t* cur = list->head;
    while (cur)
    {
        if (cur->key == key)
            break;
        cur = cur->next;
    }

    Pthread_mutex_unlock(&list->lock);
    return cur;
}
