/**
 * Return 1 when x contains an even number of 1s; 0 otherwise.
 * Assume w=32
*/

#include <stdio.h>

// https://stackoverflow.com/questions/9133279/bitparity-finding-odd-number-of-bits-in-an-integer

int even_ones(unsigned x)
{
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;
    x &= 0x1;
    return !x;
}

int main(int argc, char *argv[])
{
    printf("%d\n", even_ones(0x10101011));
    printf("%d\n", even_ones(0x01010101));
}