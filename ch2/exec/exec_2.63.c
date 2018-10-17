/*
 * 函数 srl 用算术右移来完成逻辑右移，后面的其他操作不包括右移或者除法
 * 函数 sra 用逻辑右移来完成算术右移，后面的其他操作不包括右移或者除法
 * 可以通过计算8*sizeof(int) 来确定数据类型 int 中的位数 w
 * 位移量 k 的取值范围位 0~w-1
 */

#include <stdio.h>

static int w = sizeof(int) << 3;

/**
 * 逻辑右移
*/
unsigned srl(unsigned x, int k)
{
    /* Perform shift arithmetically */
    unsigned xsra = (int)x >> k;

    int mask = -1 << (w - k);
    return xsra & ~ mask;
}

/**
 * 算数右移
*/
int sra(int x, int k)
{
    /* Perform shift logically */
    int xsrl = (unsigned)x >> k;

    int mask = -1 << (w - k);
    return x < 0 ? xsrl | mask : xsrl;
}

int main(int argc, char *argv[])
{
    unsigned test_unsigned = 0x12345678;
    int test_int = 0x12345678;

    printf("%d\n", srl(test_unsigned, 4) == test_unsigned >> 4);
    printf("%d\n", sra(test_int, 4) == test_int >> 4);

    test_unsigned = 0x87654321;
    test_int = 0x87654321;

    printf("%d\n", srl(test_unsigned, 4) == test_unsigned >> 4);
    printf("%d\n", sra(test_int, 4) == test_int >> 4);
}