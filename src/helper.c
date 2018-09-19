/**
 * helper.c
 * Contains miscellaneous helper functions for the project.
 */
#include <stdio.h>

#include "helper.h"

/**
 * Same arguments as calloc, but calls perror() on error and exits.
 */
void *calloc_or_quit(size_t nmemb, size_t size) {
    void *ptr = calloc(nmemb, size);
    if (ptr == NULL) {
        perror("Failed to allocate memory");
        exit(1);
    }

    return ptr;
}
