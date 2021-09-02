
    #include <vector>
    #include <string>


// Generated from /home/compiler15/compiler/grammar/CACT.g4 by ANTLR 4.8



#include "CACTParser.h"


using namespace antlrcpp;
using namespace antlr4;

CACTParser::CACTParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

CACTParser::~CACTParser() {
  delete _interpreter;
}

std::string CACTParser::getGrammarFileName() const {
  return "CACT.g4";
}

const std::vector<std::string>& CACTParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& CACTParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- CompUnitContext ------------------------------------------------------------------

CACTParser::CompUnitContext::CompUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CACTParser::CompUnitContext::EOF() {
  return getToken(CACTParser::EOF, 0);
}

std::vector<CACTParser::DeclContext *> CACTParser::CompUnitContext::decl() {
  return getRuleContexts<CACTParser::DeclContext>();
}

CACTParser::DeclContext* CACTParser::CompUnitContext::decl(size_t i) {
  return getRuleContext<CACTParser::DeclContext>(i);
}

std::vector<CACTParser::FuncDefContext *> CACTParser::CompUnitContext::funcDef() {
  return getRuleContexts<CACTParser::FuncDefContext>();
}

CACTParser::FuncDefContext* CACTParser::CompUnitContext::funcDef(size_t i) {
  return getRuleContext<CACTParser::FuncDefContext>(i);
}


size_t CACTParser::CompUnitContext::getRuleIndex() const {
  return CACTParser::RuleCompUnit;
}


CACTParser::CompUnitContext* CACTParser::compUnit() {
  CompUnitContext *_localctx = _tracker.createInstance<CompUnitContext>(_ctx, getState());
  enterRule(_localctx, 0, CACTParser::RuleCompUnit);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(62); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(62);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
      case 1: {
        setState(60);
        decl();
        break;
      }

      case 2: {
        setState(61);
        funcDef();
        break;
      }

      }
      setState(64); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::INT)
      | (1ULL << CACTParser::BOOL)
      | (1ULL << CACTParser::DOUBLE)
      | (1ULL << CACTParser::FLOAT)
      | (1ULL << CACTParser::VOID)
      | (1ULL << CACTParser::CONST))) != 0));
    setState(66);
    match(CACTParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclContext ------------------------------------------------------------------

CACTParser::DeclContext::DeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::ConstDeclContext* CACTParser::DeclContext::constDecl() {
  return getRuleContext<CACTParser::ConstDeclContext>(0);
}

CACTParser::VarDeclContext* CACTParser::DeclContext::varDecl() {
  return getRuleContext<CACTParser::VarDeclContext>(0);
}


size_t CACTParser::DeclContext::getRuleIndex() const {
  return CACTParser::RuleDecl;
}


CACTParser::DeclContext* CACTParser::decl() {
  DeclContext *_localctx = _tracker.createInstance<DeclContext>(_ctx, getState());
  enterRule(_localctx, 2, CACTParser::RuleDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(70);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::CONST: {
        enterOuterAlt(_localctx, 1);
        setState(68);
        constDecl();
        break;
      }

      case CACTParser::INT:
      case CACTParser::BOOL:
      case CACTParser::DOUBLE:
      case CACTParser::FLOAT: {
        enterOuterAlt(_localctx, 2);
        setState(69);
        varDecl();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstDeclContext ------------------------------------------------------------------

CACTParser::ConstDeclContext::ConstDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CACTParser::ConstDeclContext::CONST() {
  return getToken(CACTParser::CONST, 0);
}

CACTParser::BTypeContext* CACTParser::ConstDeclContext::bType() {
  return getRuleContext<CACTParser::BTypeContext>(0);
}

std::vector<CACTParser::ConstDefContext *> CACTParser::ConstDeclContext::constDef() {
  return getRuleContexts<CACTParser::ConstDefContext>();
}

CACTParser::ConstDefContext* CACTParser::ConstDeclContext::constDef(size_t i) {
  return getRuleContext<CACTParser::ConstDefContext>(i);
}


size_t CACTParser::ConstDeclContext::getRuleIndex() const {
  return CACTParser::RuleConstDecl;
}


CACTParser::ConstDeclContext* CACTParser::constDecl() {
  ConstDeclContext *_localctx = _tracker.createInstance<ConstDeclContext>(_ctx, getState());
  enterRule(_localctx, 4, CACTParser::RuleConstDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(72);
    match(CACTParser::CONST);
    setState(73);
    bType();
    setState(74);
    constDef();
    setState(79);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CACTParser::T__0) {
      setState(75);
      match(CACTParser::T__0);
      setState(76);
      constDef();
      setState(81);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(82);
    match(CACTParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BTypeContext ------------------------------------------------------------------

CACTParser::BTypeContext::BTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CACTParser::BTypeContext::INT() {
  return getToken(CACTParser::INT, 0);
}

tree::TerminalNode* CACTParser::BTypeContext::BOOL() {
  return getToken(CACTParser::BOOL, 0);
}

tree::TerminalNode* CACTParser::BTypeContext::FLOAT() {
  return getToken(CACTParser::FLOAT, 0);
}

tree::TerminalNode* CACTParser::BTypeContext::DOUBLE() {
  return getToken(CACTParser::DOUBLE, 0);
}


size_t CACTParser::BTypeContext::getRuleIndex() const {
  return CACTParser::RuleBType;
}


CACTParser::BTypeContext* CACTParser::bType() {
  BTypeContext *_localctx = _tracker.createInstance<BTypeContext>(_ctx, getState());
  enterRule(_localctx, 6, CACTParser::RuleBType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(84);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::INT)
      | (1ULL << CACTParser::BOOL)
      | (1ULL << CACTParser::DOUBLE)
      | (1ULL << CACTParser::FLOAT))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstDefContext ------------------------------------------------------------------

CACTParser::ConstDefContext::ConstDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::ConstDefContext::getRuleIndex() const {
  return CACTParser::RuleConstDef;
}

void CACTParser::ConstDefContext::copyFrom(ConstDefContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ConstDefArrayContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::ConstDefArrayContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

tree::TerminalNode* CACTParser::ConstDefArrayContext::IntConst() {
  return getToken(CACTParser::IntConst, 0);
}

std::vector<CACTParser::ConstExpContext *> CACTParser::ConstDefArrayContext::constExp() {
  return getRuleContexts<CACTParser::ConstExpContext>();
}

CACTParser::ConstExpContext* CACTParser::ConstDefArrayContext::constExp(size_t i) {
  return getRuleContext<CACTParser::ConstExpContext>(i);
}

CACTParser::ConstDefArrayContext::ConstDefArrayContext(ConstDefContext *ctx) { copyFrom(ctx); }


//----------------- ConstDefValContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::ConstDefValContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

CACTParser::ConstExpContext* CACTParser::ConstDefValContext::constExp() {
  return getRuleContext<CACTParser::ConstExpContext>(0);
}

CACTParser::ConstDefValContext::ConstDefValContext(ConstDefContext *ctx) { copyFrom(ctx); }


CACTParser::ConstDefContext* CACTParser::constDef() {
  ConstDefContext *_localctx = _tracker.createInstance<ConstDefContext>(_ctx, getState());
  enterRule(_localctx, 8, CACTParser::RuleConstDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(106);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<ConstDefContext *>(_tracker.createInstance<CACTParser::ConstDefValContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(86);
      match(CACTParser::Ident);
      setState(87);
      match(CACTParser::T__2);
      setState(88);
      constExp();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<ConstDefContext *>(_tracker.createInstance<CACTParser::ConstDefArrayContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(89);
      match(CACTParser::Ident);
      setState(90);
      match(CACTParser::T__3);
      setState(91);
      match(CACTParser::IntConst);
      setState(92);
      match(CACTParser::T__4);
      setState(93);
      match(CACTParser::T__2);
      setState(94);
      match(CACTParser::T__5);
      setState(103);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CACTParser::BoolConst)
        | (1ULL << CACTParser::IntConst)
        | (1ULL << CACTParser::FloatConst)
        | (1ULL << CACTParser::DoubleConst))) != 0)) {
        setState(95);
        constExp();
        setState(100);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == CACTParser::T__0) {
          setState(96);
          match(CACTParser::T__0);
          setState(97);
          constExp();
          setState(102);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(105);
      match(CACTParser::T__6);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDeclContext ------------------------------------------------------------------

CACTParser::VarDeclContext::VarDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::BTypeContext* CACTParser::VarDeclContext::bType() {
  return getRuleContext<CACTParser::BTypeContext>(0);
}

std::vector<CACTParser::VarDefContext *> CACTParser::VarDeclContext::varDef() {
  return getRuleContexts<CACTParser::VarDefContext>();
}

CACTParser::VarDefContext* CACTParser::VarDeclContext::varDef(size_t i) {
  return getRuleContext<CACTParser::VarDefContext>(i);
}


size_t CACTParser::VarDeclContext::getRuleIndex() const {
  return CACTParser::RuleVarDecl;
}


CACTParser::VarDeclContext* CACTParser::varDecl() {
  VarDeclContext *_localctx = _tracker.createInstance<VarDeclContext>(_ctx, getState());
  enterRule(_localctx, 10, CACTParser::RuleVarDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(108);
    bType();
    setState(109);
    varDef();
    setState(114);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CACTParser::T__0) {
      setState(110);
      match(CACTParser::T__0);
      setState(111);
      varDef();
      setState(116);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(117);
    match(CACTParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDefContext ------------------------------------------------------------------

CACTParser::VarDefContext::VarDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::VarDefContext::getRuleIndex() const {
  return CACTParser::RuleVarDef;
}

void CACTParser::VarDefContext::copyFrom(VarDefContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- DefInitArrayContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::DefInitArrayContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

tree::TerminalNode* CACTParser::DefInitArrayContext::IntConst() {
  return getToken(CACTParser::IntConst, 0);
}

std::vector<CACTParser::ConstExpContext *> CACTParser::DefInitArrayContext::constExp() {
  return getRuleContexts<CACTParser::ConstExpContext>();
}

CACTParser::ConstExpContext* CACTParser::DefInitArrayContext::constExp(size_t i) {
  return getRuleContext<CACTParser::ConstExpContext>(i);
}

CACTParser::DefInitArrayContext::DefInitArrayContext(VarDefContext *ctx) { copyFrom(ctx); }


//----------------- DefArrayContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::DefArrayContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

tree::TerminalNode* CACTParser::DefArrayContext::IntConst() {
  return getToken(CACTParser::IntConst, 0);
}

CACTParser::DefArrayContext::DefArrayContext(VarDefContext *ctx) { copyFrom(ctx); }


//----------------- DefInitValContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::DefInitValContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

CACTParser::ConstExpContext* CACTParser::DefInitValContext::constExp() {
  return getRuleContext<CACTParser::ConstExpContext>(0);
}

CACTParser::DefInitValContext::DefInitValContext(VarDefContext *ctx) { copyFrom(ctx); }


//----------------- DefValContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::DefValContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

CACTParser::DefValContext::DefValContext(VarDefContext *ctx) { copyFrom(ctx); }


CACTParser::VarDefContext* CACTParser::varDef() {
  VarDefContext *_localctx = _tracker.createInstance<VarDefContext>(_ctx, getState());
  enterRule(_localctx, 12, CACTParser::RuleVarDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(144);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<VarDefContext *>(_tracker.createInstance<CACTParser::DefValContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(119);
      match(CACTParser::Ident);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<VarDefContext *>(_tracker.createInstance<CACTParser::DefArrayContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(120);
      match(CACTParser::Ident);
      setState(121);
      match(CACTParser::T__3);
      setState(122);
      match(CACTParser::IntConst);
      setState(123);
      match(CACTParser::T__4);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<VarDefContext *>(_tracker.createInstance<CACTParser::DefInitValContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(124);
      match(CACTParser::Ident);
      setState(125);
      match(CACTParser::T__2);
      setState(126);
      constExp();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<VarDefContext *>(_tracker.createInstance<CACTParser::DefInitArrayContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(127);
      match(CACTParser::Ident);
      setState(128);
      match(CACTParser::T__3);
      setState(129);
      match(CACTParser::IntConst);
      setState(130);
      match(CACTParser::T__4);
      setState(131);
      match(CACTParser::T__2);
      setState(132);
      match(CACTParser::T__5);
      setState(141);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CACTParser::BoolConst)
        | (1ULL << CACTParser::IntConst)
        | (1ULL << CACTParser::FloatConst)
        | (1ULL << CACTParser::DoubleConst))) != 0)) {
        setState(133);
        constExp();
        setState(138);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == CACTParser::T__0) {
          setState(134);
          match(CACTParser::T__0);
          setState(135);
          constExp();
          setState(140);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(143);
      match(CACTParser::T__6);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncDefContext ------------------------------------------------------------------

CACTParser::FuncDefContext::FuncDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::BlockContext* CACTParser::FuncDefContext::block() {
  return getRuleContext<CACTParser::BlockContext>(0);
}

CACTParser::FuncTypeContext* CACTParser::FuncDefContext::funcType() {
  return getRuleContext<CACTParser::FuncTypeContext>(0);
}

tree::TerminalNode* CACTParser::FuncDefContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

std::vector<CACTParser::FuncFParamContext *> CACTParser::FuncDefContext::funcFParam() {
  return getRuleContexts<CACTParser::FuncFParamContext>();
}

CACTParser::FuncFParamContext* CACTParser::FuncDefContext::funcFParam(size_t i) {
  return getRuleContext<CACTParser::FuncFParamContext>(i);
}


size_t CACTParser::FuncDefContext::getRuleIndex() const {
  return CACTParser::RuleFuncDef;
}


CACTParser::FuncDefContext* CACTParser::funcDef() {
  FuncDefContext *_localctx = _tracker.createInstance<FuncDefContext>(_ctx, getState());
  enterRule(_localctx, 14, CACTParser::RuleFuncDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(146);
    dynamic_cast<FuncDefContext *>(_localctx)->ret = funcType();
    setState(147);
    dynamic_cast<FuncDefContext *>(_localctx)->name = match(CACTParser::Ident);
    setState(148);
    match(CACTParser::T__7);
    setState(157);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::INT)
      | (1ULL << CACTParser::BOOL)
      | (1ULL << CACTParser::DOUBLE)
      | (1ULL << CACTParser::FLOAT))) != 0)) {
      setState(149);
      funcFParam();
      setState(154);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == CACTParser::T__0) {
        setState(150);
        match(CACTParser::T__0);
        setState(151);
        funcFParam();
        setState(156);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(159);
    match(CACTParser::T__8);
    setState(160);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncTypeContext ------------------------------------------------------------------

CACTParser::FuncTypeContext::FuncTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CACTParser::FuncTypeContext::VOID() {
  return getToken(CACTParser::VOID, 0);
}

tree::TerminalNode* CACTParser::FuncTypeContext::INT() {
  return getToken(CACTParser::INT, 0);
}

tree::TerminalNode* CACTParser::FuncTypeContext::FLOAT() {
  return getToken(CACTParser::FLOAT, 0);
}

tree::TerminalNode* CACTParser::FuncTypeContext::DOUBLE() {
  return getToken(CACTParser::DOUBLE, 0);
}

tree::TerminalNode* CACTParser::FuncTypeContext::BOOL() {
  return getToken(CACTParser::BOOL, 0);
}


size_t CACTParser::FuncTypeContext::getRuleIndex() const {
  return CACTParser::RuleFuncType;
}


CACTParser::FuncTypeContext* CACTParser::funcType() {
  FuncTypeContext *_localctx = _tracker.createInstance<FuncTypeContext>(_ctx, getState());
  enterRule(_localctx, 16, CACTParser::RuleFuncType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(162);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::INT)
      | (1ULL << CACTParser::BOOL)
      | (1ULL << CACTParser::DOUBLE)
      | (1ULL << CACTParser::FLOAT)
      | (1ULL << CACTParser::VOID))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncFParamContext ------------------------------------------------------------------

CACTParser::FuncFParamContext::FuncFParamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::BTypeContext* CACTParser::FuncFParamContext::bType() {
  return getRuleContext<CACTParser::BTypeContext>(0);
}

tree::TerminalNode* CACTParser::FuncFParamContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}


size_t CACTParser::FuncFParamContext::getRuleIndex() const {
  return CACTParser::RuleFuncFParam;
}


CACTParser::FuncFParamContext* CACTParser::funcFParam() {
  FuncFParamContext *_localctx = _tracker.createInstance<FuncFParamContext>(_ctx, getState());
  enterRule(_localctx, 18, CACTParser::RuleFuncFParam);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(164);
    bType();
    setState(165);
    match(CACTParser::Ident);
    setState(168);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CACTParser::T__3) {
      setState(166);
      match(CACTParser::T__3);
      setState(167);
      match(CACTParser::T__4);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

CACTParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CACTParser::BlockItemContext *> CACTParser::BlockContext::blockItem() {
  return getRuleContexts<CACTParser::BlockItemContext>();
}

CACTParser::BlockItemContext* CACTParser::BlockContext::blockItem(size_t i) {
  return getRuleContext<CACTParser::BlockItemContext>(i);
}


size_t CACTParser::BlockContext::getRuleIndex() const {
  return CACTParser::RuleBlock;
}


CACTParser::BlockContext* CACTParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 20, CACTParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(170);
    match(CACTParser::T__5);
    setState(174);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::T__1)
      | (1ULL << CACTParser::T__5)
      | (1ULL << CACTParser::T__7)
      | (1ULL << CACTParser::INT)
      | (1ULL << CACTParser::BOOL)
      | (1ULL << CACTParser::DOUBLE)
      | (1ULL << CACTParser::FLOAT)
      | (1ULL << CACTParser::WHILE)
      | (1ULL << CACTParser::BREAK)
      | (1ULL << CACTParser::CONTINUE)
      | (1ULL << CACTParser::IF)
      | (1ULL << CACTParser::RETURN)
      | (1ULL << CACTParser::CONST)
      | (1ULL << CACTParser::BoolConst)
      | (1ULL << CACTParser::ADD)
      | (1ULL << CACTParser::SUB)
      | (1ULL << CACTParser::NOT)
      | (1ULL << CACTParser::Ident)
      | (1ULL << CACTParser::IntConst)
      | (1ULL << CACTParser::FloatConst)
      | (1ULL << CACTParser::DoubleConst))) != 0)) {
      setState(171);
      blockItem();
      setState(176);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(177);
    match(CACTParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockItemContext ------------------------------------------------------------------

CACTParser::BlockItemContext::BlockItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::DeclContext* CACTParser::BlockItemContext::decl() {
  return getRuleContext<CACTParser::DeclContext>(0);
}

CACTParser::StmtContext* CACTParser::BlockItemContext::stmt() {
  return getRuleContext<CACTParser::StmtContext>(0);
}


size_t CACTParser::BlockItemContext::getRuleIndex() const {
  return CACTParser::RuleBlockItem;
}


CACTParser::BlockItemContext* CACTParser::blockItem() {
  BlockItemContext *_localctx = _tracker.createInstance<BlockItemContext>(_ctx, getState());
  enterRule(_localctx, 22, CACTParser::RuleBlockItem);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(181);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::INT:
      case CACTParser::BOOL:
      case CACTParser::DOUBLE:
      case CACTParser::FLOAT:
      case CACTParser::CONST: {
        enterOuterAlt(_localctx, 1);
        setState(179);
        decl();
        break;
      }

      case CACTParser::T__1:
      case CACTParser::T__5:
      case CACTParser::T__7:
      case CACTParser::WHILE:
      case CACTParser::BREAK:
      case CACTParser::CONTINUE:
      case CACTParser::IF:
      case CACTParser::RETURN:
      case CACTParser::BoolConst:
      case CACTParser::ADD:
      case CACTParser::SUB:
      case CACTParser::NOT:
      case CACTParser::Ident:
      case CACTParser::IntConst:
      case CACTParser::FloatConst:
      case CACTParser::DoubleConst: {
        enterOuterAlt(_localctx, 2);
        setState(180);
        stmt();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

CACTParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::StmtContext::getRuleIndex() const {
  return CACTParser::RuleStmt;
}

void CACTParser::StmtContext::copyFrom(StmtContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ExprStmtContext ------------------------------------------------------------------

CACTParser::ExpContext* CACTParser::ExprStmtContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}

CACTParser::ExprStmtContext::ExprStmtContext(StmtContext *ctx) { copyFrom(ctx); }


//----------------- WhileStmtContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::WhileStmtContext::WHILE() {
  return getToken(CACTParser::WHILE, 0);
}

CACTParser::WhileCondContext* CACTParser::WhileStmtContext::whileCond() {
  return getRuleContext<CACTParser::WhileCondContext>(0);
}

CACTParser::StmtContext* CACTParser::WhileStmtContext::stmt() {
  return getRuleContext<CACTParser::StmtContext>(0);
}

CACTParser::WhileStmtContext::WhileStmtContext(StmtContext *ctx) { copyFrom(ctx); }


//----------------- IfStmtContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::IfStmtContext::IF() {
  return getToken(CACTParser::IF, 0);
}

CACTParser::IfCondContext* CACTParser::IfStmtContext::ifCond() {
  return getRuleContext<CACTParser::IfCondContext>(0);
}

CACTParser::StmtContext* CACTParser::IfStmtContext::stmt() {
  return getRuleContext<CACTParser::StmtContext>(0);
}

CACTParser::IfStmtContext::IfStmtContext(StmtContext *ctx) { copyFrom(ctx); }


//----------------- BlockStmtContext ------------------------------------------------------------------

CACTParser::BlockContext* CACTParser::BlockStmtContext::block() {
  return getRuleContext<CACTParser::BlockContext>(0);
}

CACTParser::BlockStmtContext::BlockStmtContext(StmtContext *ctx) { copyFrom(ctx); }


//----------------- IfElseStmtContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::IfElseStmtContext::IF() {
  return getToken(CACTParser::IF, 0);
}

CACTParser::IfCondContext* CACTParser::IfElseStmtContext::ifCond() {
  return getRuleContext<CACTParser::IfCondContext>(0);
}

CACTParser::StmtContext* CACTParser::IfElseStmtContext::stmt() {
  return getRuleContext<CACTParser::StmtContext>(0);
}

CACTParser::ElseStmtContext* CACTParser::IfElseStmtContext::elseStmt() {
  return getRuleContext<CACTParser::ElseStmtContext>(0);
}

CACTParser::IfElseStmtContext::IfElseStmtContext(StmtContext *ctx) { copyFrom(ctx); }


//----------------- AssignStmtContext ------------------------------------------------------------------

CACTParser::LValContext* CACTParser::AssignStmtContext::lVal() {
  return getRuleContext<CACTParser::LValContext>(0);
}

CACTParser::ExpContext* CACTParser::AssignStmtContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}

CACTParser::AssignStmtContext::AssignStmtContext(StmtContext *ctx) { copyFrom(ctx); }


//----------------- BreakStmtContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::BreakStmtContext::BREAK() {
  return getToken(CACTParser::BREAK, 0);
}

CACTParser::BreakStmtContext::BreakStmtContext(StmtContext *ctx) { copyFrom(ctx); }


//----------------- ReturnStmtContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::ReturnStmtContext::RETURN() {
  return getToken(CACTParser::RETURN, 0);
}

CACTParser::ExpContext* CACTParser::ReturnStmtContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}

CACTParser::ReturnStmtContext::ReturnStmtContext(StmtContext *ctx) { copyFrom(ctx); }


//----------------- ContinueStmtContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::ContinueStmtContext::CONTINUE() {
  return getToken(CACTParser::CONTINUE, 0);
}

CACTParser::ContinueStmtContext::ContinueStmtContext(StmtContext *ctx) { copyFrom(ctx); }


CACTParser::StmtContext* CACTParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 24, CACTParser::RuleStmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(221);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::AssignStmtContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(183);
      lVal();
      setState(184);
      match(CACTParser::T__2);
      setState(185);
      exp();
      setState(186);
      match(CACTParser::T__1);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::ExprStmtContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(189);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CACTParser::T__7)
        | (1ULL << CACTParser::BoolConst)
        | (1ULL << CACTParser::ADD)
        | (1ULL << CACTParser::SUB)
        | (1ULL << CACTParser::NOT)
        | (1ULL << CACTParser::Ident)
        | (1ULL << CACTParser::IntConst)
        | (1ULL << CACTParser::FloatConst)
        | (1ULL << CACTParser::DoubleConst))) != 0)) {
        setState(188);
        exp();
      }
      setState(191);
      match(CACTParser::T__1);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::BlockStmtContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(192);
      block();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::IfStmtContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(193);
      match(CACTParser::IF);
      setState(194);
      match(CACTParser::T__7);
      setState(195);
      ifCond();
      setState(196);
      match(CACTParser::T__8);
      setState(197);
      stmt();
      break;
    }

    case 5: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::IfElseStmtContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(199);
      match(CACTParser::IF);
      setState(200);
      match(CACTParser::T__7);
      setState(201);
      ifCond();
      setState(202);
      match(CACTParser::T__8);
      setState(203);
      stmt();
      setState(204);
      elseStmt();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::WhileStmtContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(206);
      match(CACTParser::WHILE);
      setState(207);
      match(CACTParser::T__7);
      setState(208);
      whileCond();
      setState(209);
      match(CACTParser::T__8);
      setState(210);
      stmt();
      break;
    }

    case 7: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::BreakStmtContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(212);
      match(CACTParser::BREAK);
      setState(213);
      match(CACTParser::T__1);
      break;
    }

    case 8: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::ContinueStmtContext>(_localctx));
      enterOuterAlt(_localctx, 8);
      setState(214);
      match(CACTParser::CONTINUE);
      setState(215);
      match(CACTParser::T__1);
      break;
    }

    case 9: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::ReturnStmtContext>(_localctx));
      enterOuterAlt(_localctx, 9);
      setState(216);
      match(CACTParser::RETURN);
      setState(218);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CACTParser::T__7)
        | (1ULL << CACTParser::BoolConst)
        | (1ULL << CACTParser::ADD)
        | (1ULL << CACTParser::SUB)
        | (1ULL << CACTParser::NOT)
        | (1ULL << CACTParser::Ident)
        | (1ULL << CACTParser::IntConst)
        | (1ULL << CACTParser::FloatConst)
        | (1ULL << CACTParser::DoubleConst))) != 0)) {
        setState(217);
        exp();
      }
      setState(220);
      match(CACTParser::T__1);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElseStmtContext ------------------------------------------------------------------

CACTParser::ElseStmtContext::ElseStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CACTParser::ElseStmtContext::ELSE() {
  return getToken(CACTParser::ELSE, 0);
}

CACTParser::StmtContext* CACTParser::ElseStmtContext::stmt() {
  return getRuleContext<CACTParser::StmtContext>(0);
}


size_t CACTParser::ElseStmtContext::getRuleIndex() const {
  return CACTParser::RuleElseStmt;
}


CACTParser::ElseStmtContext* CACTParser::elseStmt() {
  ElseStmtContext *_localctx = _tracker.createInstance<ElseStmtContext>(_ctx, getState());
  enterRule(_localctx, 26, CACTParser::RuleElseStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(223);
    match(CACTParser::ELSE);
    setState(224);
    stmt();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpContext ------------------------------------------------------------------

CACTParser::ExpContext::ExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::AddExpContext* CACTParser::ExpContext::addExp() {
  return getRuleContext<CACTParser::AddExpContext>(0);
}

tree::TerminalNode* CACTParser::ExpContext::BoolConst() {
  return getToken(CACTParser::BoolConst, 0);
}


size_t CACTParser::ExpContext::getRuleIndex() const {
  return CACTParser::RuleExp;
}


CACTParser::ExpContext* CACTParser::exp() {
  ExpContext *_localctx = _tracker.createInstance<ExpContext>(_ctx, getState());
  enterRule(_localctx, 28, CACTParser::RuleExp);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(228);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(226);
      addExp(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(227);
      match(CACTParser::BoolConst);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfCondContext ------------------------------------------------------------------

CACTParser::IfCondContext::IfCondContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::CondContext* CACTParser::IfCondContext::cond() {
  return getRuleContext<CACTParser::CondContext>(0);
}


size_t CACTParser::IfCondContext::getRuleIndex() const {
  return CACTParser::RuleIfCond;
}


CACTParser::IfCondContext* CACTParser::ifCond() {
  IfCondContext *_localctx = _tracker.createInstance<IfCondContext>(_ctx, getState());
  enterRule(_localctx, 30, CACTParser::RuleIfCond);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(230);
    cond();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileCondContext ------------------------------------------------------------------

CACTParser::WhileCondContext::WhileCondContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::CondContext* CACTParser::WhileCondContext::cond() {
  return getRuleContext<CACTParser::CondContext>(0);
}


size_t CACTParser::WhileCondContext::getRuleIndex() const {
  return CACTParser::RuleWhileCond;
}


CACTParser::WhileCondContext* CACTParser::whileCond() {
  WhileCondContext *_localctx = _tracker.createInstance<WhileCondContext>(_ctx, getState());
  enterRule(_localctx, 32, CACTParser::RuleWhileCond);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(232);
    cond();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CondContext ------------------------------------------------------------------

CACTParser::CondContext::CondContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::LOrExpContext* CACTParser::CondContext::lOrExp() {
  return getRuleContext<CACTParser::LOrExpContext>(0);
}


size_t CACTParser::CondContext::getRuleIndex() const {
  return CACTParser::RuleCond;
}


CACTParser::CondContext* CACTParser::cond() {
  CondContext *_localctx = _tracker.createInstance<CondContext>(_ctx, getState());
  enterRule(_localctx, 34, CACTParser::RuleCond);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(234);
    lOrExp(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LValContext ------------------------------------------------------------------

CACTParser::LValContext::LValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CACTParser::LValContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

CACTParser::ExpContext* CACTParser::LValContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}


size_t CACTParser::LValContext::getRuleIndex() const {
  return CACTParser::RuleLVal;
}


CACTParser::LValContext* CACTParser::lVal() {
  LValContext *_localctx = _tracker.createInstance<LValContext>(_ctx, getState());
  enterRule(_localctx, 36, CACTParser::RuleLVal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(236);
    match(CACTParser::Ident);
    setState(241);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      setState(237);
      match(CACTParser::T__3);
      setState(238);
      exp();
      setState(239);
      match(CACTParser::T__4);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrimaryExpContext ------------------------------------------------------------------

CACTParser::PrimaryExpContext::PrimaryExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::ExpContext* CACTParser::PrimaryExpContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}

CACTParser::LValContext* CACTParser::PrimaryExpContext::lVal() {
  return getRuleContext<CACTParser::LValContext>(0);
}

tree::TerminalNode* CACTParser::PrimaryExpContext::BoolConst() {
  return getToken(CACTParser::BoolConst, 0);
}

CACTParser::NumberContext* CACTParser::PrimaryExpContext::number() {
  return getRuleContext<CACTParser::NumberContext>(0);
}


size_t CACTParser::PrimaryExpContext::getRuleIndex() const {
  return CACTParser::RulePrimaryExp;
}


CACTParser::PrimaryExpContext* CACTParser::primaryExp() {
  PrimaryExpContext *_localctx = _tracker.createInstance<PrimaryExpContext>(_ctx, getState());
  enterRule(_localctx, 38, CACTParser::RulePrimaryExp);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(250);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::T__7: {
        enterOuterAlt(_localctx, 1);
        setState(243);
        match(CACTParser::T__7);
        setState(244);
        exp();
        setState(245);
        match(CACTParser::T__8);
        break;
      }

      case CACTParser::Ident: {
        enterOuterAlt(_localctx, 2);
        setState(247);
        lVal();
        break;
      }

      case CACTParser::BoolConst: {
        enterOuterAlt(_localctx, 3);
        setState(248);
        match(CACTParser::BoolConst);
        break;
      }

      case CACTParser::IntConst:
      case CACTParser::FloatConst:
      case CACTParser::DoubleConst: {
        enterOuterAlt(_localctx, 4);
        setState(249);
        number();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumberContext ------------------------------------------------------------------

CACTParser::NumberContext::NumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CACTParser::NumberContext::IntConst() {
  return getToken(CACTParser::IntConst, 0);
}

tree::TerminalNode* CACTParser::NumberContext::FloatConst() {
  return getToken(CACTParser::FloatConst, 0);
}

tree::TerminalNode* CACTParser::NumberContext::DoubleConst() {
  return getToken(CACTParser::DoubleConst, 0);
}


size_t CACTParser::NumberContext::getRuleIndex() const {
  return CACTParser::RuleNumber;
}


CACTParser::NumberContext* CACTParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 40, CACTParser::RuleNumber);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(252);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::IntConst)
      | (1ULL << CACTParser::FloatConst)
      | (1ULL << CACTParser::DoubleConst))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryExpContext ------------------------------------------------------------------

CACTParser::UnaryExpContext::UnaryExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::UnaryExpContext::getRuleIndex() const {
  return CACTParser::RuleUnaryExp;
}

void CACTParser::UnaryExpContext::copyFrom(UnaryExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->name = ctx->name;
  this->cls = ctx->cls;
  this->elemwise = ctx->elemwise;
}

//----------------- FuncallContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::FuncallContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

CACTParser::FuncRParamsContext* CACTParser::FuncallContext::funcRParams() {
  return getRuleContext<CACTParser::FuncRParamsContext>(0);
}

CACTParser::FuncallContext::FuncallContext(UnaryExpContext *ctx) { copyFrom(ctx); }


//----------------- UnaryContext ------------------------------------------------------------------

CACTParser::UnaryExpContext* CACTParser::UnaryContext::unaryExp() {
  return getRuleContext<CACTParser::UnaryExpContext>(0);
}

tree::TerminalNode* CACTParser::UnaryContext::ADD() {
  return getToken(CACTParser::ADD, 0);
}

tree::TerminalNode* CACTParser::UnaryContext::SUB() {
  return getToken(CACTParser::SUB, 0);
}

tree::TerminalNode* CACTParser::UnaryContext::NOT() {
  return getToken(CACTParser::NOT, 0);
}

CACTParser::UnaryContext::UnaryContext(UnaryExpContext *ctx) { copyFrom(ctx); }


//----------------- PrimaryContext ------------------------------------------------------------------

CACTParser::PrimaryExpContext* CACTParser::PrimaryContext::primaryExp() {
  return getRuleContext<CACTParser::PrimaryExpContext>(0);
}

CACTParser::PrimaryContext::PrimaryContext(UnaryExpContext *ctx) { copyFrom(ctx); }


CACTParser::UnaryExpContext* CACTParser::unaryExp() {
  UnaryExpContext *_localctx = _tracker.createInstance<UnaryExpContext>(_ctx, getState());
  enterRule(_localctx, 42, CACTParser::RuleUnaryExp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(263);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<UnaryExpContext *>(_tracker.createInstance<CACTParser::PrimaryContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(254);
      primaryExp();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<UnaryExpContext *>(_tracker.createInstance<CACTParser::FuncallContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(255);
      match(CACTParser::Ident);
      setState(256);
      match(CACTParser::T__7);
      setState(258);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CACTParser::T__7)
        | (1ULL << CACTParser::BoolConst)
        | (1ULL << CACTParser::ADD)
        | (1ULL << CACTParser::SUB)
        | (1ULL << CACTParser::NOT)
        | (1ULL << CACTParser::Ident)
        | (1ULL << CACTParser::IntConst)
        | (1ULL << CACTParser::FloatConst)
        | (1ULL << CACTParser::DoubleConst))) != 0)) {
        setState(257);
        funcRParams();
      }
      setState(260);
      match(CACTParser::T__8);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<UnaryExpContext *>(_tracker.createInstance<CACTParser::UnaryContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(261);
      dynamic_cast<UnaryContext *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CACTParser::ADD)
        | (1ULL << CACTParser::SUB)
        | (1ULL << CACTParser::NOT))) != 0))) {
        dynamic_cast<UnaryContext *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(262);
      unaryExp();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncRParamsContext ------------------------------------------------------------------

CACTParser::FuncRParamsContext::FuncRParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CACTParser::ExpContext *> CACTParser::FuncRParamsContext::exp() {
  return getRuleContexts<CACTParser::ExpContext>();
}

CACTParser::ExpContext* CACTParser::FuncRParamsContext::exp(size_t i) {
  return getRuleContext<CACTParser::ExpContext>(i);
}


size_t CACTParser::FuncRParamsContext::getRuleIndex() const {
  return CACTParser::RuleFuncRParams;
}


CACTParser::FuncRParamsContext* CACTParser::funcRParams() {
  FuncRParamsContext *_localctx = _tracker.createInstance<FuncRParamsContext>(_ctx, getState());
  enterRule(_localctx, 44, CACTParser::RuleFuncRParams);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(265);
    exp();
    setState(270);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CACTParser::T__0) {
      setState(266);
      match(CACTParser::T__0);
      setState(267);
      exp();
      setState(272);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MulExpContext ------------------------------------------------------------------

CACTParser::MulExpContext::MulExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::UnaryExpContext* CACTParser::MulExpContext::unaryExp() {
  return getRuleContext<CACTParser::UnaryExpContext>(0);
}

CACTParser::MulExpContext* CACTParser::MulExpContext::mulExp() {
  return getRuleContext<CACTParser::MulExpContext>(0);
}

tree::TerminalNode* CACTParser::MulExpContext::MUL() {
  return getToken(CACTParser::MUL, 0);
}

tree::TerminalNode* CACTParser::MulExpContext::DIV() {
  return getToken(CACTParser::DIV, 0);
}

tree::TerminalNode* CACTParser::MulExpContext::MOD() {
  return getToken(CACTParser::MOD, 0);
}


size_t CACTParser::MulExpContext::getRuleIndex() const {
  return CACTParser::RuleMulExp;
}



CACTParser::MulExpContext* CACTParser::mulExp() {
   return mulExp(0);
}

CACTParser::MulExpContext* CACTParser::mulExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::MulExpContext *_localctx = _tracker.createInstance<MulExpContext>(_ctx, parentState);
  CACTParser::MulExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 46;
  enterRecursionRule(_localctx, 46, CACTParser::RuleMulExp, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(274);
    unaryExp();
    _ctx->stop = _input->LT(-1);
    setState(281);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<MulExpContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleMulExp);
        setState(276);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(277);
        dynamic_cast<MulExpContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << CACTParser::MUL)
          | (1ULL << CACTParser::DIV)
          | (1ULL << CACTParser::MOD))) != 0))) {
          dynamic_cast<MulExpContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(278);
        unaryExp(); 
      }
      setState(283);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- AddExpContext ------------------------------------------------------------------

CACTParser::AddExpContext::AddExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::MulExpContext* CACTParser::AddExpContext::mulExp() {
  return getRuleContext<CACTParser::MulExpContext>(0);
}

CACTParser::AddExpContext* CACTParser::AddExpContext::addExp() {
  return getRuleContext<CACTParser::AddExpContext>(0);
}

tree::TerminalNode* CACTParser::AddExpContext::ADD() {
  return getToken(CACTParser::ADD, 0);
}

tree::TerminalNode* CACTParser::AddExpContext::SUB() {
  return getToken(CACTParser::SUB, 0);
}


size_t CACTParser::AddExpContext::getRuleIndex() const {
  return CACTParser::RuleAddExp;
}



CACTParser::AddExpContext* CACTParser::addExp() {
   return addExp(0);
}

CACTParser::AddExpContext* CACTParser::addExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::AddExpContext *_localctx = _tracker.createInstance<AddExpContext>(_ctx, parentState);
  CACTParser::AddExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 48;
  enterRecursionRule(_localctx, 48, CACTParser::RuleAddExp, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(285);
    mulExp(0);
    _ctx->stop = _input->LT(-1);
    setState(292);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<AddExpContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleAddExp);
        setState(287);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(288);
        dynamic_cast<AddExpContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(_la == CACTParser::ADD

        || _la == CACTParser::SUB)) {
          dynamic_cast<AddExpContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(289);
        mulExp(0); 
      }
      setState(294);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- RelExpContext ------------------------------------------------------------------

CACTParser::RelExpContext::RelExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::AddExpContext* CACTParser::RelExpContext::addExp() {
  return getRuleContext<CACTParser::AddExpContext>(0);
}

tree::TerminalNode* CACTParser::RelExpContext::BoolConst() {
  return getToken(CACTParser::BoolConst, 0);
}

CACTParser::RelExpContext* CACTParser::RelExpContext::relExp() {
  return getRuleContext<CACTParser::RelExpContext>(0);
}

tree::TerminalNode* CACTParser::RelExpContext::LT() {
  return getToken(CACTParser::LT, 0);
}

tree::TerminalNode* CACTParser::RelExpContext::GT() {
  return getToken(CACTParser::GT, 0);
}

tree::TerminalNode* CACTParser::RelExpContext::LE() {
  return getToken(CACTParser::LE, 0);
}

tree::TerminalNode* CACTParser::RelExpContext::GE() {
  return getToken(CACTParser::GE, 0);
}


size_t CACTParser::RelExpContext::getRuleIndex() const {
  return CACTParser::RuleRelExp;
}



CACTParser::RelExpContext* CACTParser::relExp() {
   return relExp(0);
}

CACTParser::RelExpContext* CACTParser::relExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::RelExpContext *_localctx = _tracker.createInstance<RelExpContext>(_ctx, parentState);
  CACTParser::RelExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 50;
  enterRecursionRule(_localctx, 50, CACTParser::RuleRelExp, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(298);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
    case 1: {
      setState(296);
      addExp(0);
      break;
    }

    case 2: {
      setState(297);
      match(CACTParser::BoolConst);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(305);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<RelExpContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleRelExp);
        setState(300);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(301);
        dynamic_cast<RelExpContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << CACTParser::GT)
          | (1ULL << CACTParser::LT)
          | (1ULL << CACTParser::GE)
          | (1ULL << CACTParser::LE))) != 0))) {
          dynamic_cast<RelExpContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(302);
        addExp(0); 
      }
      setState(307);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- EqExpContext ------------------------------------------------------------------

CACTParser::EqExpContext::EqExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::RelExpContext* CACTParser::EqExpContext::relExp() {
  return getRuleContext<CACTParser::RelExpContext>(0);
}

CACTParser::EqExpContext* CACTParser::EqExpContext::eqExp() {
  return getRuleContext<CACTParser::EqExpContext>(0);
}

tree::TerminalNode* CACTParser::EqExpContext::EQUAL() {
  return getToken(CACTParser::EQUAL, 0);
}

tree::TerminalNode* CACTParser::EqExpContext::NOTEQUAL() {
  return getToken(CACTParser::NOTEQUAL, 0);
}


size_t CACTParser::EqExpContext::getRuleIndex() const {
  return CACTParser::RuleEqExp;
}



CACTParser::EqExpContext* CACTParser::eqExp() {
   return eqExp(0);
}

CACTParser::EqExpContext* CACTParser::eqExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::EqExpContext *_localctx = _tracker.createInstance<EqExpContext>(_ctx, parentState);
  CACTParser::EqExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 52;
  enterRecursionRule(_localctx, 52, CACTParser::RuleEqExp, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(309);
    relExp(0);
    _ctx->stop = _input->LT(-1);
    setState(316);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<EqExpContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleEqExp);
        setState(311);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(312);
        dynamic_cast<EqExpContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(_la == CACTParser::NOTEQUAL

        || _la == CACTParser::EQUAL)) {
          dynamic_cast<EqExpContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(313);
        relExp(0); 
      }
      setState(318);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- LAndExpContext ------------------------------------------------------------------

CACTParser::LAndExpContext::LAndExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::EqExpContext* CACTParser::LAndExpContext::eqExp() {
  return getRuleContext<CACTParser::EqExpContext>(0);
}

CACTParser::LAndExpContext* CACTParser::LAndExpContext::lAndExp() {
  return getRuleContext<CACTParser::LAndExpContext>(0);
}

tree::TerminalNode* CACTParser::LAndExpContext::AND() {
  return getToken(CACTParser::AND, 0);
}


size_t CACTParser::LAndExpContext::getRuleIndex() const {
  return CACTParser::RuleLAndExp;
}



CACTParser::LAndExpContext* CACTParser::lAndExp() {
   return lAndExp(0);
}

CACTParser::LAndExpContext* CACTParser::lAndExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::LAndExpContext *_localctx = _tracker.createInstance<LAndExpContext>(_ctx, parentState);
  CACTParser::LAndExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 54;
  enterRecursionRule(_localctx, 54, CACTParser::RuleLAndExp, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(320);
    eqExp(0);
    _ctx->stop = _input->LT(-1);
    setState(327);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<LAndExpContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleLAndExp);
        setState(322);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(323);
        dynamic_cast<LAndExpContext *>(_localctx)->op = match(CACTParser::AND);
        setState(324);
        eqExp(0); 
      }
      setState(329);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- LOrExpContext ------------------------------------------------------------------

CACTParser::LOrExpContext::LOrExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::LAndExpContext* CACTParser::LOrExpContext::lAndExp() {
  return getRuleContext<CACTParser::LAndExpContext>(0);
}

CACTParser::LOrExpContext* CACTParser::LOrExpContext::lOrExp() {
  return getRuleContext<CACTParser::LOrExpContext>(0);
}

tree::TerminalNode* CACTParser::LOrExpContext::OR() {
  return getToken(CACTParser::OR, 0);
}


size_t CACTParser::LOrExpContext::getRuleIndex() const {
  return CACTParser::RuleLOrExp;
}



CACTParser::LOrExpContext* CACTParser::lOrExp() {
   return lOrExp(0);
}

CACTParser::LOrExpContext* CACTParser::lOrExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::LOrExpContext *_localctx = _tracker.createInstance<LOrExpContext>(_ctx, parentState);
  CACTParser::LOrExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 56;
  enterRecursionRule(_localctx, 56, CACTParser::RuleLOrExp, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(331);
    lAndExp(0);
    _ctx->stop = _input->LT(-1);
    setState(338);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<LOrExpContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleLOrExp);
        setState(333);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(334);
        dynamic_cast<LOrExpContext *>(_localctx)->op = match(CACTParser::OR);
        setState(335);
        lAndExp(0); 
      }
      setState(340);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ConstExpContext ------------------------------------------------------------------

CACTParser::ConstExpContext::ConstExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::ConstExpContext::getRuleIndex() const {
  return CACTParser::RuleConstExp;
}

void CACTParser::ConstExpContext::copyFrom(ConstExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->name = ctx->name;
  this->cls = ctx->cls;
}

//----------------- ConstExpBoolConstContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::ConstExpBoolConstContext::BoolConst() {
  return getToken(CACTParser::BoolConst, 0);
}

CACTParser::ConstExpBoolConstContext::ConstExpBoolConstContext(ConstExpContext *ctx) { copyFrom(ctx); }


//----------------- ConstExpNumberContext ------------------------------------------------------------------

CACTParser::NumberContext* CACTParser::ConstExpNumberContext::number() {
  return getRuleContext<CACTParser::NumberContext>(0);
}

CACTParser::ConstExpNumberContext::ConstExpNumberContext(ConstExpContext *ctx) { copyFrom(ctx); }


CACTParser::ConstExpContext* CACTParser::constExp() {
  ConstExpContext *_localctx = _tracker.createInstance<ConstExpContext>(_ctx, getState());
  enterRule(_localctx, 58, CACTParser::RuleConstExp);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(343);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::IntConst:
      case CACTParser::FloatConst:
      case CACTParser::DoubleConst: {
        _localctx = dynamic_cast<ConstExpContext *>(_tracker.createInstance<CACTParser::ConstExpNumberContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(341);
        number();
        break;
      }

      case CACTParser::BoolConst: {
        _localctx = dynamic_cast<ConstExpContext *>(_tracker.createInstance<CACTParser::ConstExpBoolConstContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(342);
        match(CACTParser::BoolConst);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool CACTParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 23: return mulExpSempred(dynamic_cast<MulExpContext *>(context), predicateIndex);
    case 24: return addExpSempred(dynamic_cast<AddExpContext *>(context), predicateIndex);
    case 25: return relExpSempred(dynamic_cast<RelExpContext *>(context), predicateIndex);
    case 26: return eqExpSempred(dynamic_cast<EqExpContext *>(context), predicateIndex);
    case 27: return lAndExpSempred(dynamic_cast<LAndExpContext *>(context), predicateIndex);
    case 28: return lOrExpSempred(dynamic_cast<LOrExpContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool CACTParser::mulExpSempred(MulExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CACTParser::addExpSempred(AddExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CACTParser::relExpSempred(RelExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool CACTParser::eqExpSempred(EqExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CACTParser::lAndExpSempred(LAndExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CACTParser::lOrExpSempred(LOrExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 5: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> CACTParser::_decisionToDFA;
atn::PredictionContextCache CACTParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN CACTParser::_atn;
std::vector<uint16_t> CACTParser::_serializedATN;

std::vector<std::string> CACTParser::_ruleNames = {
  "compUnit", "decl", "constDecl", "bType", "constDef", "varDecl", "varDef", 
  "funcDef", "funcType", "funcFParam", "block", "blockItem", "stmt", "elseStmt", 
  "exp", "ifCond", "whileCond", "cond", "lVal", "primaryExp", "number", 
  "unaryExp", "funcRParams", "mulExp", "addExp", "relExp", "eqExp", "lAndExp", 
  "lOrExp", "constExp"
};

std::vector<std::string> CACTParser::_literalNames = {
  "", "','", "';'", "'='", "'['", "']'", "'{'", "'}'", "'('", "')'", "'int'", 
  "'bool'", "'double'", "'float'", "'while'", "'break'", "'continue'", "'if'", 
  "'else'", "'return'", "'void'", "'const'", "", "'true'", "'false'", "'+'", 
  "'-'", "'*'", "'/'", "'%'", "'!'", "'!='", "'=='", "'>'", "'<'", "'>='", 
  "'<='", "'&&'", "'||'"
};

std::vector<std::string> CACTParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "INT", "BOOL", "DOUBLE", "FLOAT", 
  "WHILE", "BREAK", "CONTINUE", "IF", "ELSE", "RETURN", "VOID", "CONST", 
  "BoolConst", "TRUE", "FALSE", "ADD", "SUB", "MUL", "DIV", "MOD", "NOT", 
  "NOTEQUAL", "EQUAL", "GT", "LT", "GE", "LE", "AND", "OR", "Ident", "IntConst", 
  "FloatConst", "DoubleConst", "NewLine", "WhiteSpace", "BlockComment", 
  "LineComment"
};

dfa::Vocabulary CACTParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> CACTParser::_tokenNames;

CACTParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x30, 0x15c, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x3, 0x2, 0x3, 0x2, 0x6, 0x2, 0x41, 0xa, 0x2, 0xd, 
    0x2, 0xe, 0x2, 0x42, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 
    0x49, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 
    0x4, 0x50, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x53, 0xb, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x7, 0x6, 0x65, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x68, 0xb, 0x6, 0x5, 
    0x6, 0x6a, 0xa, 0x6, 0x3, 0x6, 0x5, 0x6, 0x6d, 0xa, 0x6, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x73, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 
    0x76, 0xb, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x7, 
    0x8, 0x8b, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0x8e, 0xb, 0x8, 0x5, 0x8, 0x90, 
    0xa, 0x8, 0x3, 0x8, 0x5, 0x8, 0x93, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0x9b, 0xa, 0x9, 0xc, 0x9, 
    0xe, 0x9, 0x9e, 0xb, 0x9, 0x5, 0x9, 0xa0, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x5, 0xb, 0xab, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0xaf, 0xa, 0xc, 
    0xc, 0xc, 0xe, 0xc, 0xb2, 0xb, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 
    0xd, 0x5, 0xd, 0xb8, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0xc0, 0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0xdd, 0xa, 0xe, 0x3, 0xe, 
    0x5, 0xe, 0xe0, 0xa, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 
    0x10, 0x5, 0x10, 0xe7, 0xa, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x5, 0x14, 0xf4, 0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0xfd, 0xa, 0x15, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 
    0x17, 0x105, 0xa, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 
    0x10a, 0xa, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x7, 0x18, 0x10f, 
    0xa, 0x18, 0xc, 0x18, 0xe, 0x18, 0x112, 0xb, 0x18, 0x3, 0x19, 0x3, 0x19, 
    0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x7, 0x19, 0x11a, 0xa, 0x19, 
    0xc, 0x19, 0xe, 0x19, 0x11d, 0xb, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 
    0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x7, 0x1a, 0x125, 0xa, 0x1a, 0xc, 0x1a, 
    0xe, 0x1a, 0x128, 0xb, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 
    0x12d, 0xa, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x7, 0x1b, 0x132, 
    0xa, 0x1b, 0xc, 0x1b, 0xe, 0x1b, 0x135, 0xb, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 
    0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x7, 0x1c, 0x13d, 0xa, 0x1c, 
    0xc, 0x1c, 0xe, 0x1c, 0x140, 0xb, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 
    0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x7, 0x1d, 0x148, 0xa, 0x1d, 0xc, 0x1d, 
    0xe, 0x1d, 0x14b, 0xb, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
    0x3, 0x1e, 0x3, 0x1e, 0x7, 0x1e, 0x153, 0xa, 0x1e, 0xc, 0x1e, 0xe, 0x1e, 
    0x156, 0xb, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 0x15a, 0xa, 0x1f, 
    0x3, 0x1f, 0x2, 0x8, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x20, 0x2, 
    0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 
    0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 
    0x36, 0x38, 0x3a, 0x3c, 0x2, 0xa, 0x3, 0x2, 0xc, 0xf, 0x4, 0x2, 0xc, 
    0xf, 0x16, 0x16, 0x3, 0x2, 0x2a, 0x2c, 0x4, 0x2, 0x1b, 0x1c, 0x20, 0x20, 
    0x3, 0x2, 0x1d, 0x1f, 0x3, 0x2, 0x1b, 0x1c, 0x3, 0x2, 0x23, 0x26, 0x3, 
    0x2, 0x21, 0x22, 0x2, 0x16a, 0x2, 0x40, 0x3, 0x2, 0x2, 0x2, 0x4, 0x48, 
    0x3, 0x2, 0x2, 0x2, 0x6, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x8, 0x56, 0x3, 0x2, 
    0x2, 0x2, 0xa, 0x6c, 0x3, 0x2, 0x2, 0x2, 0xc, 0x6e, 0x3, 0x2, 0x2, 0x2, 
    0xe, 0x92, 0x3, 0x2, 0x2, 0x2, 0x10, 0x94, 0x3, 0x2, 0x2, 0x2, 0x12, 
    0xa4, 0x3, 0x2, 0x2, 0x2, 0x14, 0xa6, 0x3, 0x2, 0x2, 0x2, 0x16, 0xac, 
    0x3, 0x2, 0x2, 0x2, 0x18, 0xb7, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xdf, 0x3, 
    0x2, 0x2, 0x2, 0x1c, 0xe1, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xe6, 0x3, 0x2, 
    0x2, 0x2, 0x20, 0xe8, 0x3, 0x2, 0x2, 0x2, 0x22, 0xea, 0x3, 0x2, 0x2, 
    0x2, 0x24, 0xec, 0x3, 0x2, 0x2, 0x2, 0x26, 0xee, 0x3, 0x2, 0x2, 0x2, 
    0x28, 0xfc, 0x3, 0x2, 0x2, 0x2, 0x2a, 0xfe, 0x3, 0x2, 0x2, 0x2, 0x2c, 
    0x109, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x30, 0x113, 
    0x3, 0x2, 0x2, 0x2, 0x32, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x34, 0x12c, 0x3, 
    0x2, 0x2, 0x2, 0x36, 0x136, 0x3, 0x2, 0x2, 0x2, 0x38, 0x141, 0x3, 0x2, 
    0x2, 0x2, 0x3a, 0x14c, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x159, 0x3, 0x2, 0x2, 
    0x2, 0x3e, 0x41, 0x5, 0x4, 0x3, 0x2, 0x3f, 0x41, 0x5, 0x10, 0x9, 0x2, 
    0x40, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x40, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x41, 
    0x42, 0x3, 0x2, 0x2, 0x2, 0x42, 0x40, 0x3, 0x2, 0x2, 0x2, 0x42, 0x43, 
    0x3, 0x2, 0x2, 0x2, 0x43, 0x44, 0x3, 0x2, 0x2, 0x2, 0x44, 0x45, 0x7, 
    0x2, 0x2, 0x3, 0x45, 0x3, 0x3, 0x2, 0x2, 0x2, 0x46, 0x49, 0x5, 0x6, 
    0x4, 0x2, 0x47, 0x49, 0x5, 0xc, 0x7, 0x2, 0x48, 0x46, 0x3, 0x2, 0x2, 
    0x2, 0x48, 0x47, 0x3, 0x2, 0x2, 0x2, 0x49, 0x5, 0x3, 0x2, 0x2, 0x2, 
    0x4a, 0x4b, 0x7, 0x17, 0x2, 0x2, 0x4b, 0x4c, 0x5, 0x8, 0x5, 0x2, 0x4c, 
    0x51, 0x5, 0xa, 0x6, 0x2, 0x4d, 0x4e, 0x7, 0x3, 0x2, 0x2, 0x4e, 0x50, 
    0x5, 0xa, 0x6, 0x2, 0x4f, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x50, 0x53, 0x3, 
    0x2, 0x2, 0x2, 0x51, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 0x3, 0x2, 
    0x2, 0x2, 0x52, 0x54, 0x3, 0x2, 0x2, 0x2, 0x53, 0x51, 0x3, 0x2, 0x2, 
    0x2, 0x54, 0x55, 0x7, 0x4, 0x2, 0x2, 0x55, 0x7, 0x3, 0x2, 0x2, 0x2, 
    0x56, 0x57, 0x9, 0x2, 0x2, 0x2, 0x57, 0x9, 0x3, 0x2, 0x2, 0x2, 0x58, 
    0x59, 0x7, 0x29, 0x2, 0x2, 0x59, 0x5a, 0x7, 0x5, 0x2, 0x2, 0x5a, 0x6d, 
    0x5, 0x3c, 0x1f, 0x2, 0x5b, 0x5c, 0x7, 0x29, 0x2, 0x2, 0x5c, 0x5d, 0x7, 
    0x6, 0x2, 0x2, 0x5d, 0x5e, 0x7, 0x2a, 0x2, 0x2, 0x5e, 0x5f, 0x7, 0x7, 
    0x2, 0x2, 0x5f, 0x60, 0x7, 0x5, 0x2, 0x2, 0x60, 0x69, 0x7, 0x8, 0x2, 
    0x2, 0x61, 0x66, 0x5, 0x3c, 0x1f, 0x2, 0x62, 0x63, 0x7, 0x3, 0x2, 0x2, 
    0x63, 0x65, 0x5, 0x3c, 0x1f, 0x2, 0x64, 0x62, 0x3, 0x2, 0x2, 0x2, 0x65, 
    0x68, 0x3, 0x2, 0x2, 0x2, 0x66, 0x64, 0x3, 0x2, 0x2, 0x2, 0x66, 0x67, 
    0x3, 0x2, 0x2, 0x2, 0x67, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x68, 0x66, 0x3, 
    0x2, 0x2, 0x2, 0x69, 0x61, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6a, 0x3, 0x2, 
    0x2, 0x2, 0x6a, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x6d, 0x7, 0x9, 0x2, 
    0x2, 0x6c, 0x58, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x5b, 0x3, 0x2, 0x2, 0x2, 
    0x6d, 0xb, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x6f, 0x5, 0x8, 0x5, 0x2, 0x6f, 
    0x74, 0x5, 0xe, 0x8, 0x2, 0x70, 0x71, 0x7, 0x3, 0x2, 0x2, 0x71, 0x73, 
    0x5, 0xe, 0x8, 0x2, 0x72, 0x70, 0x3, 0x2, 0x2, 0x2, 0x73, 0x76, 0x3, 
    0x2, 0x2, 0x2, 0x74, 0x72, 0x3, 0x2, 0x2, 0x2, 0x74, 0x75, 0x3, 0x2, 
    0x2, 0x2, 0x75, 0x77, 0x3, 0x2, 0x2, 0x2, 0x76, 0x74, 0x3, 0x2, 0x2, 
    0x2, 0x77, 0x78, 0x7, 0x4, 0x2, 0x2, 0x78, 0xd, 0x3, 0x2, 0x2, 0x2, 
    0x79, 0x93, 0x7, 0x29, 0x2, 0x2, 0x7a, 0x7b, 0x7, 0x29, 0x2, 0x2, 0x7b, 
    0x7c, 0x7, 0x6, 0x2, 0x2, 0x7c, 0x7d, 0x7, 0x2a, 0x2, 0x2, 0x7d, 0x93, 
    0x7, 0x7, 0x2, 0x2, 0x7e, 0x7f, 0x7, 0x29, 0x2, 0x2, 0x7f, 0x80, 0x7, 
    0x5, 0x2, 0x2, 0x80, 0x93, 0x5, 0x3c, 0x1f, 0x2, 0x81, 0x82, 0x7, 0x29, 
    0x2, 0x2, 0x82, 0x83, 0x7, 0x6, 0x2, 0x2, 0x83, 0x84, 0x7, 0x2a, 0x2, 
    0x2, 0x84, 0x85, 0x7, 0x7, 0x2, 0x2, 0x85, 0x86, 0x7, 0x5, 0x2, 0x2, 
    0x86, 0x8f, 0x7, 0x8, 0x2, 0x2, 0x87, 0x8c, 0x5, 0x3c, 0x1f, 0x2, 0x88, 
    0x89, 0x7, 0x3, 0x2, 0x2, 0x89, 0x8b, 0x5, 0x3c, 0x1f, 0x2, 0x8a, 0x88, 
    0x3, 0x2, 0x2, 0x2, 0x8b, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8a, 0x3, 
    0x2, 0x2, 0x2, 0x8c, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x90, 0x3, 0x2, 
    0x2, 0x2, 0x8e, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x87, 0x3, 0x2, 0x2, 
    0x2, 0x8f, 0x90, 0x3, 0x2, 0x2, 0x2, 0x90, 0x91, 0x3, 0x2, 0x2, 0x2, 
    0x91, 0x93, 0x7, 0x9, 0x2, 0x2, 0x92, 0x79, 0x3, 0x2, 0x2, 0x2, 0x92, 
    0x7a, 0x3, 0x2, 0x2, 0x2, 0x92, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x92, 0x81, 
    0x3, 0x2, 0x2, 0x2, 0x93, 0xf, 0x3, 0x2, 0x2, 0x2, 0x94, 0x95, 0x5, 
    0x12, 0xa, 0x2, 0x95, 0x96, 0x7, 0x29, 0x2, 0x2, 0x96, 0x9f, 0x7, 0xa, 
    0x2, 0x2, 0x97, 0x9c, 0x5, 0x14, 0xb, 0x2, 0x98, 0x99, 0x7, 0x3, 0x2, 
    0x2, 0x99, 0x9b, 0x5, 0x14, 0xb, 0x2, 0x9a, 0x98, 0x3, 0x2, 0x2, 0x2, 
    0x9b, 0x9e, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x9c, 
    0x9d, 0x3, 0x2, 0x2, 0x2, 0x9d, 0xa0, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9c, 
    0x3, 0x2, 0x2, 0x2, 0x9f, 0x97, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xa0, 0x3, 
    0x2, 0x2, 0x2, 0xa0, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa2, 0x7, 0xb, 
    0x2, 0x2, 0xa2, 0xa3, 0x5, 0x16, 0xc, 0x2, 0xa3, 0x11, 0x3, 0x2, 0x2, 
    0x2, 0xa4, 0xa5, 0x9, 0x3, 0x2, 0x2, 0xa5, 0x13, 0x3, 0x2, 0x2, 0x2, 
    0xa6, 0xa7, 0x5, 0x8, 0x5, 0x2, 0xa7, 0xaa, 0x7, 0x29, 0x2, 0x2, 0xa8, 
    0xa9, 0x7, 0x6, 0x2, 0x2, 0xa9, 0xab, 0x7, 0x7, 0x2, 0x2, 0xaa, 0xa8, 
    0x3, 0x2, 0x2, 0x2, 0xaa, 0xab, 0x3, 0x2, 0x2, 0x2, 0xab, 0x15, 0x3, 
    0x2, 0x2, 0x2, 0xac, 0xb0, 0x7, 0x8, 0x2, 0x2, 0xad, 0xaf, 0x5, 0x18, 
    0xd, 0x2, 0xae, 0xad, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xb2, 0x3, 0x2, 0x2, 
    0x2, 0xb0, 0xae, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xb1, 0x3, 0x2, 0x2, 0x2, 
    0xb1, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xb0, 0x3, 0x2, 0x2, 0x2, 0xb3, 
    0xb4, 0x7, 0x9, 0x2, 0x2, 0xb4, 0x17, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb8, 
    0x5, 0x4, 0x3, 0x2, 0xb6, 0xb8, 0x5, 0x1a, 0xe, 0x2, 0xb7, 0xb5, 0x3, 
    0x2, 0x2, 0x2, 0xb7, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xb8, 0x19, 0x3, 0x2, 
    0x2, 0x2, 0xb9, 0xba, 0x5, 0x26, 0x14, 0x2, 0xba, 0xbb, 0x7, 0x5, 0x2, 
    0x2, 0xbb, 0xbc, 0x5, 0x1e, 0x10, 0x2, 0xbc, 0xbd, 0x7, 0x4, 0x2, 0x2, 
    0xbd, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xc0, 0x5, 0x1e, 0x10, 0x2, 0xbf, 
    0xbe, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xc1, 
    0x3, 0x2, 0x2, 0x2, 0xc1, 0xe0, 0x7, 0x4, 0x2, 0x2, 0xc2, 0xe0, 0x5, 
    0x16, 0xc, 0x2, 0xc3, 0xc4, 0x7, 0x13, 0x2, 0x2, 0xc4, 0xc5, 0x7, 0xa, 
    0x2, 0x2, 0xc5, 0xc6, 0x5, 0x20, 0x11, 0x2, 0xc6, 0xc7, 0x7, 0xb, 0x2, 
    0x2, 0xc7, 0xc8, 0x5, 0x1a, 0xe, 0x2, 0xc8, 0xe0, 0x3, 0x2, 0x2, 0x2, 
    0xc9, 0xca, 0x7, 0x13, 0x2, 0x2, 0xca, 0xcb, 0x7, 0xa, 0x2, 0x2, 0xcb, 
    0xcc, 0x5, 0x20, 0x11, 0x2, 0xcc, 0xcd, 0x7, 0xb, 0x2, 0x2, 0xcd, 0xce, 
    0x5, 0x1a, 0xe, 0x2, 0xce, 0xcf, 0x5, 0x1c, 0xf, 0x2, 0xcf, 0xe0, 0x3, 
    0x2, 0x2, 0x2, 0xd0, 0xd1, 0x7, 0x10, 0x2, 0x2, 0xd1, 0xd2, 0x7, 0xa, 
    0x2, 0x2, 0xd2, 0xd3, 0x5, 0x22, 0x12, 0x2, 0xd3, 0xd4, 0x7, 0xb, 0x2, 
    0x2, 0xd4, 0xd5, 0x5, 0x1a, 0xe, 0x2, 0xd5, 0xe0, 0x3, 0x2, 0x2, 0x2, 
    0xd6, 0xd7, 0x7, 0x11, 0x2, 0x2, 0xd7, 0xe0, 0x7, 0x4, 0x2, 0x2, 0xd8, 
    0xd9, 0x7, 0x12, 0x2, 0x2, 0xd9, 0xe0, 0x7, 0x4, 0x2, 0x2, 0xda, 0xdc, 
    0x7, 0x15, 0x2, 0x2, 0xdb, 0xdd, 0x5, 0x1e, 0x10, 0x2, 0xdc, 0xdb, 0x3, 
    0x2, 0x2, 0x2, 0xdc, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xde, 0x3, 0x2, 
    0x2, 0x2, 0xde, 0xe0, 0x7, 0x4, 0x2, 0x2, 0xdf, 0xb9, 0x3, 0x2, 0x2, 
    0x2, 0xdf, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xc2, 0x3, 0x2, 0x2, 0x2, 
    0xdf, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xdf, 
    0xd0, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xd8, 
    0x3, 0x2, 0x2, 0x2, 0xdf, 0xda, 0x3, 0x2, 0x2, 0x2, 0xe0, 0x1b, 0x3, 
    0x2, 0x2, 0x2, 0xe1, 0xe2, 0x7, 0x14, 0x2, 0x2, 0xe2, 0xe3, 0x5, 0x1a, 
    0xe, 0x2, 0xe3, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe7, 0x5, 0x32, 0x1a, 
    0x2, 0xe5, 0xe7, 0x7, 0x18, 0x2, 0x2, 0xe6, 0xe4, 0x3, 0x2, 0x2, 0x2, 
    0xe6, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xe7, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xe8, 
    0xe9, 0x5, 0x24, 0x13, 0x2, 0xe9, 0x21, 0x3, 0x2, 0x2, 0x2, 0xea, 0xeb, 
    0x5, 0x24, 0x13, 0x2, 0xeb, 0x23, 0x3, 0x2, 0x2, 0x2, 0xec, 0xed, 0x5, 
    0x3a, 0x1e, 0x2, 0xed, 0x25, 0x3, 0x2, 0x2, 0x2, 0xee, 0xf3, 0x7, 0x29, 
    0x2, 0x2, 0xef, 0xf0, 0x7, 0x6, 0x2, 0x2, 0xf0, 0xf1, 0x5, 0x1e, 0x10, 
    0x2, 0xf1, 0xf2, 0x7, 0x7, 0x2, 0x2, 0xf2, 0xf4, 0x3, 0x2, 0x2, 0x2, 
    0xf3, 0xef, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xf4, 
    0x27, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf6, 0x7, 0xa, 0x2, 0x2, 0xf6, 0xf7, 
    0x5, 0x1e, 0x10, 0x2, 0xf7, 0xf8, 0x7, 0xb, 0x2, 0x2, 0xf8, 0xfd, 0x3, 
    0x2, 0x2, 0x2, 0xf9, 0xfd, 0x5, 0x26, 0x14, 0x2, 0xfa, 0xfd, 0x7, 0x18, 
    0x2, 0x2, 0xfb, 0xfd, 0x5, 0x2a, 0x16, 0x2, 0xfc, 0xf5, 0x3, 0x2, 0x2, 
    0x2, 0xfc, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xfa, 0x3, 0x2, 0x2, 0x2, 
    0xfc, 0xfb, 0x3, 0x2, 0x2, 0x2, 0xfd, 0x29, 0x3, 0x2, 0x2, 0x2, 0xfe, 
    0xff, 0x9, 0x4, 0x2, 0x2, 0xff, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x100, 0x10a, 
    0x5, 0x28, 0x15, 0x2, 0x101, 0x102, 0x7, 0x29, 0x2, 0x2, 0x102, 0x104, 
    0x7, 0xa, 0x2, 0x2, 0x103, 0x105, 0x5, 0x2e, 0x18, 0x2, 0x104, 0x103, 
    0x3, 0x2, 0x2, 0x2, 0x104, 0x105, 0x3, 0x2, 0x2, 0x2, 0x105, 0x106, 
    0x3, 0x2, 0x2, 0x2, 0x106, 0x10a, 0x7, 0xb, 0x2, 0x2, 0x107, 0x108, 
    0x9, 0x5, 0x2, 0x2, 0x108, 0x10a, 0x5, 0x2c, 0x17, 0x2, 0x109, 0x100, 
    0x3, 0x2, 0x2, 0x2, 0x109, 0x101, 0x3, 0x2, 0x2, 0x2, 0x109, 0x107, 
    0x3, 0x2, 0x2, 0x2, 0x10a, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x10b, 0x110, 0x5, 
    0x1e, 0x10, 0x2, 0x10c, 0x10d, 0x7, 0x3, 0x2, 0x2, 0x10d, 0x10f, 0x5, 
    0x1e, 0x10, 0x2, 0x10e, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x112, 0x3, 
    0x2, 0x2, 0x2, 0x110, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x110, 0x111, 0x3, 
    0x2, 0x2, 0x2, 0x111, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x112, 0x110, 0x3, 0x2, 
    0x2, 0x2, 0x113, 0x114, 0x8, 0x19, 0x1, 0x2, 0x114, 0x115, 0x5, 0x2c, 
    0x17, 0x2, 0x115, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x116, 0x117, 0xc, 0x3, 
    0x2, 0x2, 0x117, 0x118, 0x9, 0x6, 0x2, 0x2, 0x118, 0x11a, 0x5, 0x2c, 
    0x17, 0x2, 0x119, 0x116, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x11d, 0x3, 0x2, 
    0x2, 0x2, 0x11b, 0x119, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x11c, 0x3, 0x2, 
    0x2, 0x2, 0x11c, 0x31, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x11b, 0x3, 0x2, 0x2, 
    0x2, 0x11e, 0x11f, 0x8, 0x1a, 0x1, 0x2, 0x11f, 0x120, 0x5, 0x30, 0x19, 
    0x2, 0x120, 0x126, 0x3, 0x2, 0x2, 0x2, 0x121, 0x122, 0xc, 0x3, 0x2, 
    0x2, 0x122, 0x123, 0x9, 0x7, 0x2, 0x2, 0x123, 0x125, 0x5, 0x30, 0x19, 
    0x2, 0x124, 0x121, 0x3, 0x2, 0x2, 0x2, 0x125, 0x128, 0x3, 0x2, 0x2, 
    0x2, 0x126, 0x124, 0x3, 0x2, 0x2, 0x2, 0x126, 0x127, 0x3, 0x2, 0x2, 
    0x2, 0x127, 0x33, 0x3, 0x2, 0x2, 0x2, 0x128, 0x126, 0x3, 0x2, 0x2, 0x2, 
    0x129, 0x12a, 0x8, 0x1b, 0x1, 0x2, 0x12a, 0x12d, 0x5, 0x32, 0x1a, 0x2, 
    0x12b, 0x12d, 0x7, 0x18, 0x2, 0x2, 0x12c, 0x129, 0x3, 0x2, 0x2, 0x2, 
    0x12c, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x133, 0x3, 0x2, 0x2, 0x2, 
    0x12e, 0x12f, 0xc, 0x4, 0x2, 0x2, 0x12f, 0x130, 0x9, 0x8, 0x2, 0x2, 
    0x130, 0x132, 0x5, 0x32, 0x1a, 0x2, 0x131, 0x12e, 0x3, 0x2, 0x2, 0x2, 
    0x132, 0x135, 0x3, 0x2, 0x2, 0x2, 0x133, 0x131, 0x3, 0x2, 0x2, 0x2, 
    0x133, 0x134, 0x3, 0x2, 0x2, 0x2, 0x134, 0x35, 0x3, 0x2, 0x2, 0x2, 0x135, 
    0x133, 0x3, 0x2, 0x2, 0x2, 0x136, 0x137, 0x8, 0x1c, 0x1, 0x2, 0x137, 
    0x138, 0x5, 0x34, 0x1b, 0x2, 0x138, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x139, 
    0x13a, 0xc, 0x3, 0x2, 0x2, 0x13a, 0x13b, 0x9, 0x9, 0x2, 0x2, 0x13b, 
    0x13d, 0x5, 0x34, 0x1b, 0x2, 0x13c, 0x139, 0x3, 0x2, 0x2, 0x2, 0x13d, 
    0x140, 0x3, 0x2, 0x2, 0x2, 0x13e, 0x13c, 0x3, 0x2, 0x2, 0x2, 0x13e, 
    0x13f, 0x3, 0x2, 0x2, 0x2, 0x13f, 0x37, 0x3, 0x2, 0x2, 0x2, 0x140, 0x13e, 
    0x3, 0x2, 0x2, 0x2, 0x141, 0x142, 0x8, 0x1d, 0x1, 0x2, 0x142, 0x143, 
    0x5, 0x36, 0x1c, 0x2, 0x143, 0x149, 0x3, 0x2, 0x2, 0x2, 0x144, 0x145, 
    0xc, 0x3, 0x2, 0x2, 0x145, 0x146, 0x7, 0x27, 0x2, 0x2, 0x146, 0x148, 
    0x5, 0x36, 0x1c, 0x2, 0x147, 0x144, 0x3, 0x2, 0x2, 0x2, 0x148, 0x14b, 
    0x3, 0x2, 0x2, 0x2, 0x149, 0x147, 0x3, 0x2, 0x2, 0x2, 0x149, 0x14a, 
    0x3, 0x2, 0x2, 0x2, 0x14a, 0x39, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x149, 0x3, 
    0x2, 0x2, 0x2, 0x14c, 0x14d, 0x8, 0x1e, 0x1, 0x2, 0x14d, 0x14e, 0x5, 
    0x38, 0x1d, 0x2, 0x14e, 0x154, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x150, 0xc, 
    0x3, 0x2, 0x2, 0x150, 0x151, 0x7, 0x28, 0x2, 0x2, 0x151, 0x153, 0x5, 
    0x38, 0x1d, 0x2, 0x152, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x153, 0x156, 0x3, 
    0x2, 0x2, 0x2, 0x154, 0x152, 0x3, 0x2, 0x2, 0x2, 0x154, 0x155, 0x3, 
    0x2, 0x2, 0x2, 0x155, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x156, 0x154, 0x3, 0x2, 
    0x2, 0x2, 0x157, 0x15a, 0x5, 0x2a, 0x16, 0x2, 0x158, 0x15a, 0x7, 0x18, 
    0x2, 0x2, 0x159, 0x157, 0x3, 0x2, 0x2, 0x2, 0x159, 0x158, 0x3, 0x2, 
    0x2, 0x2, 0x15a, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x23, 0x40, 0x42, 0x48, 0x51, 
    0x66, 0x69, 0x6c, 0x74, 0x8c, 0x8f, 0x92, 0x9c, 0x9f, 0xaa, 0xb0, 0xb7, 
    0xbf, 0xdc, 0xdf, 0xe6, 0xf3, 0xfc, 0x104, 0x109, 0x110, 0x11b, 0x126, 
    0x12c, 0x133, 0x13e, 0x149, 0x154, 0x159, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

CACTParser::Initializer CACTParser::_init;
