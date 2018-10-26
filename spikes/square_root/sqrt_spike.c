/**
* CS 4900
* Square Root Spike
* Author: Joshua Sziede
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sqrt.h"

#define BUFF 50	//maximum number of characters to store from stdin

int main(int argc, char* argv[]) {
	long double number;	//stores the input number as a floating point

	if(argc < 2) {	//if no number was provided as an arg
		printf("Enter a number to see its square root value.\n");

		char valid = '0';	//determines whether or not number has a proper value
		char buffer[BUFF];	//stores the user input from stdin

		while (valid == '0') { //while number does not have a value
			if (fgets(buffer, sizeof(buffer), stdin)) {	//if user provides input
			    if (1 == sscanf(buffer, "%Le", &number)) { //if input is good
			    	//cast input as a float and prepares to exit loop
			        valid = '1';
			    }
			}
			fflush(stdin);
		}
	} else { //at least one argument was provided
		//converts the argument string into digits
		number = atol(argv[1]);
		sscanf(argv[1], "%Le", &number);

		if (argc > 2) { //if multiple arguments, only first one is used
			printf("Multiple args provided, only using the first.\n");
		}
	}

	do_square_root(&number);
	printf("\nNow doing the inverse.\n\n");
	number = number * -1;
	do_square_root(&number);
}