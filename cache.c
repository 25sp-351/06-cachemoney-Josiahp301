#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cache.h"
#include "numberwords.h"

#define MAX_DOLLARS 150000
#define BUFFER_SIZE 512

char* cache[MAX_DOLLARS];

void initialize_cache() {
    for (int ix = 0; ix < MAX_DOLLARS; ix++) {
        cache[ix] = NULL;
    }
}

char* cache_func(int dollars) {
    if (dollars < 0) {
        return strdup("Negative dollars do not exist\n");
    }
    if (dollars < MAX_DOLLARS && cache[dollars] != NULL) {
        printf("Using cache...\n");
        return strdup(cache[dollars]);
    }

    char result[BUFFER_SIZE];
    number_to_text(dollars, result);
    char* money = strdup(result);
    if (dollars < MAX_DOLLARS) {
        cache[dollars] = strdup(money);
    }
    return money;
}

void free_cache() {
    printf("Freeing cache memory");
    for (int ix = 0; ix < MAX_DOLLARS; ix++) {
        free(cache[ix]);
        cache[ix] = NULL;
    }
}

