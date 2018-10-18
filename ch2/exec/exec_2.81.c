#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

/*
 * 2.81
 *
 * int 类型值为 32 位。值以补码形式表示，都是算术右移的。
 * unsigned 类型的值是 32 位的。
 *
 * 产生随机数 x 和 y，并且把它们转换成无符号数，显示如下：
 *
 * // Create some arbitrary values
 * int x = random();
 * int y = random();
 * // Convert to unsigned
 * unsigned ux = (unsigned) x;
 * unsigned uy = (unsigned) y;
 *
 * 对于下列每个 C 表达式，你要指出表达式是否总是为 1。如果它总是为 1，那么请描
 * 述其中的数学原理。否则，列举一个使它为 0 的参数示例。
 *
 * A. (x > y) == (-x < -y)
 * B. ((x + y) << 5) + x - y == 31 * y + 33 * x
 * C. ~x + ~y == ~(x + y)
 * D. (int)(ux - uy) == -(y - x)
 * E. ((x >> 1) << 1) <= x
 *
 */

unsigned int next = 1;

/* rand - return pseudo-random integer on 0..32767 */
int rand(void)
{
    next = next*1103515245 + 12345;
    return (unsigned int)(next/65536) % 32768;
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

int A(int x, int y)
{
    /*
    *  A. (x > y) == (-x < -y)
    *
    *  False when y=INT_MIN
    */
    return (x < y) == (-x > -y);
}

int B(int x, int y)
{
    /*
    * B. ((x + y) << 5) + x - y == 31 * y + 33 * x
    *
    * Always True 补码加减法
    */
    return ((x + y) << 5) + x - y == 31 * y + 33 * x;
}

int C(int x, int y)
{
    /*
    * C. ~x + ~y == ~(x + y)
    *
    * Always False
    * 
    * ~x = 2^w - x - 1
    * ~y = 2^w - y - 1
    * ~x + ~y = 2^(w+1) - x - y -2
    * ~(x+y) = 2^w - x - y - 1
    */
    return ~x + ~y == ~(x + y);
}

int D(int x, int y)
{
    /*
    * D. (int)(ux - uy) == -(y - x)
    *
    * Always True
    *
    * 对于任意的数字 a，有如下的等式成立：
    *
    *     -a = ~a + 1 = 2^w - a
    *
    * -(y - x) = 2^w - (y - x) = 2^w + x - y
    * 对于 w 位补码，算术运算的结果截断为 w 位。
    *
    * ux - uy == 2^w + x - y
    */
    unsigned ux = (unsigned)x;
    unsigned uy = (unsigned)y;
    return (int)(ux - uy) == -(y - x);
}

int E(int x, int y)
{
    /*
    * E. ((x >> 1) << 1) <= x
    *
    * Always True
    *
    * 因为右移会将最低位置零
    * 如果最低位是 1 左移回来就会小于移位前的数
    * 如果最低位是 0 左移回来的数等于移位前的数。
    */
    return ((x >> 1) << 1) <= x;
}

int main(int argc, char *argv[])
{
    init_seed();
    int x = random_int();
    int y = random_int();

    unsigned ux = (unsigned)x;
    unsigned uy = (unsigned)y;

    printf("%x\n", A(x, y));
    //printf("%x\n", A(INT_MIN, 0));
    printf("%x\n", B(x, y));
    printf("%x\n", C(x, y));
    printf("%x\n", D(x, y));
    printf("%x\n", E(x, y));
    return 0;
}
