
# C - Quadratic Solver

## Authors
* Steven Johnson
* Brandon Rodriguez
* Joshua Sziede

## Description
A console program to solve quadratic equations. See program help for more details.

## Building and Running

To build run:

    $ make

Now you can run the program and see the help text:

    $ src/quad_solver -h

For development, you should use valgrind. First install valgrind if not installed:

    $ sudo apt install valgrind

Then to build and run valgrind on the executable, run:

    $ make valgrind

Valgrind will report pointers that were allocated but not freed.

## Distributing

To create a .tar.gz of source files run:

    $ make distribute

The file will be named quad-solver-<VERSION>.tar.gz

## Testing

To run all the tests:

    $ make test