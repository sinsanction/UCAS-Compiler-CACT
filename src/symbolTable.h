#ifndef SYMTABLE_H
#define SYMTABLE_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>
#include <string>
#include <stack>
#include <array>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <iomanip>

enum
{
	CLASS_INT,
	CLASS_BOOLEAN,
	CLASS_FLOAT,
	CLASS_DOUBLE,
	CLASS_VOID
};
enum
{
	TYPE_CONST,
	TYPE_VAR,
	TYPE_CONST_ARRAY,
	TYPE_ARRAY,
	TYPE_PARAM
};

struct VarInfo
{
	int cls;	   	// CLASS
	int type;	   	// TYPE
	int length;	   	// 对于数组，表示长度；对于参数，表示第几个
	int line;      	// 行号
	int global = 0;	// 全局变量标志
	int offset = 0; // 相对fp寄存器的偏移值
	std::string name;
};

struct BlockTable
{
	int line;
	std::map<int, struct BlockTable *> sub_blocks;
	std::map<std::string, VarInfo> local_symbols;
};

struct FuncInfo
{
	int cls;		        // 返回值的CLASS
	int param_num;	        // 参数个数
	int line;	            // 行号
	int stack_size = 0;     // 函数需要栈的大小
	struct BlockTable base_block;	// 函数的block，其local_symbols是参数
	std::string name;
};

//　符号表
class SymbolTable
{
public:
	std::map<std::string, VarInfo> global_symbols;	// 全局变量表
	std::map<std::string, FuncInfo> func_symbols;   // 函数表
	std::vector<BlockTable *> block_stack;			// block的栈
	std::string cur_func;							// 目前函数
	int stack_frame;		// 目前相对于栈底的偏移值
	int temp_var_count;		// 临时变量的数量

public:
	SymbolTable()
	{
		temp_var_count = 0;
		stack_frame = 0;
		cur_func = "$";
		block_stack.push_back(nullptr);
	}

	VarInfo *lookup(const std::string &name); 				// 查找变量
	FuncInfo *lookup_func(const std::string &func_name);	// 查找函数
	VarInfo *lookup_param(FuncInfo &func, int para_idx);	// 查找函数参数
	
	void addSymbol(std::string name, int cls, int type, int length, int line);
	void addFunc(std::string name, int return_class, int param_num, int line);
	void addBlock(int line);

	std::string gen_Temp_Var(int lc, int cls, SymbolTable& st, int type = TYPE_VAR);
	std::string gen_Temp_Array(int lc, int cls, int size, SymbolTable& st);
	std::string get_fp_offset(VarInfo *info);

	void printSymbol(std::ofstream &o);
};

int getIntStringBase(std::string literal);

#endif
