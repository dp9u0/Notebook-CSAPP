# 优化程序性能

## 编译器优化能力有限

```c
// twittle 并不能优化为 twittle2
// xp == yp 内存别名引用
long twittle(long *xp,long *yp){
  *xp += *yp;
  *xp += *yp;
}

long twittle2(long *xp,long *yp){
  *xp += 2* *yp;
}
```

优化过程中使用每元素周期数表示程序性能.

## 优化

### 消除循环的低效率

```c
/* Convert string to lowercase: slow */
void lower1(char *s)
{
  long i;

  for (i = 0; i < strlen(s); i++)
    if (s[i] >= 'A' && s[i] <= 'Z')
      s[i] -= ('A' - 'a');
}
```

避免每次循环都调用 `strlen(s)`

```c
/* Convert string to lowercase: faster */
void lower2(char *s)
{
  long i;
  long len = strlen(s);

  for (i = 0; i < len; i++)
    if (s[i] >= 'A' && s[i] <= 'Z')
      s[i] -= ('A' - 'a');
}

// Pocessor Clock Rate ~= 1.9962 GHz (extracted from file)
// Length  lower1  lower2
// 20000   0.113237        0.000017
// 40000   0.454898        0.000034
// 60000   1.046550        0.000079
// 80000   2.078326        0.000067
// 100000  2.969809        0.000084
// 120000  4.280525        0.000100
```

### 减少过程调用

调用过程会有很多比必要的开销.

### 减少不必要的内存引用

```c
/* Direct access to vector data */
void combine3(vec_ptr v, data_t *dest)
{
  long i;
  long length = vec_length(v);
  data_t *data = get_vec_start(v);

  *dest = IDENT;
  for (i = 0; i < length; i++)
  {
    *dest = *dest OP data[i];
  }
}
/* $end combine3 */
```

循环中对每次都使用 `*dest` 更改为 使用栈上的临时变量 `acc` :

```c
/* Accumulate result in local variable */
void combine4(vec_ptr v, data_t *dest)
{
  long i;
  long length = vec_length(v);
  data_t *data = get_vec_start(v);
  data_t acc = IDENT;

  for (i = 0; i < length; i++)
  {
    acc = acc OP data[i];
  }
  *dest = acc;
}
/* $end combine4 */
```

### 循环展开

降低循环次数,一次循环执行两次甚至多次计算

```c
/* 2 x 1 loop unrolling */
void combine5(vec_ptr v, data_t *dest)
{
  long i;
  long length = vec_length(v);
  long limit = length - 1;
  data_t *data = get_vec_start(v);
  data_t acc = IDENT;

  /* Combine 2 elements at a time */
  for (i = 0; i < limit; i += 2)
  {
    /* $begin combine5-update */
    acc = (acc OP data[i])OP data[i + 1];
    /* $end combine5-update */
  }

  /* Finish any remaining elements */
  for (; i < length; i++)
  {
    acc = acc OP data[i];
  }
  *dest = acc;
}
/* $end combine5 */
```

但是仅对整数计算有效果,如果类型是基于double的 效果就不会那么明显

### 提高并行

考虑到当前CPU架构设计,利用Superscalar 可以在循环展开的基础上进一步提升速度.

```c
/* $begin combine6 */
/* 2 x 2 loop unrolling */
void combine6(vec_ptr v, data_t *dest)
{
  long i;
  long length = vec_length(v);
  long limit = length - 1;
  data_t *data = get_vec_start(v);
  data_t acc0 = IDENT;
  data_t acc1 = IDENT;

  /* Combine 2 elements at a time */
  for (i = 0; i < limit; i += 2)
  {
    acc0 = acc0 OP data[i];
    acc1 = acc1 OP data[i + 1];
  }

  /* Finish any remaining elements */
  for (; i < length; i++)
  {
    acc0 = acc0 OP data[i];
  }
  *dest = acc0 OP acc1;
}
/* $end combine6 */
```

> 利用向量指令可以进一步达到更好的并行度. 即 SIMD

## 一些限制

* 寄存器溢出 : 使用提高并行度方法时,需要注意不要超过可用寄存器数量.
* 分支预测
* 内存性能 : 无论如何都要进行内存存取,这才是瓶颈的最终所在,上面的优化只能尽量减少内存存取.

## 优化指导

* 高级数据结构和算法
* 消除函数调用,将函数调用移动到循环外
* 消除内存引用.引入临时变量.
* 循环展开
* 使用新技术 例如 SIMD
* 编写生成条件传送(`cmov`)而不是条件控制转移(`jXX`)的代码 : 条件传送没有预测失败惩罚