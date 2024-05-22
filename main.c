#include "vec.h" // main lib file
#include <stdio.h> // printf

int main() {
    Vec *vector = vec_init(10);
    if (vector == NULL) {
        puts("Shits fucked");
    }
    for (size_t i = 0; i < vector->cap; i++) {
        printf("%d, ", *(int *)vector->ptr[i]);
    }
    vec_print("%d", vector, int);
}