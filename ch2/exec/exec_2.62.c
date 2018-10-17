/*
 * 编写一个函数 int_shifts_are_logical()
 * 在对 int 类型的数使用算术右移的机器上运行这个函数生成 1
 * 其他情况下生成 0
 */

#include <stdio.h>

int int_shifts_are_logical()
{
    return (-1 >> 1) == -1;
}

int main(int argc, char *argv[])
{
    printf("%d\n", int_shifts_are_logical());
}