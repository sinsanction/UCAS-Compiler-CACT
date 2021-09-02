#include "semanticAnalysis.h"
#include "symbolTable.h"

void SemanticAnalysis::enterCompUnit(CACTParser::CompUnitContext *ctx)
{
    sym_table.addFunc("print_int", CLASS_VOID, 1, 0);
    sym_table.addSymbol("_int_", CLASS_INT, TYPE_PARAM, 0, 0);
    sym_table.block_stack.pop_back();
    sym_table.cur_func = "$";

    sym_table.addFunc("print_float", CLASS_VOID, 1, 0);
    sym_table.addSymbol("_float_", CLASS_FLOAT, TYPE_PARAM, 0, 0);
    sym_table.block_stack.pop_back();
    sym_table.cur_func = "$";

    sym_table.addFunc("print_double", CLASS_VOID, 1, 0);
    sym_table.addSymbol("_double_", CLASS_DOUBLE, TYPE_PARAM, 0, 0);
    sym_table.block_stack.pop_back();
    sym_table.cur_func = "$";

    sym_table.addFunc("print_bool", CLASS_VOID, 1, 0);
    sym_table.addSymbol("_bool_", CLASS_BOOLEAN, TYPE_PARAM, 0, 0);
    sym_table.block_stack.pop_back();
    sym_table.cur_func = "$";

    sym_table.addFunc("get_int", CLASS_INT, 0, 0);
    sym_table.block_stack.pop_back();
    sym_table.cur_func = "$";

    sym_table.addFunc("get_float", CLASS_FLOAT, 0, 0);
    sym_table.block_stack.pop_back();
    sym_table.cur_func = "$";

    sym_table.addFunc("get_double", CLASS_DOUBLE, 0, 0);
    sym_table.block_stack.pop_back();
    sym_table.cur_func = "$";
}
void SemanticAnalysis::exitCompUnit(CACTParser::CompUnitContext *ctx)
{
    if (sym_table.lookup_func("main") == nullptr)
        throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: function 'main' not found\n");
}

/*--------------- const decl ---------------*/
void SemanticAnalysis::enterConstDecl(CACTParser::ConstDeclContext *ctx)
{
    std::string class_str = ctx->bType()->getText();
    u_stack.push(class_str); // push type info into stack for child to use
}
void SemanticAnalysis::exitConstDecl(CACTParser::ConstDeclContext *ctx)
{
    u_stack.pop(); // pop the type info
}

/*--------------- func decl ---------------*/
void SemanticAnalysis::enterFuncDef(CACTParser::FuncDefContext *ctx)
{
    std::string function_name = ctx->name->getText();
    std::string return_type_str = ctx->ret->getText();
    sym_table.stack_frame = 0;
    int return_type;

    if (return_type_str == "int") {
        return_type = CLASS_INT;
    }
    else if (return_type_str == "bool") {
        return_type = CLASS_BOOLEAN;
    }
    else if (return_type_str == "float") {
        return_type = CLASS_FLOAT;
    }
    else if (return_type_str == "double") {
        return_type = CLASS_DOUBLE;
    }
    else if (return_type_str == "void") {
        return_type = CLASS_VOID;
    }
    else {
        throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: unknown type name '" + return_type_str + "'\n");
    }

    // get the number of parameters & check main
    int param_num = ctx->funcFParam().size();
    if (function_name == "main") {
        if (param_num != 0) {
            throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: too many arguments for function 'main'\n");
        }
        if (return_type != CLASS_INT) {
            throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: function 'main' returns " + return_type_str + "\n");
        }
    }

    // add function to sym table
    sym_table.addFunc(function_name, return_type, param_num, ctx->getStart()->getLine());
    ir.addIMC(function_name, OP::FUNC_BEGIN, VOID, VOID, return_type);

    // add parameters to sym table
    int param_count= 0;
    for (auto &param : ctx->funcFParam()) {
        std::string param_type = param->bType()->getText();
        std::string param_name = param->Ident()->getText();
        int param_class;

        if (param_type == "int") {
            param_class = CLASS_INT;
        }
        else if (param_type == "double") {
            param_class = CLASS_DOUBLE;
        }
        else if (param_type == "float") {
            param_class = CLASS_FLOAT;
        }
        else if (param_type == "bool") {
            param_class = CLASS_BOOLEAN;
        }
        else {
            throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: unknown type name '" + param_type + "'\n");
        }

        sym_table.addSymbol(param_name, param_class, TYPE_PARAM, param_count, param->getStart()->getLine());
        VarInfo *info = sym_table.lookup(param_name);
        auto offset_str = sym_table.get_fp_offset(info);
        // put param (in reg) into stack
        ir.addIMC("t2", OP::MOV, "a" + std::to_string(param_count), VOID, param_class);
        ir.addIMC("t2", OP::STORE, offset_str, VOID, param_class);
        param_count++;
    }
}
void SemanticAnalysis::exitFuncDef(CACTParser::FuncDefContext *ctx)
{
    std::string func_name = ctx->name->getText();
    FuncInfo *funcInfo = sym_table.lookup_func(func_name);
    funcInfo->stack_size = sym_table.stack_frame;
    sym_table.cur_func = "$";
    sym_table.block_stack.pop_back();
    sym_table.stack_frame = 0;
    ir.addIMC(func_name, OP::FUNC_END, VOID, VOID, CLASS_VOID);
}

void SemanticAnalysis::enterConstDefVal(CACTParser::ConstDefValContext *ctx)
{
    std::string var_name = ctx->Ident()->getText();         // 常量名
    std::string class_str = u_stack.top();                  // 类型名
    std::string literal_val = ctx->constExp()->getText();   // 常量值
    int var_cls;
    std::string value_str;
    int int_val;
    bool bool_val;
    float float_val;
    double double_val;

    if (class_str == "int") {
        var_cls = CLASS_INT;
        if (ctx->constExp()->getStart()->getType() != CACTLexer::IntConst)
            throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: invalid initializer of '" + var_name + "'\n");
        int_val = std::stoi(literal_val, 0, getIntStringBase(literal_val));
        value_str = std::to_string(int_val);
    }
    else if (class_str == "bool") {
        var_cls = CLASS_BOOLEAN;
        if (ctx->constExp()->getStart()->getType() != CACTLexer::BoolConst)
            throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: invalid initializer of '" + var_name + "'\n");
        bool_val = (literal_val == "true") ? 1 : 0;
        value_str = std::to_string(bool_val);
    }
    else if (class_str == "float") {
        var_cls = CLASS_FLOAT;
        if (ctx->constExp()->getStart()->getType() != CACTLexer::FloatConst)
            throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: invalid initializer of '" + var_name + "'\n");
        float_val = std::stof(literal_val.substr(0, literal_val.length() - 1));
        value_str = std::to_string(float_val);
    }
    else if (class_str == "double") {
        var_cls = CLASS_DOUBLE;
        if (ctx->constExp()->getStart()->getType() != CACTLexer::DoubleConst)
            throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: invalid initializer of '" + var_name + "'\n");
        double_val = std::stod(literal_val);
        value_str = std::to_string(double_val);
    }
    else{
        throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: unknown type name '" + class_str + "'\n");
    }

    sym_table.addSymbol(var_name, var_cls, TYPE_CONST, 0, ctx->getStart()->getLine());
    VarInfo *var = sym_table.lookup(var_name);
    auto offset_str = sym_table.get_fp_offset(var);
    if (var->global) {
        ir.addIMC(var_name, OP::GLOBAL_ASSIGN, value_str, "const", var_cls);
    }
    else {
        ir.addIMC("t2", OP::LI, value_str, VOID, var_cls);
        ir.addIMC("t2", OP::STORE, offset_str, VOID, var_cls);
    }
}
void SemanticAnalysis::exitConstDefVal(CACTParser::ConstDefValContext *ctx) {}

void SemanticAnalysis::enterConstDefArray(CACTParser::ConstDefArrayContext *ctx)
{
    std::string var_name = ctx->Ident()->getText(); // 常量名
    int array_len = std::stoi(ctx->IntConst()->getText());
    if (array_len <= 0)
        throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: size of array '" + var_name + "' is negative\n");
    std::string class_str = u_stack.top();  // 类型名
    int var_cls;
    std::string value_str;
    int int_val;
    bool bool_val;
    float float_val;
    double double_val;

    if (class_str == "int")
        var_cls = CLASS_INT;
    else if (class_str == "bool")
        var_cls = CLASS_BOOLEAN;
    else if (class_str == "float")
        var_cls = CLASS_FLOAT;
    else if (class_str == "double")
        var_cls = CLASS_DOUBLE;
    else
        throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: unknown type name '" + class_str + "'\n");
    sym_table.addSymbol(var_name, var_cls, TYPE_CONST_ARRAY, array_len, ctx->getStart()->getLine());

    VarInfo *var = sym_table.lookup(var_name);
    int init_count = 0;
    if (var->global) {
        ir.addIMC(var_name, OP::GLOBAL_ARRAY, std::to_string(array_len), "const", var_cls);

        for (auto &elem : ctx->constExp()) {
            std::string literal_val = elem->getText();
            auto literal_type = elem->getStart()->getType();

            if (var_cls == CLASS_INT && literal_type != CACTLexer::IntConst || var_cls == CLASS_BOOLEAN && literal_type != CACTLexer::BoolConst || \
                var_cls == CLASS_FLOAT && literal_type != CACTLexer::FloatConst || var_cls == CLASS_DOUBLE && literal_type != CACTLexer::DoubleConst)
                throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: invalid initializer of '" + var_name + "'\n");
            
            if (var_cls == CLASS_INT) {
                int_val = std::stoi(literal_val, 0, getIntStringBase(literal_val));
                value_str = std::to_string(int_val);
            }
            else if (var_cls == CLASS_BOOLEAN) {
                bool_val = (literal_val == "true") ? 1 : 0;
                value_str = std::to_string(bool_val);
            }
            else if (var_cls == CLASS_FLOAT) {
                float_val = std::stof(literal_val.substr(0, literal_val.length() - 1));
                value_str = std::to_string(float_val);
            }
            else if (var_cls == CLASS_DOUBLE) {
                double_val = std::stod(literal_val);
                value_str = std::to_string(double_val);
            }
            
            ir.addIMC(var_name, OP::GLOBAL_ARRAY_ASSIGN, value_str, std::to_string(init_count), var_cls);
            init_count++;
        }

        if (init_count > array_len)
            throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: excess elements in array initializer\n");
        while (init_count < array_len) {
            ir.addIMC(var_name, OP::GLOBAL_ARRAY_ASSIGN, "0", std::to_string(init_count), var_cls);
            init_count++;
        }
    }
    else {
        auto offset_str = sym_table.get_fp_offset(var);
        for (auto &elem : ctx->constExp()) {
            std::string literal_val = elem->getText();
            auto literal_type = elem->getStart()->getType();

            if (var_cls == CLASS_INT && literal_type != CACTLexer::IntConst || var_cls == CLASS_BOOLEAN && literal_type != CACTLexer::BoolConst || \
                var_cls == CLASS_FLOAT && literal_type != CACTLexer::FloatConst || var_cls == CLASS_DOUBLE && literal_type != CACTLexer::DoubleConst)
                throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: invalid initializer of '" + var_name + "'\n");
            
            if (var_cls == CLASS_INT) {
                int_val = std::stoi(literal_val, 0, getIntStringBase(literal_val));
                value_str = std::to_string(int_val);
            }
            else if (var_cls == CLASS_BOOLEAN) {
                bool_val = (literal_val == "true") ? 1 : 0;
                value_str = std::to_string(bool_val);
            }
            else if (var_cls == CLASS_FLOAT) {
                float_val = std::stof(literal_val.substr(0, literal_val.length() - 1));
                value_str = std::to_string(float_val);
            }
            else if (var_cls == CLASS_DOUBLE) {
                double_val = std::stod(literal_val);
                value_str = std::to_string(double_val);
            }
            
            ir.addIMC("t2", OP::LI, value_str, VOID, var_cls);
            ir.addIMC("t3", OP::LI, std::to_string(init_count), VOID, CLASS_INT);
            ir.addIMC("t2", OP::SAVE_ARRAY, offset_str, "t3", var_cls);
            init_count++;
        }

        if (init_count > array_len)
            throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: excess elements in array initializer\n");
        while (init_count < array_len) {
            ir.addIMC("t2", OP::LI, "0", VOID, var_cls);
            ir.addIMC("t3", OP::LI, std::to_string(init_count), VOID, CLASS_INT);
            ir.addIMC("t2", OP::SAVE_ARRAY, offset_str, "t3", var_cls);
            init_count++;
        }
    }
}
void SemanticAnalysis::exitConstDefArray(CACTParser::ConstDefArrayContext *ctx) {}

/*--------------- var decl ---------------*/
void SemanticAnalysis::enterVarDecl(CACTParser::VarDeclContext *ctx)
{
    std::string class_str = ctx->bType()->getText();
    u_stack.push(class_str); // push type info into stack for child to use
}
void SemanticAnalysis::exitVarDecl(CACTParser::VarDeclContext *ctx)
{
    u_stack.pop(); // pop the type info
}

void SemanticAnalysis::enterDefVal(CACTParser::DefValContext *ctx)
{
    std::string var_name = ctx->Ident()->getText();         // 变量名
    std::string class_str = u_stack.top();                  // 类型名
    int var_cls;
    if (class_str == "int")
        var_cls = CLASS_INT;
    else if (class_str == "bool")
        var_cls = CLASS_BOOLEAN;
    else if (class_str == "float")
        var_cls = CLASS_FLOAT;
    else if (class_str == "double")
        var_cls = CLASS_DOUBLE;
    else
        throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: unknown type name '" + class_str + "'\n");
    sym_table.addSymbol(var_name, var_cls, TYPE_VAR, 0, ctx->getStart()->getLine());
}
void SemanticAnalysis::exitDefVal(CACTParser::DefValContext *ctx) {}

void SemanticAnalysis::enterDefArray(CACTParser::DefArrayContext *ctx)
{
    std::string var_name = ctx->Ident()->getText(); // 类型名
    int array_len = std::stoi(ctx->IntConst()->getText());
    if (array_len <= 0)
        throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: size of array '" + var_name + "' is negative\n");
    std::string class_str = u_stack.top();  // 类型名
    int var_cls;                            // 类型变量
    if (class_str == "int")
        var_cls = CLASS_INT;
    else if (class_str == "bool")
        var_cls = CLASS_BOOLEAN;
    else if (class_str == "float")
        var_cls = CLASS_FLOAT;
    else if (class_str == "double")
        var_cls = CLASS_DOUBLE;
    else
        throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: unknown type name '" + class_str + "'\n");
    sym_table.addSymbol(var_name, var_cls, TYPE_ARRAY, array_len, ctx->getStart()->getLine());

    VarInfo *array_info = sym_table.lookup(var_name);
    if (array_info->global) {
        ir.addIMC(var_name, OP::GLOBAL_ARRAY, std::to_string(array_len), "uninited", var_cls);
    }
}
void SemanticAnalysis::exitDefArray(CACTParser::DefArrayContext *ctx) {}

void SemanticAnalysis::enterDefInitVal(CACTParser::DefInitValContext *ctx)
{
    std::string var_name = ctx->Ident()->getText();         // 变量名
    std::string class_str = u_stack.top();                  // 类型名
    std::string literal_val = ctx->constExp()->getText();   // 初始值
    int var_cls;
    std::string value_str;
    int int_val;
    bool bool_val;
    float float_val;
    double double_val;
    
    if (class_str == "int") {
        var_cls = CLASS_INT;
        if (ctx->constExp()->getStart()->getType() != CACTLexer::IntConst)
            throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: invalid initializer of '" + var_name + "'\n");
        int_val = std::stoi(literal_val, 0, getIntStringBase(literal_val));
        value_str = std::to_string(int_val);
    }
    else if (class_str == "bool") {
        var_cls = CLASS_BOOLEAN;
        if (ctx->constExp()->getStart()->getType() != CACTLexer::BoolConst)
            throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: invalid initializer of '" + var_name + "'\n");
        bool_val = (literal_val == "true") ? 1 : 0;
        value_str = std::to_string(bool_val);
    }
    else if (class_str == "float") {
        var_cls = CLASS_FLOAT;
        if (ctx->constExp()->getStart()->getType() != CACTLexer::FloatConst)
            throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: invalid initializer of '" + var_name + "'\n");
        float_val = std::stof(literal_val.substr(0, literal_val.length() - 1));
        value_str = std::to_string(float_val);
    }
    else if (class_str == "double") {
        var_cls = CLASS_DOUBLE;
        if (ctx->constExp()->getStart()->getType() != CACTLexer::DoubleConst)
            throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: invalid initializer of '" + var_name + "'\n");
        double_val = std::stod(literal_val);
        value_str = std::to_string(double_val);
    }
    else{
        throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: unknown type name '" + class_str + "'\n");
    }

    sym_table.addSymbol(var_name, var_cls, TYPE_VAR, 0, ctx->getStart()->getLine());
    VarInfo *var = sym_table.lookup(var_name);
    auto offset_str = sym_table.get_fp_offset(var);
    if (var->global) {
        ir.addIMC(var_name, OP::GLOBAL_ASSIGN, value_str, "var", var_cls);
    }
    else {
        ir.addIMC("t2", OP::LI, value_str, VOID, var_cls);
        ir.addIMC("t2", OP::STORE, offset_str, VOID, var_cls);
    }
}
void SemanticAnalysis::exitDefInitVal(CACTParser::DefInitValContext *ctx) {}

void SemanticAnalysis::enterDefInitArray(CACTParser::DefInitArrayContext *ctx)
{
    std::string var_name = ctx->Ident()->getText(); // 类型名
    int array_len = std::stoi(ctx->IntConst()->getText());
    if (array_len <= 0)
        throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: size of array '" + var_name + "' is negative\n");
    std::string class_str = u_stack.top();  // 类型名
    int var_cls;
    std::string value_str;
    int int_val;
    bool bool_val;
    float float_val;
    double double_val;

    if (class_str == "int")
        var_cls = CLASS_INT;
    else if (class_str == "bool")
        var_cls = CLASS_BOOLEAN;
    else if (class_str == "float")
        var_cls = CLASS_FLOAT;
    else if (class_str == "double")
        var_cls = CLASS_DOUBLE;
    else
        throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: unknown type name '" + class_str + "'\n");
    sym_table.addSymbol(var_name, var_cls, TYPE_ARRAY, array_len, ctx->getStart()->getLine());

    VarInfo *var = sym_table.lookup(var_name);
    int init_count = 0;
    if (var->global) {
        ir.addIMC(var_name, OP::GLOBAL_ARRAY, std::to_string(array_len), "var", var_cls);

        for (auto &elem : ctx->constExp()) {
            std::string literal_val = elem->getText();
            auto literal_type = elem->getStart()->getType();

            if (var_cls == CLASS_INT && literal_type != CACTLexer::IntConst || var_cls == CLASS_BOOLEAN && literal_type != CACTLexer::BoolConst || \
                var_cls == CLASS_FLOAT && literal_type != CACTLexer::FloatConst || var_cls == CLASS_DOUBLE && literal_type != CACTLexer::DoubleConst)
                throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: invalid initializer of '" + var_name + "'\n");
            
            if (var_cls == CLASS_INT) {
                int_val = std::stoi(literal_val, 0, getIntStringBase(literal_val));
                value_str = std::to_string(int_val);
            }
            else if (var_cls == CLASS_BOOLEAN) {
                bool_val = (literal_val == "true") ? 1 : 0;
                value_str = std::to_string(bool_val);
            }
            else if (var_cls == CLASS_FLOAT) {
                float_val = std::stof(literal_val.substr(0, literal_val.length() - 1));
                value_str = std::to_string(float_val);
            }
            else if (var_cls == CLASS_DOUBLE) {
                double_val = std::stod(literal_val);
                value_str = std::to_string(double_val);
            }
            
            ir.addIMC(var_name, OP::GLOBAL_ARRAY_ASSIGN, value_str, std::to_string(init_count), var_cls);
            init_count++;
        }

        if (init_count > array_len)
            throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: excess elements in array initializer\n");
        while (init_count < array_len) {
            ir.addIMC(var_name, OP::GLOBAL_ARRAY_ASSIGN, "0", std::to_string(init_count), var_cls);
            init_count++;
        }
    }
    else {
        auto offset_str = sym_table.get_fp_offset(var);
        for (auto &elem : ctx->constExp()) {
            std::string literal_val = elem->getText();
            auto literal_type = elem->getStart()->getType();

            if (var_cls == CLASS_INT && literal_type != CACTLexer::IntConst || var_cls == CLASS_BOOLEAN && literal_type != CACTLexer::BoolConst || \
                var_cls == CLASS_FLOAT && literal_type != CACTLexer::FloatConst || var_cls == CLASS_DOUBLE && literal_type != CACTLexer::DoubleConst)
                throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: invalid initializer of '" + var_name + "'\n");
            
            if (var_cls == CLASS_INT) {
                int_val = std::stoi(literal_val, 0, getIntStringBase(literal_val));
                value_str = std::to_string(int_val);
            }
            else if (var_cls == CLASS_BOOLEAN) {
                bool_val = (literal_val == "true") ? 1 : 0;
                value_str = std::to_string(bool_val);
            }
            else if (var_cls == CLASS_FLOAT) {
                float_val = std::stof(literal_val.substr(0, literal_val.length() - 1));
                value_str = std::to_string(float_val);
            }
            else if (var_cls == CLASS_DOUBLE) {
                double_val = std::stod(literal_val);
                value_str = std::to_string(double_val);
            }
            
            ir.addIMC("t2", OP::LI, value_str, VOID, var_cls);
            ir.addIMC("t3", OP::LI, std::to_string(init_count), VOID, CLASS_INT);
            ir.addIMC("t2", OP::SAVE_ARRAY, offset_str, "t3", var_cls);
            init_count++;
        }

        if (init_count > array_len)
            throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: excess elements in array initializer\n");
        while (init_count < array_len) {
            ir.addIMC("t2", OP::LI, "0", VOID, var_cls);
            ir.addIMC("t3", OP::LI, std::to_string(init_count), VOID, CLASS_INT);
            ir.addIMC("t2", OP::SAVE_ARRAY, offset_str, "t3", var_cls);
            init_count++;
        }
    }
}
void SemanticAnalysis::exitDefInitArray(CACTParser::DefInitArrayContext *ctx) {}

/*--------------- block ---------------*/
void SemanticAnalysis::enterBlock(CACTParser::BlockContext *ctx)
{
    sym_table.addBlock(ctx->getStart()->getLine());
}
void SemanticAnalysis::exitBlock(CACTParser::BlockContext *ctx)
{
    sym_table.block_stack.pop_back();
}

/*--------------- function ---------------*/
// Ident '(' (funcRParams)? ')'
void SemanticAnalysis::enterFuncall(CACTParser::FuncallContext *ctx)
{
    auto func_name = ctx->Ident()->getText();
    auto func_info = sym_table.lookup_func(func_name);

    int param_num = 0;
    if (ctx->funcRParams())
        param_num = ctx->funcRParams()->exp().size();
    
    if (!func_info){
        throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: undefined function '" + func_name +"'\n");
    }
    if (param_num < func_info->param_num){
        throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: too few arguments to function '" + func_name +"'\n");
    }
    if (param_num > func_info->param_num){
        throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: too many arguments to function '" + func_name +"'\n");
    }
}
void SemanticAnalysis::exitFuncall(CACTParser::FuncallContext *ctx)
{
    auto func_name = ctx->Ident()->getText();
    auto func_info = sym_table.lookup_func(func_name);
    int para_count = 0;
    if (ctx->funcRParams()) {
        for (auto &param : ctx->funcRParams()->exp()) {
            auto *para_info = sym_table.lookup_param(*func_info, para_count);
            if (para_info->cls != param->cls)
                throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: incompatible type for argument " + std::to_string(para_count) + " of '" + func_name +"'\n");

            VarInfo *temp_info = sym_table.lookup(param->name);
            auto offset_str = sym_table.get_fp_offset(temp_info);
            ir.addIMC("a" + std::to_string(para_count), OP::LOAD, offset_str, VOID, temp_info->cls);
            para_count++;
        }
    }

    ir.addIMC(func_name, OP::CALL, VOID, VOID, CLASS_VOID);

    if (func_info->cls == CLASS_VOID) {
        ctx->cls = CLASS_VOID;
    }
    else {
        auto ret_var = sym_table.gen_Temp_Var(ctx->getStart()->getLine(), func_info->cls, sym_table);
        VarInfo *ret_info = sym_table.lookup(ret_var);
        auto offset_str = sym_table.get_fp_offset(ret_info);
        ctx->cls = func_info->cls;
        ctx->name = ret_var;
        ir.addIMC("a0", OP::STORE, offset_str, VOID, func_info->cls);
    }
}

void SemanticAnalysis::enterReturnStmt(CACTParser::ReturnStmtContext *ctx) {}
void SemanticAnalysis::exitReturnStmt(CACTParser::ReturnStmtContext *ctx)
{
    if (ctx->exp() != nullptr){
        std::string return_name = ctx->exp()->name;
        VarInfo *return_info = sym_table.lookup(return_name);
        FuncInfo *func = sym_table.lookup_func(sym_table.cur_func);
        int cls = ctx->exp()->cls;
        if (cls != func->cls){
            throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: incompatible type when returning\n");
        }

        auto offset_str = sym_table.get_fp_offset(return_info);
        ir.addIMC("a0", OP::LOAD, offset_str, VOID, cls);
        ir.addIMC(VOID, OP::RET, VOID, VOID, CLASS_VOID);
    }
    else{
        FuncInfo *func = sym_table.lookup_func(sym_table.cur_func);
        if (func->cls != CLASS_VOID)
            throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: incompatible type when returning\n");
        ir.addIMC(VOID, OP::RET, VOID, VOID, CLASS_VOID);
    }
}

/*--------------- condition ---------------*/
void SemanticAnalysis::enterCond(CACTParser::CondContext *ctx) {}
void SemanticAnalysis::exitCond(CACTParser::CondContext *ctx)
{
    ctx->cls = ctx->lOrExp()->cls;
    ctx->name = ctx->lOrExp()->name;
    if (ctx->cls != CLASS_BOOLEAN){
        throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: incompatible type in condition\n");
    }
}

void SemanticAnalysis::enterIfCond(CACTParser::IfCondContext *ctx) {}
void SemanticAnalysis::exitIfCond(CACTParser::IfCondContext *ctx)
{
    ctx->cls = ctx->cond()->cls;
    ctx->name = ctx->cond()->name;
    VarInfo *info = sym_table.lookup(ctx->name);
    auto labels = if_labels.get(ctx->parent);

    auto offset_str = sym_table.get_fp_offset(info);
    ir.addIMC("t2", OP::LOAD, offset_str, VOID, CLASS_BOOLEAN);
    ir.addIMC(labels[0], OP::BEQZ, "t2", VOID, CLASS_VOID);
}

void SemanticAnalysis::enterWhileCond(CACTParser::WhileCondContext *ctx) {}
void SemanticAnalysis::exitWhileCond(CACTParser::WhileCondContext *ctx)
{
    ctx->cls = ctx->cond()->cls;
    ctx->name = ctx->cond()->name;
    VarInfo *info = sym_table.lookup(ctx->name);
    auto labels = while_labels.get(ctx->parent);

    auto offset_str = sym_table.get_fp_offset(info);
    ir.addIMC("t2", OP::LOAD, offset_str, VOID, CLASS_BOOLEAN);
    ir.addIMC(labels[1], OP::BEQZ, "t2", VOID, CLASS_VOID);
}

void SemanticAnalysis::enterIfStmt(CACTParser::IfStmtContext *ctx)
{
    auto label1 = ir.gen_label();
    std::vector<std::string> label_set = {label1};
    if_labels.put(ctx, label_set);
}
void SemanticAnalysis::exitIfStmt(CACTParser::IfStmtContext *ctx)
{
    auto labels = if_labels.get(ctx);
    ir.addIMC(labels[0], OP::LABEL, VOID, VOID, CLASS_VOID);
}

void SemanticAnalysis::enterIfElseStmt(CACTParser::IfElseStmtContext *ctx)
{
    auto label1 = ir.gen_label();
    auto label2 = ir.gen_label();
    std::vector<std::string> label_set = {label1, label2};
    if_labels.put(ctx, label_set);
}
void SemanticAnalysis::exitIfElseStmt(CACTParser::IfElseStmtContext *ctx)
{
    auto labels = if_labels.get(ctx);
    ir.addIMC(labels[1], OP::LABEL, VOID, VOID, CLASS_VOID);
}

void SemanticAnalysis::enterElseStmt(CACTParser::ElseStmtContext *ctx)
{
    auto labels = if_labels.get(ctx->parent);
    ir.addIMC(labels[1], OP::GOTO, VOID, VOID, CLASS_VOID);
    ir.addIMC(labels[0], OP::LABEL, VOID, VOID, CLASS_VOID);
}
void SemanticAnalysis::exitElseStmt(CACTParser::ElseStmtContext *ctx) {}

void SemanticAnalysis::enterWhileStmt(CACTParser::WhileStmtContext *ctx)
{
    auto label_begin = ir.gen_label();
    auto label_end = ir.gen_label();
    std::vector<std::string> label_set = {label_begin, label_end};
    while_labels.put(ctx, label_set);
    label_stack.push_back(label_begin);
    label_stack.push_back(label_end);
    ir.addIMC(label_begin, OP::LABEL, VOID, VOID, CLASS_VOID);
}
void SemanticAnalysis::exitWhileStmt(CACTParser::WhileStmtContext *ctx)
{
    auto labels = while_labels.get(ctx);
    ir.addIMC(labels[0], OP::GOTO, VOID, VOID, CLASS_VOID);
    ir.addIMC(labels[1], OP::LABEL, VOID, VOID, CLASS_VOID);
    label_stack.pop_back();
    label_stack.pop_back();
}

void SemanticAnalysis::enterBreakStmt(CACTParser::BreakStmtContext *ctx) {}
void SemanticAnalysis::exitBreakStmt(CACTParser::BreakStmtContext *ctx)
{
    auto index = label_stack.size();
    auto label = label_stack[index - 1];
    ir.addIMC(label, OP::GOTO, VOID, VOID, CLASS_VOID);
}

void SemanticAnalysis::enterContinueStmt(CACTParser::ContinueStmtContext *ctx) {}
void SemanticAnalysis::exitContinueStmt(CACTParser::ContinueStmtContext *ctx)
{
    auto index = label_stack.size();
    auto label = label_stack[index - 2];
    ir.addIMC(label, OP::GOTO, VOID, VOID, CLASS_VOID);
}

/*--------------- expression ---------------*/
//  lVal '=' exp ';'
void SemanticAnalysis::enterAssignStmt(CACTParser::AssignStmtContext *ctx) {}
void SemanticAnalysis::exitAssignStmt(CACTParser::AssignStmtContext *ctx)
{
    bool elemwise = false;
    bool isArray = false;
    std::string lval_name = ctx->lVal()->name;
    std::string index_name;
    // lVal is: array[index]
    if (ctx->lVal()->exp() != nullptr) {
        index_name = ctx->lVal()->exp()->name;
        auto *index_var_info = sym_table.lookup(index_name);
        if (index_var_info->cls != CLASS_INT)
            throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: array subscript is not an integer\n");
        isArray = true;
    }

    // check lhs
    auto *lhs_var_info = sym_table.lookup(lval_name);
    if (lhs_var_info == nullptr){
        throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: '" + lval_name + "' undeclared (first use in this function)\n");
    }

    // check rhs
    std::string rval_name = ctx->exp()->name;
    auto *rval_var_info = sym_table.lookup(rval_name);
    if (rval_var_info == nullptr){
        throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: '" + lval_name + "' undeclared (first use in this function)\n");
    }

    // 类型检查
    if (rval_var_info->cls != lhs_var_info->cls)
        throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: incompatible types when assigning\n");
    
    if (lhs_var_info->type == TYPE_ARRAY &&
        (rval_var_info->type == TYPE_ARRAY || rval_var_info->type == TYPE_CONST_ARRAY)){
        elemwise = true;
    }
    int var_cls = lhs_var_info->cls;
    int var_type = lhs_var_info->type;

    if (lhs_var_info->type == TYPE_CONST || lhs_var_info->type == TYPE_CONST_ARRAY){
        throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: assignment of read-only variable\n");
    }
    if (ctx->exp()->cls == CLASS_VOID)
        throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: void value not ignored as it ought to be\n");
    
    // 代码生成
    auto lhs_offset_str = sym_table.get_fp_offset(lhs_var_info);
    auto rhs_offset_str = sym_table.get_fp_offset(rval_var_info);
    if (!isArray && !elemwise) { // a = b
        ir.addIMC("t2", OP::LOAD, rhs_offset_str, VOID, var_cls);
        ir.addIMC("t2", OP::STORE, lhs_offset_str, VOID, var_cls);
    }
    else if (elemwise){ // A = B (a[i] = b[i] for all i)
        if (lhs_var_info->length != rval_var_info->length)
            throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: incompatible length when assigning\n");
        for (int i = 0; i < lhs_var_info->length; i++) {
            ir.addIMC("t3", OP::LI, std::to_string(i), VOID, CLASS_INT);
            ir.addIMC("t2", OP::READ_ARRAY, rhs_offset_str, "t3", var_cls);
            ir.addIMC("t2", OP::SAVE_ARRAY, lhs_offset_str , "t3", var_cls);
        }
    }
    else { // a[i] = b
        // 这里不能使用 lhs_offset_str，因为a[i]本质是一个临时变量，这里需要写到实际的数组里
        auto array_name = ctx->lVal()->Ident()->getText();
        auto array_info = sym_table.lookup(array_name);
        auto index_var = sym_table.lookup(index_name);

        auto array_offset_str = sym_table.get_fp_offset(array_info);
        auto index_offset_str = sym_table.get_fp_offset(index_var);
        ir.addIMC("t2", OP::LOAD, rhs_offset_str, VOID, CLASS_INT);
        ir.addIMC("t4", OP::LOAD, index_offset_str, VOID, CLASS_INT);
        ir.addIMC("t2", OP::SAVE_ARRAY, array_offset_str, "t4", var_cls);
    }
}

void SemanticAnalysis::enterExp(CACTParser::ExpContext *ctx) {}
void SemanticAnalysis::exitExp(CACTParser::ExpContext *ctx)
{
    // addExp
    if (ctx->addExp()) {
        ctx->cls = ctx->addExp()->cls;
        ctx->name = ctx->addExp()->name;
    }
    // BoolConst
    if (ctx->BoolConst()) {
        ctx->cls = CLASS_BOOLEAN;
    }
}

void SemanticAnalysis::enterLVal(CACTParser::LValContext *ctx) {}
void SemanticAnalysis::exitLVal(CACTParser::LValContext *ctx)
{
    // Ident
    if (ctx->exp() == nullptr) {
        std::string var_name = ctx->Ident()->getText();
        VarInfo *var_info = sym_table.lookup(var_name);
        if (!var_info)
            throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: '" + var_name + "' undeclared (first use in this function)\n");
        ctx->cls = var_info->cls;
        ctx->name = ctx->Ident()->getText();
    }
    // Ident[exp]
    else {
        std::string array_name = ctx->Ident()->getText();
        VarInfo *array_info = sym_table.lookup(array_name);
        if (!array_info)
            throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: '" + array_name + "' undeclared (first use in this function)\n");
        if (!(array_info->type == TYPE_ARRAY || array_info->type == TYPE_CONST_ARRAY))
            throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: subscripted value is not array");
        
        ctx->cls = array_info->cls;
        auto exp_name = ctx->exp()->name;
        VarInfo *exp_info = sym_table.lookup(exp_name);
        if (exp_info->cls != CLASS_INT)
            throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: array subscript is not an integer\n");
        std::string arrayelem = sym_table.gen_Temp_Var(ctx->getStart()->getLine(), ctx->cls, sym_table, array_info->type);
        ctx->name = arrayelem;
        VarInfo *tmp_info = sym_table.lookup(arrayelem);
        auto array_offset_str = sym_table.get_fp_offset(array_info);
        auto index_offset_str = sym_table.get_fp_offset(exp_info);
        auto tmp_offset_str = sym_table.get_fp_offset(tmp_info);
        ir.addIMC("t1", OP::LOAD, index_offset_str, VOID, CLASS_INT);
        ir.addIMC("t2", OP::READ_ARRAY, array_offset_str, "t1", array_info->cls);
        ir.addIMC("t2", OP::STORE, tmp_offset_str, VOID, array_info->cls);
    }
}

void SemanticAnalysis::enterPrimary(CACTParser::PrimaryContext *ctx) {}
void SemanticAnalysis::exitPrimary(CACTParser::PrimaryContext *ctx)
{
    // ( exp )
    if (ctx->primaryExp()->exp() != nullptr) {
        ctx->cls = ctx->primaryExp()->exp()->cls;
        ctx->name = ctx->primaryExp()->exp()->name;
    }
    // lVal
    else if (ctx->primaryExp()->lVal() != nullptr) {
        ctx->cls = ctx->primaryExp()->lVal()->cls;
        ctx->name = ctx->primaryExp()->lVal()->name;
    }
    // bool
    else if (ctx->getText() == "true" || ctx->getText() == "false") {
        std::string temp = sym_table.gen_Temp_Var(ctx->getStart()->getLine(), CLASS_BOOLEAN, sym_table);
        ctx->cls = CLASS_BOOLEAN;
        ctx->name = temp;
        VarInfo *tmp_info = sym_table.lookup(temp);
        auto tmp_offset_str = sym_table.get_fp_offset(tmp_info);
        int value = (ctx->getText() == "true") ? 1 : 0;
        ir.addIMC("t2", OP::LI, std::to_string(value), VOID, CLASS_BOOLEAN);
        ir.addIMC("t2", OP::STORE, tmp_offset_str, VOID, CLASS_BOOLEAN);
    }
    // number
    else {
        int num_cls = ctx->primaryExp()->getStart()->getType();
        std::string literal_val = ctx->getText();
        std::string value_str;
        int int_val;
        float float_val;
        double double_val;

        if (num_cls == CACTLexer::IntConst) {
            ctx->cls = CLASS_INT;
            ctx->name = sym_table.gen_Temp_Var(ctx->getStart()->getLine(), CLASS_INT, sym_table);
            int_val = std::stoi(literal_val, 0, getIntStringBase(literal_val));
            value_str = std::to_string(int_val);
        }
        else if (num_cls == CACTLexer::FloatConst) {
            ctx->cls = CLASS_FLOAT;
            ctx->name = sym_table.gen_Temp_Var(ctx->getStart()->getLine(), CLASS_FLOAT, sym_table);
            float_val = std::stof(literal_val.substr(0, literal_val.length() - 1));
            value_str = std::to_string(float_val);
        }
        else if (num_cls == CACTLexer::DoubleConst) {
            ctx->cls = CLASS_DOUBLE;
            ctx->name = sym_table.gen_Temp_Var(ctx->getStart()->getLine(), CLASS_DOUBLE, sym_table);
            double_val = std::stod(literal_val);
            value_str = std::to_string(double_val);
        }

        VarInfo *tmp_info = sym_table.lookup(ctx->name);
        auto tmp_offset_str = sym_table.get_fp_offset(tmp_info);
        ir.addIMC("t2", OP::LI, value_str, VOID, ctx->cls);
        ir.addIMC("t2", OP::STORE, tmp_offset_str, VOID, ctx->cls);
    }
}

void SemanticAnalysis::enterUnary(CACTParser::UnaryContext *ctx) {}
void SemanticAnalysis::exitUnary(CACTParser::UnaryContext *ctx)
{
    if (ctx->op->getType() == CACTLexer::NOT) {
        if (ctx->unaryExp()->cls != CLASS_BOOLEAN)
            throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: wrong type argument to unary exclamation mark\n");
        ctx->cls = CLASS_BOOLEAN;
        ctx->name = sym_table.gen_Temp_Var(ctx->getStart()->getLine(), CLASS_BOOLEAN, sym_table);
        VarInfo *tmp_info = sym_table.lookup(ctx->name);
        std::string child_name = ctx->unaryExp()->name;
        VarInfo *child_info = sym_table.lookup(child_name);
        auto tmp_offset_str = sym_table.get_fp_offset(tmp_info);
        auto child_offset_str = sym_table.get_fp_offset(child_info);
        ir.addIMC("t2", OP::LOAD, child_offset_str, VOID, CLASS_BOOLEAN);
        ir.addIMC("t2", OP::NOT, "t2", VOID, CLASS_BOOLEAN);
        ir.addIMC("t2", OP::STORE, tmp_offset_str, VOID, CLASS_BOOLEAN);
    }
    else if (ctx->op->getType() == CACTLexer::ADD) {
        if (ctx->cls == CLASS_BOOLEAN)
            throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: wrong type argument to unary '+' mark\n");
        ctx->cls = ctx->unaryExp()->cls;
        ctx->name = ctx->unaryExp()->name;
    }
    else if (ctx->op->getType() == CACTLexer::SUB) {
        if (ctx->cls == CLASS_BOOLEAN)
            throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: wrong type argument to unary '-' mark\n");
        ctx->cls = ctx->unaryExp()->cls;
        ctx->name = sym_table.gen_Temp_Var(ctx->getStart()->getLine(), ctx->cls, sym_table);
        VarInfo *tmp_info = sym_table.lookup(ctx->name);
        std::string child_name = ctx->unaryExp()->name;
        VarInfo *child_info = sym_table.lookup(child_name);
        auto tmp_offset_str = sym_table.get_fp_offset(tmp_info);
        auto child_offset_str = sym_table.get_fp_offset(child_info);
        ir.addIMC("t0", OP::LI, "0", VOID, ctx->cls);
        ir.addIMC("t1", OP::LOAD, child_offset_str, VOID, ctx->cls);
        ir.addIMC("t2", OP::SUB, "t0", "t1", ctx->cls);
        ir.addIMC("t2", OP::STORE, tmp_offset_str, VOID, ctx->cls);
    }
}

void SemanticAnalysis::enterMulExp(CACTParser::MulExpContext *ctx) {}
void SemanticAnalysis::exitMulExp(CACTParser::MulExpContext *ctx)
{
    // unaryexp
    if (!ctx->mulExp()) {
        ctx->cls = ctx->unaryExp()->cls;
        ctx->name = (ctx->cls == CLASS_VOID) ? "NULL" : ctx->unaryExp()->name;
    }
    // mulExp (MUL | DIV | MOD) unaryExp
    else {
        if (ctx->mulExp()->cls != ctx->unaryExp()->cls) //类型检查
            throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: wrong type to binary * or / or %\n");
        auto op1 = ctx->mulExp()->name;
        auto op2 = ctx->unaryExp()->name;
        VarInfo *op1_info = sym_table.lookup(op1);
        VarInfo *op2_info = sym_table.lookup(op2);

        // element wise op
        if ((op1_info->type == TYPE_ARRAY || op1_info->type == TYPE_CONST_ARRAY) &&
            (op2_info->type == TYPE_ARRAY || op2_info->type == TYPE_CONST_ARRAY)) { 
            if (op1_info->length != op2_info->length) {
                throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: wrong size to element wise operation\n");
            }
            auto res = sym_table.gen_Temp_Array(ctx->getStart()->getLine(), op1_info->cls, op1_info->length, sym_table);
            ctx->elemwise = true;
            ctx->cls = op1_info->cls;
            ctx->name = res;

            VarInfo *res_info = sym_table.lookup(res);
            auto op1_offset_str = sym_table.get_fp_offset(op1_info);
            auto op2_offset_str = sym_table.get_fp_offset(op2_info);
            auto res_offset_str = sym_table.get_fp_offset(res_info);
            for (int i = 0; i < op1_info->length; i++) {
                ir.addIMC("t4", OP::LI, std::to_string(i), VOID, CLASS_INT);
                ir.addIMC("t1", OP::READ_ARRAY, op1_offset_str, "t4", ctx->cls);
                ir.addIMC("t2", OP::READ_ARRAY, op2_offset_str, "t4", ctx->cls);
                if (ctx->op->getType() == CACTLexer::MUL)
                    ir.addIMC("t3", OP::MUL, "t1", "t2", ctx->cls);
                else if (ctx->op->getType() == CACTLexer::DIV)
                    ir.addIMC("t3", OP::DIV, "t1", "t2", ctx->cls);
                else if (ctx->op->getType() == CACTLexer::MOD)
                    ir.addIMC("t3", OP::MOD, "t1", "t2", ctx->cls);
                ir.addIMC("t3", OP::SAVE_ARRAY, res_offset_str, "t4", ctx->cls);
            }
        }
        // normal op
        else {
            if (op1_info->type == TYPE_ARRAY || op1_info->type == TYPE_CONST_ARRAY ||
                op2_info->type == TYPE_ARRAY || op2_info->type == TYPE_CONST_ARRAY) {
                throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: invalid operands to binary * or / or %\n");
            }
            else if (op1_info->cls == CLASS_BOOLEAN) {
                throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: invalid operands to binary * or / or %\n");
            }
            auto res = sym_table.gen_Temp_Var(ctx->getStart()->getLine(), op1_info->cls, sym_table);
            ctx->elemwise = false;
            ctx->cls = op1_info->cls;
            ctx->name = res;

            VarInfo *res_info = sym_table.lookup(res);
            auto op1_offset_str = sym_table.get_fp_offset(op1_info);
            auto op2_offset_str = sym_table.get_fp_offset(op2_info);
            auto res_offset_str = sym_table.get_fp_offset(res_info);

            ir.addIMC("t0", OP::LOAD, op1_offset_str, VOID, ctx->cls);
            ir.addIMC("t1", OP::LOAD, op2_offset_str, VOID, ctx->cls);
            if (ctx->op->getType() == CACTLexer::MUL)
                ir.addIMC("t2", OP::MUL, "t0", "t1", ctx->cls);
            else if (ctx->op->getType() == CACTLexer::DIV)
                ir.addIMC("t2", OP::DIV, "t0", "t1", ctx->cls);
            else if (ctx->op->getType() == CACTLexer::MOD)
                ir.addIMC("t2", OP::MOD, "t0", "t1", ctx->cls);
            ir.addIMC("t2", OP::STORE, res_offset_str, VOID, ctx->cls);
        }
    }
}

void SemanticAnalysis::enterAddExp(CACTParser::AddExpContext *ctx) {}
void SemanticAnalysis::exitAddExp(CACTParser::AddExpContext *ctx)
{
    // mulexp
    if (!ctx->addExp()) {
        ctx->cls = ctx->mulExp()->cls;
        ctx->name = ctx->mulExp()->name;
        ctx->elemwise = ctx->mulExp()->elemwise;
    }
    // addExp (ADD | SUB) mulExp
    else {
        if (ctx->addExp()->cls != ctx->mulExp()->cls) //类型检查
            throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: wrong type to binary + or -\n");
        auto op1 = ctx->addExp()->name;
        auto op2 = ctx->mulExp()->name;
        VarInfo *op1_info = sym_table.lookup(op1);
        VarInfo *op2_info = sym_table.lookup(op2);

        // element wise op
        if ((op1_info->type == TYPE_ARRAY || op1_info->type == TYPE_CONST_ARRAY) &&
            (op2_info->type == TYPE_ARRAY || op2_info->type == TYPE_CONST_ARRAY)) { 
            if (op1_info->length != op2_info->length){
                throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: wrong size to element wise operation\n");
            }
            auto res = sym_table.gen_Temp_Array(ctx->getStart()->getLine(), op1_info->cls, op1_info->length, sym_table);
            ctx->elemwise = true;
            ctx->cls = op1_info->cls;
            ctx->name = res;

            VarInfo *res_info = sym_table.lookup(res);
            auto op1_offset_str = sym_table.get_fp_offset(op1_info);
            auto op2_offset_str = sym_table.get_fp_offset(op2_info);
            auto res_offset_str = sym_table.get_fp_offset(res_info);
            for (int i = 0; i < op1_info->length; i++) {
                ir.addIMC("t4", OP::LI, std::to_string(i), VOID, CLASS_INT);
                ir.addIMC("t1", OP::READ_ARRAY, op1_offset_str, "t4", ctx->cls);
                ir.addIMC("t2", OP::READ_ARRAY, op2_offset_str, "t4", ctx->cls);
                if (ctx->op->getType() == CACTLexer::ADD)
                    ir.addIMC("t3", OP::ADD, "t1", "t2", ctx->cls);
                else if (ctx->op->getType() == CACTLexer::SUB)
                    ir.addIMC("t3", OP::SUB, "t1", "t2", ctx->cls);
                ir.addIMC("t3", OP::SAVE_ARRAY, res_offset_str, "t4", ctx->cls);
            }
        }
        // normal op
        else {
            if (op1_info->type == TYPE_ARRAY || op1_info->type == TYPE_CONST_ARRAY ||
                op2_info->type == TYPE_ARRAY || op2_info->type == TYPE_CONST_ARRAY) {
                throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: invalid operands to binary + or -\n");
            }
            else if (op1_info->cls == CLASS_BOOLEAN) {
                throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: invalid operands to binary + or -\n");
            }
            auto res = sym_table.gen_Temp_Var(ctx->getStart()->getLine(), op1_info->cls, sym_table);
            ctx->elemwise = false;
            ctx->cls = op1_info->cls;
            ctx->name = res;

            VarInfo *res_info = sym_table.lookup(res);
            auto op1_offset_str = sym_table.get_fp_offset(op1_info);
            auto op2_offset_str = sym_table.get_fp_offset(op2_info);
            auto res_offset_str = sym_table.get_fp_offset(res_info);

            ir.addIMC("t0", OP::LOAD, op1_offset_str, VOID, ctx->cls);
            ir.addIMC("t1", OP::LOAD, op2_offset_str, VOID, ctx->cls);
            if (ctx->op->getType() == CACTLexer::ADD)
                ir.addIMC("t2", OP::ADD, "t0", "t1", ctx->cls);
            else if (ctx->op->getType() == CACTLexer::SUB)
                ir.addIMC("t2", OP::SUB, "t0", "t1", ctx->cls);
            ir.addIMC("t2", OP::STORE, res_offset_str, VOID, ctx->cls);
        }
    }
}

void SemanticAnalysis::enterRelExp(CACTParser::RelExpContext *ctx) {}
void SemanticAnalysis::exitRelExp(CACTParser::RelExpContext *ctx)
{
    // boolconst
    if (ctx->BoolConst()) {
        auto res = sym_table.gen_Temp_Var(ctx->getStart()->getLine(), CLASS_BOOLEAN, sym_table);
        ctx->cls = CLASS_BOOLEAN;
        ctx->name = res;
        ctx->value = ctx->BoolConst()->getText() == "true" ? 1 : 0;
        VarInfo *res_info = sym_table.lookup(res);
        auto res_offset_str = sym_table.get_fp_offset(res_info);

        ir.addIMC("t2", OP::LI, std::to_string(ctx->value), VOID, CLASS_BOOLEAN);
        ir.addIMC("t2", OP::STORE, res_offset_str, VOID, CLASS_BOOLEAN);
    }
    // relExp op addExp
    else if (ctx->relExp()) {
        std::string op1 = ctx->relExp()->name;
        std::string op2 = ctx->addExp()->name;
        VarInfo *op1_info = sym_table.lookup(op1);
        VarInfo *op2_info = sym_table.lookup(op2);

        if (op1_info->cls != op2_info->cls) {
            throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: wrong type to comparison\n");
        }
        if (op1_info->type == TYPE_ARRAY || op1_info->type == TYPE_CONST_ARRAY ||
            op2_info->type == TYPE_ARRAY || op2_info->type == TYPE_CONST_ARRAY) {
            throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: invalid operands to comparison\n");
        }

        auto res = sym_table.gen_Temp_Var(ctx->getStart()->getLine(), CLASS_BOOLEAN, sym_table);
        ctx->cls = CLASS_BOOLEAN;
        ctx->name = res;

        VarInfo *res_info = sym_table.lookup(res);
        auto op1_offset_str = sym_table.get_fp_offset(op1_info);
        auto op2_offset_str = sym_table.get_fp_offset(op2_info);
        auto res_offset_str = sym_table.get_fp_offset(res_info);

        ir.addIMC("t0", OP::LOAD, op1_offset_str, VOID, op1_info->cls);
        ir.addIMC("t1", OP::LOAD, op2_offset_str, VOID, op2_info->cls);
        if (ctx->op->getType() == CACTLexer::GT)
            ir.addIMC("t2", OP::GT, "t0", "t1", op1_info->cls);
        else if (ctx->op->getType() == CACTLexer::GE)
            ir.addIMC("t2", OP::GE, "t0", "t1", op1_info->cls);
        else if (ctx->op->getType() == CACTLexer::LE)
            ir.addIMC("t2", OP::LE, "t0", "t1", op1_info->cls);
        else if (ctx->op->getType() == CACTLexer::LT)
            ir.addIMC("t2", OP::LT, "t0", "t1", op1_info->cls);
        ir.addIMC("t2", OP::STORE, res_offset_str, VOID, CLASS_BOOLEAN);
    }
    // addExp
    else {
        ctx->cls = ctx->addExp()->cls;
        ctx->name = ctx->addExp()->name;
    }
}

void SemanticAnalysis::enterEqExp(CACTParser::EqExpContext *ctx) {}
void SemanticAnalysis::exitEqExp(CACTParser::EqExpContext *ctx)
{
    // eqExp (EQUAL | NOTEQUAL) relExp
    if (ctx->eqExp()) {
        std::string op1 = ctx->eqExp()->name;
        std::string op2 = ctx->relExp()->name;
        VarInfo *op1_info = sym_table.lookup(op1);
        VarInfo *op2_info = sym_table.lookup(op2);

        if (op1_info->cls != op2_info->cls) {
            throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: wrong type to comparison\n");
        }
        if (op1_info->type == TYPE_ARRAY || op1_info->type == TYPE_CONST_ARRAY ||
            op2_info->type == TYPE_ARRAY || op2_info->type == TYPE_CONST_ARRAY) {
            throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: invalid operands to comparison\n");
        }

        auto res = sym_table.gen_Temp_Var(ctx->getStart()->getLine(), CLASS_BOOLEAN, sym_table);
        ctx->cls = CLASS_BOOLEAN;
        ctx->name = res;

        VarInfo *res_info = sym_table.lookup(res);
        auto op1_offset_str = sym_table.get_fp_offset(op1_info);
        auto op2_offset_str = sym_table.get_fp_offset(op2_info);
        auto res_offset_str = sym_table.get_fp_offset(res_info);

        ir.addIMC("t0", OP::LOAD, op1_offset_str, VOID, op1_info->cls);
        ir.addIMC("t1", OP::LOAD, op2_offset_str, VOID, op2_info->cls);
        if (ctx->op->getType() == CACTLexer::EQUAL)
            ir.addIMC("t2", OP::EQU, "t0", "t1", op1_info->cls);
        else if (ctx->op->getType() == CACTLexer::NOTEQUAL)
            ir.addIMC("t2", OP::NEQ, "t0", "t1", op1_info->cls);
        ir.addIMC("t2", OP::STORE, res_offset_str, VOID, CLASS_BOOLEAN);
    }
    // relExp
    else {
        ctx->cls = ctx->relExp()->cls;
        ctx->name = ctx->relExp()->name;
    }
}

void SemanticAnalysis::enterLAndExp(CACTParser::LAndExpContext *ctx) {}
void SemanticAnalysis::exitLAndExp(CACTParser::LAndExpContext *ctx)
{
    //lAndExp AND eqExp
    if (ctx->lAndExp()) {
        std::string op1 = ctx->lAndExp()->name;
        std::string op2 = ctx->eqExp()->name;
        VarInfo *op1_info = sym_table.lookup(op1);
        VarInfo *op2_info = sym_table.lookup(op2);

        if (op1_info->cls != op2_info->cls) {
            throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: wrong type to &7\n");
        }
        if (op1_info->type == TYPE_ARRAY || op1_info->type == TYPE_CONST_ARRAY ||
            op2_info->type == TYPE_ARRAY || op2_info->type == TYPE_CONST_ARRAY) {
            throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: invalid operands to &&\n");
        }

        auto res = sym_table.gen_Temp_Var(ctx->getStart()->getLine(), CLASS_BOOLEAN, sym_table);
        ctx->cls = CLASS_BOOLEAN;
        ctx->name = res;

        VarInfo *res_info = sym_table.lookup(res);
        auto op1_offset_str = sym_table.get_fp_offset(op1_info);
        auto op2_offset_str = sym_table.get_fp_offset(op2_info);
        auto res_offset_str = sym_table.get_fp_offset(res_info);

        ir.addIMC("t0", OP::LOAD, op1_offset_str, VOID, op1_info->cls);
        ir.addIMC("t1", OP::LOAD, op2_offset_str, VOID, op2_info->cls);
        ir.addIMC("t2", OP::AND, "t0", "t1", CLASS_BOOLEAN);
        ir.addIMC("t2", OP::STORE, res_offset_str, VOID, CLASS_BOOLEAN);
    }
    // eqExp
    else {
        ctx->cls = ctx->eqExp()->cls;
        ctx->name = ctx->eqExp()->name; 
    }
}

void SemanticAnalysis::enterLOrExp(CACTParser::LOrExpContext *ctx) {}
void SemanticAnalysis::exitLOrExp(CACTParser::LOrExpContext *ctx)
{
    // lOrExp OR lAndExp
    if (ctx->lOrExp()) {
        std::string op1 = ctx->lOrExp()->name;
        std::string op2 = ctx->lAndExp()->name;
        VarInfo *op1_info = sym_table.lookup(op1);
        VarInfo *op2_info = sym_table.lookup(op2);

        if (op1_info->cls != op2_info->cls) {
            throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: wrong type to ||\n");
        }
        if (op1_info->type == TYPE_ARRAY || op1_info->type == TYPE_CONST_ARRAY ||
            op2_info->type == TYPE_ARRAY || op2_info->type == TYPE_CONST_ARRAY) {
            throw std::runtime_error("line " + std::to_string(ctx->getStart()->getLine()) + ": error: invalid operands to ||\n");
        }

        auto res = sym_table.gen_Temp_Var(ctx->getStart()->getLine(), CLASS_BOOLEAN, sym_table);
        ctx->cls = CLASS_BOOLEAN;
        ctx->name = res;

        VarInfo *res_info = sym_table.lookup(res);
        auto op1_offset_str = sym_table.get_fp_offset(op1_info);
        auto op2_offset_str = sym_table.get_fp_offset(op2_info);
        auto res_offset_str = sym_table.get_fp_offset(res_info);

        ir.addIMC("t0", OP::LOAD, op1_offset_str, VOID, op1_info->cls);
        ir.addIMC("t1", OP::LOAD, op2_offset_str, VOID, op2_info->cls);
        ir.addIMC("t2", OP::OR, "t0", "t1", CLASS_BOOLEAN);
        ir.addIMC("t2", OP::STORE, res_offset_str, VOID, CLASS_BOOLEAN);
    }
    // lAndExp
    else {
        ctx->cls = ctx->lAndExp()->cls;
        ctx->name = ctx->lAndExp()->name;
    }
}
