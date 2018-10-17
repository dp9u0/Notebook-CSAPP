#include <stdio.h>

/*
 * 2.70
 *
 * 写出具有如下原型的函数的代码：
 *
 * 1  : x can be represented as an n-bit, 2's complement number
 * 0  : otherwise
 * Assume 1 <= n <= w
 *         int fits_bits(int x, int n);
 * 函数应该遵循位级整数编码规则。
 */

/* 一个数是否可以使用n位补码表示
   * w = 8, n = 3
   * x > 0, w-n位全为 0
   *   0b00000010
   *   0b00001010 no
   *   0b00000110 no
   * x < 0, w-n位全为 1
   *   0b11111100 
   *   0b10111100 no
   *   0b11111000 no
*/

static int w = sizeof(int) << 3;

int fits_bits(int x, int n)
{
    // x << (w-n) >> (w-n)  == x
    // printf("-----------------\n");
    // printf("x : %x\n", x);
    // printf("(w - n) : %d\n", (w - n));
    // printf("x << (w - n) : %x\n", x << (w - n));
    // printf("(x << (w - n) >> (w - n)) : %x\n", (x << (w - n) >> (w - n)));
    return (x << (w - n) >> (w - n)) == x;
}

int main(int argc, char *argv[])
{
    printf("%x\n", !fits_bits(0xFF, 8));
    printf("%x\n", !fits_bits(~0xFF, 8));

    printf("%x\n", fits_bits(0b0010, 3));
    printf("%x\n", !fits_bits(0b1010, 3));
    printf("%x\n", !fits_bits(0b0110, 3));

    printf("%x\n", fits_bits(~0b11, 3));
    printf("%x\n", !fits_bits(~0b01000011, 3));
    printf("%x\n", !fits_bits(~0b111, 3));
    return 0;
}