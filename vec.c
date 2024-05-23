#include "vec.h" // impl file
#include <stdlib.h> // malloc, free, realloc
#include <string.h> // memmove

Vec *vec_init(size_t cap) {
    Vec *vec = malloc(sizeof(Vec));
    if (!vec) 
        return (Vec *)NULL;
        
    vec->ptr = malloc(cap * sizeof(void *));
    if (!vec->ptr) 
        return (Vec *)NULL;

    for (size_t i = 0; i < cap; i++) 
        vec->ptr[i] = NULL;

    vec->cap = cap;
    vec->len = 0;
    return vec;
}

// Doubles the size of the vec
int vec_grow(Vec *vec) {
    size_t new_cap = vec->cap * 2;
    void  **new_ptr = realloc(vec->ptr, vec->cap * sizeof(void *));

    if (!new_ptr) 
        return -1;
    
    vec->cap = new_cap;
    vec->ptr = new_ptr;

    for (size_t i = vec->len; i < vec->cap; i++) 
        vec->ptr[i] = NULL;

    return 0;
}

int vec_push(Vec *vec, void *data) {
    if (vec->cap == vec->len)
        if (vec_grow(vec) != 0)
            return -1;
    
    vec->ptr[vec->len++] = data;

    return 0;
}

void *vec_pop(Vec *vec) {
    if (vec->len == 0)
        return NULL;

    void *data = vec->ptr[vec->len - 1];
    vec->ptr[vec->len - 1] = NULL;
    
    vec->len--;

    return data;
}

void *vec_get(Vec *vec, size_t index) {
    if (index >= vec->len) 
        return NULL;

    return vec->ptr[index];
}

void vec_free(Vec *vec) {
    for (size_t i = 0; i < vec->len; i++) {
        free(vec->ptr[i]);
    }
    free(vec->ptr);
    free(vec);
}

int vec_insert(Vec *vec, void *data, size_t index) {
    if (index > vec->len)
        return -2;

    if (vec->len == vec->cap) 
        if (vec_grow(vec) != 0) 
            return -1;

    memmove(
        &vec->ptr[index + 1],
        &vec->ptr[index],
        (vec->len - index) * sizeof(void *)
    );

    vec->ptr[index] = data;
    vec->len++;

    return 0;
}

int vec_remove(Vec *vec, size_t index) {
    if (index >= vec->len)
        return -2;

    memmove(
        &vec->ptr[index],
        &vec->ptr[index + 1],
        (vec->len - index - 1) * sizeof(void *)
    );

    vec->len--;

    return 0;
}

bool vec_is_empty(Vec *vec) {
    return vec->len == 0;
}