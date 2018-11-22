# 链接

链接是将各个代码和数据段合并为一个单一文件的过程.

```c
int sum(int *a, int n);

int array[2] = {1, 2};

int main()
{
  int val = sum(array, 2);
  return val;
}
```

```c
int sum(int *a, int n)
{
  int i, s = 0;
  for (i = 0; i < n; i++)
  {
    s += a[i];
  }
  return s;
}
```

## 静态链接与目标文件

通过符号解析和重定位将多个多个目标文件合并为一个可执行目标文件,目标文件主要有可重定位(用于编译生成可执行文件),可执行(直接复制到内存运行)以及共享(执行时动态加载)

目标文件不同操作系统上格式有所不同但是大同小异 : PE Mach-O ELF