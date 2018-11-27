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