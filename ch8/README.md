# 异常控制流

异常处理用来响应处理器状态的某些变化.

![处理异常过程](./img/8.01.png)

![异常跳转表](./img/8.02.png)

## 异常分类

中断是外部I/O 信号导致的异步异常,其他(陷阱,故障,中断)都是由于当前指令引起的同步异常

### 中断

外部I/O 设备发出信号引发中断,处理器执行完当前指令后检测到这一信号,然后中断跳转到对应的异常处理代码.处理完后跳转回执行下一指令.

### 陷阱

陷阱是有意的异常,最重要的作用是提供系统调用(syscall).

```s
# #include "csapp.h"
# int main()
# {
#   write(1, "hello, world\n", 13);
#   _exit(0);
# }

.section .data
string:
  .ascii "hello, world\n"
string_end:
  .equ len, string_end - string
.section .text
.globl main
main:
    # First, call write(1, "hello, world\n", 13)
    movq $1, %rax        # System call number 1
    movq $1, %rdi        # stdout has descriptor 1
    movq $string, %rsi   # Hello world string
    movq $len, %rdx      # String length
    syscall

    # Next, call exit(0)
    movq $60, %rax       # System call number 60
    movq $0, %rdi        # Argument is 0
    syscall
```

### 故障

典型的故障时缺页异常,当读取一个地址,发现缺页,会引发缺页异常,系统加载缺页的内存,然后重新执行当前指令.

### 终止

不可恢复的致命错误