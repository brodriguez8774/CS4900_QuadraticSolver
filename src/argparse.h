#ifndef _ARGPARSE_H
#define _ARGPARSE_H
#include <stdlib.h>

typedef struct {
    unsigned char optional;
    const char *text;
    const char *flag;
    const char *help;
    const char *value; // value after parsing
} ARGUMENT;

typedef struct {
    const char *prologue;
    const char *description;
    const char *epilogue;
    size_t arguments_length;
    size_t arguments_size;
    ARGUMENT **arguments;
} ARGPARSE;

ARGPARSE *argparse_new(const char *prologue, const char *description, const char *epilogue, size_t num_args);
void argparse_free(ARGPARSE *argparse);

size_t argparse_add_argument(
        ARGPARSE *argparse, const char *text, const char *flag,
        const char *help);
const char *argparse_get_argument(ARGPARSE *argparse, size_t key);

void argparse_parse(ARGPARSE *argparse, int argc, char **argv);

#endif // _ARGPARSE_H
