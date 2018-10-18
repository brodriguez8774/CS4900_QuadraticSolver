/**
* CS 4900
* IEEE Floating Point Spike
* Author: Joshua Sziede
*/

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "./sandbox/sandbox.h"

#define BUFF 50	//maximum number of characters to store from stdin

int main(int argc, char* argv[]) {
	float number;			//stores the input number as a floating point
	double numberPrecise;	//stores the input number as a double for increased precision
	double roundError;		//stores the difference of the input as a float and as a double

	if(argc < 2) {	//if no number was provided as an arg
		printf("Enter a number to see its floating point format:\nNote - keywords such as \"infinity\" and \"NaN\" are also acceptable.\n");
		
		char valid = '0';	//determines whether or not number has a proper value
		char buffer[BUFF];	//stores the user input from stdin

		while (valid == '0') { //while number does not have a value
			if (fgets(buffer, sizeof(buffer), stdin)) {	//if user provides input
			    if (1 == sscanf(buffer, "%le", &numberPrecise)) { //if input is good
			    	//cast input as a float and prepares to exit loop
			    	number = (float) numberPrecise;
			        valid = '1';
			    }
			}
			fflush(stdin);
		}
	} else { //at least one argument was provided
		//converts the argument string into digits
		number = atof(argv[1]);
		sscanf(argv[1], "%le", &numberPrecise);

		if (argc > 2) { //if multiple arguments, only first one is used
			printf("Multiple args provided, only using the first.\n");
		}
	}

	roundError = numberPrecise - number;

	char* floatRound;	//the method of rounding used by the system
	if (FLT_ROUNDS == -1) {
		floatRound = "(-1) Indeterminable";
	} else if (FLT_ROUNDS == 0) {
		floatRound = "(0) Towards zero";
	} else if (FLT_ROUNDS == 1) {
		floatRound = "(1) To nearest";
	} else if (FLT_ROUNDS == 2) {
		floatRound = "(2) Towards positive infinity";
	} else if (FLT_ROUNDS == 3) {
		floatRound = "(3) Towards negative infinity";
	} 

	//who doesn't love fun facts?
	printf("\nFirst of all, here are some fun facts on how your machine handles floating point numbers!\nMax value of floats: %f\nMin value of positive floats: %f\nRounding method: %s\nMantissa precision: %i bits\n", FLT_MAX, FLT_MIN, floatRound, FLT_MANT_DIG);

	printf("\nYour input number as a float: %f\nRounding error: %lf\n", number, roundError);

	debug_print_ieee_float(&numberPrecise);
}