#ifndef VEC_H
#define VEC_H

#include <stddef.h> // size_t
#include <stdbool.h> // bool

// Enum for possible return values
typedef enum {
    Success = 0,
    OutOfMemory = -1,
    RangeOutOfBounds = -2
} VecResult;

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
VecResult vec_push(Vec *vec, void *data);

// Gets data at a given index
void *vec_get(Vec *vec, size_t index);

// Free the vector
void vec_free(Vec *vec);

// Inserts data into the vec at a given index
VecResult vec_insert(Vec *vec, void *data, size_t index);

// Removes data at a given index
VecResult vec_remove(Vec *vec, size_t index);

// Pops the last element on the vec and returns it
void *vec_pop(Vec *vec);

// Returns true if the len = 0
bool vec_is_empty(Vec *vec);

#endif