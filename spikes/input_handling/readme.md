
# C - Quadratic Solver > Spikes > Input Handling

## Description
Spikes specific to handling user input.

## Spikes

### Simple Parse
A basic implementation of handling argv input.
* Parses out values from argv, using basic counting and indexes.
* If a specific arg (such as --help) is provided, then it must be in a specific, predetermined index to handle.

### Arg Parse
A more robust implementation of handling argv input.
* Parses out values from argv and feeds into "argparse" functions.
* These functions can take expected positional elements and optional args.
* Args are not limited to one single index location of argv.

### Std In
A basic implementation of handling standard in.
* Uses low level read and write commands.
* Implemented in a way that checks for multiple input lines for each read in.
