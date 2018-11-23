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

## objdump命令使用

```shell
 用法：objdump <选项> <文件>
 显示来自目标 <文件> 的信息。
 至少必须给出以下选项之一：
  -a, --archive-headers    Display archive header information
  -f, --file-headers       Display the contents of the overall file header
  -p, --private-headers    Display object format specific file header contents
  -P, --private=OPT,OPT... Display object format specific contents
  -h, --[section-]headers  Display the contents of the section headers
  -x, --all-headers        Display the contents of all headers　　　　　　　　　　显示头信息
  -d, --disassemble        Display assembler contents of executable sections　　显示代码段代码
  -D, --disassemble-all    Display assembler contents of all sections　　　　　　显示所有段代码
  -S, --source             Intermix source code with disassembly
  -s, --full-contents      Display the full contents of all sections requested
  -g, --debugging          Display debug information in object file
  -e, --debugging-tags     Display debug information using ctags style
  -G, --stabs              Display (in raw form) any STABS info in the file
  -W[lLiaprmfFsoRt] or
  --dwarf[=rawline,=decodedline,=info,=abbrev,=pubnames,=aranges,=macro,=frames,
          =frames-interp,=str,=loc,=Ranges,=pubtypes,
          =gdb_index,=trace_info,=trace_abbrev,=trace_aranges,
          =addr,=cu_index]
                           Display DWARF info in the file
  -t, --syms               Display the contents of the symbol table(s)
  -T, --dynamic-syms       Display the contents of the dynamic symbol table
  -r, --reloc              Display the relocation entries in the file
  -R, --dynamic-reloc      Display the dynamic relocation entries in the file
  @<file>                  Read options from <file>
  -v, --version            Display this program's version number
  -i, --info               List object formats and architectures supported
  -H, --help               Display this information

 以下选项是可选的：
  -b, --target=BFDNAME           将标的目标文件格式指定为 BFDNAME
  -m, --architecture=MACHINE     将标的体系结构指定为 MACHINE
  -j, --section=NAME             只显示 NAME 节的信息
  -M, --disassembler-options=OPT 将文本传递到 OPT 反汇编程序
  -EB --endian=big               反汇编时假定高位字节在前
  -EL --endian=little            反汇编时假定低位字节在前
      --file-start-context       从文件的起点引入上下文 (带有 -S)
  -l, --line-numbers             在输出中给出行号和文件名
  -C, --demangle[=STYLE]         对修饰过的 (mangled) 符号名进行解码
                                  如果给出了 STYLE，STYLE 可能为“auto”、“gnu”、
                                 “lucid”、“arm”、“hp”、“edg”或“gnu-new-abi”
  -w, --wide                     以多于 80 列的宽度对输出进行格式化
  -z, --disassemble-zeroes       反汇编时不要跳过为零的块
      --start-address=ADDR       只有进程数据的地址 >= ADDR
      --stop-address=ADDR        只有进程数据的地址 <= ADDR
      --prefix-addresses         同反汇编代码并列显示完整的地址
      --[no-]show-raw-insn       同符号反汇编并列显示十六进制值
      --adjust-vma=OFFSET        为所有显示的节地址增加 OFFSET

      --dwarf-depth=N        Do not display DIEs at depth N or greater
      --dwarf-start=N        Display DIEs starting with N, at the same depth
                             or deeper
      --dwarf-check          Make additional dwarf internal consistency checks.      

objdump：支持的目标： elf64-x86-64 elf32-i386 elf32-iamcu elf32-x86-64 a.out-i386-linux pei-i386 pei-x86-64 elf64-l1om elf64-k1om elf64-little elf64-big elf32-little elf32-big plugin srec symbolsrec verilog tekhex binary ihex
objdump：支持的体系结构： i386 i386:x86-64 i386:x64-32 i8086 i386:intel i386:x86-64:intel i386:x64-32:intel i386:nacl i386:x86-64:nacl i386:x64-32:nacl iamcu iamcu:intel l1om l1om:intel k1om k1om:intel plugin

下列 i386/x86-64 特定的反汇编器选项在使用 -M 开关时可用（使用逗号分隔多个选项）：
  x86-64      Disassemble in 64bit mode
  i386        Disassemble in 32bit mode
  i8086       在 16 位模式下反汇编
  att         用 AT&T 语法显示指令
  intel       用 Intel 语法显示指令
  att-mnemonic
              Display instruction in AT&T mnemonic
  intel-mnemonic
              Display instruction in Intel mnemonic
  addr64      假定 64 位地址大小
  addr32      假定 32 位地址大小
  addr16      假定 16 位地址大小
  data32      假定 32 位数据大小
  data16      假定 16 位数据大小
  suffix      在 AT&T 语法中始终显示指令后缀
  amd64       Display instruction in AMD64 ISA
  intel64     Display instruction in Intel64 ISA
```