#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

/*
 * 2.83
 *
 * 填写下列程序的返回值，这个程序是测试它的第一个参数是否大于或者等于第二个参数。
 * 假定函数 f2u 返回一个无符号 32 位数字，其位表示与它的浮点参数相同。
 * 假设两个参数都不是 NaN。两种 0，+0 和 -0 都认为是相等的。
 *
 *      int float_ge(float x, float y) {
 *          unsigned ux = f2u(x);
 *          unsigned uy = f2u(y);
 *
 *          // Get the sign bits
 *          unsigned sx = ux >> 31;
 *          unsigned sy = uy >> 31;
 *
 *          // Given an expression using only ux, uy, sx, sy
 *          return ________;
 *      }
 */

unsigned f2u(float f)
{
    union {
        float f;
        unsigned u;
    } a;
    a.f = f;
    return a.u;
}

float u2f(unsigned x)
{
    union {
        unsigned u;
        float f;
    } a;
    a.u = x;
    return a.f;
}

int float_ge(float x, float y)
{
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);

    /* Get the sign bits */
    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;

    return (ux << 1 == 0 && uy << 1 == 0) || /* -0 && +0 : ux = uy = 0 */
           (!sx && sy) ||                    /* x >= 0, y < 0 */
           (!sx && !sy && ux >= uy) ||       /* x >= 0, y >= 0 */
           (sx && sy && ux <= uy);           /* x < 0, y < 0 */
}

int main(int argc, char *argv[])
{
    printf("%x\n", float_ge(-0, +0));
    printf("%x\n", float_ge(+0, -0));
    printf("%x\n", float_ge(0, 3));
    printf("%x\n", float_ge(-4, -0));
    printf("%x\n", float_ge(-4, 4));
    return 0;
}