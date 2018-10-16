/*
测试无符号整数相加是否溢出
*/
int uadd_ok(unsigned x, unsigned y)
{
    unsigned result = x + y;
    return x <= result && y <= result;
}