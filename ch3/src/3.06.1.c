#include <stdio.h>

long leaf(long y)
{
    return y + 2;
}

long top(long x)
{
    long result = leaf(x - 5);
    return result + result;
}

int main()
{
    top(100);
    return 0;
}