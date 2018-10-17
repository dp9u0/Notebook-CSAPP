#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

/*
 * 2.81
 *
 * 我们在一个 int 类型值为 32 位的机器上运行程序。这些值以补码形式表示，而且它们都是算术右移的。
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
}

int B(int x, int y)
{
}

int C(int x, int y)
{
}

int D(int x, int y)
{
}

int E(int x, int y)
{
}

int main(int argc, char *argv[])
{
        init_seed();
        int x = random_int();
        int y = random_int();

        printf("%x\n", !A(INT_MIN, 0));
        printf("%x\n", B(x, y));
        printf("%x\n", C(x, y));
        printf("%x\n", D(x, y));
        printf("%x\n", E(x, y));
        return 0;
}
