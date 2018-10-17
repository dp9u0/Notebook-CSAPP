#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

/*
 * 2.78
 *
 * 写出函数 mul5div8 的代码，对于整数参数 x，计算 5*x/8，
 * 遵循位级整数编码规则。
 * 计算 5*x 会产生溢出。
*/

int mul5div8(int x)
{
}

int main(int argc, char *argv[])
{
        int x = 0x87654321;
        printf("%x\n", mul5div8(x) == x * 5 / 8);

        x = 0x12345678;
        printf("%x\n", mul5div8(x) == x * 5 / 8);
        return 0;
}