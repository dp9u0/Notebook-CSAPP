unsigned long long getbuf()
{
    char buf[36];
    volatile char *variable_length;
    int i;
    unsigned long long val;
    return val % 40;
}

int main()
{
    getbuf();
    return 0;
}