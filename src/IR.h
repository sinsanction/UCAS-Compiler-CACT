#ifndef IR_H
#define IR_H

#include "symbolTable.h"

// 中间代码使用五元式：结果，操作，操作数1，操作数2，结果类型 (rst, op, arg1, arg2, cls)
//                         rst          op                 arg1                 arg2          cls
// func_begin              name       FUNC_BEGIN           void                 void          ret_class
// func_end                name       FUNC_END             void                 void          void
// call                    name       CALL                 void                 void          void
// ret                     void       RET                  void                 void          void
// label                   label      LABEL                void                 void          void
// goto                    label      GOTO                 void                 void          void
// beqz                    label      BEQZ                 reg_src              void          void

// not                     reg_dst    NOT                  reg_src              void          bool
// neg                     reg_dst    NEG                  reg_src              void          int
// other arithmetic        reg_dst                         reg_src1             reg_src2      src_class

// load                    reg_dst    LOAD                 offset               void          dst_class
// store                   reg_src    STORE                offset               void          src_class
// mov                     reg_dst    MOV                  reg_src              void          src_class
// li                      reg_dst    LI                   const_str            void          const_class

// a[i]=                   reg_src    SAVE_ARRAY           offset_(a)           reg_i         a_class
// =b[i]                   reg_dst    READ_ARRAY           offset_(b)           reg_i         b_class

// 注意 load store save_array read_array 中的 offset ，当目标为局部变量时，是相对于 fp 的 offset_to_fp ，当目标为全局变量时是 name.g 
// 生成它们的中间代码时，并不需要区分全局还是局部，在 get_fp_offset() 和生成汇编时会处理，只需要使用 get_fp_offset() 生成相应的 offset 即可 

// global_assign           name       GLOBAL_ASSIGN        value_str            type          var_class
// global_array            name       GLOBAL_ARRAY         length               type          array_class
// global_array_assign     name       GLOBAL_ARRAY_ASSIGN  value_str            index         array_class

// 第一个生成单个全局变量，第二个生成全局变量数组的头部，第三个对全局变量数组的某个元素赋值 

struct IRCode {
	std::string rst;
	std::string op;
	std::string arg1;
	std::string arg2;
	int cls;
};

// IR op
namespace OP {
	constexpr auto ADD = "add";
	constexpr auto SUB = "sub";
	constexpr auto MUL = "mul";
	constexpr auto DIV = "div";
	constexpr auto MOD = "mod";

	constexpr auto AND = "&&";
	constexpr auto OR = "||";
	constexpr auto NOT = "!";
	constexpr auto NEG = "-";

	constexpr auto EQU = "==";
	constexpr auto NEQ = "!=";
	constexpr auto GT = ">";
	constexpr auto GE = ">=";
	constexpr auto LT = "<";
	constexpr auto LE = "<=";

	constexpr auto LOAD = "load";
    constexpr auto STORE = "store";
	constexpr auto MOV = "mov";
	constexpr auto LI = "li";

	constexpr auto READ_ARRAY = "=[]";
	constexpr auto SAVE_ARRAY = "[]=";

	// 函数
	constexpr auto FUNC_BEGIN = "func_begin";
	constexpr auto FUNC_END = "func_end";
	constexpr auto CALL = "call";
	constexpr auto RET = "ret";

	// 跳转
	constexpr auto LABEL = "label";
	constexpr auto GOTO = "goto";
	constexpr auto BEQZ = "beqz";

	// 全局变量
	constexpr auto GLOBAL_ASSIGN = "global_assign";
	constexpr auto GLOBAL_ARRAY = "global_array";
	constexpr auto GLOBAL_ARRAY_ASSIGN = "global_array_assign";
}

class IR {
public:
    std::vector<IRCode> ir_codes;
    int label_cnt;

public:
    IR() {
        label_cnt = 0;
    }

	std::string gen_label();

	void addIMC(std::string rst, const std::string &op, std::string arg1, std::string arg2,int cls);
	void printIMC(std::ofstream &o);
};

#endif
