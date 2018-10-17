#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

/*
 * 2.80
 *
 * 编写 C 表达式产生如下位模式，其中 a^n 表示符号 a 重复 n 次。
 * 假设一个 w 位的数据类型。
 * 你的代码可以包含对参数 m 和 n 的引用，它们分别表示 m 和 n 的值，但是不能使用表示 w 的参数。
 *
 * A. 1^(w-n)0^n
 * B. 0^(w-n-m)1^n0^m
 */

/*
 * A.1^(w-n)0^n
 */
int a(int n)
{
}

/*
 * B.0^(w-n-m)1^n0^m
 */
int B(int n, int m)
{
}

int main(int argc, char *argv[])
{
        printf("%x\n", A(8) == 0xFFFFFF00);
        printf("%x\n", B(16, 8) == 0x00FFFF00);
        return 0;
}
