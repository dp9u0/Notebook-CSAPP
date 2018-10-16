/*
将参数 x 中的第 i 个字节替换成 b
*/
#include <stdio.h>

unsigned replace_byte(unsigned x, int i, unsigned char b)
{
    return x & (~(0xff << (i << 3))) | (b << (i << 3));
}

int main(int argc, char *argv[])
{
    printf("0x%x", replace_byte(0x12345678, 2, 0xff));
}