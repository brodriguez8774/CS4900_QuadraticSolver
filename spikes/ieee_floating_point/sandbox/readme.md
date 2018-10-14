QuadSolver

This sandbox folder is to test out how IEEE works.

I learned that the significand in binary is literally the binary follow "1."
for a normalized float. I also learned that my computer is little endian and
that is how the floats are in memory. (They typically match whatever ints use)
-Steven

Directions:

In this folder run:

$ make

Now run and give a float:

$ ./sandbox FLOAT

Example:

$ ./sandbox 5
Interpreted 5.000000
Size of float: 4
Size of short: 2
Size of int:   4
Size of long:  8
Memory address: 0x7ffe3f3f5244
Debug float: 5.000000
As int:      1084227584
Sign bit:    0
Exp+bias:    129    (-127= 2)
Signifcand:  010 0000 0000 0000 0000 0000
=-1^(0) x (1 + 0.010 0000 0000 0000 0000 0000 ) x 2^(2)
bits: 0100 0000 1010 0000 0000 0000 0000 0000

Now doing inverse...
Memory address: 0x7ffe3f3f5244
Debug float: -5.000000
As int:      3231711232
Sign bit:    1
Exp+bias:    129    (-127= 2)
Signifcand:  010 0000 0000 0000 0000 0000
=-1^(1) x (1 + 0.010 0000 0000 0000 0000 0000 ) x 2^(2)
bits: 1100 0000 1010 0000 0000 0000 0000 0000
