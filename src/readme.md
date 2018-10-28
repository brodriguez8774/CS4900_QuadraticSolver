
# C - Quadratic Solver > Src

## Description
Project source code goes here.

## Spikes
**Authors:**\
Steven Johnson
Brandon Rodriguez
Joshua Sziede 

### Running
To compile main.c:

`$ make`

To run the program after compilation:

`$ ./quad_solver`

### Quadratic Solver
The purpose of this program is to solve the equation _ax² + bx + c = 0_ when provided the three constants _a_, _b_, and _c_. The user can either provide the values of the three constants as command line arguments or the program will prompt the user for the values during execution if they are not provided as arguments. The values of both _x²_ and _x_ are output to the user as _X1_ and _X2_ respectively upon completion of the quadratic formula calculation, as well as if both _X_ values could contain any rounding errors.

### Examples
Complete examples will be provided when the program is completed. Rudimentary examples are as follows:
```
$ ./quad_solver
Calculating -2.000000x^2 + 4.000000x + 0.000000.
Results:
	X1: -0.000000
	Possible rounding error: No

	X2: 2.000000
	Possible rounding error: No

Exiting program with code of 0.
```

```
$ ./quad_solver
Calculating -2.000000x^2 + 4.522222x + 0.000000.
Answer:
	X1: -0.000000
	Possible rounding error: Yes

	X2: 2.261111
	Possible rounding error: Yes

Exiting program with code of 0.
```

## TODO
Mention the program arguments in the readme.
Finish the string to double parsing for the input values.
Add logging functionality for when logging mode is enabled.
Report on specific rounding errors and not just whether or not errors could have occurred.
