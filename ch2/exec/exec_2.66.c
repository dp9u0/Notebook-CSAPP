/**
 * Generate mask indicating leftmost 1 in x.  Assume w=32.
 * For example, 0xFF00 -> 0x8000, and 0x6000 -> 0x4000.
 * If x = 0, then return 0.
 *
 *         int leftmost_one(unsigned x);
 *
 * 函数应该遵循位级整数编码规则
 * 假设数据类型 int 有 w=32 位
 * 你的代码最多只能包含 15 个算术运算位运算和逻辑运算
*/

#include <stdio.h>

int leftmost_one(unsigned x)
{
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    //[00001....] -> [0000111111.1111]
    return x - (x >> 1);
}

int main(int argc, char *argv[])
{
    printf("%d\n", leftmost_one(0x80101011));
    printf("%d\n", leftmost_one(0x01010101));
}