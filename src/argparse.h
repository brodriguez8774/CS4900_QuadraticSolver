/**
 * CS 4900
 * Header file for argument parse handling.
 */


// Import headers.
#ifndef _ARGPARSE_H
#define _ARGPARSE_H
#include <stdlib.h>


// Encapsulate away the key type
typedef size_t ARGKEY;

typedef struct {
    unsigned char set; // boolean
    unsigned char optional;
    size_t nargs; // number of arguments immediately after this argument
    const char *text;
    const char *flag;
    const char *help;
    const char *value; // value after parsing
    const char **values; // if nargs > 1, array of values
} ARGUMENT;

typedef struct {
    const char *prologue;
    const char *description;
    const char *epilogue;
    size_t arguments_length;
    size_t arguments_size;
    ARGKEY arg_help;
    ARGUMENT **arguments;
} ARGPARSE;


// Function Prototypes.
ARGPARSE *argparse_new(const char *prologue, const char *description, const char *epilogue, size_t num_args);
void argparse_free(ARGPARSE *argparse);

ARGKEY argparse_add_argument(
        ARGPARSE *argparse, const char *text, const char *flag,
        const char *help, size_t nargs);
char argparse_get_argument(ARGPARSE *argparse, ARGKEY key, const char **value, const char ***values);

char argparse_parse(ARGPARSE *argparse, int argc, char **argv);

#endif // _ARGPARSE_H
