#include <stdio.h>
#include <stdlib.h>
#include "numberwords.h"
#include "cache.h"

int main() {
    initialize_cache();

    int test_values[] = {123, 456, 123, 789, 456, -1};
    int num_tests = sizeof(test_values) / sizeof(test_values[0]);

    for (int i = 0; i < num_tests; i++) {
        char* result = cache_func(test_values[i]);
        printf("Result for %d: %s\n", test_values[i], result);
        free(result);
    }

    free_cache();
    return 0;
}
