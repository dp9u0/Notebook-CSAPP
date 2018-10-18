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

/* false 当比较大的时候 会出现丢失精度的问题 260908146*/
int A(int x, double dx)
{
    return (double)(float)x == dx;
}

/* false when y is INT_MIN */
int B(int x, double dx, int y, double dy)
{
    return dx - dy == (double)(x - y);
}

/* false 还没找到 数字 */
int C(double dx, double dy, double dz)
{
    printf("dx + dy + dz : %lf\n", dx + dy + dz);
    printf("dz + dy + dx : %lf\n", dz + dy + dx);
    return dx + dy + dz == dz + dy + dx;
}

/*
 *  false 浮点乘法无结合性
 */
int D(double dx, double dy, double dz)
{
    return dx * dy * dz == dz * dx * dy;
}

/* false when dx != 0 and dy == 0 */
int E(double dx, double dy)
{
    return dx / dx == dy / dy;
}

int main(int argc, char *argv[])
{
    init_seed();
    int x = random_int();
    int y = random_int();
    int z = random_int();

    float fx = (float)x;
    float fy = (float)y;
    float fz = (float)z;

    double dx = (double)x;
    double dy = (double)y;
    double dz = (double)z;

    printf("sizeof(int) : %x ,sizeof(float) : %x ,sizeof(double) : %x\n", sizeof(int), sizeof(float), sizeof(double));
    printf("x : %d ,y : %d ,z : %d\n", x, y, z);
    printf("fx : %f ,fy : %f ,fz : %f\n", fx, fy, fz);
    printf("dx : %llx ,dy : %llx ,dz : %llx\n", dx, dy, dz);
    printf("%x\n", !A(260908146, (double)(260908146)));
    printf("%x\n", !B(0, (double)(int)0, INT_MIN, (double)(int)INT_MIN));
    printf("%x\n", !C(1, 1e10, -1e10));
    printf("%x\n", !D((double)(int)0x64e73387, (double)(int)0xd31cb264, (double)(int)0xd22f1fcd));
    printf("%x\n", !E(dx, (double)(int)0));
    return 0;
}
