#include <stdio.h>

/*
 * 2.71
 * 将 4 个有符号字节封装成一个 32 位 unsigned。
 * 一个字中的字节从 0（最低有效字节）编号到3（最高有效字节）。
 * 为一个使用补码运算和算数右移的机器编写一个具有如下原型的函数：
 *
 * Declaration of data type where 4 bytes are packed into an unsigned
 *
 *         typedef unsigned packed_t;
 *
 * Extract byte from word.  Return as signed integer
 *
 *         int xbyte(packed_t word, int bytenum);
 *
 * 也就是说，函数会抽取出指定的字节，再把它符号扩展为一个 32 位 int。你的前任
 * （因为水平不够高而被解雇了）编写了下面的代码：
 *
 * Failed attempt at xbyte
 * int xbyte(packed_t word, int bytenum)
 * {
 *      return (word >> (bytenum << 3)) & 0xFF;
 * }
 *
 * A. 这段代码错在哪里？ // 抽取的字节是负数 没有考虑到
 * B. 给出函数的正确实现，只能使用左右移位和一个减法。
 */

typedef unsigned packed_t;

int xbyte(packed_t word, int bytenum)
{
    // 抽取的字节是负数
    printf("%x\n", (word << ((3 - bytenum) << 3)));
    return ((int)(word << ((3 - bytenum) << 3)) >> 24);
}

int main(int argc, char *argv[])
{
    printf("%x\n", xbyte(0xAABBCCDD, 1)); //  == 0xFFFFFFCC
    printf("%x\n", xbyte(0x00112233, 2)); // == 0x11
    return 0;
}