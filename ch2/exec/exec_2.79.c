#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

/*
 * 2.79
 *
 * 写出函数 fiveeighths 的代码，对于整数参数 x，计算 5/8x 的值，向零舍入。
 * 它不会溢出。
 * 遵循整数位级编码规则。
 */

int fiveeighths(int x)
{
}

int threeforths(int x)
{
}

int main(int argc, char *argv[])
{
        printf("%x\n", threeforths(8) == 6);
        printf("%x\n", threeforths(9) == 6);
        printf("%x\n", threeforths(10) == 7);
        printf("%x\n", threeforths(11) == 8);
        printf("%x\n", threeforths(12) == 9);

        printf("%x\n", threeforths(-8) == -6);
        printf("%x\n", threeforths(-9) == -6);
        printf("%x\n", threeforths(-10) == -7);
        printf("%x\n", threeforths(-11) == -8);
        printf("%x\n", threeforths(-12) == -9);
}