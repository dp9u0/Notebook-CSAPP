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
 * 2.78
 *
 * 写出函数 mul5div8 的代码，对于整数参数 x，计算 5*x/8，
 * 遵循位级整数编码规则。
 * 计算 5*x 会产生溢出。
*/

int mul5div8(int x)
{
    return divide_power2((x << 2) + x, 3);
}

int main(int argc, char *argv[])
{
    int x = 0x87654321;
    printf("%x\n", mul5div8(x) == x * 5 / 8);

    x = 0x12345678;
    printf("%x\n", mul5div8(x) == x * 5 / 8);
    return 0;
}