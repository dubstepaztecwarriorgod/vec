#ifndef VEC_H
#define VEC_H

#include <sys/types.h> // size_t
#include <stdbool.h> // bool

// Macro for printing every element in the vector
#define vec_print(formatter, vec, type) { \
    for (size_t i = 0; i < (vec)->len; i++) { \
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

// Pushes the data into the vec
int vec_push(Vec *vec, void *data);

// Gets data at a given index
void *vec_get(Vec *vec, size_t index);

// Free the vector
void vec_free(Vec *vec);

// Inserts data into the vec at a given index
int vec_insert(Vec *vec, void *data, size_t index);

// Removes data at a given index
int vec_remove(Vec *vec, size_t index);

// Returns true if the len = 0
bool vec_is_empty(Vec *vec);

#endif