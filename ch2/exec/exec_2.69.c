#include <stdio.h>

/*
 * Do rotating right shift.  
 * Example
 *     x = 0x12345678 and w=32:
 *     n=4 -> 0x81234567
 *     n=20 -> 0x45678123
 * Assume 0 <= n < w
 * 函数应该遵循位级整数编码规则
 * 要注意 n = 0 的情况。
 */

static int w = sizeof(int) << 3;

unsigned rotate_left(unsigned x, int n)
{
    // return ((x << (w-n-1)) << 1) + (x >> n);
    return (x << (w - n)) | (x >> n);
}

int main(int argc, char *argv[])
{
    printf("%x\n", rotate_left(0x12345678, 0));
    printf("%x\n", rotate_left(0x12345678, 4));
    printf("%x\n", rotate_left(0x12345678, 20));
    printf("%x\n", rotate_left(0x12345678, 31));
    return 0;
}