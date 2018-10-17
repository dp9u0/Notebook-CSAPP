#include <stdio.h>
#include <math.h>

/*
 * 2.89
 *
 * 计算 2^x 的浮点表示。
 * 完成这个任务的最好方法是直接创建结果的 IEEE 单精度表示。
 * 当 x 太小时，你的程序将返回 0.0
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

    if (x < 2 - pow(2, 7) - 23)
    {
        /* too small. return 0.0 */
        exp = 0;
        frac = 0;
    }
    else if (x < 2 - pow(2, 7))
    {
        /* Denormalized result */
        exp = 0;
        frac = 1 << (unsigned)(x - (2 - pow(2, 7) - 23));
    }
    else if (x < pow(2, 7) - 1 + 1)
    {
        /* Normalized result */
        exp = pow(2, 7) - 1 + x;
        frac = 0;
    }
    else
    {
        /* Too big, return +oo */
        exp = 0xFF;
        frac = 0;
    }
    /* pack exp and frac into 32 bits */
    u = exp << 23 | frac;
    /* Result as float */
    return u2f(u);
}

int main(int argc, char *argv[])
{
    printf("%llx == %llx\n", fpwr2(0), powf(2, 0));
    printf("%llx == %llx\n", fpwr2(12), powf(2, 12));
    printf("%llx == %llx\n", fpwr2(45), powf(2, 45));
    printf("%llx == %llx\n", fpwr2(99), powf(2, 99));
    printf("%llx == %llx\n", fpwr2(100), powf(2, 100));
    printf("%llx == %llx\n", fpwr2(500), powf(2, 500));     // too big
    printf("%llx == %llx\n", fpwr2(10000), powf(2, 10000)); // too big
    printf("%llx == %llx\n", fpwr2(-12), powf(2, -12));
    printf("%llx == %llx\n", fpwr2(-45), powf(2, -45));
    printf("%llx == %llx\n", fpwr2(-99), powf(2, -99));
    printf("%llx == %llx\n", fpwr2(-100), powf(2, -100));
    printf("%llx == %llx\n", fpwr2(-500), powf(2, -500));     // too small
    printf("%llx == %llx\n", fpwr2(-10000), powf(2, -10000)); // too small
    return 0;
}