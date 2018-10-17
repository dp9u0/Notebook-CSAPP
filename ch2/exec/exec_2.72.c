#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

/*
 *
 * 给你一个任务，写一个函数，将整数 val 复制到缓冲区 buf 中，但是只有缓冲区
 * buf 中，但是只有当缓冲区中有足够可用的空间时，才执行复制。
 *
 * 你写的代码如下：
 *
 * // Copy integer into buffer if space is available
 * // WARNING: The following code is buggy
 * void copy_int(int val, void *buf, int maxbytes) {
 *     if (maxbytes-sizeof(val) >= 0)
 *         memcpy(buf, (void *)&val, sizeof(val));
 * }
 *
 * 这段代码使用了库函数 memcpy。虽然在这里用这个函数有点刻意，因为我们只是想复
 * 制一个 int，但是说明了一种复制较大数据结构的常见方法。
 *
 * 你仔细地测试了这段代码后发现，哪怕 maxbytes 很小的时候，它也能把值复制到缓
 * 冲区中。
 *
 * A. 解释为什么代码中的条件测试总是成功。提示：sizeof 运算符返回类型为 size_t 的值。
 * B. 你该如何重写这个条件测试，使之工作正确。
 *
 */

void copy_int(int val, void *buf, int maxbytes)
{

    // A 这段代码不能处理 maxbytes < 0 的情况
    if (maxbytes > 0 && maxbytes >= sizeof(int))
    {
        memcpy(buf, (void *)&val, sizeof(val));
    }
}

int main(int argc, char *argv[])
{
    int maxbytes = sizeof(int) * 10;
    void *buf = malloc(maxbytes);
    int val;

    val = 0x12345678;
    copy_int(val, buf, maxbytes);
    printf("%x\n", (*(int *)buf));

    val = 0xAABBCCDD;
    copy_int(val, buf, 0);
    printf("%x\n", (*(int *)buf));

    free(buf);
    return 0;
}