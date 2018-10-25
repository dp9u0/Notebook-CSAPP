struct rec
{
    int i;
    int j;
    int a[2];
    int *p;
};

void createRec()
{
    struct rec r;
    int i = 1;
    r.i = 10;
    r.j = 20;
    r.a[0] = 30;
    r.a[1] = 40;
    r.p = &i;
}