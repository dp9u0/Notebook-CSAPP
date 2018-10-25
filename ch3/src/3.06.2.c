void proc(long x1, long *x2p, int x3, int *x4p, short x5, short *x6p, char x7, char *x8p)
{
    *x2p += x1;
    *x4p += x3;
    *x6p += x5;
    *x8p += x7;
}

long call_proc()
{
    long x1 = 1;
    int x2 = 2;
    short x3 = 3;
    char x4 = 4;
    proc(x1, &x1, x2, &x2, x3, &x3, x4, &x4);
    return (x1 + x2) * (x3 - x4);
}