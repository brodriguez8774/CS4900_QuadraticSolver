
# C - Quadratic Solver > Spikes > Unit Testing

## Description
Spikes specific to unit testing using CUnit.

## About CUnit
General information and documentation for CUnit can be found at http://cunit.sourceforge.net/.

An additional example of running CUnit is located at http://cunit.sourceforge.net/example.html.

### Installation
For linux machines, you will need to install (through apt or your respective linux package manager):
* libcunit1
* libcunit1-doc
* libcunit1-dev

Example: ``sudo apt install libcunit1 libcunit1-doc libcunit1-dev``

### Make File
To compile with CUnit, add the **-lcunit** flag to include the CUnit library.

### Using CUnit
To run CUnit within your program, you will need to:
* Initialize a CUnit registry.
** On major failure or program exit, this registry should be cleared.
* Create one or more tests suites. Each suite can have its own setup and teardown methods.
** If familiar with Python unit testing, a CUnit test suite is equivalent to a Python test class.
* Create one or more unit tests for each test suite.
** If familiar with Python unit testing, a CUnit unit test is equivalent to a Python test function.
* Run tests through CUnit's interface.
