/*
x y 分别取 : 
x : 最低有效字节 
y : 剩余字节

例如 x = 0x12345678 y = 0x000000FF
得到 0x123456ff
*/
#include <stdio.h>

unsigned combine(unsigned x, unsigned y)
{
    return (x & 0xFF) | (y & ~0xFF);
}

int main(int argc, char *argv[])
{
    printf("0x%x", combine(0x000000FF,0x12345678));
}
