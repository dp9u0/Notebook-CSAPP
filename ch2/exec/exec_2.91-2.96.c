#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <limits.h>
#include <time.h>

typedef unsigned float_bits;

static int w = sizeof(unsigned) << 3;
static int frac_w = 23;
static int exp_w = 8;
static unsigned pos_inf = (0xFF << 23);             //正无穷
static unsigned neg_inf = (1 << 31) | (0xFF << 23); //负无穷
static unsigned next = 1;
static unsigned bias = (1 << 7) - 1;

/* rand - return pseudo-random integer on 0..32767 */
int rand(void)
{
    next = next * 1103515245 + 12345;
    return (unsigned int)(next / 65536) % 32768;
}

/* srand - set seed for rand() */
void srand(unsigned int seed)
{
    next = seed;
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

unsigned f2u(float f)
{
    return *(unsigned *)&f;
}

float u2f(unsigned u)
{
    return *(float *)&u;
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
    unsigned exp = (f >> frac_w) & 0xFF;
    unsigned frac = f & 0x007FFFFF;

    /* NaN */
    if (exp == 0xFF && frac != 0)
    {
        return f;
    }
    return exp << frac_w | frac;
}

/*
 * 2.92
 *
 * 遵循位级浮点编码规则，实现具有如下原型的函数：
 *
 * // Compute -f.  If f is Nan, then return f.
 * float_bits float_negate(float_bits f);
 *
 * 对于浮点数 f，这个函数计算 -f。如果 f 是 NaN，你的函数应该简单地返回 f。
 */

float_bits float_negate(float_bits f)
{

    unsigned exp = (f >> frac_w) & 0xFF;
    unsigned frac = f & 0x007FFFFF;
    unsigned sign = f >> (w - 1) & 1;
    /* NaN */
    if (exp == 0xFF && frac != 0)
    {
        return f;
    }
    sign = sign ^ 1; // toggle sign
    return (sign << (w - 1)) | (exp << frac_w) | frac;
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
    unsigned exp = (f >> frac_w) & 0xFF;
    unsigned frac = f & 0x007FFFFF;
    unsigned sign = f >> (w - 1) & 1;

    // printf("exp\t: 0x%.8X\t\n", exp);
    // printf("frac\t: 0x%.8X\t\n", frac);

    /* NaN or Inf or +0 or -0 */
    if ((exp == 0xFF && frac != 0) || (exp == 0xFF && frac == 0) || (exp == 0 && frac == 0))
    {
        return f;
    }
    // 规格化数 -> 非规格化数  or 非规格化数 -> 非规格化数
    if (exp == 0 || exp == 1)
    {
        unsigned frac_0 = frac & 1;
        // printf("frac_0\t: 0x%.8X\t\n", frac_0);
        // 规格化数 -> 非规格化数  1.frac  ->  0.frac frac 最高位 补 1
        if (exp == 1)
        {
            frac |= 1 << frac_w;
        }
        frac >>= 1; // M / 2
        // frac最后一位是 1 精度丢失 并且计算后非0 则需要补 1
        (frac != 0 && (frac += frac_0));
        exp = 0;
    }
    else //规格化数 -> 规格化数
    {
        exp -= 1;
    }
    return (sign << (w - 1)) | (exp << frac_w) | frac;
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
    unsigned exp = (f >> frac_w) & 0xFF;
    unsigned frac = f & 0x007FFFFF;
    unsigned sign = f >> (w - 1) & 1;

    // printf("exp\t: 0x%.8X\t\n", exp);
    // printf("frac\t: 0x%.8X\t\n", frac);

    /* NaN or Inf or +0 or -0 */
    if ((exp == 0xFF && frac != 0) || (exp == 0xFF && frac == 0) || (exp == 0 && frac == 0))
    {
        return f;
    }
    // 非规格化数 -> 非规格化数  or 非规格化数 -> 规格化数
    if (exp == 0)
    {
        frac <<= 1;
        unsigned bit_24 = 1 << frac_w;
        unsigned frac_24 = frac & bit_24;
        if (frac_24)
        {
            exp = 1;
            frac &= (bit_24 - 1);
        }
    }
    else if (exp == 0xFE) // 规格化数 -> Inf
    {
        exp = 0xFF;
        frac = 0;
    }
    else //规格化数 -> 规格化数
    {
        exp += 1;
    }
    return (sign << (w - 1)) | (exp << frac_w) | frac;
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
    if (i == 0)
    {
        return i;
    }
    unsigned sign = (i >> (w - 1)) & 1;
    unsigned ui = (unsigned)(sign ? 0 - i : i);
    int shift = 0; // 把 ui 最右边的 1 移位到 31 位 需要左移距离
    unsigned i2f = 0;
    // printf("i\t: %d\tsign\t: %d\tui\t: 0x%.8X\n", i, sign, ui);
    // int 转 float 肯定都属于规范化数区间
    while (!(ui & 0x80000000)) // 首先将ui中最高的1右移到31位
    {
        ui = ui << 1;
        shift++;
    }
    // printf("shift\t: %d\n", shift);
    // printf("ui\t: 0x%.8X\n", ui);
    unsigned frac = (ui >> 8) & 0x007FFFFF;
    // printf("frac\t: 0x%.8X\n", frac);
    int exp = 8 - shift + 23 + bias;
    // printf("exp\t: 0x%.8X\n", exp);
    return (exp << frac_w) | frac | sign << 31;
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
 * 对于浮点数 f，这个函数计算 (int)f。你的函数应该向零舍入。如果 f 不能用整数表示
 * （例如，超出表示范围，或者它是一个 NaN），那么函数应该返回0x80000000。
 */
int float_f2i(float_bits f)
{
    unsigned exp = (f >> frac_w) & 0xFF;
    unsigned frac = f & 0x007FFFFF;
    unsigned sign = f >> (w - 1) & 1;
    int E = (int)exp - bias;
    // printf("exp\t: 0x%.8X\t%d\t\n", exp, exp);
    // printf("E\t: %d\t\n", E);
    // printf("frac\t: 0x%.8X\t\n", frac);
    /* too Big or NaN or Inf */
    // 当 E >=31 时, 1.frac << E 会导致溢出(int 需要保留一位符号位,最高只能移位到 1)
    if ((E >= 31) || (exp == 0xFF && frac != 0) || (exp == 0xFF && frac == 0))
    {
        // printf("too Big or NaN or Inf \n");
        return 0x80000000;
    }
    // too small -1 < float < 1
    if (E < 0)
    {
        // printf("too small  -1 < x < 1\n");
        return 0;
    }
    unsigned M = (frac | (1 << frac_w)) << 8;
    // printf("M\t: %d\t\n", M);
    return sign ? (int)0 - (M >> (31 - E)) : M >> (31 - E);
}

int run(unsigned r)
{
    float f = u2f(r);
    int i = (int)f;

    if (isnan(f))
    {
        printf("----------------------------------------isnan----------------------------------------\n");
    }
    else if (isinf(f))
    {
        printf("----------------------------------------isinf----------------------------------------\n");
    }
    else
    {
        printf("-------------------------------------------------------------------------------------\n");
    }

    printf("r\t: 0x%.8X\t%d\n", r, r);
    printf("f\t: 0x%.8X\t%.50f\n", f2u(f), f);
    printf("i\t: 0x%.8X\t%d\n", i, i);

    float fneg = -f;
    //printf("fneg\t: 0x%.8X\t%.50f\n", f2u(fneg), fneg);

    float fabsv = fabsf(f);
    //printf("fabs\t: 0x%.8X\t%.50f\n", f2u(fabsv), fabsv);

    float fmul2 = f * 2.0;
    //printf("fmul2\t: 0x%.8X\t%.50f\n", f2u(fmul2), fmul2);

    float fdiv2 = f * 0.5;
    //printf("fdiv2\t: 0x%.8X\t%.50f\n", f2u(fdiv2), fdiv2);

    float i2f = (float)i;
    // printf("i2f\t: 0x%.8X\t%.50f\n", f2u(i2f), i2f);

    int f2i = (int)f; // = i
    // printf("f2i\t: 0x%.8X\t%d\n", f2i, f2i);

    if (isnan(f))
    {
        // printf("float_absval(r) \t: 0x%X == 0x%X\n", float_absval(r), r);
        // printf("float_negate(r) \t: 0x%X == 0x%X\n", float_negate(r), r);
        // printf("float_twice(r) \t: 0x%X == 0x%X\n", float_twice(r), r);
        // printf("float_half(r) \t: 0x%X == 0x%X\n", float_half(r), r);
        assert(float_absval(r) == r);
        assert(float_negate(r) == r);
        assert(float_twice(r) == r);
        assert(float_half(r) == r);
    }
    else
    {
        // printf("float_absval(r) \t: 0x%X == 0x%X\n", (float_absval(r)), f2u(fabsv));
        // printf("float_negate(r) \t: 0x%X == 0x%X\n", (float_negate(r)), f2u(fneg));
        // printf("float_twice(r) \t\t: 0x%X == 0x%X\n", (float_twice(r)), f2u(fmul2));
        // printf("float_half(r)\t\t: 0x%X == 0x%X\n", (float_half(r)), f2u(fdiv2));
        assert(float_absval(r) == f2u(fabsv));
        assert(float_negate(r) == f2u(fneg));
        assert(float_twice(r) == f2u(fmul2));
        assert(float_half(r) == f2u(fdiv2));
    }

    // printf("float_f2i(r) \t: 0x%X == 0x%X\n", float_f2i(r), f2i);
    assert(float_f2i(r) == f2i);

    // printf("float_i2f(%d) \t: 0x%X == 0x%X\n", i, float_i2f(i), f2u(i2f));
    // printf("float_i2f(%d) \t: %f == %f\n", i, u2f(float_i2f(i)), i2f);
    assert(float_i2f(i) == f2u((float)i));
}

int main(int argc, char *argv[])
{

    // 0x46B03E46
    run(0x46B03E46);
    // 0xC6B03E46
    run(0xC6B03E46);
    // 0
    run(0x00000000);
    // -0
    run(0x80000000);
    // 最小非规格化数
    run(0x00000001);
    // - 最小非规格化数
    run(0x80000001);
    // 最大非规格化数
    run(0x007FFFFF);
    // - 最大非规格化数
    run(0x807FFFFF);
    // 最小规格化数
    run(0x08000000);
    // - 最小规格化数
    run(0x88000000);
    // 最大规格化数 0x7F7FFFFF
    run(0x7F7FFFFF);
    // -最大规格化数 0xFF7FFFFF
    run(0xFF7FFFFF);

    // NaN
    unsigned u_nan = (0xFF << frac_w) | 1;
    run(u_nan);

    //正无穷
    run(pos_inf);

    //负无穷
    run(neg_inf);

    init_seed();

    unsigned round = 0XFF;
    long long count = 0;
    for (unsigned n = 0; round; n++)
    {
        if (n == 0xFF)
        {
            round--;
            n = 0;
        }
        unsigned r = random_int();
        run(r);
        count++;
    }
    printf("run : %lld", count);

    return 0;
}
