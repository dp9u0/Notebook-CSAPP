#include <stdio.h>
#include <limits.h>

int divide_power2(int x, int k)
{
    int bias = 0;
    int sign = (x & INT_MIN) == INT_MIN;
    (sign && (bias = (1 << k) - 1));
    return (x + bias) >> k;
}

/*
 * 2.79
 *
 * 写出函数 fiveeighths 的代码，对于整数参数 x，计算 5/8x 的值，向零舍入。
 * 它不会溢出。
 * 遵循整数位级编码规则。
 */

int fiveeighths(int x)
{
    int div = divide_power2(x, 3);
    return (div << 2) + div;
}

int main(int argc, char *argv[])
{
    printf("%x\n", fiveeighths(8) == 8 / 8 * 5);
    printf("%x\n", fiveeighths(9) == 9 / 8 * 5);
    printf("%x\n", fiveeighths(10) == 10 / 8 * 5);
    printf("%x\n", fiveeighths(11) == 11 / 8 * 5);
    printf("%x\n", fiveeighths(12) == 12 / 8 * 5);

    printf("%x\n", fiveeighths(-8) == -8 / 8 * 5);
    printf("%x\n", fiveeighths(-9) == -9 / 8 * 5);
    printf("%x\n", fiveeighths(-10) == -10 / 8 * 5);
    printf("%x\n", fiveeighths(-11) == -11 / 8 * 5);
    printf("%x\n", fiveeighths(-12) == -12 / 8 * 5);
}