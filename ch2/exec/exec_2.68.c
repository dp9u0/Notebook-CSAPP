#include <stdio.h>

/*
 * Make with least signficant n bits set to 1
 * n = 6 --> 0x3f
 * n = 17 --> 0x1FFFF
 * Assume 1 <= n <= w
 *         int lower_bits(int x, int n);
 * 函数应该遵循位级整数编码规则。
 * 要注意 n = w 的情况
 */

static  int w = sizeof(int) << 3;

int lower_bits(int x, int n)
{
    // int mask = (1<<(n-1)) - 1 + (1<<(n-1));
    return x | ((unsigned) -1 >> (w - n));
}

int main(int argc, char *argv[])
{
    printf("%x\n", lower_bits(0, 1));
    printf("%x\n", lower_bits(0, 6));
    printf("%x\n", lower_bits(0, 17));
    printf("%x\n", lower_bits(0, 32));
}