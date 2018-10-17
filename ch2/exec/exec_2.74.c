#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

/*
 * 2.74
 *
 * 写出具有如下原型的函数的代码：
 *
 * Determine whether subtracting arguments will cause overflow int tsub_ovf(int x, int y);
 *
 * 如果计算 x-y 导致溢出，这个函数就返回 1。
 *
 */

int tsub_ok(int x, int y)
{
    int sub = x - y;
    return y == INT_MIN || (y < 0 && x < sub) || (y > 0 && x > sub);
}

int main(int argc, char *argv[])
{
    printf("%x\n", tsub_ok(0x00, INT_MIN));
    printf("%x\n", !tsub_ok(0x00, 0x00));
    return 0;
}