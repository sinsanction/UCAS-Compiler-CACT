
    #include <vector>
    #include <string>


// Generated from CACT.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "CACTParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by CACTParser.
 */
class  CACTListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterCompUnit(CACTParser::CompUnitContext *ctx) = 0;
  virtual void exitCompUnit(CACTParser::CompUnitContext *ctx) = 0;

  virtual void enterDecl(CACTParser::DeclContext *ctx) = 0;
  virtual void exitDecl(CACTParser::DeclContext *ctx) = 0;

  virtual void enterConstDecl(CACTParser::ConstDeclContext *ctx) = 0;
  virtual void exitConstDecl(CACTParser::ConstDeclContext *ctx) = 0;

  virtual void enterBType(CACTParser::BTypeContext *ctx) = 0;
  virtual void exitBType(CACTParser::BTypeContext *ctx) = 0;

  virtual void enterConstDefVal(CACTParser::ConstDefValContext *ctx) = 0;
  virtual void exitConstDefVal(CACTParser::ConstDefValContext *ctx) = 0;

  virtual void enterConstDefArray(CACTParser::ConstDefArrayContext *ctx) = 0;
  virtual void exitConstDefArray(CACTParser::ConstDefArrayContext *ctx) = 0;

  virtual void enterVarDecl(CACTParser::VarDeclContext *ctx) = 0;
  virtual void exitVarDecl(CACTParser::VarDeclContext *ctx) = 0;

  virtual void enterDefVal(CACTParser::DefValContext *ctx) = 0;
  virtual void exitDefVal(CACTParser::DefValContext *ctx) = 0;

  virtual void enterDefArray(CACTParser::DefArrayContext *ctx) = 0;
  virtual void exitDefArray(CACTParser::DefArrayContext *ctx) = 0;

  virtual void enterDefInitVal(CACTParser::DefInitValContext *ctx) = 0;
  virtual void exitDefInitVal(CACTParser::DefInitValContext *ctx) = 0;

  virtual void enterDefInitArray(CACTParser::DefInitArrayContext *ctx) = 0;
  virtual void exitDefInitArray(CACTParser::DefInitArrayContext *ctx) = 0;

  virtual void enterFuncDef(CACTParser::FuncDefContext *ctx) = 0;
  virtual void exitFuncDef(CACTParser::FuncDefContext *ctx) = 0;

  virtual void enterFuncType(CACTParser::FuncTypeContext *ctx) = 0;
  virtual void exitFuncType(CACTParser::FuncTypeContext *ctx) = 0;

  virtual void enterFuncFParam(CACTParser::FuncFParamContext *ctx) = 0;
  virtual void exitFuncFParam(CACTParser::FuncFParamContext *ctx) = 0;

  virtual void enterBlock(CACTParser::BlockContext *ctx) = 0;
  virtual void exitBlock(CACTParser::BlockContext *ctx) = 0;

  virtual void enterBlockItem(CACTParser::BlockItemContext *ctx) = 0;
  virtual void exitBlockItem(CACTParser::BlockItemContext *ctx) = 0;

  virtual void enterAssignStmt(CACTParser::AssignStmtContext *ctx) = 0;
  virtual void exitAssignStmt(CACTParser::AssignStmtContext *ctx) = 0;

  virtual void enterExprStmt(CACTParser::ExprStmtContext *ctx) = 0;
  virtual void exitExprStmt(CACTParser::ExprStmtContext *ctx) = 0;

  virtual void enterBlockStmt(CACTParser::BlockStmtContext *ctx) = 0;
  virtual void exitBlockStmt(CACTParser::BlockStmtContext *ctx) = 0;

  virtual void enterIfStmt(CACTParser::IfStmtContext *ctx) = 0;
  virtual void exitIfStmt(CACTParser::IfStmtContext *ctx) = 0;

  virtual void enterIfElseStmt(CACTParser::IfElseStmtContext *ctx) = 0;
  virtual void exitIfElseStmt(CACTParser::IfElseStmtContext *ctx) = 0;

  virtual void enterWhileStmt(CACTParser::WhileStmtContext *ctx) = 0;
  virtual void exitWhileStmt(CACTParser::WhileStmtContext *ctx) = 0;

  virtual void enterBreakStmt(CACTParser::BreakStmtContext *ctx) = 0;
  virtual void exitBreakStmt(CACTParser::BreakStmtContext *ctx) = 0;

  virtual void enterContinueStmt(CACTParser::ContinueStmtContext *ctx) = 0;
  virtual void exitContinueStmt(CACTParser::ContinueStmtContext *ctx) = 0;

  virtual void enterReturnStmt(CACTParser::ReturnStmtContext *ctx) = 0;
  virtual void exitReturnStmt(CACTParser::ReturnStmtContext *ctx) = 0;

  virtual void enterElseStmt(CACTParser::ElseStmtContext *ctx) = 0;
  virtual void exitElseStmt(CACTParser::ElseStmtContext *ctx) = 0;

  virtual void enterExp(CACTParser::ExpContext *ctx) = 0;
  virtual void exitExp(CACTParser::ExpContext *ctx) = 0;

  virtual void enterIfCond(CACTParser::IfCondContext *ctx) = 0;
  virtual void exitIfCond(CACTParser::IfCondContext *ctx) = 0;

  virtual void enterWhileCond(CACTParser::WhileCondContext *ctx) = 0;
  virtual void exitWhileCond(CACTParser::WhileCondContext *ctx) = 0;

  virtual void enterCond(CACTParser::CondContext *ctx) = 0;
  virtual void exitCond(CACTParser::CondContext *ctx) = 0;

  virtual void enterLVal(CACTParser::LValContext *ctx) = 0;
  virtual void exitLVal(CACTParser::LValContext *ctx) = 0;

  virtual void enterPrimaryExp(CACTParser::PrimaryExpContext *ctx) = 0;
  virtual void exitPrimaryExp(CACTParser::PrimaryExpContext *ctx) = 0;

  virtual void enterNumber(CACTParser::NumberContext *ctx) = 0;
  virtual void exitNumber(CACTParser::NumberContext *ctx) = 0;

  virtual void enterPrimary(CACTParser::PrimaryContext *ctx) = 0;
  virtual void exitPrimary(CACTParser::PrimaryContext *ctx) = 0;

  virtual void enterFuncall(CACTParser::FuncallContext *ctx) = 0;
  virtual void exitFuncall(CACTParser::FuncallContext *ctx) = 0;

  virtual void enterUnary(CACTParser::UnaryContext *ctx) = 0;
  virtual void exitUnary(CACTParser::UnaryContext *ctx) = 0;

  virtual void enterFuncRParams(CACTParser::FuncRParamsContext *ctx) = 0;
  virtual void exitFuncRParams(CACTParser::FuncRParamsContext *ctx) = 0;

  virtual void enterMulExp(CACTParser::MulExpContext *ctx) = 0;
  virtual void exitMulExp(CACTParser::MulExpContext *ctx) = 0;

  virtual void enterAddExp(CACTParser::AddExpContext *ctx) = 0;
  virtual void exitAddExp(CACTParser::AddExpContext *ctx) = 0;

  virtual void enterRelExp(CACTParser::RelExpContext *ctx) = 0;
  virtual void exitRelExp(CACTParser::RelExpContext *ctx) = 0;

  virtual void enterEqExp(CACTParser::EqExpContext *ctx) = 0;
  virtual void exitEqExp(CACTParser::EqExpContext *ctx) = 0;

  virtual void enterLAndExp(CACTParser::LAndExpContext *ctx) = 0;
  virtual void exitLAndExp(CACTParser::LAndExpContext *ctx) = 0;

  virtual void enterLOrExp(CACTParser::LOrExpContext *ctx) = 0;
  virtual void exitLOrExp(CACTParser::LOrExpContext *ctx) = 0;

  virtual void enterConstExpNumber(CACTParser::ConstExpNumberContext *ctx) = 0;
  virtual void exitConstExpNumber(CACTParser::ConstExpNumberContext *ctx) = 0;

  virtual void enterConstExpBoolConst(CACTParser::ConstExpBoolConstContext *ctx) = 0;
  virtual void exitConstExpBoolConst(CACTParser::ConstExpBoolConstContext *ctx) = 0;


};

