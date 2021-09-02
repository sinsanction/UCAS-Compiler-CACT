
    #include <vector>
    #include <string>


// Generated from /home/compiler15/compiler/grammar/CACT.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"




class  CACTLexer : public antlr4::Lexer {
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

  CACTLexer(antlr4::CharStream *input);
  ~CACTLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

