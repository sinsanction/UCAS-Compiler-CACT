
    #include <vector>
    #include <string>


// Generated from CACT.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "CACTListener.h"


/**
 * This class provides an empty implementation of CACTListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  CACTBaseListener : public CACTListener {
public:

  virtual void enterCompUnit(CACTParser::CompUnitContext * /*ctx*/) override { }
  virtual void exitCompUnit(CACTParser::CompUnitContext * /*ctx*/) override { }

  virtual void enterDecl(CACTParser::DeclContext * /*ctx*/) override { }
  virtual void exitDecl(CACTParser::DeclContext * /*ctx*/) override { }

  virtual void enterConstDecl(CACTParser::ConstDeclContext * /*ctx*/) override { }
  virtual void exitConstDecl(CACTParser::ConstDeclContext * /*ctx*/) override { }

  virtual void enterBType(CACTParser::BTypeContext * /*ctx*/) override { }
  virtual void exitBType(CACTParser::BTypeContext * /*ctx*/) override { }

  virtual void enterConstDefVal(CACTParser::ConstDefValContext * /*ctx*/) override { }
  virtual void exitConstDefVal(CACTParser::ConstDefValContext * /*ctx*/) override { }

  virtual void enterConstDefArray(CACTParser::ConstDefArrayContext * /*ctx*/) override { }
  virtual void exitConstDefArray(CACTParser::ConstDefArrayContext * /*ctx*/) override { }

  virtual void enterVarDecl(CACTParser::VarDeclContext * /*ctx*/) override { }
  virtual void exitVarDecl(CACTParser::VarDeclContext * /*ctx*/) override { }

  virtual void enterDefVal(CACTParser::DefValContext * /*ctx*/) override { }
  virtual void exitDefVal(CACTParser::DefValContext * /*ctx*/) override { }

  virtual void enterDefArray(CACTParser::DefArrayContext * /*ctx*/) override { }
  virtual void exitDefArray(CACTParser::DefArrayContext * /*ctx*/) override { }

  virtual void enterDefInitVal(CACTParser::DefInitValContext * /*ctx*/) override { }
  virtual void exitDefInitVal(CACTParser::DefInitValContext * /*ctx*/) override { }

  virtual void enterDefInitArray(CACTParser::DefInitArrayContext * /*ctx*/) override { }
  virtual void exitDefInitArray(CACTParser::DefInitArrayContext * /*ctx*/) override { }

  virtual void enterFuncDef(CACTParser::FuncDefContext * /*ctx*/) override { }
  virtual void exitFuncDef(CACTParser::FuncDefContext * /*ctx*/) override { }

  virtual void enterFuncType(CACTParser::FuncTypeContext * /*ctx*/) override { }
  virtual void exitFuncType(CACTParser::FuncTypeContext * /*ctx*/) override { }

  virtual void enterFuncFParam(CACTParser::FuncFParamContext * /*ctx*/) override { }
  virtual void exitFuncFParam(CACTParser::FuncFParamContext * /*ctx*/) override { }

  virtual void enterBlock(CACTParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(CACTParser::BlockContext * /*ctx*/) override { }

  virtual void enterBlockItem(CACTParser::BlockItemContext * /*ctx*/) override { }
  virtual void exitBlockItem(CACTParser::BlockItemContext * /*ctx*/) override { }

  virtual void enterAssignStmt(CACTParser::AssignStmtContext * /*ctx*/) override { }
  virtual void exitAssignStmt(CACTParser::AssignStmtContext * /*ctx*/) override { }

  virtual void enterExprStmt(CACTParser::ExprStmtContext * /*ctx*/) override { }
  virtual void exitExprStmt(CACTParser::ExprStmtContext * /*ctx*/) override { }

  virtual void enterBlockStmt(CACTParser::BlockStmtContext * /*ctx*/) override { }
  virtual void exitBlockStmt(CACTParser::BlockStmtContext * /*ctx*/) override { }

  virtual void enterIfStmt(CACTParser::IfStmtContext * /*ctx*/) override { }
  virtual void exitIfStmt(CACTParser::IfStmtContext * /*ctx*/) override { }

  virtual void enterIfElseStmt(CACTParser::IfElseStmtContext * /*ctx*/) override { }
  virtual void exitIfElseStmt(CACTParser::IfElseStmtContext * /*ctx*/) override { }

  virtual void enterWhileStmt(CACTParser::WhileStmtContext * /*ctx*/) override { }
  virtual void exitWhileStmt(CACTParser::WhileStmtContext * /*ctx*/) override { }

  virtual void enterBreakStmt(CACTParser::BreakStmtContext * /*ctx*/) override { }
  virtual void exitBreakStmt(CACTParser::BreakStmtContext * /*ctx*/) override { }

  virtual void enterContinueStmt(CACTParser::ContinueStmtContext * /*ctx*/) override { }
  virtual void exitContinueStmt(CACTParser::ContinueStmtContext * /*ctx*/) override { }

  virtual void enterReturnStmt(CACTParser::ReturnStmtContext * /*ctx*/) override { }
  virtual void exitReturnStmt(CACTParser::ReturnStmtContext * /*ctx*/) override { }

  virtual void enterElseStmt(CACTParser::ElseStmtContext * /*ctx*/) override { }
  virtual void exitElseStmt(CACTParser::ElseStmtContext * /*ctx*/) override { }

  virtual void enterExp(CACTParser::ExpContext * /*ctx*/) override { }
  virtual void exitExp(CACTParser::ExpContext * /*ctx*/) override { }

  virtual void enterIfCond(CACTParser::IfCondContext * /*ctx*/) override { }
  virtual void exitIfCond(CACTParser::IfCondContext * /*ctx*/) override { }

  virtual void enterWhileCond(CACTParser::WhileCondContext * /*ctx*/) override { }
  virtual void exitWhileCond(CACTParser::WhileCondContext * /*ctx*/) override { }

  virtual void enterCond(CACTParser::CondContext * /*ctx*/) override { }
  virtual void exitCond(CACTParser::CondContext * /*ctx*/) override { }

  virtual void enterLVal(CACTParser::LValContext * /*ctx*/) override { }
  virtual void exitLVal(CACTParser::LValContext * /*ctx*/) override { }

  virtual void enterPrimaryExp(CACTParser::PrimaryExpContext * /*ctx*/) override { }
  virtual void exitPrimaryExp(CACTParser::PrimaryExpContext * /*ctx*/) override { }

  virtual void enterNumber(CACTParser::NumberContext * /*ctx*/) override { }
  virtual void exitNumber(CACTParser::NumberContext * /*ctx*/) override { }

  virtual void enterPrimary(CACTParser::PrimaryContext * /*ctx*/) override { }
  virtual void exitPrimary(CACTParser::PrimaryContext * /*ctx*/) override { }

  virtual void enterFuncall(CACTParser::FuncallContext * /*ctx*/) override { }
  virtual void exitFuncall(CACTParser::FuncallContext * /*ctx*/) override { }

  virtual void enterUnary(CACTParser::UnaryContext * /*ctx*/) override { }
  virtual void exitUnary(CACTParser::UnaryContext * /*ctx*/) override { }

  virtual void enterFuncRParams(CACTParser::FuncRParamsContext * /*ctx*/) override { }
  virtual void exitFuncRParams(CACTParser::FuncRParamsContext * /*ctx*/) override { }

  virtual void enterMulExp(CACTParser::MulExpContext * /*ctx*/) override { }
  virtual void exitMulExp(CACTParser::MulExpContext * /*ctx*/) override { }

  virtual void enterAddExp(CACTParser::AddExpContext * /*ctx*/) override { }
  virtual void exitAddExp(CACTParser::AddExpContext * /*ctx*/) override { }

  virtual void enterRelExp(CACTParser::RelExpContext * /*ctx*/) override { }
  virtual void exitRelExp(CACTParser::RelExpContext * /*ctx*/) override { }

  virtual void enterEqExp(CACTParser::EqExpContext * /*ctx*/) override { }
  virtual void exitEqExp(CACTParser::EqExpContext * /*ctx*/) override { }

  virtual void enterLAndExp(CACTParser::LAndExpContext * /*ctx*/) override { }
  virtual void exitLAndExp(CACTParser::LAndExpContext * /*ctx*/) override { }

  virtual void enterLOrExp(CACTParser::LOrExpContext * /*ctx*/) override { }
  virtual void exitLOrExp(CACTParser::LOrExpContext * /*ctx*/) override { }

  virtual void enterConstExpNumber(CACTParser::ConstExpNumberContext * /*ctx*/) override { }
  virtual void exitConstExpNumber(CACTParser::ConstExpNumberContext * /*ctx*/) override { }

  virtual void enterConstExpBoolConst(CACTParser::ConstExpBoolConstContext * /*ctx*/) override { }
  virtual void exitConstExpBoolConst(CACTParser::ConstExpBoolConstContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

