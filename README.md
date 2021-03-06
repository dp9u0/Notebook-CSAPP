# 计算机系统

[Notebook系列](https://github.com/dp9u0/Notebook)

## [从HelloWorld讲起](ch1/README.md)

* [信息](ch1/README.md#信息)
* [编译](ch1/README.md#编译)
* [处理器执行指令](ch1/README.md#处理器执行指令)
* [高速缓存](ch1/README.md#高速缓存)
* [存储层次](ch1/README.md#存储层次)
* [操作系统](ch1/README.md#操作系统)
* [IPC(进程间通信)](ch1/README.md#ipc进程间通信)
  
## [信息的表示和处理](ch2/README.md)

* [信息存储](ch2/2.1.md)
* [整数](ch2/2.2.md)
* [整数运算](ch2/2.3.md)
* [浮点数](ch2/2.4.md)
* [字符编码](ch2/2.5.md)
* Reference
  * [Unicode 11.0 Character Code Charts](https://www.unicode.org/charts/)

## [程序的表示](ch3/README.md)

* [程序编码](ch3/3.01.md)
* [数据格式](ch3/3.02.md)
* [存取指令](ch3/3.03.md)
* [运算指令](ch3/3.04.md)
* [条件控制指令](ch3/3.05.md)
* [过程调用](ch3/3.06.md)
* [数组](ch3/3.07.md)
* [数据结构](ch3/3.08.md)
* [指针与溢出](ch3/3.09.md)
* [浮点数](ch3/3.10.md)
* Reference
  * [Stack allocation, padding, and alignment](https://stackoverflow.com/questions/1061818/stack-allocation-padding-and-alignment)
  * [Difference between movq and movabsq in x86-64](https://stackoverflow.com/questions/40315803/difference-between-movq-and-movabsq-in-x86-64)
  * [Linux中的各种栈:进程栈,线程栈,内核栈,中断栈](https://blog.csdn.net/yangkuanqaz85988/article/details/52403726)

## [处理器体系结构](ch4/README.md)

* [Y86-64](ch4/./4.1.md) : 介绍一个简单的64位架构 Y86-64 用以连接处理器体系结构
* [逻辑电路](ch4/./4.2.md) : 介绍逻辑电路和硬件控制语言 HCL
* [Y86-64 SEQ](ch4/./4.3.md) : Y86-64 CPU的顺序实现
* [流水线](ch4/./4.4.md) : 流水线设计
* [Y86-64 流水线](ch4/./4.5.md) : Y86-64 CPU 流水线设计

## [存储器层次结构](ch6/README.md)

* [存储器技术](ch6/6.1.md)
* [存储器层次](ch6/6.2.md)
* [高速缓存](ch6/6.3.md)
* Reference
  * [每个程序员都应该了解的内存知识](http://blog.jobbole.com/34303/)
  * [每个程序员都应该了解的CPU高速缓存](http://blog.jobbole.com/36263/)
  * [Memory part 1](https://lwn.net/Articles/250967/)
  * [Memory part 2: CPU caches](https://lwn.net/Articles/252125/)

## [虚拟存储器](ch9/README.md)

* [虚拟内存](ch9/9.1.md)
* [地址翻译](ch9/9.2.md)
* [内存映射与分配](ch9/9.3.md)
* [虚拟内存相关的其他知识](ch9/9.4.md) : 垃圾回收与内存错误
* Reference
  * [每个程序员都应该了解的“虚拟内存”知识](http://blog.jobbole.com/36303/)
  * [Linux虚拟内存空间分布](https://blog.csdn.net/wyq_5/article/details/77481136)
  * [Linux虚拟地址空间布局以及进程栈和线程栈总结](https://www.cnblogs.com/xzzzh/p/6596982.html)
  * [64位Windows内核虚拟地址空间布局](http://blog.51cto.com/shayi1983/1734822)
  * [Kernel Virtual Address Layout](http://www.codemachine.com/article_x64kvas.html)

## [优化程序性能](ch5/README.md)

* [高效的循环](ch5/README.md#消除循环的低效率)
* [减少内存引用](ch5/README.md#减少不必要的内存引用)
* [循环展开](ch5/README.md#循环展开)
* [提高并行](ch5/README.md#提高并行)

## [链接](ch7/README.md)

* [静态链接](ch7/7.1.md) : 介绍ELF头,如何将目标文件重定向为一个可执行目标文件
* [动态链接共享库](ch7/7.2.md) : 介绍运行时链接机制

## [异常控制流](ch8/README.md)

* [异常分类](ch8/README.md#异常分类)
* [进程](ch8/README.md#进程)
* [信号](ch8/README.md#信号)
