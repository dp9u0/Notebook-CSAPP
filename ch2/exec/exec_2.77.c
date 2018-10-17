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
 * 该函数要用正确的舍入计算 x/2^k，并且应该遵循位级整数编码规则。
 */

int divide_power2(int x, int k)
{
}

int main(int argc, char *argv[])
{
        int x = 0x80000007;
        printf("%x\n", divide_power2(x, 1));
        printf("%x\n", divide_power2(x, 2));
        return 0;
}
