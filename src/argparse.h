#ifndef _ARGPARSE_H
#define _ARGPARSE_H

typedef struct {
    unsigned char optional;
} ARGUMENT;

typedef struct {
    unsigned short arguments_length;
    ARGUMENT **arguments;
} ARGPARSE;

ARGPARSE *argparse_new();
void argparse_free(ARGPARSE *argparse);

#endif // _ARGPARSE_H
