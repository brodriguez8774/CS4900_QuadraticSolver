/**
 * argparse.c
 * Simple library to parse command line arguments.
 */
#include "argparse.h"
#include "helper.h"

ARGPARSE *argparse_new() {
    ARGPARSE *argparse = calloc_or_quit(1, sizeof argparse);

    // TODO: Setup

    return argparse;
}

void argparse_free(ARGPARSE *argparse) {
    free(argparse);
}
