#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

/* print_byte based from https://stackoverflow.com/a/19885112 */
const char *bit_rep[16] = {
    [ 0] = "0000", [ 1] = "0001", [ 2] = "0010", [ 3] = "0011",
    [ 4] = "0100", [ 5] = "0101", [ 6] = "0110", [ 7] = "0111",
    [ 8] = "1000", [ 9] = "1001", [10] = "1010", [11] = "1011",
    [12] = "1100", [13] = "1101", [14] = "1110", [15] = "1111",
};

int print_byte(char *buffer, size_t length, u_int8_t byte)
{
    return snprintf(buffer, length, "%s %s", bit_rep[byte >> 4], bit_rep[byte & 0x0F]);
}

/**
 * Assumes little endian
 */
char *make_bytes_string(size_t size, const void *data) {
    size_t i = size;
    char *casted = (char *)data;
    char *text = calloc(500, sizeof(char));
    size_t offset = 0;
    for (i = 0; i < size; ++i) {
        offset += print_byte((char*)(text+offset), 500-offset, *(u_int8_t *)(casted+size-i-1));
        offset += snprintf((char*)(text+offset), 2, " ");
    }
    return text;
}

void debug_print_ieee_float(const void *number) {
    printf("Memory address: %p\n", number);
    const float as_float = *(float *)number;
    const unsigned int as_int = *(int *)number;

    const unsigned char sign =        as_int >> 31;
    const unsigned char biased_exp =  (as_int << 1) >> 24;
    const unsigned int significand = (as_int << 9) >> 9;
    const char *significand_string = make_bytes_string(3, &significand)+1; // +1 to ignore first bit

    printf("Debug float: %f\n", as_float);
    printf("As int:      %u\n", as_int);
    printf("Sign bit:    %d\n", sign);
    printf("Exp+bias:    %d    (-127= %d)\n", biased_exp, biased_exp - 127);
    printf("Signifcand:  %s\n", significand_string);
    printf("=-1^(%d) x (1 + 0.%s) x 2^(%d)\n", sign, significand_string, biased_exp - 127);
    printf("bits: %s\n", make_bytes_string(sizeof(int), number));
}
