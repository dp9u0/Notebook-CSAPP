#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

/*
 * 2.75
 *
 * 假设我们想要计算 x·y 的完整的 2w 位表示，其中，x 和 y 都是无符号数，并且运行在数据类型 unsigned 是 w 位的机器上。
 * 乘积的低 w 位能够用表达式 x·y 计算，我们只需要一个具有下列原型的函数：
 *
 * unsigned unsigned_high_prod(unsigned x, unsigned y);
 *
 * 这个函数计算无符号变量 x·y 的高 w 位。
 * 我们使用一个具有下面原型的库函数：
 *
 * int signed_high_prod(int x, int y);
 *
 * 它计算在 x 和 y 采用补码形式的情况下，x·y 的高 w 位。编写代码调用这个过程，
 * 以实现用无符号数为参数的函数。验证你的解答的正确性。
 *
 */

#include <inttypes.h>

int signed_high_prod(int x, int y)
{
    int64_t mul = (int64_t)x * y;
    return mul >> 32;
}

unsigned unsigned_high_prod(unsigned x, unsigned y)
{
}

/* a theorically correct version to test unsigned_high_prod func */
unsigned another_unsigned_high_prod(unsigned x, unsigned y)
{
    uint64_t mul = (uint64_t)x * y;
    return mul >> 32;
}

int main(int argc, char *argv[])
{
    unsigned x = 0x12345678;
    unsigned y = 0xFFFFFFFF;
    printf("%x\n", another_unsigned_high_prod(x, y) == unsigned_high_prod(x, y));
    return 0;
}
