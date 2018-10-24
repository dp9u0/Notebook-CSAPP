void proc(long x1, long *x2p, int x3, int *x4p, short x5, short *x6p, char x7, char *x8p)
{
    *x2p += x1;
    *x4p += x3;
    *x6p += x5;
    *x8p += x7;
}