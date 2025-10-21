#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dynarray.h"

// Error checked malloc
void* ecmalloc(size_t n)
{
    void* p = malloc(n);
    if (p == NULL)
    {
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }
    return p;
}

void clean(Dynarray* pd)
{
    for (size_t i = 0; i < pd->size; ++i)
        pd->data[i] = 0;
}

void init(Dynarray* pd, size_t initial_size) 
{
    pd->size = initial_size;
    pd->capacity = initial_size;
    if (pd->size == 0)
        pd->data = NULL;
    else
        pd->data = (int*)ecmalloc(pd->capacity * sizeof(int));
    clean(pd);
}

void reserve(Dynarray* pd, size_t new_capacity)
{
    if (new_capacity <= pd->capacity)
        return;

    int* new_data = (int*)ecmalloc(new_capacity * sizeof(int));

    for (size_t i = 0; i < pd->size; ++i)
    {
        new_data[i] = pd->data[i];
    }

    free(pd->data);
    pd->data = new_data;
    pd->capacity = new_capacity;
}


void push_back(Dynarray* pd, int x) 
{
    static const double growth_factor = 2;
    if (pd->size == pd->capacity) 
    {
        size_t new_capacity = (size_t)(growth_factor * pd->capacity);
        
        if (new_capacity <= pd->size)
            new_capacity = pd->size + 1;

        reserve(pd, new_capacity);
    }
    pd->data[pd->size] = x;
    pd->size += 1;
}


int get(const Dynarray* pd, size_t index) 
{
    assert(index < pd->size);
    return pd->data[index];
}


void set(Dynarray* pd, size_t index, int value) 
{
    assert(index < pd->size);
    pd->data[index] = value;
}


void print(const Dynarray* pd) 
{
    printf("dynarray: ");
    for (size_t i = 0; i < pd->size; ++i) 
        printf("%i ", pd->data[i]);

    printf("\n");
}


void destroy(Dynarray* pd) 
{
    free(pd->data);
    pd->data = NULL;
    pd->size = 0;
    pd->capacity = 0;
}

int pop_back(Dynarray* pd)
{
    if (pd->size == 0)
    {
        fprintf(stderr, "pop_back error: dynarray is empty.\n");
        exit(1);
    }
    int value = pd->data[pd->size - 1];
    pd->size -= 1;
    return value;
}

void resize(Dynarray* pd, size_t new_size)
{
    size_t old_size = pd->size;
    if (new_size > pd->capacity)
        reserve(pd, new_size);

    pd->size = new_size;

    if (new_size > old_size)
    {
        for (size_t i = old_size; i < new_size; ++i)
            pd->data[i] = 0;
    }
}

void shrink_to_fit(Dynarray* pd)
{
    if (pd->capacity == pd->size)
        return;

    if (pd->size == 0)
    {
        free(pd->data);
        pd->data = NULL;
        pd->capacity = 0;
        return;
    }

    int* new_data = (int*)ecmalloc(pd->size * sizeof(int));
    for (size_t i = 0; i < pd->size; ++i)
        new_data[i] = pd->data[i];

    free(pd->data);
    pd->data = new_data;
    pd->capacity = pd->size;
}

Dynarray shallow_copy(Dynarray* pd)
{
    Dynarray copy;
    copy.data = pd->data;
    copy.size = pd->size;
    copy.capacity = pd->capacity;
    return copy;
}

Dynarray deep_copy(const Dynarray* pd)
{
    Dynarray copy;
    copy.size = pd->size;
    copy.capacity = pd->capacity;
    if (copy.capacity == 0)
    {
        copy.data = NULL;
        return copy;
    }

    copy.data = (int*)ecmalloc(copy.capacity * sizeof(int));
    for (size_t i = 0; i < copy.size; ++i)
        copy.data[i] = pd->data[i];

    for (size_t i = copy.size; i < copy.capacity; ++i)
        copy.data[i] = 0;

    return copy;
}
