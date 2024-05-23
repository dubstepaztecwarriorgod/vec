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
    int d = 4141;
    vec_push(vec, &a);
    vec_push(vec, &b);
    vec_push(vec, &c);
    vec_print("%d", vec, int);
    puts("");
    vec_insert(vec, &d, 1);
    vec_print("%d", vec, int);
}