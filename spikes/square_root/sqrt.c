#include <math.h>
#include <stdio.h>

void do_square_root(long double *num) {
	float as_float_from_double = (float) sqrtl(*num);
	long double as_double_from_double = sqrtl(*num);

	float num_to_float = (float) *num;
	float as_float_from_float = (float) sqrtf(num_to_float);
	long double as_double_from_float = sqrtf(num_to_float);

	long double diff = as_double_from_double - as_float_from_double;
	long double diff_rounded = as_double_from_float - as_float_from_float;

	printf("Results of square rooting %Lf:\n"
"Expected square root:	%Lf\n"
"Floated square root:	%f\n"
"Difference:		%Lf\n\n"
"Results of square rooting with floated input:\n"
"Expected square root:	%Lf\n"
"Floated square root:	%f\n"
"Difference:		%Lf\n"
,*num, as_double_from_double, as_float_from_double, diff, as_double_from_float, as_float_from_float, diff_rounded);
}