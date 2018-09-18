/**
 * argparse.c
 * Simple library to parse command line arguments.
 */
#include <stdio.h>
#include <string.h>

#include "argparse.h"
#include "helper.h"

#define DESCRIPTION_OFFSET 16

ARGPARSE *argparse_new(
        const char *prologue, const char *description, const char *epilogue,
        size_t num_args) {
    ARGPARSE *argparse = calloc_or_quit(1, sizeof(ARGPARSE));

    ++num_args; // add 1 for help

    argparse->prologue = prologue; // TODO: strncpy these
    argparse->description = description;
    argparse->epilogue = epilogue;
    argparse->arguments_size = num_args;
    argparse->arguments_length = 0;
    argparse->arguments = calloc_or_quit(num_args, sizeof(ARGUMENT*));

    for (size_t i = 0; i < num_args; ++i) {
        argparse->arguments[i] = calloc_or_quit(1, sizeof(ARGUMENT));
    }

    argparse_add_argument(argparse, "--help", "-h", "Show this help text");

    return argparse;
}

void argparse_free(ARGPARSE *argparse) {
    free(argparse);
}

// Returns a key (index) so caller can use to get parsed results for argument
size_t argparse_add_argument(
        ARGPARSE *argparse, const char *text, const char *flag,
        const char *help) {
    if (argparse->arguments_length >= argparse->arguments_size) {
        // Not enough room to add another argument
        code_error_quit("arguments array size exceeded");
    } else if (text == NULL) {
        code_error_quit("text argument can't be NULL");
    }

    size_t index = argparse->arguments_length++;

    ARGUMENT *argument = argparse->arguments[index];
    argument->optional = 0;
    argument->text = text;
    argument->flag = flag;
    argument->help = help;
    argument->value = NULL;

    if (flag != NULL || strncmp(text, "--", 2) == 0) {
        argument->optional = 1;
    }

    return index;
}

const char *argparse_get_argument(ARGPARSE *argparse, size_t key) {
    if (key < 0 || key >= argparse->arguments_length) {
        code_error_quit("invalid key");
    }

    return argparse->arguments[key]->value;
}

void argparse_print_help(ARGPARSE *argparse, const char *arg0) {
    ARGUMENT *argument = NULL;
    short x, i;

    if (argparse->prologue) {
        printf("%s\n\n", argparse->prologue);
    }
    if (argparse->description) {
        printf("Description:\n%s\n\n", argparse->description);
    }

    printf("Usage: %s", arg0);

    // TODO: Print out arguments and usage here
    for (short i = 0; i < argparse->arguments_length; ++i) {
        argument = argparse->arguments[i];
        if (argument->optional == 0) {
            printf(" %s", argument->text);
        }
    }

    printf("\n\nArguments:\n");

    // Print out each arguments help text
    for (i = 0; i < argparse->arguments_length; ++i) {
        argument = argparse->arguments[i];
        x = printf("   ");
        if (argument->flag) {
            x += printf("%s, ", argument->flag);
        }
        x += printf("%s", argument->text);
        for (; x < DESCRIPTION_OFFSET;) {
            x += printf(" ");
        }
        if (argument->help) {
            printf("%s", argument->help);
        }
        printf("\n");
    }

    if (argparse->epilogue) {
        printf("%s\n", argparse->epilogue);
    }
}

void argparse_parse(ARGPARSE *argparse, int argc, char **argv) {
    // Count how many args we require at a minimum
    int require = 1; // Always require the first argument (program name)
    short i, j;
    ARGUMENT *argument = NULL;
    for (i = 0; i < argparse->arguments_length; ++i) {
        argument = argparse->arguments[i];
        if (argument->optional == 0) {
            ++require;
        }
    }

    if (argc < require) {
        // print help and quit
        argparse_print_help(argparse, argv[0]);
    } else {
        // TODO: Parse args to see if need to show help
        printf("Checking arguments...\n");

        const char *value = NULL;
        for (i = 1; i < argc; ++i) {
            value = argv[i];

            // First pass getting all required/positional arguments
            for (j = 0; j < argparse->arguments_length; ++j) {
                argument = argparse->arguments[j];
                if (argument->value) {
                    continue; // already processed
                } else if (argument->flag && strncmp(value, argument->flag, 2) == 0) {
                    printf("TODO: Trigger argument for %s\n", argument->text);
                    break;
                } else if (argument->optional == 0) {
                    argument->value = value;
                    break; // found our positional argument
                }
            }
        }

    }
}
