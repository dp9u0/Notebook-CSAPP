#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

/*
 * 2.77
 *
 * Divide by power of two.  Assume 0 <= k < w-1
 * int divide_power2(int x, int k);
 *
 * 该函数要用正确的舍入计算 x/2^k  -> 向 O 舍入
 * 遵循位级整数编码规则。
 */

/**
 * x >= 0 : 简单的右移运算的结果也是整数除法的结果。
 * x < 0 结果是向下舍入的 但是需要向上舍入的结果 需要为 x 加上一个偏置值 (1<<k)-1 就可以使右移的结果向上舍入了。
*/
int divide_power2(int x, int k)
{
    int bias = 0;
    int sign = (x & INT_MIN) == INT_MIN;
    (sign && (bias = (1 << k) - 1));
    return (x + bias) >> k;
}

int main(int argc, char *argv[])
{
    int x = 0x80000007;
    printf("%x == %x\n", divide_power2(x, 0), x / 1);
    printf("%x == %x\n", divide_power2(x, 2), x / 4);
    printf("%x == %x\n", divide_power2(x, 30), x / (2 ^ 30));

    x = 0x70000007;
    printf("%x == %x\n", divide_power2(x, 0), x / 1);
    printf("%x == %x\n", divide_power2(x, 2), x / 4);
    printf("%x == %x\n", divide_power2(x, 30), x / (2 ^ 30));
    return 0;
}