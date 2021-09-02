grammar CACT;

// The language generated
options {
    language = Cpp;
}

@header {
    #include <vector>
    #include <string>
}

/********** Parser **********/
compUnit
    : (decl | funcDef)+ EOF
    ;

decl
    : constDecl
    | varDecl
    ;

constDecl
    : CONST bType constDef (',' constDef)* ';'
    ;

bType
    : INT
    | BOOL
    | FLOAT
    | DOUBLE
    ;

constDef
    : Ident '=' constExp										        # constDefVal
	| Ident '[' IntConst ']' '=' '{' (constExp ( ',' constExp)*)? '}'	# constDefArray
    ;

varDecl
    : bType varDef (',' varDef)* ';'
    ;

varDef
    : Ident																# defVal
	| Ident '[' IntConst ']'											# defArray
	| Ident '=' constExp											    # defInitVal
	| Ident '[' IntConst ']' '=' '{' (constExp ( ',' constExp)*)? '}'	# defInitArray
    ;

funcDef
    : ret = funcType name = Ident '(' (funcFParam (',' funcFParam)*)? ')' block
    ;

funcType
    : VOID
    | INT
    | FLOAT
    | DOUBLE
    | BOOL
    ;

funcFParam
    : bType Ident ('['']')?
    ;

block
    : '{' (blockItem)* '}'
    ;

blockItem
    : decl
    | stmt
    ;

stmt
    : lVal '=' exp ';'                           # assignStmt
    | (exp)? ';'                                 # exprStmt
    | block                                      # blockStmt
    | IF '(' ifCond ')' stmt                     # ifStmt
    | IF '(' ifCond ')' stmt elseStmt            # ifElseStmt
    | WHILE '(' whileCond ')' stmt               # whileStmt
    | BREAK ';'                                  # breakStmt
    | CONTINUE ';'                               # continueStmt
    | RETURN (exp)? ';'                          # returnStmt
    ;

elseStmt
    :ELSE stmt
    ;

exp
    locals[
	    std::string name,
	    int cls
	]
    : addExp
    | BoolConst
    ;

ifCond locals[
	std::string name,
	int cls,
	bool value
	]
    : cond
    ;

whileCond locals[
	std::string name,
	int cls,
	bool value
	]
    : cond
    ;

cond
    locals[
	    std::string name,
	    int cls,
	    bool value
	]
    : lOrExp
    ;

lVal
    locals[
	    std::string name,
	    int cls,
	    bool elemwise
	]
    : Ident ('[' exp ']')?
    ;

primaryExp
    locals[
	    std::string name,
	    int cls,
	    bool elemwise
	]
    : '(' exp ')'
    | lVal
    | BoolConst
    | number
    ;

number
    locals[
        std::string name,
	    int cls
    ]
    : IntConst
    | FloatConst
    | DoubleConst
    ;

unaryExp
    locals[
	    std::string name,
	    int cls,
	    bool elemwise
	]
    : primaryExp                       # primary
    | Ident '(' (funcRParams)? ')'     # funcall
    | op=(ADD | SUB | NOT) unaryExp    # unary
    ;

funcRParams
    : exp (',' exp)*
    ;

mulExp
    locals[
	    std::string name,
	    int cls,
	    bool elemwise
	]
    : unaryExp
    | mulExp op=(MUL | DIV | MOD) unaryExp
    ;

addExp
    locals[
	    std::string name,
	    int cls,
	    bool elemwise
	]
    : mulExp
    | addExp op=(ADD | SUB) mulExp
    ;

relExp
    locals[
	    std::string name,
	    int cls,
	    bool value
	]
    : addExp 
    | relExp op=(LT | GT | LE | GE) addExp 
    | BoolConst
    ;

eqExp
    locals[
	    std::string name,
	    int cls,
	    bool value
	]
    : relExp
    | eqExp op=(EQUAL | NOTEQUAL) relExp
    ;

lAndExp
    locals[
	    std::string name,
	    int cls,
	    bool value
	]
    : eqExp
    | lAndExp op=AND eqExp
    ;

lOrExp
    locals[
	    std::string name,
	    int cls,
	    bool value
	]
    : lAndExp
    | lOrExp op=OR lAndExp
    ;

constExp
    locals[
        std::string name,
	    int cls
    ]
    : number        # constExpNumber
    | BoolConst     # constExpBoolConst
    ;


/********** Lexer **********/
INT: 'int';
BOOL: 'bool';
DOUBLE: 'double';
FLOAT: 'float';
WHILE: 'while';
BREAK: 'break';
CONTINUE: 'continue';
IF: 'if';
ELSE: 'else';
RETURN: 'return';
VOID: 'void';
CONST: 'const';
BoolConst: TRUE | FALSE;
TRUE: 'true';
FALSE: 'false';

ADD: '+';
SUB: '-';
MUL: '*';
DIV: '/';
MOD: '%';	

NOT: '!';

NOTEQUAL: '!=';
EQUAL:'==';
GT:'>';
LT:'<';
GE:'>=';
LE:'<=';

AND: '&&';
OR: '||';

Ident
    : IdentNondigit [a-zA-Z_0-9]*
    ;

fragment
IdentNondigit
    : [a-zA-Z_]
    ;

fragment
Digit
    : [0-9]
    ;

IntConst
    : DecimalConst 
    | OctalConst
    | HexadecimalConst
    ;

fragment
DecimalConst
    : '0'
    | NonzeroDigit Digit*
    ;

fragment
OctalConst
    : '0' OctalDigit+
    ;

fragment
HexadecimalConst
    : HexadecimalPrefix HexadecimalDigit+
    ;

fragment
NonzeroDigit
    : [1-9]
    ;

fragment
OctalDigit
    : [0-7]
    ;

fragment
HexadecimalPrefix
    : '0x'
    | '0X'
    ;

fragment
HexadecimalDigit
    : [0-9a-fA-F]
    ;

FloatConst
    : DoubleConst FloatingSuffix
    ;

fragment
FloatingSuffix
    : 'f' | 'F'
    ;

DoubleConst
    : FractionalConstant ExponentPart?
    | DigitSequence ExponentPart
    ;

fragment
FractionalConstant
    : DigitSequence? '.' DigitSequence
    | DigitSequence '.'
    ;

fragment
ExponentPart
    : 'e' Sign? DigitSequence
    | 'E' Sign? DigitSequence
    ;

fragment
Sign
    : '+' | '-'
    ;

fragment
DigitSequence
    : Digit+
    ;

NewLine
    : ('\r' '\n'? | '\n') 
      -> skip
    ;

WhiteSpace
    : [ \t]+ 
      -> skip
    ;

BlockComment
    : '/*' .*? '*/'
      -> skip
    ;

LineComment
    : '//' ~[\r\n]*
      -> skip
    ;
