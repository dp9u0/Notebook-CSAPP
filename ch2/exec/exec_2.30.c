/*
测试补码整数相加是否溢出
*/
int tadd_ok(int x, int y)
{
    if (x > 0 && y > 0)
    {
        return x + y > 0;
    }
    if (x < 0 && y > 0)
    {
        return x + y < 0;
    }
    return 1;
}