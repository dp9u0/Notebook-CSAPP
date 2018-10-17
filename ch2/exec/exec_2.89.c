#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

/*
 * 2.89
 *
 * 计算 2^x 的浮点表示。
 * 完成这个任务的最好方法是直接创建结果的 IEEE 单精度表示。
 * 当 x 太小时，你的程序将返回0.0
 * x 太大时，它会返回 +oo。
 * 填写下列代码的空白部分，以计算出正确的结果。
 * 假设函数 u2f 返回的浮点值与它的无符号参数有相同的位表示。
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
        /* 这里假设无符号整数和单精度浮点数的位表示相同 */
        union {
                unsigned u;
                float f;
        } a;
        a.u = x;
        return a.f;
}

float fpwr2(int x)
{
        /* Result exponent and fraction */
        unsigned exp, frac;
        unsigned u;

        if (x < -149)
        {
                /* Too small.  Return 0.0 */
                exp = 0;
                frac = 0;
        }
        else if (x < -126)
        {
                /* Denormalized result */
                exp = 0;
                frac = 1 << (x + 149);
        }
        else if (x < 129)
        {
                /* Normalized result */
                exp = x + 127;
                frac = 0;
        }
        else
        {
                /* Too big.  Return +oo */
                exp = 0xFF;
                frac = 0;
        }

        /* Pack exp and frac into 32 bits */
        u = exp << 23 | frac;

        /* Return as float */
        return u2f(u);
}

int main(int argc, char *argv[])
{
        printf("%x\n", fpwr2(0) == powf(2, 0));
        printf("%x\n", fpwr2(100) == powf(2, 100));
        printf("%x\n", fpwr2(-100) == powf(2, -100));
        printf("%x\n", fpwr2(10000) == powf(2, 10000));
        printf("%x\n", fpwr2(-10000) == powf(2, -10000));
        return 0;
}