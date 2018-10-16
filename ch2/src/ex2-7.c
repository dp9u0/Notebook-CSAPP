#include <stdio.h>
#include <string.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len)
{
    int i;
    for (i = 0; i < len; i++)
        printf(" %.2x", start[i]); //line:data:show_bytes_printf
    printf("\n");
}

int main(void)
{
        const char *s = "abcdef";
        show_bytes((byte_pointer)s, strlen(s));
        return 0;
}
