# 链接

链接是将各个代码和数据段合并为一个单一文件的过程.

通过一段代码讲解这些内容:

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

主要分为两部分介绍:

* [静态链接](./7.1.md) : 介绍ELF头,如何将目标文件重定向为一个可执行目标文件
* [动态链接共享库](./7.2.md) : 介绍运行时链接机制