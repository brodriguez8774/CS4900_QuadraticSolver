/**
 * argparse.c
 * Simple library to parse command line arguments.
 */
#include <stdio.h>
#include <string.h>

#include "argparse.h"
#include "helper.h"

#define DESCRIPTION_OFFSET 16

/**
 * Create an ARGPARSE object.
 *
 * prologue, description, and epilogue are optional and can be NULL.
 *
 * NOTE: num_args must be set to at least the number of arguments that will be
 * added (not including the help argument).
 *
 * Always includes the -h, --help argument to display help text.
 *
 * Caller should call argparse_free() when done
 */
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

    argparse->arg_help = argparse_add_argument(
        argparse, "--help", "-h", "Show this help text", 0);

    return argparse;
}

/**
 * Release resources used by argparse.
 */
void argparse_free(ARGPARSE *argparse) {
    // free each argument
    for (size_t i = 0; i < argparse->arguments_size; ++i) {
        if (argparse->arguments[i]->values) {
            free(argparse->arguments[i]->values);
        }
        free(argparse->arguments[i]);
    }

    free(argparse->arguments);
    free(argparse);
}

/**
 * Add an argument to the parser.
 *
 * If flag is given (e.g. "-x") or text starts with "--" (e.g. "--extra") then
 * it is assumed the argument is optional.
 *
 * help is shown next to the argument text (and flag if given) when the help
 * text is shown.
 *
 * Will exit() if there is no more room to add an argument.
 *
 * Returns a key that can be used with argparse_get_argument() after
 * argparse_parse() has been run, to get whether the flag was provided or the
 * string value for a positional argument.
 */
ARGKEY argparse_add_argument(
        ARGPARSE *argparse, const char *text, const char *flag,
        const char *help, size_t nargs) {
    if (argparse->arguments_length >= argparse->arguments_size) {
        // Not enough room to add another argument
        code_error_quit("arguments array size exceeded");
    } else if (text == NULL) {
        code_error_quit("text argument can't be NULL");
    }

    size_t index = argparse->arguments_length++;

    ARGUMENT *argument = argparse->arguments[index];
    argument->optional = 0;
    argument->nargs = nargs;
    argument->text = text;
    argument->flag = flag;
    argument->help = help;
    argument->value = NULL;
    argument->values = NULL;
    argument->set = 0;

    if (flag != NULL || strncmp(text, "--", 2) == 0) {
        argument->optional = 1;
    }

    return index;
}

/**
 * Get whether the argument matching the given key was provided.
 *
 * Positional arguments or nargs == 1 will have strings stored in the pointer
 * given by value if value is not NULL.
 * 
 * Arguments with nargs > 1 will have an array of strings stored in the pointer
 * given by values if values is not NULL.
 *
 * Returns 1 if argument was given, and 0 if not.
 */
char argparse_get_argument(ARGPARSE *argparse, ARGKEY key, const char **value, const char ***values) {
    if (key < 0 || key >= argparse->arguments_length) {
        code_error_quit("invalid key");
    }

    if (argparse->arguments[key]->nargs > 1 && values) {
        *values = argparse->arguments[key]->values;
    } else if (value) {
        *value = argparse->arguments[key]->value;
    }

    return argparse->arguments[key]->set;
}

/**
 * Print out the help text for all current arguments.
 */
void argparse_print_help(ARGPARSE *argparse, const char *arg0) {
    ARGUMENT *argument = NULL;
    short x, i, j;

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
        printf("   ");
        if (argument->flag) {
            printf("%s, ", argument->flag);
        }
        printf("%s ", argument->text);
        for (j = 0; j < argument->nargs; ++j) {
            printf("VALUE ");
        }
        printf("\n");
        for (x = 0; x < DESCRIPTION_OFFSET;) {
            x += printf(" ");
        }
        if (argument->help) {
            printf("%s", argument->help);
        }
        printf("\n");
    }

    if (argparse->epilogue) {
        printf("\n%s\n", argparse->epilogue);
    }
}

/**
 * Parse given arguments.
 *
 * Returns 1 if not enough required arguments were given, or the help text was
 * asked to be shown. Caller should free the argparse object.
 *
 * Returns 0 otherwise. Caller should use argparse_get_argument() to see values.
 */
char argparse_parse(ARGPARSE *argparse, int argc, char **argv) {
    // Count how many args we require at a minimum
    int require = 1; // Always require the first argument (program name)
    short i, j, k;
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
        return 1;
    } else {
        // Actually parse the arguments
        const char *value = NULL;
        for (i = 1; i < argc; ++i) {
            value = argv[i];

            for (j = 0; j < argparse->arguments_length; ++j) {
                argument = argparse->arguments[j];
                if (argument->set) {
                    continue; // already processed
                } else if (argument->flag && (
                    strncmp(value, argument->flag, 2) == 0 ||
                    strcmp(value, argument->text) == 0)
                ) {
                    if (argument->nargs > 0) {
                        // Need to process more arguments
                        if (i + argument->nargs >= argc) {
                            // Required values not given!
                            argparse_print_help(argparse, argv[0]);
                            return 1;
                        }

                        if (argument->nargs == 1) {
                            // Just need to get one value
                            argument->value = argv[++i];
                        } else {
                            // Need to get an array of values
                            argument->values = calloc_or_quit(argument->nargs, sizeof (char*));
                            for (k = 1; k <= argument->nargs; ++k) {
                                argument->values[k-1] = argv[i + k];
                            }

                            // Don't process the values again
                            i += argument->nargs;
                        }
                    }
                    
                    argument->set = 1;
                    break;
                } else if (argument->optional == 0) {
                    argument->value = value;
                    argument->set = 1;
                    break; // found positional argument
                }
            }
        }
    }

    if (argparse_get_argument(argparse, argparse->arg_help, NULL, NULL)) {
        // print help and quit
        argparse_print_help(argparse, argv[0]);
        return 1;
    }

    // Verify positional arguments are given since they are not optional
    for (i = 0; i < argparse->arguments_length; ++i) {
        argument = argparse->arguments[i];
        if (argument->optional == 0 && argument->set != 1) {
            // print help and quit
            argparse_print_help(argparse, argv[0]);
            return 1;
        }
    }

    return 0;
}
