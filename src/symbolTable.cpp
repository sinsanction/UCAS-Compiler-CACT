#include "symbolTable.h"

#define SYM_CLS(x) ((x.cls == CLASS_INT     ? "int"    : \
					 x.cls == CLASS_BOOLEAN ? "bool"   : \
					 x.cls == CLASS_FLOAT   ? "float"  : \
					 x.cls == CLASS_DOUBLE  ? "double" : \
					  						  "void"))

#define SYM_TYP(x) ((x.type == TYPE_CONST       ? "const"       : \
					 x.type == TYPE_VAR         ? "var"         : \
					 x.type == TYPE_CONST_ARRAY ? "const_array" : \
					 x.type == TYPE_ARRAY       ? "array"       : \
					  							  "para"))

VarInfo *SymbolTable::lookup(const std::string &name)
{
	int depth = block_stack.size();
	while (depth > 1) {
		BlockTable *block = block_stack[depth - 1];
		if (block->local_symbols.count(name) == 1)
			return &block->local_symbols[name];
		depth--;
	}

	if (global_symbols.count(name) == 1)
		return &global_symbols[name];
	else
		return nullptr;
}

FuncInfo *SymbolTable::lookup_func(const std::string &func_name)
{
	if (func_symbols.count(func_name) == 1)
		return &func_symbols[func_name];
	else
		return nullptr;
}

VarInfo *SymbolTable::lookup_param(FuncInfo &func, int para_idx)
{
	for (auto i = func.base_block.local_symbols.begin(); i != func.base_block.local_symbols.end(); i++) {
		if (i->second.length == para_idx && i->second.type == TYPE_PARAM) {
			return &(i->second);
		}
	}
	return nullptr;
}

void SymbolTable::addSymbol(std::string name, int cls, int type, int length, int line)
{
	VarInfo *var = new VarInfo;
	var->name = name;
	var->cls = cls;
	var->type = type;
	var->length = length;
	var->line = line;

	if (type == TYPE_CONST || type == TYPE_VAR || type == TYPE_PARAM) {
		stack_frame += (cls == CLASS_DOUBLE) ? 8 : 4;
		var->offset = stack_frame;
	}
	else if (type == TYPE_ARRAY || type == TYPE_CONST_ARRAY) {
		stack_frame += ((cls == CLASS_DOUBLE) ? 8 : 4) * length;
		var->offset = stack_frame;
	}

	int depth = block_stack.size();
	if (cur_func == "$") {
		if (global_symbols.count(name) == 0) {
			var->global = 1;
			global_symbols.insert(std::pair<std::string, VarInfo>(name, *var));
		}
		else
			throw std::runtime_error("line " + std::to_string(line) + ": error: redeclaration of '" + name + "'\n");
	}
	else {
		BlockTable *top = block_stack[depth - 1];
		if (top->local_symbols.count(name) != 0)
			throw std::runtime_error("line " + std::to_string(line) + ": error: redeclaration of '" + name + "'\n");

		// 不能和函数参数名相同
		BlockTable *param_block = &func_symbols[cur_func].base_block;
		if (block_stack[depth - 2] == param_block && param_block->local_symbols.count(name) != 0)
			throw std::runtime_error("line " + std::to_string(line) + ": error: '" + name + "' redeclared as different kind of symbol\n");
		top->local_symbols.insert(std::pair<std::string, VarInfo>(name, *var));
	}
}

void SymbolTable::addFunc(std::string name, int return_class, int param_num, int line)
{
	FuncInfo *func = new FuncInfo;
	func->name = name;
	func->cls = return_class;
	func->param_num = param_num;
	func->line = line;

	func->base_block.line = line;
	if (func_symbols.count(name) == 0)
		func_symbols.insert(std::pair<std::string, FuncInfo>(name, *func));
	else
		throw std::runtime_error("line " + std::to_string(line) + ": error: redefinition of '" + name + "'\n");

	// 修改目前函数和block栈
	cur_func = name;
	block_stack.push_back(&func_symbols[name].base_block);
}

void SymbolTable::addBlock(int line)
{
	BlockTable *block = new BlockTable;
	block->line = line;

	int depth = block_stack.size();
	BlockTable *top = block_stack[depth - 1];
	top->sub_blocks.insert(std::pair<int, BlockTable *>(line, block));
	block_stack.push_back(block);
}

// 产生临时变量
std::string SymbolTable::gen_Temp_Var(int lc, int cls, SymbolTable& st, int type) {
    assert(cls == CLASS_INT || cls == CLASS_BOOLEAN || cls == CLASS_FLOAT || cls == CLASS_DOUBLE);
    std::string name = "#" + std::to_string(++temp_var_count);
    if(type == TYPE_CONST_ARRAY || type == TYPE_CONST){
        st.addSymbol(name, cls, TYPE_CONST, 0, lc);
	}
    else if(type == TYPE_ARRAY || type == TYPE_VAR){
        st.addSymbol(name, cls, TYPE_VAR, 0, lc);
    }
	return name;
}

// 产生临时数组
std::string SymbolTable::gen_Temp_Array(int lc, int cls, int size, SymbolTable& st) {
    assert(cls == CLASS_INT || cls == CLASS_BOOLEAN || cls == CLASS_FLOAT || cls == CLASS_DOUBLE);
    std::string name = "#" + std::to_string(++temp_var_count);
    st.addSymbol(name, cls, TYPE_ARRAY, size, lc);
	return name;
}

std::string SymbolTable::get_fp_offset(VarInfo *info)
{
	if (!info->global) {
		int offset_to_sp = info->offset + 16; // ra:8 + sp:8
		std::string res = "-" + std::to_string(offset_to_sp) + "(s0)";
		return res;
	}
	else {
		return (info->name) + ".g";
	}
}

void printTable(std::ofstream &o, std::map<std::string, VarInfo> &sym_table)
{
	o << std::setw(14) << "name" << '|' 
	  << std::setw(7) << "class" << '|' 
	  << std::setw(12) << "type" << '|' 
	  << std::setw(10) << "val" << '|' 
	  << std::setw(5) << "line" << '|' << std::endl;
	for (auto i = sym_table.begin(); i != sym_table.end(); i++){
		o << std::setw(14) << i->first << '|' 
		  << std::setw(7) << SYM_CLS(i->second) << '|' 
		  << std::setw(12) << SYM_TYP(i->second) << '|' 
	      << std::dec << std::setw(10) << i->second.length << '|' 
		  << std::dec << std::setw(5) << i->second.line << '|'<< std::endl;
	}
	o << std::endl;
}

void printBlock(std::ofstream &o, BlockTable *block)
{
	o << "Block " << block->line << " has " << block->sub_blocks.size() << " children:\n";
	for (auto i = block->sub_blocks.begin(); i != block->sub_blocks.end(); i++)
		o << "\t" << i->first;
	o << std::endl;

	o << "Block " << block->line << " local symbols:\n";
	printTable(o, block->local_symbols);
	for (auto i = block->sub_blocks.begin(); i != block->sub_blocks.end(); i++)
		printBlock(o, i->second);

	o << "Block " << block->line << " ends.\n";
	o << std::endl;
}

void printFunc(std::ofstream &o, FuncInfo &func)
{
	o << func.name << " returns " << SYM_CLS(func) << ':' << std::endl;
	printBlock(o, &func.base_block);
	o << func.name << " ends.\n";
	o << std::endl;
}

void SymbolTable::printSymbol(std::ofstream &o)
{
	o << std::right;
	o << "global:" << std::endl;
	printTable(o, global_symbols);

	for (auto i = func_symbols.begin(); i != func_symbols.end(); i++){
		if (i->first != "main")
		if (i->first != "print_int")
		if (i->first != "print_float")
		if (i->first != "print_double")
		if (i->first != "print_bool")
		if (i->first != "get_int")
		if (i->first != "get_float")
		if (i->first != "get_double"){
			printFunc(o, i->second);
		}
	}
	printFunc(o, func_symbols["main"]);
}

int getIntStringBase(std::string literal) {
    int base = 10;
    if (literal.substr(0, 1) == "0") {
        if (literal.substr(0, 2) == "0x" || literal.substr(0, 2) == "0X")
            base = 16;
        else
            base = 8;
    }
	else if (literal.substr(0, 1) == "-") {
        if (literal.substr(1, 2) == "0x" || literal.substr(1, 2) == "0X")
            base = 16;
        else if (literal.substr(1, 1) == "0")
            base = 8;
    }
	
    return base;
}
