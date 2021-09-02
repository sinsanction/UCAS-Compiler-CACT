#ifndef RISCV_H
#define RISCV_H
#include "symbolTable.h"
#include "IR.h"

class RISCV_CODE {
public:
	std::vector<std::string> riscv_codes;

    int end_func_label = 0;
	int float_tmp_count = 0;

public:
	void RISCV_Gen(SymbolTable &sym_table, IR &ir, std::string out_file);

	void RISCV_FuncBegin(SymbolTable &sym_table, IRCode & );
	void RISCV_FuncEnd(SymbolTable &sym_table, IRCode & );
	void RISCV_Call(IRCode & );
	void RISCV_Return(IRCode & );
	void RISCV_Label(IRCode & );
	void RISCV_Goto(IRCode & );
	void RISCV_Beqz(IRCode & );

	void RISCV_Arithmetic(IRCode & );
	void RISCV_Load(IRCode & );
	void RISCV_Store(IRCode & );
	void RISCV_Move(IRCode & );
	void RISCV_Li(IRCode & );

	void RISCV_READARRAY(IRCode & );
	void RISCV_SAVEARRAY(IRCode & );
	void RISCV_GLOBAL(IRCode & );
	void RISCV_GLOBAL_ARRAY(IRCode & );
	void RISCV_GLOBAL_ARRAY_ASSIGN(IRCode & );
};

#endif
