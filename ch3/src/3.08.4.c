/* $begin 440-aligns1-c */
struct S1
{
    int i;
    char c;
    int j;
};
/* $end 440-aligns1-c */

/* $begin 440-aligns2-c */
struct S2
{
    int i;
    int j;
    char c;
};
/* $end 440-aligns2-c */

struct S1 allocS1()
{
    struct S1 s1;
    return s1;
}

struct S2 allocS2()
{
    struct S2 s2;
    return s2;
}