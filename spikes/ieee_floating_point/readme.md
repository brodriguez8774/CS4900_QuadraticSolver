
# C - Quadratic Solver > Spikes > IEEE Floating Point

## Description
Spikes specific to IEEE Floating Point manipulation.

## Spikes
**Authors:**\
Steven Johnson\
Joshua Sziede 
### Running
To compile float.c:

`$make`

To run the program after compilation:

`$./float <float>`

where `<float>` is any number. Alternatively, using

`$make test`

will run the program using the number *123456.78*. If a number is not provided upon process execution, the program will prompt the user to enter one during runtime.

### Float
Implementation and testing of how single-digit precise floating point numbers work. Given a number, the float program will provide the user with some details on how that number is stored as a float as well as possible rounding errors that occurred during the number's conversion to a float. The user is also provided some details specific to their machine on how it handles floats.
