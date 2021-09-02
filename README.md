# UCAS Compiler

UCAS 编译原理实验课 一个基于 Antlr 的 CACT 语言编译器

注意：

        CACT 项目难度远高于 LLVM ，如果你不对编译特别感兴趣，请不要选择该项目。
        仅作思路参考，请不要直接照抄。


本项目参考了学长的项目：[https://github.com/zhangshuoming990105/CACTcompiler](https://github.com/zhangshuoming990105/CACTcompiler)

在此基础上做了诸多改进：将中间代码 IR 生成，目标代码 RISCV 生成都实现为独立的模块，并对符号表和中间代码形式都做了进一步优化。
