int uadd_ok(unsigned x, unsigned y)
{
    unsigned result = x + y;
    return x <= result && y <= result;
}