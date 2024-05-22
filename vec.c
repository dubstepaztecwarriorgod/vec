#include "vec.h" // impl file
#include <stdlib.h> // malloc, free, realloc
#include <stdio.h> // printf

Vec *vec_init(size_t cap) {
    // Init the vec and allocate the array of pointers
    Vec *vec = malloc(sizeof(Vec));
    if (!vec) 
        return (Vec *)NULL;
        
    vec->ptr = malloc(cap * sizeof(void *));
    if (!vec->ptr) 
        return (Vec *)NULL;

    // initilize the array
    for (size_t i = 0; i < cap; i++) {
        vec->ptr[i] = malloc(sizeof(void *));
        if (!vec->ptr[i]) 
            return (Vec *)NULL;
    }

    vec->cap = cap;
    vec->len = 0;
    return vec;
}

void vec_push(Vec *vec, void *data) {
    if (vec->cap == vec->len)
        vec_grow(vec);
    
    vec->ptr[vec->len] = data;

    vec->len++;
}

enum VecErrors vec_grow(Vec *vec) {
    vec->cap *= 2;

    vec->ptr = realloc(vec->ptr, vec->cap * sizeof(void *));
    if (!vec->ptr) 
        return -1;

    for (size_t i = vec->len; i < vec->cap; i++) {
        vec->ptr[i] = malloc(sizeof(void *));
        if (!vec->ptr[i]) 
            return -1;
    }
}