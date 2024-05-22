#ifndef VEC_H
#define VEC_H

#include <sys/types.h> // size_t

#define vec_print(formatter, vec, type) { \
    for (size_t i = 0; i < (vec)->len; i++) { \
        puts("made it here"); \
        printf(formatter "\n", *((type *)(vec)->ptr[i])); \
    } \
}

// This is a dynamic array implementation.
// This is EXTREMELY UNSAFE because C does not do type checking
// During execution time so make sure you type cast the void * correctly
typedef struct Vec {
    // The max number of items the vec holds
    size_t cap;
    // The current number of items the vec holds
    size_t len;
    // The array of pointers the vec uses to store the data
    void **ptr;
} Vec;

// Initilizaize a vector with a initial capacity
Vec *vec_init(size_t cap);

// Doubles the size of the vector array
int vec_grow(Vec *vec);

// Pushes the data into the vec
void vec_push(Vec *vec, void *data);

#endif