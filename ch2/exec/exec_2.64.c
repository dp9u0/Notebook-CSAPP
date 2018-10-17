/*
 * Return 1 when any even bit of x equals 1; 0 otherwise.  
 * Assume w=32
 */

#include <stdio.h>

int any_even_one(unsigned x)
{
    return (x & 0x55555555) && 1;
}

int main(int argc, char *argv[])
{
    printf("%d\n", any_even_one(0x2));
    printf("%d\n", any_even_one(0x4));
}