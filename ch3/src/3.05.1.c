#include <stdio.h>
#include <time.h>

static unsigned next = 1;

int rand(void)
{
    next = next * 1103515245 + 12345;
    return (unsigned int)(next / 65536) % 32768;
}

/* srand - set seed for rand() */
void srand(unsigned int seed)
{
    next = seed;
}

void init_seed(void)
{
    srand(time(NULL));
}

int random_int(void)
{
    int int_bits = sizeof(int) * 8;
    int i;
    int random = 0;
    for (i = 0; i < int_bits; i++)
    {
        random |= rand() % 2;
        random <<= 1;
    }
    return random;
}

long absdiff(long x, long y)
{
    long result;
    if (x < y)
    {
        result = y - x;
    }
    else
    {
        result = x - y;
    }
    return result;
}

long cmovdiff(long x, long y)
{
    long xy = x - y;
    long yx = y - x;
    long cond = x >= y;
    if (cond)
    {
        return yx = xy;
    }
    return yx;
}

int main(int argc, char *argv[])
{
    init_seed();
}