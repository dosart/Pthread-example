#include "pthread_wrappers.h"

#define NUM_THREADS 4
#define NUM_ELEMENTS 1000000

#define BAD_CAST -10

typedef struct __args_t
{
    int* elements;
    long long int* results;
    size_t from;
    size_t to;
    short thread_id;
} args_t;

void init_args(args_t* args);
void init_elements(int* elements);

void* sum(void* args)
{
    args_t* arg = (args_t*)args;
    if (arg == NULL)
        return (void*)BAD_CAST;

    long long int result = 0;
    for (size_t i = arg->from; i < arg->to; ++i)
        result += arg->elements[i];

    arg->results[arg->thread_id] = result;
}

int elements[NUM_ELEMENTS] = { 0 };
long long int results[NUM_THREADS] = { 0 };

int main()
{
    init_elements(elements);

    args_t args[NUM_THREADS];
    init_args(args);

    pthread_t threads[NUM_THREADS];
    for (size_t i = 0; i < NUM_THREADS; i++)
        Pthread_create(&threads[i], NULL, sum, (void*)&args[i]);

    for (size_t i = 0; i < NUM_THREADS; i++)
        Pthread_join(threads[i], NULL);

    long long int main_result = 0;
    for (size_t i = 0; i < NUM_THREADS; i++)
        main_result += results[i];

    return 0;
}

void init_elements(int* elements)
{
    for (size_t i = 0; i < NUM_ELEMENTS; i++)
        elements[i] = i;
}

void init_args(args_t* args)
{
    size_t elements_per_thread = NUM_ELEMENTS / NUM_THREADS;
    size_t residue = NUM_ELEMENTS % NUM_THREADS;

    for (short i = 0; i < NUM_THREADS; i++)
    {
        args[i].elements = elements;
        args[i].results = results;
        args[i].thread_id = i;
        args[i].from = elements_per_thread * i;
        args[i].to = elements_per_thread * (i + 1);
    }
    args[NUM_THREADS - 1].to += residue;
}