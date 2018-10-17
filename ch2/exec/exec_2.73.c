#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

/*
 * 2.73
 *
 * Addition that saturates to TMin or TMax
 *
 * 与正常的补码溢出的方式不同，
 * 正溢出时，返回 TMax，
 * 负溢出时，返回 TMin。
 * 这种运算常常用在执行数字信号处理的程序中。
 *
 * 你的函数应该遵循位级整数编码规则。
 */

int saturating_add(int x, int y)
{
    int sum = x + y;
    int pos_overflow = !(x & INT_MIN) && !(y & INT_MIN) && (sum & INT_MIN);
    int neg_overflow = (x & INT_MIN) && (y & INT_MIN) && !(sum & INT_MIN);
    (pos_overflow && (sum = INT_MAX) || neg_overflow && (sum = INT_MIN));
    return sum;
}

int main(int argc, char *argv[])
{
    printf("%x\n", INT_MAX == saturating_add(INT_MAX, 0x1234));
    printf("%x\n", INT_MIN == saturating_add(INT_MIN, -0x1234));
    printf("%x\n", 0x11 + 0x22 == saturating_add(0x11, 0x22));
    return 0;
}