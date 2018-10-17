#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

typedef unsigned float_bits;

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

void init_seed(void)
{
        srand(time(NULL));
}

int random_int(void)
{
        int int_bits = sizeof(int) * 8;
        int i;
        int random = 0;
        for (i = 0; i < int_bits; i++)
        {
                random |= rand() % 2;
                random <<= 1;
        }
        return random;
}

/*
 * 2.91
 *
 * 遵循位级浮点编码规则，实现具有如下原型的函数：
 *
 * // Compute |f|.  If f is NaN, then return f.
 * float_bits float_absval(float_bits f);
 *
 * 对于浮点数 f，这个函数计算 |f|。如果 f 是 NaN，你的函数应该简单地返回 f。
 * 对参数 f 可以取的所有 2^32 个值求值，将结果与你实用机器的浮点运算得到的结果相比较。
 */
float_bits float_absval(float_bits f)
{
}

/*
 * 2.92
 *
 * 遵循位级浮点编码规则，实现具有如下原型的函数：
 *
 * // Compute -f.  If f is Nan, then return f.
 * float_bits float_absval(float_bits f);
 *
 * 对于浮点数 f，这个函数计算 -f。如果 f 是 NaN，你的函数应该简单地返回 f。
 */

float_bits float_negate(float_bits f)
{
}

/*
 * 2.93
 *
 * 遵循位级浮点编码规则，实现具有如下原型的函数：
 *
 * // Compute 0.5*f.  If f is NaN, then return f.
 * float_bits float_half(float_bits f);
 *
 * 对于浮点数 f，这个函数计算 0.5*f。如果 f 是 NaN，你的函数应该简单返回 f。
 */
/* Compute 0.5*f.  If f is NaN, then return f. */
float_bits float_half(float_bits f)
{
}

/*
 * 2.94
 *
 * 遵循位级浮点编码规则，实现具有如下原型的函数：
 *
 * // Compute 2*f.  If f is NaN, then return f.
 * float_bits float_twice(float_bits f);
 *
 * 对于浮点数 f，这个函数计算 2.0*f。如果 f 是 NaN，你的函数应该简单地返回 f。
 */
/* Compute 2*f.  If f is NaN, then return f. */
float_bits float_twice(float_bits f)
{
}

/*
 * 2.95
 *
 * 遵循位级浮点编码规则，实现具有如下原型的函数：
 *
 * // Compute (float) i
 * float_bits float_i2f(int i);
 *
 * 对于参数 i，这个函数计算 (float)i 的位级表示。
 */
float_bits float_i2f(int i)
{
}

/*
 * 2.96
 *
 * 遵循位级浮点编码规则，实现具有如下原型的函数：
 *
 * // Compute (int) f.
 * // If conversion causes overflow or f is NaN, return 0x80000000
 * int float_f2i(float_bits f);
 *
 * 对于浮点数 f，这个函数计算 (int)f。你的函数应该向零舍入。如果f 不能用整数表示
 * （例如，超出表示范围，或者它是一个 NaN），那么函数应该返回0x80000000。
 */
int float_f2i(float_bits f)
{
}

int main(int argc, char *argv[])
{
        init_seed();

        for (unsigned n = 0, round = 0; !round; n = n + 1)
        {
                if (n == 0xFFF)
                {
                        round++;
                }

                // test all int numbers waste a lot of time
                // just test 0xFFF random numbers here
                unsigned r = random_int();
                /*r = n;*/
                printf("r:\t0x%.8X\t%d\n", r, r);

                float f = u2f(r);
                printf("f:\t0x%.8X\t%.50f\n", f2u(f), f);

                float fmul2 = f * 2.0;
                printf("fmul2:\t0x%.8X\t%.50f\n", f2u(fmul2), fmul2);

                float fdiv2 = f * 0.5;
                printf("fdiv2:\t0x%.8X\t%.50f\n", f2u(fdiv2), fdiv2);

                int f2i = (int)f;
                printf("f2i:\t0x%.8X\t%d\n", f2i, f2i);

                float i2f = (float)(int)r;
                printf("r:\t0x%.8X\t%d\n", r, r);
                printf("i2f:\t0x%.8X\t%.50f\n", f2u(i2f), i2f);

                if (isnan(f))
                {
                        printf("%x\n", float_negate(r) == r);
                        printf("%x\n", float_absval(r) == r);
                        printf("%x\n", float_twice(r) == r);
                        printf("%x\n", float_half(r) == r);
                        printf("%x\n", float_f2i(r) == f2i);
                }
                else
                {
                        printf("%x\n", u2f(float_negate(r)) == -f);
                        printf("%x\n", u2f(float_absval(r)) == fabsf(f));
                        printf("%x\n", u2f(float_twice(r)) == fmul2);
                        printf("%x\n", u2f(float_half(r)) == fdiv2);
                        /* whether f > (float)INT_MAX || f < (float)INT_MIN) */
                        printf("%x\n", float_f2i(r) == f2i);

                        float my_i2f = u2f(float_i2f(r));
                        printf("my_i2f:\t0x%.8X\t%.50f\n", f2u(my_i2f), my_i2f);
                        printf("%x\n", my_i2f == i2f);
                }

                printf("\n");
                return 0;
        }
}
