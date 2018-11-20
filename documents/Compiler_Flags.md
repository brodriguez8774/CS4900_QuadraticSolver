## Compiler Flags

### Description
The quadratic solver program uses multiple flags to compile. This document will list them and explain why they are used.

#### -Wall
Wall is used to enable many warnings that would otherwise be ignored. Typically these warnings can cause undesired and inconsistent behavior if ignored. Although we have already tested that the program compiles while using the Wall flag, there may come a time when we need to add more code and make changes to existing code. Therefore, if modifications need to be made to the quadratic solver, it is important to maintain the program's stability by keeping the Wall flag present.

#### -pedantic
Similar to Wall, we want to prevent any undesired or inconsistent behavior that may occur after compilation. pedantic enables more warning messages during compilation that would otherwise be ignored.

### -std=c99
This tells the compiler we want to follow the C99 standard during compilation.

### -g
g allows the compiler to produce debugging information that may be useful.
