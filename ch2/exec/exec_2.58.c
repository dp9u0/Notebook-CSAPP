/*
小端机器输出 1 大端机器输出 0
*/

#include <stdio.h>
#include <assert.h>

typedef unsigned char *byte_pointer;

int is_little_endian()
{
    int test = 0xff;
    byte_pointer chars = (byte_pointer)&test;
    return chars[0] == 0xff;
}

int main(int argc, char* argv[]) {
  printf("%d",is_little_endian());
  return 0;
}