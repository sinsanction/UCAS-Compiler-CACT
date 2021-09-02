
    #include <vector>
    #include <string>


// Generated from /home/compiler15/compiler/grammar/CACT.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"




class  CACTParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, INT = 10, BOOL = 11, DOUBLE = 12, FLOAT = 13, WHILE = 14, 
    BREAK = 15, CONTINUE = 16, IF = 17, ELSE = 18, RETURN = 19, VOID = 20, 
    CONST = 21, BoolConst = 22, TRUE = 23, FALSE = 24, ADD = 25, SUB = 26, 
    MUL = 27, DIV = 28, MOD = 29, NOT = 30, NOTEQUAL = 31, EQUAL = 32, GT = 33, 
    LT = 34, GE = 35, LE = 36, AND = 37, OR = 38, Ident = 39, IntConst = 40, 
    FloatConst = 41, DoubleConst = 42, NewLine = 43, WhiteSpace = 44, BlockComment = 45, 
    LineComment = 46
  };

  enum {
    RuleCompUnit = 0, RuleDecl = 1, RuleConstDecl = 2, RuleBType = 3, RuleConstDef = 4, 
    RuleVarDecl = 5, RuleVarDef = 6, RuleFuncDef = 7, RuleFuncType = 8, 
    RuleFuncFParam = 9, RuleBlock = 10, RuleBlockItem = 11, RuleStmt = 12, 
    RuleElseStmt = 13, RuleExp = 14, RuleIfCond = 15, RuleWhileCond = 16, 
    RuleCond = 17, RuleLVal = 18, RulePrimaryExp = 19, RuleNumber = 20, 
    RuleUnaryExp = 21, RuleFuncRParams = 22, RuleMulExp = 23, RuleAddExp = 24, 
    RuleRelExp = 25, RuleEqExp = 26, RuleLAndExp = 27, RuleLOrExp = 28, 
    RuleConstExp = 29
  };

  CACTParser(antlr4::TokenStream *input);
  ~CACTParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class CompUnitContext;
  class DeclContext;
  class ConstDeclContext;
  class BTypeContext;
  class ConstDefContext;
  class VarDeclContext;
  class VarDefContext;
  class FuncDefContext;
  class FuncTypeContext;
  class FuncFParamContext;
  class BlockContext;
  class BlockItemContext;
  class StmtContext;
  class ElseStmtContext;
  class ExpContext;
  class IfCondContext;
  class WhileCondContext;
  class CondContext;
  class LValContext;
  class PrimaryExpContext;
  class NumberContext;
  class UnaryExpContext;
  class FuncRParamsContext;
  class MulExpContext;
  class AddExpContext;
  class RelExpContext;
  class EqExpContext;
  class LAndExpContext;
  class LOrExpContext;
  class ConstExpContext; 

  class  CompUnitContext : public antlr4::ParserRuleContext {
  public:
    CompUnitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<DeclContext *> decl();
    DeclContext* decl(size_t i);
    std::vector<FuncDefContext *> funcDef();
    FuncDefContext* funcDef(size_t i);

   
  };

  CompUnitContext* compUnit();

  class  DeclContext : public antlr4::ParserRuleContext {
  public:
    DeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ConstDeclContext *constDecl();
    VarDeclContext *varDecl();

   
  };

  DeclContext* decl();

  class  ConstDeclContext : public antlr4::ParserRuleContext {
  public:
    ConstDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CONST();
    BTypeContext *bType();
    std::vector<ConstDefContext *> constDef();
    ConstDefContext* constDef(size_t i);

   
  };

  ConstDeclContext* constDecl();

  class  BTypeContext : public antlr4::ParserRuleContext {
  public:
    BTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *BOOL();
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *DOUBLE();

   
  };

  BTypeContext* bType();

  class  ConstDefContext : public antlr4::ParserRuleContext {
  public:
    ConstDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ConstDefContext() = default;
    void copyFrom(ConstDefContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ConstDefArrayContext : public ConstDefContext {
  public:
    ConstDefArrayContext(ConstDefContext *ctx);

    antlr4::tree::TerminalNode *Ident();
    antlr4::tree::TerminalNode *IntConst();
    std::vector<ConstExpContext *> constExp();
    ConstExpContext* constExp(size_t i);
  };

  class  ConstDefValContext : public ConstDefContext {
  public:
    ConstDefValContext(ConstDefContext *ctx);

    antlr4::tree::TerminalNode *Ident();
    ConstExpContext *constExp();
  };

  ConstDefContext* constDef();

  class  VarDeclContext : public antlr4::ParserRuleContext {
  public:
    VarDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BTypeContext *bType();
    std::vector<VarDefContext *> varDef();
    VarDefContext* varDef(size_t i);

   
  };

  VarDeclContext* varDecl();

  class  VarDefContext : public antlr4::ParserRuleContext {
  public:
    VarDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    VarDefContext() = default;
    void copyFrom(VarDefContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  DefInitArrayContext : public VarDefContext {
  public:
    DefInitArrayContext(VarDefContext *ctx);

    antlr4::tree::TerminalNode *Ident();
    antlr4::tree::TerminalNode *IntConst();
    std::vector<ConstExpContext *> constExp();
    ConstExpContext* constExp(size_t i);
  };

  class  DefArrayContext : public VarDefContext {
  public:
    DefArrayContext(VarDefContext *ctx);

    antlr4::tree::TerminalNode *Ident();
    antlr4::tree::TerminalNode *IntConst();
  };

  class  DefInitValContext : public VarDefContext {
  public:
    DefInitValContext(VarDefContext *ctx);

    antlr4::tree::TerminalNode *Ident();
    ConstExpContext *constExp();
  };

  class  DefValContext : public VarDefContext {
  public:
    DefValContext(VarDefContext *ctx);

    antlr4::tree::TerminalNode *Ident();
  };

  VarDefContext* varDef();

  class  FuncDefContext : public antlr4::ParserRuleContext {
  public:
    CACTParser::FuncTypeContext *ret = nullptr;;
    antlr4::Token *name = nullptr;;
    FuncDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BlockContext *block();
    FuncTypeContext *funcType();
    antlr4::tree::TerminalNode *Ident();
    std::vector<FuncFParamContext *> funcFParam();
    FuncFParamContext* funcFParam(size_t i);

   
  };

  FuncDefContext* funcDef();

  class  FuncTypeContext : public antlr4::ParserRuleContext {
  public:
    FuncTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VOID();
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *DOUBLE();
    antlr4::tree::TerminalNode *BOOL();

   
  };

  FuncTypeContext* funcType();

  class  FuncFParamContext : public antlr4::ParserRuleContext {
  public:
    FuncFParamContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BTypeContext *bType();
    antlr4::tree::TerminalNode *Ident();

   
  };

  FuncFParamContext* funcFParam();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<BlockItemContext *> blockItem();
    BlockItemContext* blockItem(size_t i);

   
  };

  BlockContext* block();

  class  BlockItemContext : public antlr4::ParserRuleContext {
  public:
    BlockItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DeclContext *decl();
    StmtContext *stmt();

   
  };

  BlockItemContext* blockItem();

  class  StmtContext : public antlr4::ParserRuleContext {
  public:
    StmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    StmtContext() = default;
    void copyFrom(StmtContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ExprStmtContext : public StmtContext {
  public:
    ExprStmtContext(StmtContext *ctx);

    ExpContext *exp();
  };

  class  WhileStmtContext : public StmtContext {
  public:
    WhileStmtContext(StmtContext *ctx);

    antlr4::tree::TerminalNode *WHILE();
    WhileCondContext *whileCond();
    StmtContext *stmt();
  };

  class  IfStmtContext : public StmtContext {
  public:
    IfStmtContext(StmtContext *ctx);

    antlr4::tree::TerminalNode *IF();
    IfCondContext *ifCond();
    StmtContext *stmt();
  };

  class  BlockStmtContext : public StmtContext {
  public:
    BlockStmtContext(StmtContext *ctx);

    BlockContext *block();
  };

  class  IfElseStmtContext : public StmtContext {
  public:
    IfElseStmtContext(StmtContext *ctx);

    antlr4::tree::TerminalNode *IF();
    IfCondContext *ifCond();
    StmtContext *stmt();
    ElseStmtContext *elseStmt();
  };

  class  AssignStmtContext : public StmtContext {
  public:
    AssignStmtContext(StmtContext *ctx);

    LValContext *lVal();
    ExpContext *exp();
  };

  class  BreakStmtContext : public StmtContext {
  public:
    BreakStmtContext(StmtContext *ctx);

    antlr4::tree::TerminalNode *BREAK();
  };

  class  ReturnStmtContext : public StmtContext {
  public:
    ReturnStmtContext(StmtContext *ctx);

    antlr4::tree::TerminalNode *RETURN();
    ExpContext *exp();
  };

  class  ContinueStmtContext : public StmtContext {
  public:
    ContinueStmtContext(StmtContext *ctx);

    antlr4::tree::TerminalNode *CONTINUE();
  };

  StmtContext* stmt();

  class  ElseStmtContext : public antlr4::ParserRuleContext {
  public:
    ElseStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ELSE();
    StmtContext *stmt();

   
  };

  ElseStmtContext* elseStmt();

  class  ExpContext : public antlr4::ParserRuleContext {
  public:
    std::string name;
    int cls;
    ExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AddExpContext *addExp();
    antlr4::tree::TerminalNode *BoolConst();

   
  };

  ExpContext* exp();

  class  IfCondContext : public antlr4::ParserRuleContext {
  public:
    std::string name;
    int cls;
    bool value;
    IfCondContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CondContext *cond();

   
  };

  IfCondContext* ifCond();

  class  WhileCondContext : public antlr4::ParserRuleContext {
  public:
    std::string name;
    int cls;
    bool value;
    WhileCondContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CondContext *cond();

   
  };

  WhileCondContext* whileCond();

  class  CondContext : public antlr4::ParserRuleContext {
  public:
    std::string name;
    int cls;
    bool value;
    CondContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LOrExpContext *lOrExp();

   
  };

  CondContext* cond();

  class  LValContext : public antlr4::ParserRuleContext {
  public:
    std::string name;
    int cls;
    bool elemwise;
    LValContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Ident();
    ExpContext *exp();

   
  };

  LValContext* lVal();

  class  PrimaryExpContext : public antlr4::ParserRuleContext {
  public:
    std::string name;
    int cls;
    bool elemwise;
    PrimaryExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpContext *exp();
    LValContext *lVal();
    antlr4::tree::TerminalNode *BoolConst();
    NumberContext *number();

   
  };

  PrimaryExpContext* primaryExp();

  class  NumberContext : public antlr4::ParserRuleContext {
  public:
    std::string name;
    int cls;
    NumberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IntConst();
    antlr4::tree::TerminalNode *FloatConst();
    antlr4::tree::TerminalNode *DoubleConst();

   
  };

  NumberContext* number();

  class  UnaryExpContext : public antlr4::ParserRuleContext {
  public:
    std::string name;
    int cls;
    bool elemwise;
    UnaryExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    UnaryExpContext() = default;
    void copyFrom(UnaryExpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  FuncallContext : public UnaryExpContext {
  public:
    FuncallContext(UnaryExpContext *ctx);

    antlr4::tree::TerminalNode *Ident();
    FuncRParamsContext *funcRParams();
  };

  class  UnaryContext : public UnaryExpContext {
  public:
    UnaryContext(UnaryExpContext *ctx);

    antlr4::Token *op = nullptr;
    UnaryExpContext *unaryExp();
    antlr4::tree::TerminalNode *ADD();
    antlr4::tree::TerminalNode *SUB();
    antlr4::tree::TerminalNode *NOT();
  };

  class  PrimaryContext : public UnaryExpContext {
  public:
    PrimaryContext(UnaryExpContext *ctx);

    PrimaryExpContext *primaryExp();
  };

  UnaryExpContext* unaryExp();

  class  FuncRParamsContext : public antlr4::ParserRuleContext {
  public:
    FuncRParamsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpContext *> exp();
    ExpContext* exp(size_t i);

   
  };

  FuncRParamsContext* funcRParams();

  class  MulExpContext : public antlr4::ParserRuleContext {
  public:
    std::string name;
    int cls;
    bool elemwise;
    antlr4::Token *op = nullptr;;
    MulExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UnaryExpContext *unaryExp();
    MulExpContext *mulExp();
    antlr4::tree::TerminalNode *MUL();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *MOD();

   
  };

  MulExpContext* mulExp();
  MulExpContext* mulExp(int precedence);
  class  AddExpContext : public antlr4::ParserRuleContext {
  public:
    std::string name;
    int cls;
    bool elemwise;
    antlr4::Token *op = nullptr;;
    AddExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    MulExpContext *mulExp();
    AddExpContext *addExp();
    antlr4::tree::TerminalNode *ADD();
    antlr4::tree::TerminalNode *SUB();

   
  };

  AddExpContext* addExp();
  AddExpContext* addExp(int precedence);
  class  RelExpContext : public antlr4::ParserRuleContext {
  public:
    std::string name;
    int cls;
    bool value;
    antlr4::Token *op = nullptr;;
    RelExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AddExpContext *addExp();
    antlr4::tree::TerminalNode *BoolConst();
    RelExpContext *relExp();
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *GT();
    antlr4::tree::TerminalNode *LE();
    antlr4::tree::TerminalNode *GE();

   
  };

  RelExpContext* relExp();
  RelExpContext* relExp(int precedence);
  class  EqExpContext : public antlr4::ParserRuleContext {
  public:
    std::string name;
    int cls;
    bool value;
    antlr4::Token *op = nullptr;;
    EqExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    RelExpContext *relExp();
    EqExpContext *eqExp();
    antlr4::tree::TerminalNode *EQUAL();
    antlr4::tree::TerminalNode *NOTEQUAL();

   
  };

  EqExpContext* eqExp();
  EqExpContext* eqExp(int precedence);
  class  LAndExpContext : public antlr4::ParserRuleContext {
  public:
    std::string name;
    int cls;
    bool value;
    antlr4::Token *op = nullptr;;
    LAndExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    EqExpContext *eqExp();
    LAndExpContext *lAndExp();
    antlr4::tree::TerminalNode *AND();

   
  };

  LAndExpContext* lAndExp();
  LAndExpContext* lAndExp(int precedence);
  class  LOrExpContext : public antlr4::ParserRuleContext {
  public:
    std::string name;
    int cls;
    bool value;
    antlr4::Token *op = nullptr;;
    LOrExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LAndExpContext *lAndExp();
    LOrExpContext *lOrExp();
    antlr4::tree::TerminalNode *OR();

   
  };

  LOrExpContext* lOrExp();
  LOrExpContext* lOrExp(int precedence);
  class  ConstExpContext : public antlr4::ParserRuleContext {
  public:
    std::string name;
    int cls;
    ConstExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ConstExpContext() = default;
    void copyFrom(ConstExpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ConstExpBoolConstContext : public ConstExpContext {
  public:
    ConstExpBoolConstContext(ConstExpContext *ctx);

    antlr4::tree::TerminalNode *BoolConst();
  };

  class  ConstExpNumberContext : public ConstExpContext {
  public:
    ConstExpNumberContext(ConstExpContext *ctx);

    NumberContext *number();
  };

  ConstExpContext* constExp();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool mulExpSempred(MulExpContext *_localctx, size_t predicateIndex);
  bool addExpSempred(AddExpContext *_localctx, size_t predicateIndex);
  bool relExpSempred(RelExpContext *_localctx, size_t predicateIndex);
  bool eqExpSempred(EqExpContext *_localctx, size_t predicateIndex);
  bool lAndExpSempred(LAndExpContext *_localctx, size_t predicateIndex);
  bool lOrExpSempred(LOrExpContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

