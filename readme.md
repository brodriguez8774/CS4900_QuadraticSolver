
# C - Quadratic Solver

## Authors
* Steven Johnson
* Brandon Rodriguez
* Joshua Sziede

## Description
A console program to solve quadratic equations. See program help for more details.

## Building and Running

To build, change to the `src` directory and run:

    $ make

Now you can run the program and see the help text:

    $ ./quad_solver -h

For development, you should use valgrind. First install valgrind if not installed:

    $ sudo apt install valgrind

Then to build and run valgrind on the executable, run:

    $ make valgrind

Valgrind will report pointers that were allocated but not freed.

TODO: Finish writing the source files in the src directory.
