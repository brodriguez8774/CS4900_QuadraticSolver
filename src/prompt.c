#include <stdio.h>
#include "helper.h"


/**
 * Prompt a user for input.
 *
 * text: The text that will be shown to the user.
 * options: If not NULL, then is displayed just before the
 *     location where the user types.
 * size: The size of the buffer to create. At most size-1
 *     characters will be written, and the string will be
 *     null terminated. (See fgets())
 *
 * Returns an allocated string of submitted text.
 * The caller should call free() on it when done.
 *
 * Examples:
 *
 * prompt_user("Do you want to quit?", "(y/N)", 2);
 *
 *     Do you want to quit?
 *     (y/N): _
 *
 * prompt_user("What is your name?", NULL, 255);
 *
 *     What is your name?
 *     : _
 */
char *prompt_user(char *text, char *options, size_t size) {
    printf("%s\n", text);
    if (options) {
        printf("%s", options);
    }
    printf(": ");
    char *buffer = calloc_or_quit(size, 1);
    fgets(buffer, size, stdin);

    return buffer;
}
