#include "vec.h" // main lib file
#include <stdio.h> // printf
#include <stdlib.h> 

int main() {
    Vec *vec = vec_init(10);
    if (vec == NULL) {
        puts("Shits fucked");
    }
    int a = 4;
    int b = 23;
    int c = 540;
    vec_push(vec, &a);
    vec_push(vec, &b);
    vec_push(vec, &c);
    vec_print("%d", vec, int);
}