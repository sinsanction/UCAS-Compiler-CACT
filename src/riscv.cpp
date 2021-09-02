#include "riscv.h"

void RISCV_CODE::RISCV_Gen(SymbolTable &sym_table, IR &ir, std::string out_file)
{
    //file info
    std::string name;
    name = ".file   \"" + out_file + ".cact\"";
    riscv_codes.push_back(name);
    riscv_codes.push_back(".option nopic");
    riscv_codes.push_back(".attribute arch, \"rv64i2p0_m2p0_a2p0_f2p0_d2p0_c2p0\"");
    riscv_codes.push_back(".attribute unaligned_access, 0");
    riscv_codes.push_back(".attribute stack_align, 16");

    for (auto i = ir.ir_codes.begin(); i != ir.ir_codes.end(); i++) {
        auto ins = *i;

        if (ins.op == OP::FUNC_BEGIN) {
            RISCV_FuncBegin(sym_table, ins);
        }
        else if (ins.op == OP::FUNC_END) {
            RISCV_FuncEnd(sym_table, ins);
        }
        else if (ins.op == OP::CALL) {
            RISCV_Call(ins);
        }
        else if (ins.op == OP::RET) {
            RISCV_Return(ins);
        }
        else if (ins.op == OP::LABEL) {
            RISCV_Label(ins);
        }
        else if (ins.op == OP::GOTO) {
            RISCV_Goto(ins);
        }
        else if (ins.op == OP::BEQZ) {
            RISCV_Beqz(ins);
        }

        else if (ins.op == OP::LOAD) {
            RISCV_Load(ins);
        }
        else if (ins.op == OP::STORE) {
            RISCV_Store(ins);
        }
        else if (ins.op == OP::MOV) {
            RISCV_Move(ins);
        }
        else if (ins.op == OP::LI) {
            RISCV_Li(ins);
        }

        else if (ins.op == OP::READ_ARRAY) {
            RISCV_READARRAY(ins);
        }
        else if (ins.op == OP::SAVE_ARRAY) {
            RISCV_SAVEARRAY(ins);
        }

        else if (ins.op == OP::GLOBAL_ASSIGN) {
            RISCV_GLOBAL(ins);
        }
        else if (ins.op == OP::GLOBAL_ARRAY) {
            RISCV_GLOBAL_ARRAY(ins);
        }
        else if (ins.op == OP::GLOBAL_ARRAY_ASSIGN) {
            RISCV_GLOBAL_ARRAY_ASSIGN(ins);
        }
        else {
            RISCV_Arithmetic(ins);
        }
    }

    // 输出到文件
    //std::ofstream outfile("./out/" + out_file + ".s", std::ios::trunc);
    //std::cout << "Output File: " << "./out/" << out_file << ".s" << std::endl;
    std::ofstream outfile("../out/" + out_file + ".s", std::ios::trunc);
    std::cout << "Output File: " << "../out/" << out_file << ".s" << std::endl;
    for (auto &ins : riscv_codes) {
        if (ins.find(':') == -1) {
            outfile << '\t';
        }
        outfile << ins << std::endl;
    }
    outfile.close();
}

void RISCV_CODE::RISCV_FuncBegin(SymbolTable &sym_table, IRCode &ins)
{
    auto func_name = ins.rst;
    riscv_codes.push_back("");
    riscv_codes.push_back(".text");
    riscv_codes.push_back(".align   1");
    riscv_codes.push_back(".globl   " + func_name);
    riscv_codes.push_back(".type    " + func_name + ", @function");
    riscv_codes.push_back(func_name + ":");

    FuncInfo *func_info = sym_table.lookup_func(func_name);
    int frame_size = func_info->stack_size;
    int div = frame_size / 16;
    int mod = frame_size % 16;
    int size = (mod == 0) ? (div + 1) * 16 : (div + 2) * 16; //ra sp 8+8
    riscv_codes.push_back("#frame size: " + std::to_string(size));
    riscv_codes.push_back("addi  sp, sp, -" + std::to_string(size));
    riscv_codes.push_back("sd    ra, " + std::to_string(size - 8) + "(sp)");
    riscv_codes.push_back("sd    s0, " + std::to_string(size - 16) + "(sp)");
    riscv_codes.push_back("addi  s0, sp, " + std::to_string(size));
}

void RISCV_CODE::RISCV_FuncEnd(SymbolTable &sym_table, IRCode &ins)
{
    auto func_name = ins.rst;
    FuncInfo *func_info = sym_table.lookup_func(func_name);
    int frame_size = func_info->stack_size;
    int div = frame_size / 16;
    int mod = frame_size % 16;
    int size = (mod == 0) ? (div + 1) * 16 : (div + 2) * 16; //ra sp 8+8

    //riscv_codes.push_back("#frame size: " + std::to_string(size));
    riscv_codes.push_back("func_end" + std::to_string(end_func_label++) + ":");
    riscv_codes.push_back("ld    ra, " + std::to_string(size - 8) + "(sp)");
    riscv_codes.push_back("ld    s0, " + std::to_string(size - 16) + "(sp)");
    riscv_codes.push_back("addi  sp, sp, " + std::to_string(size));
    riscv_codes.push_back("jr    ra");
    riscv_codes.push_back(".size    " + func_name + ",  .-" + func_name);
}

void RISCV_CODE::RISCV_Call(IRCode &ins)
{
    auto func_name = ins.rst;
    riscv_codes.push_back("call  " + func_name);
    riscv_codes.push_back("nop");
}

void RISCV_CODE::RISCV_Return(IRCode &ins)
{
    std::string j = "j     ";
    std::string target = "func_end" + std::to_string(end_func_label);
    riscv_codes.push_back(j + target);
}

void RISCV_CODE::RISCV_Label(IRCode &ins)
{
    riscv_codes.push_back(ins.rst);
}

void RISCV_CODE::RISCV_Goto(IRCode &ins)
{
    auto lab = ins.rst.substr(0, ins.rst.length() - 1);
    riscv_codes.push_back("j     " + lab);
}

void RISCV_CODE::RISCV_Beqz(IRCode &ins)
{
    auto lab = ins.rst.substr(0, ins.rst.length() - 1);
    riscv_codes.push_back("beqz  " + ins.arg1 + ", " + lab);
}

void RISCV_CODE::RISCV_Arithmetic(IRCode &ins)
{
    if (ins.cls == CLASS_INT) {
        if (ins.op == OP::ADD) {
            riscv_codes.push_back("addw  " + ins.rst + ", " + ins.arg1 + ", " + ins.arg2);
        }
        else if (ins.op == OP::SUB) {
            riscv_codes.push_back("subw  " + ins.rst + ", " + ins.arg1 + ", " + ins.arg2);
        }
        else if (ins.op == OP::MUL) {
            riscv_codes.push_back("mul   " + ins.rst + ", " + ins.arg1 + ", " + ins.arg2);
        }
        else if (ins.op == OP::DIV) {
            riscv_codes.push_back("div   " + ins.rst + ", " + ins.arg1 + ", " + ins.arg2);
        }
        else if (ins.op == OP::MOD) {
            riscv_codes.push_back("rem   " + ins.rst + ", " + ins.arg1 + ", " + ins.arg2);
        }
        else if (ins.op == OP::NEG) {
            riscv_codes.push_back("neg   " + ins.rst + ", " + ins.arg1);
        }

        else if (ins.op == OP::EQU) {
            riscv_codes.push_back("subw  " + ins.rst + ", " + ins.arg1 + ", " + ins.arg2);
            riscv_codes.push_back("sltu  " + ins.rst + ", zero, " + ins.rst);
            riscv_codes.push_back("not   " + ins.rst + ", " + ins.rst);
            riscv_codes.push_back("andi  " + ins.rst + ", " + ins.rst + ", 1");
        }
        else if (ins.op == OP::NEQ) {
            riscv_codes.push_back("subw  " + ins.rst + ", " + ins.arg1 + ", " + ins.arg2);
            riscv_codes.push_back("sltu  " + ins.rst + ", zero, " + ins.rst);
        }
        else if (ins.op == OP::LT) {
            riscv_codes.push_back("slt   " + ins.rst + ", " + ins.arg1 + ", " + ins.arg2);
        }
        else if (ins.op == OP::GE) {
            riscv_codes.push_back("slt   " + ins.rst + ", " + ins.arg1 + ", " + ins.arg2);
            riscv_codes.push_back("not   " + ins.rst + ", " + ins.rst);
            riscv_codes.push_back("andi  " + ins.rst + ", " + ins.rst + ", 1");
        }
        else if (ins.op == OP::GT) {
            riscv_codes.push_back("slt   " + ins.rst + ", " + ins.arg2 + ", " + ins.arg1);
        }
        else if (ins.op == OP::LE) {
            riscv_codes.push_back("slt   " + ins.rst + ", " + ins.arg2 + ", " + ins.arg1);
            riscv_codes.push_back("not   " + ins.rst + ", " + ins.rst);
            riscv_codes.push_back("andi  " + ins.rst + ", " + ins.rst + ", 1");
        }
    }
    else if (ins.cls == CLASS_BOOLEAN) {
        if (ins.op == OP::AND) {
            riscv_codes.push_back("and   " + ins.rst + ", " + ins.arg1 + ", " + ins.arg2);
        }
        else if (ins.op == OP::OR) {
            riscv_codes.push_back("or    " + ins.rst + ", " + ins.arg1 + ", " + ins.arg2);
        }
        else if (ins.op == OP::NOT) {
            riscv_codes.push_back("not   " + ins.rst + ", " + ins.arg1);
        }
        else if (ins.op == OP::EQU) {
            riscv_codes.push_back("subw  " + ins.rst + ", " + ins.arg1 + ", " + ins.arg2);
            riscv_codes.push_back("sltu  " + ins.rst + ", zero, " + ins.rst);
            riscv_codes.push_back("not   " + ins.rst + ", " + ins.rst);
            riscv_codes.push_back("andi  " + ins.rst + ", " + ins.rst + ", 1");
        }
        else if (ins.op == OP::NEQ) {
            riscv_codes.push_back("subw  " + ins.rst + ", " + ins.arg1 + ", " + ins.arg2);
            riscv_codes.push_back("sltu  " + ins.rst + ", zero, " + ins.rst);
        }
    }
    else if (ins.cls == CLASS_FLOAT) {
        if (ins.op == OP::ADD) {
            riscv_codes.push_back("fadd.s  f" + ins.rst + ", f" + ins.arg1 + ", f" + ins.arg2);
        }
        else if (ins.op == OP::SUB) {
            riscv_codes.push_back("fsub.s  f" + ins.rst + ", f" + ins.arg1 + ", f" + ins.arg2);
        }
        else if (ins.op == OP::MUL) {
            riscv_codes.push_back("fmul.s  f" + ins.rst + ", f" + ins.arg1 + ", f" + ins.arg2);
        }
        else if (ins.op == OP::DIV) {
            riscv_codes.push_back("fdiv.s  f" + ins.rst + ", f" + ins.arg1 + ", f" + ins.arg2);
        }

        else if (ins.op == OP::EQU) {
            riscv_codes.push_back("feq.s   " + ins.rst + ", f" + ins.arg1 + ", f" + ins.arg2);
        }
        else if (ins.op == OP::NEQ) {
            riscv_codes.push_back("feq.s   " + ins.rst + ", f" + ins.arg1 + ", f" + ins.arg2);
            riscv_codes.push_back("not   " + ins.rst + ", " + ins.rst);
            riscv_codes.push_back("andi  " + ins.rst + ", " + ins.rst + ", 1");
        }
        else if (ins.op == OP::LT) {
            riscv_codes.push_back("flt.s   " + ins.rst + ", f" + ins.arg1 + ", f" + ins.arg2);
        }
        else if (ins.op == OP::GE) {
            riscv_codes.push_back("flt.s   " + ins.rst + ", f" + ins.arg1 + ", f" + ins.arg2);
            riscv_codes.push_back("not   " + ins.rst + ", " + ins.rst);
            riscv_codes.push_back("andi  " + ins.rst + ", " + ins.rst + ", 1");
        }
        else if (ins.op == OP::LE) {
            riscv_codes.push_back("fle.s   " + ins.rst + ", f" + ins.arg1 + ", f" + ins.arg2);
        }
        else if (ins.op == OP::GT) {
            riscv_codes.push_back("fle.s   " + ins.rst + ", f" + ins.arg1 + ", f" + ins.arg2);
            riscv_codes.push_back("not   " + ins.rst + ", " + ins.rst);
            riscv_codes.push_back("andi  " + ins.rst + ", " + ins.rst + ", 1");
        }
    }
    else if (ins.cls == CLASS_DOUBLE) {
        if (ins.op == OP::ADD) {
            riscv_codes.push_back("fadd.d  f" + ins.rst + ", f" + ins.arg1 + ", f" + ins.arg2);
        }
        else if (ins.op == OP::SUB) {
            riscv_codes.push_back("fsub.d  f" + ins.rst + ", f" + ins.arg1 + ", f" + ins.arg2);
        }
        else if (ins.op == OP::MUL) {
            riscv_codes.push_back("fmul.d  f" + ins.rst + ", f" + ins.arg1 + ", f" + ins.arg2);
        }
        else if (ins.op == OP::DIV) {
            riscv_codes.push_back("fdiv.d  f" + ins.rst + ", f" + ins.arg1 + ", f" + ins.arg2);
        }

        else if (ins.op == OP::EQU) {
            riscv_codes.push_back("feq.d   " + ins.rst + ", f" + ins.arg1 + ", f" + ins.arg2);
        }
        else if (ins.op == OP::NEQ) {
            riscv_codes.push_back("feq.d   " + ins.rst + ", f" + ins.arg1 + ", f" + ins.arg2);
            riscv_codes.push_back("not   " + ins.rst + ", " + ins.rst);
            riscv_codes.push_back("andi  " + ins.rst + ", " + ins.rst + ", 1");
        }
        else if (ins.op == OP::LT) {
            riscv_codes.push_back("flt.d   " + ins.rst + ", f" + ins.arg1 + ", f" + ins.arg2);
        }
        else if (ins.op == OP::GE) {
            riscv_codes.push_back("flt.d   " + ins.rst + ", f" + ins.arg1 + ", f" + ins.arg2);
            riscv_codes.push_back("not   " + ins.rst + ", " + ins.rst);
            riscv_codes.push_back("andi  " + ins.rst + ", " + ins.rst + ", 1");
        }
        else if (ins.op == OP::LE) {
            riscv_codes.push_back("fle.d   " + ins.rst + ", f" + ins.arg1 + ", f" + ins.arg2);
        }
        else if (ins.op == OP::GT) {
            riscv_codes.push_back("fle.d   " + ins.rst + ", f" + ins.arg1 + ", f" + ins.arg2);
            riscv_codes.push_back("not   " + ins.rst + ", " + ins.rst);
            riscv_codes.push_back("andi  " + ins.rst + ", " + ins.rst + ", 1");
        }
    }
}

void RISCV_CODE::RISCV_Load(IRCode &ins)
{
    auto name = ins.arg1;
    auto postfix = name.substr(name.length() - 2, 2);
    if (postfix == ".g") {
        name = name.substr(0, name.length() - 2);
        if (ins.cls == CLASS_INT || ins.cls == CLASS_BOOLEAN) {
            riscv_codes.push_back("lui   t5, %hi(" + name + ")");
            riscv_codes.push_back("lw    " + ins.rst + ", %lo(" + name + ")(t5)");
        }
        else if (ins.cls == CLASS_FLOAT) {
            riscv_codes.push_back("lui   t5, %hi(" + name + ")");
            riscv_codes.push_back("flw     f" + ins.rst + ", %lo(" + name + ")(t5)");
        }
        else if (ins.cls == CLASS_DOUBLE) {
            riscv_codes.push_back("lui   t5, %hi(" + name + ")");
            riscv_codes.push_back("fld     f" + ins.rst + ", %lo(" + name + ")(t5)");
        }
    }
    else {
        if (ins.cls == CLASS_INT || ins.cls == CLASS_BOOLEAN) {
            riscv_codes.push_back("lw    " + ins.rst + ", " + ins.arg1);
        }
        else if (ins.cls == CLASS_FLOAT) {
            riscv_codes.push_back("flw     f" + ins.rst + ", " + ins.arg1);
        }
        else if (ins.cls == CLASS_DOUBLE) {
            riscv_codes.push_back("fld     f" + ins.rst + ", " + ins.arg1);
        }
    }
}

void RISCV_CODE::RISCV_Store(IRCode &ins)
{
    auto name = ins.arg1;
    auto postfix = name.substr(name.length() - 2, 2);
    if (postfix == ".g") {
        name = name.substr(0, name.length() - 2);
        if (ins.cls == CLASS_INT || ins.cls == CLASS_BOOLEAN) {
            riscv_codes.push_back("lui   t5, %hi(" + name + ")");
            riscv_codes.push_back("sw    " + ins.rst + ", %lo(" + name + ")(t5)");
        }
        else if (ins.cls == CLASS_FLOAT) {
            riscv_codes.push_back("lui   t5, %hi(" + name + ")");
            riscv_codes.push_back("fsw     f" + ins.rst + ", %lo(" + name + ")(t5)");
        }
        else if (ins.cls == CLASS_DOUBLE) {
            riscv_codes.push_back("lui   t5, %hi(" + name + ")");
            riscv_codes.push_back("fsd     f" + ins.rst + ", %lo(" + name + ")(t5)");
        }
    }
    else {
        if (ins.cls == CLASS_INT || ins.cls == CLASS_BOOLEAN) {
            riscv_codes.push_back("sw    " + ins.rst + ", " + ins.arg1);
        }
        else if (ins.cls == CLASS_FLOAT) {
            riscv_codes.push_back("fsw     f" + ins.rst + ", " + ins.arg1);
        }
        else if (ins.cls == CLASS_DOUBLE) {
            riscv_codes.push_back("fsd     f" + ins.rst + ", " + ins.arg1);
        }
    }
}

void RISCV_CODE::RISCV_Move(IRCode &ins)
{
    if (ins.cls == CLASS_INT || ins.cls == CLASS_BOOLEAN) {
        riscv_codes.push_back("mv    " + ins.rst + ", " + ins.arg1);
    }
    else if (ins.cls == CLASS_FLOAT) {
        riscv_codes.push_back("fmv.s   f" + ins.rst + ", f" + ins.arg1);
    }
    else if (ins.cls == CLASS_DOUBLE) {
        riscv_codes.push_back("fmv.d   f" + ins.rst + ", f" + ins.arg1);
    }
}

void RISCV_CODE::RISCV_Li(IRCode &ins)
{
    if (ins.cls == CLASS_INT || ins.cls == CLASS_BOOLEAN) {
        riscv_codes.push_back("li    " + ins.rst + ", " + ins.arg1);
    }
    else if (ins.cls == CLASS_FLOAT) {
        riscv_codes.push_back("lui   a5, %hi(.LC" + std::to_string(float_tmp_count) + ")");
        riscv_codes.push_back("flw     f" + ins.rst + ", %lo(.LC" + std::to_string(float_tmp_count) + ")(a5)");

        float fval = std::stof(ins.arg1);
        int decimal_fval = *(int *)&fval;
        riscv_codes.push_back(".section .rodata");
        riscv_codes.push_back(".align   2");
        riscv_codes.push_back(".LC" + std::to_string(float_tmp_count) + ":");
        riscv_codes.push_back(".word    " + std::to_string(decimal_fval));
        riscv_codes.push_back(".text");
        float_tmp_count++;
    }
    else if (ins.cls == CLASS_DOUBLE) {
        riscv_codes.push_back("lui   a5, %hi(.LC" + std::to_string(float_tmp_count) + ")");
        riscv_codes.push_back("fld     f" + ins.rst + ", %lo(.LC" + std::to_string(float_tmp_count) + ")(a5)");

        double dval = std::stod(ins.arg1);
        long long decimal_dval = *(long long *)&dval;
        int hi = decimal_dval >> 32;
        int lo = decimal_dval & 0x00000000ffffffff;
        riscv_codes.push_back(".section .rodata");
        riscv_codes.push_back(".align   3");
        riscv_codes.push_back(".LC" + std::to_string(float_tmp_count) + ":");
        riscv_codes.push_back(".word    " + std::to_string(lo));
        riscv_codes.push_back(".word    " + std::to_string(hi));
        riscv_codes.push_back(".text");
        float_tmp_count++;
    }
}

void RISCV_CODE::RISCV_READARRAY(IRCode &ins)
{
    auto name = ins.arg1;
    auto postfix = name.substr(name.length() - 2, 2);
    if (postfix == ".g") {
        name = name.substr(0, name.length() - 2);
        if (ins.cls == CLASS_INT || ins.cls == CLASS_BOOLEAN) {
            riscv_codes.push_back("mv    t5," + ins.arg2);
            riscv_codes.push_back("slliw t5, t5, 2");
            riscv_codes.push_back("lui   s2, %hi(" + name + ")");
            riscv_codes.push_back("addi  s2, s2, %lo(" + name + ")");
            riscv_codes.push_back("add   s3, s2, t5");
            riscv_codes.push_back("lw    " + ins.rst + ", 0(s3)");
        }
        else if (ins.cls == CLASS_FLOAT) {
            riscv_codes.push_back("mv    t5," + ins.arg2);
            riscv_codes.push_back("slliw t5, t5, 2");
            riscv_codes.push_back("lui   s2, %hi(" + name + ")");
            riscv_codes.push_back("addi  s2, s2, %lo(" + name + ")");
            riscv_codes.push_back("add   s3, s2, t5");
            riscv_codes.push_back("flw     f" + ins.rst + ", 0(s3)");
        }
        else if (ins.cls == CLASS_DOUBLE) {
            riscv_codes.push_back("mv    t5," + ins.arg2);
            riscv_codes.push_back("slliw t5, t5, 3");
            riscv_codes.push_back("lui   s2, %hi(" + name + ")");
            riscv_codes.push_back("addi  s2, s2, %lo(" + name + ")");
            riscv_codes.push_back("add   s3, s2, t5");
            riscv_codes.push_back("fld     f" + ins.rst + ", 0(s3)");
        }
    }
    else {
        if (ins.cls == CLASS_INT || ins.cls == CLASS_BOOLEAN) {
            riscv_codes.push_back("mv    t5," + ins.arg2);
            riscv_codes.push_back("slliw t5, t5, 2");
            riscv_codes.push_back("add   s2, s0, t5");
            // s0 -> fp, addr of x[] is relative to fp, it is described as offset_to_fp(fp) in arg1
            // addr x[arg2] = addr_of_x[] + arg2 = offset_to_fp + (fp + arg2) = offset_to_fp + s2 = offset_to_fp(s2)
            std::string load_str = "lw    " + ins.rst + "," + ins.arg1;
            load_str = load_str.substr(0, load_str.find_first_of("("));
            load_str = load_str + "(s2)";
            riscv_codes.push_back(load_str);
        }
        else if (ins.cls == CLASS_FLOAT) {
            riscv_codes.push_back("mv    t5," + ins.arg2);
            riscv_codes.push_back("slliw t5, t5, 2");
            riscv_codes.push_back("add   s2, s0, t5");
            std::string load_str = "flw     f" + ins.rst + ", " + ins.arg1;
            load_str = load_str.substr(0, load_str.find_first_of("("));
            load_str = load_str + "(s2)";
            riscv_codes.push_back(load_str);
        }
        else if (ins.cls == CLASS_DOUBLE) {
            riscv_codes.push_back("mv    t5," + ins.arg2);
            riscv_codes.push_back("slliw t5, t5, 3");
            riscv_codes.push_back("add   s2, s0, t5");
            std::string load_str = "fld     f" + ins.rst + ", " + ins.arg1;
            load_str = load_str.substr(0, load_str.find_first_of("("));
            load_str = load_str + "(s2)";
            riscv_codes.push_back(load_str);
        }
    }
}

void RISCV_CODE::RISCV_SAVEARRAY(IRCode &ins)
{
    auto name = ins.arg1;
    auto postfix = name.substr(name.length() - 2, 2);
    if (postfix == ".g") {
        name = name.substr(0, name.length() - 2);
        if (ins.cls == CLASS_INT || ins.cls == CLASS_BOOLEAN) {
            riscv_codes.push_back("mv    t5," + ins.arg2);
            riscv_codes.push_back("slliw t5, t5, 2");
            riscv_codes.push_back("lui   s2, %hi(" + name + ")");
            riscv_codes.push_back("addi  s2, s2, %lo(" + name + ")");
            riscv_codes.push_back("add   s3, s2, t5");
            riscv_codes.push_back("sw    " + ins.rst + ", 0(s3)");
        }
        else if (ins.cls == CLASS_FLOAT) {
            riscv_codes.push_back("mv    t5," + ins.arg2);
            riscv_codes.push_back("slliw t5, t5, 2");
            riscv_codes.push_back("lui   s2, %hi(" + name + ")");
            riscv_codes.push_back("addi  s2, s2, %lo(" + name + ")");
            riscv_codes.push_back("add   s3, s2, t5");
            riscv_codes.push_back("fsw     f" + ins.rst + ", 0(s3)");
        }
        else if (ins.cls == CLASS_DOUBLE) {
            riscv_codes.push_back("mv    t5," + ins.arg2);
            riscv_codes.push_back("slliw t5, t5, 3");
            riscv_codes.push_back("lui   s2, %hi(" + name + ")");
            riscv_codes.push_back("addi  s2, s2, %lo(" + name + ")");
            riscv_codes.push_back("add   s3, s2, t5");
            riscv_codes.push_back("fsd     f" + ins.rst + ", 0(s3)");
        }
    }
    else {
        if (ins.cls == CLASS_INT || ins.cls == CLASS_BOOLEAN) {
            riscv_codes.push_back("mv    t5," + ins.arg2);
            riscv_codes.push_back("slliw t5, t5, 2");
            riscv_codes.push_back("add   s2, s0, t5"); 
            std::string store_str = "sw    " + ins.rst + ", " + ins.arg1;
            store_str = store_str.substr(0, store_str.find_first_of("("));
            store_str = store_str + "(s2)";
            riscv_codes.push_back(store_str);
        }
        else if (ins.cls == CLASS_FLOAT) {
            riscv_codes.push_back("mv    t5," + ins.arg2);
            riscv_codes.push_back("slliw t5, t5, 2");
            riscv_codes.push_back("add   s2, s0, t5");
            std::string store_str = "fsw     f" + ins.rst + ", " + ins.arg1;
            store_str = store_str.substr(0, store_str.find_first_of("("));
            store_str = store_str + "(s2)";
            riscv_codes.push_back(store_str);
        }
        else if (ins.cls == CLASS_DOUBLE) {
            riscv_codes.push_back("mv    t5," + ins.arg2);
            riscv_codes.push_back("slliw t5, t5, 3");
            riscv_codes.push_back("add   s2, s0, t5");
            std::string store_str = "fsd     f" + ins.rst + ", " + ins.arg1;
            store_str = store_str.substr(0, store_str.find_first_of("("));
            store_str = store_str + "(s2)";
            riscv_codes.push_back(store_str);
        }
    }
}

void RISCV_CODE::RISCV_GLOBAL(IRCode &ins)
{
    auto name = ins.rst;
    std::string ro_str = (ins.arg2 == "const") ? ".section .srodata, \"a\"" : (ins.arg2 == "uninited") ? ".bss" : ".section .sdata, \"aw\"";
    std::string align_str = (ins.cls == CLASS_DOUBLE) ? ".align   3" : ".align   2";
    int size = (ins.cls == CLASS_DOUBLE) ? 8 : 4;

    riscv_codes.push_back("");
    riscv_codes.push_back(".globl   " + name);
    riscv_codes.push_back(ro_str);
    riscv_codes.push_back(align_str);
    riscv_codes.push_back(".type    " + name + ", @object");
    riscv_codes.push_back(".size    " + name + ", " + std::to_string(size));
    riscv_codes.push_back(name + ":");

    if (ins.arg2 == "uninited") {
        riscv_codes.push_back(".zero    " + std::to_string(size));
    }
    else {
        if (ins.cls == CLASS_INT || ins.cls == CLASS_BOOLEAN) {
            riscv_codes.push_back(".word    " + ins.arg1);
        }
        else if (ins.cls == CLASS_FLOAT) {
            float fvalue = std::stof(ins.arg1);
            int decimal_fval = *(int *)&fvalue;
            riscv_codes.push_back(".word    " + std::to_string(decimal_fval));
        }
        else if (ins.cls == CLASS_DOUBLE) {
            double dvalue = std::stod(ins.arg1);
            long long decimal_dval = *(long long *)&dvalue;
            int hi = decimal_dval >> 32;
            int lo = decimal_dval & 0x00000000ffffffff;
            riscv_codes.push_back(".word    " + std::to_string(lo));
            riscv_codes.push_back(".word    " + std::to_string(hi));
        }
    }
}

void RISCV_CODE::RISCV_GLOBAL_ARRAY(IRCode &ins)
{
    auto name = ins.rst;
    std::string ro_str = (ins.arg2 == "const") ? ".section .srodata, \"a\"" : (ins.arg2 == "uninited") ? ".bss" : (ins.cls == CLASS_DOUBLE || ins.cls == CLASS_FLOAT) ? ".section .sdata, \"aw\"" : ".data";
    std::string align_str = ".align   3";
    int length = std::stoi(ins.arg1);
    int size = (ins.cls == CLASS_DOUBLE) ? 8 * length : 4 * length;

    riscv_codes.push_back("");
    riscv_codes.push_back(".globl   " + name);
    riscv_codes.push_back(ro_str);
    riscv_codes.push_back(align_str);
    riscv_codes.push_back(".type    " + name + ", @object");
    riscv_codes.push_back(".size    " + name + ", " + std::to_string(size));
    riscv_codes.push_back(name + ":");

    if (ins.arg2 == "uninited") {
        riscv_codes.push_back(".zero    " + std::to_string(size));
    }
}

void RISCV_CODE::RISCV_GLOBAL_ARRAY_ASSIGN(IRCode &ins)
{
    auto cls = ins.cls;
    if (ins.cls == CLASS_INT || ins.cls == CLASS_BOOLEAN) {
        riscv_codes.push_back(".word    " + ins.arg1);
    }
    else if (ins.cls == CLASS_FLOAT) {
        float fvalue = std::stof(ins.arg1);
        int decimal_fval = *(int *)&fvalue;
        riscv_codes.push_back(".word    " + std::to_string(decimal_fval));
    }
    else if (ins.cls == CLASS_DOUBLE) {
        double dvalue = std::stod(ins.arg1);
        long long decimal_dval = *(long long *)&dvalue;
        int hi = decimal_dval >> 32;
        int lo = decimal_dval & 0x00000000ffffffff;
        riscv_codes.push_back(".word    " + std::to_string(lo));
        riscv_codes.push_back(".word    " + std::to_string(hi));
    }
}