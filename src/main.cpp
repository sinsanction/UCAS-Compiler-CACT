#include <iostream>
#include <string>

#include "antlr4-runtime.h"
#include "../grammar/CACTLexer.h"
#include "../grammar/CACTParser.h"
#include "../grammar/CACTBaseListener.h"

#include "semanticAnalysis.h"
#include "riscv.h"

using namespace antlr4;

int main(int argc, const char* argv[]) {
    const std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

    std::ifstream stream;
    stream.open(argv[1]);
    if(!stream.good()){
        std::cout << "No such file!" << std::endl;
        exit(1);
    }
    ANTLRInputStream input(stream);
    
    // syntax analysis
    CACTLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    CACTParser parser(&tokens);
    tree::ParseTree *tree = parser.compUnit();

	if (parser.getNumberOfSyntaxErrors() > 0 || lexer.getNumberOfSyntaxErrors() > 0) {
		std::cout << "Syntax Error!" << std::endl;
        exit(1);
	}

	// semantic analysis
    SemanticAnalysis listener;
	tree::ParseTreeWalker walker;
	try {
        walker.walk(&listener, tree);
    }
    catch (const std::exception &e) {
        std::cerr << e.what();
		std::cout << "Semantic Error!" << std::endl;
        exit(1);
    }
    std::cout << "OK!" << std::endl;

    // gen code
    std::cout << "START GEN CODE!" << std::endl;
    std::string in_file = argv[1];
    std::string out_file = in_file.substr(0, in_file.length() - 5);
    reverse(out_file.begin(), out_file.end());
    out_file = out_file.substr(0, out_file.find_first_of("/"));
    reverse(out_file.begin(), out_file.end());

    RISCV_CODE riscv_codes;
    riscv_codes.RISCV_Gen(listener.sym_table, listener.ir, out_file);

    // print symbol table
    if(argc >= 3){
        std::ofstream stream;
        stream.open(argv[2]);
        listener.sym_table.printSymbol(stream);
    }
    // print IR
    if(argc >= 4){
        std::ofstream stream;
        stream.open(argv[3]);
        listener.ir.printIMC(stream);
    }

    const std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	const auto elapsed_time_us = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	const auto elapsed_time_sec = (elapsed_time_us.count() / 1000000.0);
	std::cout << "Compilation Time: " << elapsed_time_sec << " seconds\n";
    exit(0);
}
