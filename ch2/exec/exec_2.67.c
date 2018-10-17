/*
 * 2.67
 *
 * 编写nt_size_is_32()
 * 当在一个 int 是 32 位的机器上运行时产生 1
 * 其他情况则产生 0。
 * 不允许使用 sizeof 运算符
 *
 * // The following code does not run properly on some machines
 * int bad_int_size_is_32() {
 *     // Set most significant bit (msb) of 32-bit machine
 *     int set_msb = 1 << 31;
 *     // Shift past msb of 32-bit word
 *     int beyond_msb = 1 << 32;
 *
 *     // set_msb is nonzero when word size >= 32
 *     // beyond_msb is zero when word size <= 32
 *     return set_msb && !beyond_msb;
 * }
 *
 * 当在 SUN SPARC 这样的 32 位机器上编译并运行时，这个过程返回的却是 0。下面的
 * 编译器信息给了我们一个问题的指示：
 *
 * warning: left shift count >= width of type
 *
 * A. 我们的代码在哪个方面没有遵守 C 语言标准？
 * B. 修改代码，使得它在 int 至少为 32 位的任何机器上都能正确运行。
 * C. 修改代码，使得它在 int 至少为 16 位的任何机器上都能正确运行。
 */

#include <limits.h>

int int_size_is_32()
{
    int t = 0x80000000;
    return t == INT_MIN;
}

/*
 * B
 */
int int_size_is_32_for_32bit()
{
    int t = 0x80000000;
    return t;
}

/*
 * C
 */
int int_size_is_32_for_16bit()
{
    int t = 0x8000;
    return t;
}

int main(int argc, char *argv[])
{

}