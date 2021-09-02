#include "IR.h"

std::string IR::gen_label() {
    return "label" + std::to_string(++label_cnt) + ":";
}

void IR::addIMC(std::string rst, const std::string &op, std::string arg1, std::string arg2, int cls) {
    IRCode t;
    t.arg1 = arg1;
	t.arg2 = arg2;
	t.op = op;
	t.rst = rst;
	t.cls = cls;
    this->ir_codes.push_back(t);
}

void IR::printIMC(std::ofstream &o) {
	o 	<< std::setw(10) << "arg1"   << '|' 
		<< std::setw(10) << "arg2"   << '|' 
		<< std::setw(10) << "op"     << '|' 
		<< std::setw(10) << "result" << '|' 
		<< std::setw(10) << "class"  << '|' << std::endl;
	for(auto iterm = ir_codes.begin(); iterm!= ir_codes.end(); iterm++) {
		std::string cls =(iterm->cls==0)?   "int": \
						 (iterm->cls==1)?	"double": \
						 (iterm->cls==2)?	"float": \
						 (iterm->cls==3)?	"bool":"";
			
		o << std::setw(10) << iterm->arg1 << '|' 
		  << std::setw(10) << iterm->arg2 << '|' 
		  << std::setw(10) << iterm->op   << '|' 
	      << std::setw(10) << iterm->rst  << '|' 
		  << std::setw(10) << cls         << '|'<< std::endl;
	}
}
