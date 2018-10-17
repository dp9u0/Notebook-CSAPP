/*
 * A. x 的任何位都等于 1
 * B. x 的任何位都等于 0
 * C. x 的最高有效字节中的位都等于 1
 * D. x 的最低有效字节中的位都等于 0
*/
#include <stdio.h>
#define LEFT_SHIFT (sizeof(int) - 1 << 3)

int A(int x)
{
    return !~x;
}

int B(int x)
{
    return !x;
}

int C(int x)
{
    return A(x | (~(0xff << LEFT_SHIFT)));
}

int D(int x)
{
    printf("%x\n", (x & 0xff));
    return B(x & 0xff);
}

int main(int argc, char *argv[])
{
    int all_bit_one = ~0;
    int all_bit_zero = 0;

    printf("A(all_bit_one) = 1 : %d\n", A(all_bit_one));
    printf("B(all_bit_one) = 0 : %d\n", B(all_bit_one));
    printf("C(all_bit_one) = 1 : %d\n", C(all_bit_one));
    printf("D(all_bit_one) = 0 : %d\n", D(all_bit_one));

    printf("A(all_bit_zero) = 0 : %d\n", A(all_bit_zero));
    printf("B(all_bit_zero) = 1 : %d\n", B(all_bit_zero));
    printf("C(all_bit_zero) = 0 : %d\n", C(all_bit_zero));
    printf("D(all_bit_zero) = 1 : %d\n", D(all_bit_zero));

    // test 0x1234ff

    printf("A(0xff123400) = 0 : %d\n", A(0xff123400));
    printf("B(0xff123400) = 0 : %d\n", B(0xff123400));
    printf("C(0xff123400) = 1 : %d\n", C(0xff123400));
    printf("D(0xff123400) = 1 : %d\n", D(0xff123400));

    // test 0x1234
    printf("A(0x1234) = 0 : %d\n", A(0x1234));
    printf("B(0x1234) = 0 : %d\n", B(0x1234));
    printf("C(0x1234) = 0 : %d\n", C(0x1234));
    printf("D(0x1234) = 0 : %d\n", D(0x1234));
}