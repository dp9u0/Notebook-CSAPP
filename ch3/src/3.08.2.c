struct S3
{
    char c;
    int i[2];
    double v;
};

union U3 {
    char c;
    int i[2];
    double v;
};

double uu2double(unsigned word0, unsigned word1)
{
    union {
        double d;
        unsigned u[2];
    } temp;

    temp.u[0] = word0;
    temp.u[1] = word1;
    return temp.d;
}