#include <stdio.h>
 
unsigned long long getbuf()
{
  char buf[36];
  volatile char* bufp = &buf;
  buf[0] = 1;
  int i = 2;
  unsigned long long val = buf; 
  printf("%llx %llx %llx %llx\n", bufp, i, val, *bufp); 
  return val % 40;
}
 
int main()
{
    getbuf();
    return 0;
}
