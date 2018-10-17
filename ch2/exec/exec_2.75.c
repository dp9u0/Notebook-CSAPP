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

static int w = sizeof(int) << 3;

#include <inttypes.h>

int signed_high_prod(int x, int y)
{
    int64_t result = (int64_t)x * (int64_t)y;
    printf("signed_high_prod result: %llx\n", result);
    return result >> 32;
}

// x' · y' =  (x + x[w-1] * 2^w) · (y + y[w-1] * 2^w)
//         = x · y + (x[w-1] * y + y[w-1] * x ) * 2^w + (x[w-1] * y[w-1] * 2^2w)
// x' · y' >> 32 =
// x · y >> 32 + x[w-1] * y + y[w-1] * x + (x[w-1] * y[w-1] * 2^w)
unsigned unsigned_high_prod(unsigned x, unsigned y)
{
    // x[w-1]
    int x_wm1 = (x & INT_MIN) == INT_MIN; // 0 or 1
    // y[w-1]
    int y_wm1 = (y & INT_MIN) == INT_MIN; // 0 or 1
    int result = signed_high_prod(x, y) + x * y_wm1 + y * x_wm1; // + (x[w-1] * y[w-1] * 2^w) overflow
}

/* a theorically correct version to test unsigned_high_prod func */
unsigned unsigned_high_prod_v2(unsigned x, unsigned y)
{
    uint64_t result = (uint64_t)x * (uint64_t)y;
    printf("unsigned_high_prod_v2 result: %llx\n", result);
    return result >> 32;
}

int main(int argc, char *argv[])
{
    unsigned x = 0x72345678;
    unsigned y = 0x7FFFFFFF;
    printf("%x\n", unsigned_high_prod_v2(x, y));
    printf("%x\n", unsigned_high_prod(x, y));

    x = 0x72345678;
    y = 0xFFFFFFFF;
    printf("%x\n", unsigned_high_prod_v2(x, y));
    printf("%x\n", unsigned_high_prod(x, y));

    x = 0xD2345678;
    y = 0xFFFFFFFF;
    printf("%x\n", unsigned_high_prod_v2(x, y));
    printf("%x\n", unsigned_high_prod(x, y));

    return 0;
}
