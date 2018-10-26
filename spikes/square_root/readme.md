
# C - Quadratic Solver > Spikes > IEEE Floating Point

## Description
Spikes specific to the square root function from the Math library.

## Spikes
**Author:**\
Joshua Sziede 
### Running
To compile sqrt_spike.c:

`$ make`

To run the program after compilation:

`$ ./sqrt <double>`

where `<double>` is any number. Alternatively, using

`$ make test`

will run the program using the number *123456.78*. If a number is not provided upon process execution, the program will prompt the user to enter one during runtime.

### Square Root
Implementation and testing of the possible outputs the Math library sqrt function can compute. Given a number, the program will provide the user with multiple outputs consisting of the input number as both a double and a float, as well as using two different square root functions meant for the two number types. This process is then repeated using the inverse of the input number.

### Examples
```
$ ./sqrt 4562.7366
Results of square rooting 4562.736600:
Expected square root:	67.548032
Floated square root:	67.548035
Difference:		-0.000003

Results of square rooting with floated input:
Expected square root:	67.548035
Floated square root:	67.548035
Difference:		0.000000

Now doing the inverse.

Results of square rooting -4562.736600:
Expected square root:	-nan
Floated square root:	-nan
Difference:		-nan

Results of square rooting with floated input:
Expected square root:	-nan
Floated square root:	-nan
Difference:		-nan
```

```
$ ./sqrt -23
Results of square rooting -23.000000:
Expected square root:	-nan
Floated square root:	-nan
Difference:		-nan

Results of square rooting with floated input:
Expected square root:	-nan
Floated square root:	-nan
Difference:		-nan

Now doing the inverse.

Results of square rooting 23.000000:
Expected square root:	4.795832
Floated square root:	4.795832
Difference:		-0.000000

Results of square rooting with floated input:
Expected square root:	4.795832
Floated square root:	4.795832
Difference:		0.000000
```

```
$ ./sqrt 0
Results of square rooting 0.000000:
Expected square root:	0.000000
Floated square root:	0.000000
Difference:		0.000000

Results of square rooting with floated input:
Expected square root:	0.000000
Floated square root:	0.000000
Difference:		0.000000

Now doing the inverse.

Results of square rooting -0.000000:
Expected square root:	-0.000000
Floated square root:	-0.000000
Difference:		0.000000

Results of square rooting with floated input:
Expected square root:	-0.000000
Floated square root:	-0.000000
Difference:		0.000000
```

```
$ ./sqrt inf
Results of square rooting inf:
Expected square root:	inf
Floated square root:	inf
Difference:		-nan

Results of square rooting with floated input:
Expected square root:	inf
Floated square root:	inf
Difference:		-nan

Now doing the inverse.

Results of square rooting -inf:
Expected square root:	-nan
Floated square root:	-nan
Difference:		-nan

Results of square rooting with floated input:
Expected square root:	-nan
Floated square root:	-nan
Difference:		-nan
```

```
$ ./sqrt nan
Results of square rooting nan:
Expected square root:	nan
Floated square root:	nan
Difference:		nan

Results of square rooting with floated input:
Expected square root:	nan
Floated square root:	nan
Difference:		nan

Now doing the inverse.

Results of square rooting -nan:
Expected square root:	-nan
Floated square root:	-nan
Difference:		-nan

Results of square rooting with floated input:
Expected square root:	-nan
Floated square root:	-nan
Difference:		-nan
```