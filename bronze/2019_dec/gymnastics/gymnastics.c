/*
ID: qoob
LANG: C
TASK: gymnastics
*/

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,sse,sse2")

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

#define KMAX 10
#define NMAX 20

typedef struct {
    size_t a;
    size_t b;

    size_t cnt;
} pair_t;

/**
 * Theory
 * ------
 * This is going to be utter cancer.
 * 
 * On the first run. a list of every possible
 * pair will be created. For every successive run, 
 * the list will be updated.
 * 
 * The `cnt` value is updated every time a pair
 * is found. This is less taxing than removing
 * a pair from the list.
 * 
 * At the end, the amount of pairs with `cnt` == `k`
 * will be the final solution.
 */

static inline
int update(pair_t* pairs,
           size_t  n,
           size_t  a,
           size_t  b) {

    for (size_t i = 0; i < n; i++) {
        pair_t cur = pairs[i];

        if (cur.a == a && cur.b == b) {
            cur.cnt++;

            return 0;
        }
    }

    return -1;
}

int main() {
    FILE* in = fopen("gymnastics.in", "r");
    FILE* out = fopen("gymnastics.out", "w");

    size_t k, n;
    fscanf(in, "%ln %ln\n", &k, &n);

    pair_t* pairs = malloc(sizeof(pair_t));

    /**
     * When in loops that perform heavy lifting,
     * I heard it's best to use inline functions
     * to allow the compiler to optimize around them.
     * 
     * write is faster than printf, so use it when possible
     */

    for (size_t i = 0; i < k; i++) {
        
    }

    return 0;
}
