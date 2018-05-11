%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Define the tokens that you want to return from your lex as follows
#define ID 256

#define PREPROC 258

#define LP 324
#define RP 325
#define LCURLY 326
#define RCURLY 327
#define LBRACKET 328
#define RBRACKET 329
#define COMMA 330
#define SEMICOLON 331

#define INTVAL 257
#define DBLVAL 260
#define FLTVAL 261
#define STRVAl 330
#define CHARVAL 263

#define VOID 264
#define SHORT 265
#define LONG 266
#define DOUBLE 267
#define CHAR 268
#define INT 269
#define FLOAT 270

#define EQ 271
#define LE 272
#define ADD 273
#define DIV 274
#define AND 275
#define BITXOR 276
#define LSH 277
#define SETADD 278
#define SETDIV 279
#define SETAND 280
#define SETRSH 281
#define NE 282
#define GT 283
#define SUB 284
#define MOD 285
#define BITOR 286
#define NOT 287
#define RSH 288
#define SETSUB 289
#define SETMOD 290
#define SETXOR 291
#define GE 292
#define LT 293
#define MUL 294
#define OR 295
#define BITAND 296
#define COM 297
#define SET 298
#define SETMUL 299
#define SETOR 300
#define SETLSH 301

#define RETURN 302
#define WHILE 303
#define SWITCH 304
#define DEFAULT 305
#define ELSE 306
#define BREAK 307
#define DO 308
#define FOR 309
#define CASE 310
#define IF 311
#define CONTINUE 312
#define GOTO 313

#define UNSIGNED 314
#define STRUCT 315
#define CONST 316
#define EXTERN 317
#define REGISTER 318
#define TYPEDEF 319
#define UNION 320
#define STATIC 321
#define AUTO 322
#define SIZEOF 323


%}

%option noyywrap nounput yylineno
%x COMMENT MULTILINE PREPRO

ID [a-zA-Z][a-zA-Z0-9_]*
PREPROC "#"

LP "("
RP ")"
LCURLY "{"
RCURLY "}"
LBRACKET "["
RBRACKET "]"
COMMA ","
SEMICOLON ";"

INTVAL [0-9]+|"0x"[0-9]+|"0"[0-9]+
DBLVAL [0-9]+"."[0-9]+
FLTVAL [0-9]+"."[0-9]+f
STRVAL \"(\\.|[^"])*\"
CHARVAL \'(\\.|[^'])*\'

VOID "void"
SHORT "short"
LONG "long"
DOUBLE "double"
CHAR "char"
INT "int"
FLOAT "float"

EQ "=="
LE "<="
ADD "+"
DIV "/"
AND "&&"
BITXOR "^"
LSH "<<"
SETADD "+="
SETDIV "/="
SETAND "&="
SETRSH ">>="
NE "!="
GT ">"
SUB "-"
MOD "%"
BITOR "|"
NOT "!"
RSH ">>"
SETSUB "-="
SETMOD "%="
SETXOR "^="
GE ">="
LT "<"
MUL "*"
OR "||"
BITAND "&"
COM "~"
SET "="
SETMUL "*="
SETOR "|="
SETLSH "<<="

RETURN "return"
WHILE "while"
SWITCH "switch"
DEFAULT "default"
ELSE "else"
BREAK "break"
DO "do"
FOR "for"
CASE "case"
IF "if"
CONTINUE "continue"
GOTO "goto"

UNSIGNED "unsigned"
STRUCT "struct"
CONST "const"
EXTERN "extern"
REGISTER "register"
TYPEDEF "typedef"
UNION "union"
STATIC "static"
AUTO "auto"
SIZEOF "sizeof"


%%
"//" {
    /****************************************
    * Matching with Single line comments in our
    * C code
    ******************************************/
    BEGIN COMMENT;
}

<COMMENT>[\n](\r)? {
    /****************************************
    * A new line indicates end of a single
    * line comment in C
    ****************************************/

    BEGIN 0;
}

<COMMENT>[ \t] {
    /****************************************
    * Lexer ignores the comments section
    * by Ignoring anything inside a comment
    ****************************************/

    BEGIN 0;
}

<COMMENT>. {
}

"/*" {
    /****************************************
    * Lexer ignores the comments section
    * by Ignoring anything inside a comment
    ****************************************/
    BEGIN MULTILINE;
}

<MULTILINE>"*/" {
    BEGIN 0;
}

<MULTILINE>[ \n\t\r] {

}

<MULTILINE>. {

}

"#" {
    /**************************************
    * If a Preprocessor Directive is matched, then
    * print PREPROC and return the token PREPROC
    **************************************/

    printf("PREPROC\n");
    BEGIN PREPRO;

}

<PREPRO>[\n] {

    BEGIN 0;
    return PREPROC;
}

<PREPRO>[ \t] {

}

<PREPRO>. {

}

"(" {

    printf("(\n");
    return LP;
}

{RP} {

    printf(")\n");
    return RP;
}

{LCURLY} {

    printf("{\n");
    return LCURLY;
}

{RCURLY} {

    printf("}\n");
    return RCURLY;
}

{LBRACKET} {

    printf("[\n");
    return LBRACKET;
}

{RBRACKET} {

    printf("]\n");
    return RBRACKET;
}

{COMMA} {

    printf(",\n");
    return COMMA;
}

{SEMICOLON} {

    printf(";\n");
    return SEMICOLON;
}

{INTVAL} {

    printf("INTVAL\n");
    return INTVAL;
}

{DBLVAL} {

    printf("DBLVAL\n");
    return DBLVAL;
}

{FLTVAL} {

    printf("FLTVAL\n");
    return FLTVAL;
}

{STRVAL} {

    printf("STRVAL\n");
}

{CHARVAL} {

    printf("CHARVAL\n");
    return CHARVAL;
}

{VOID} {

    printf("VOID\n");
    return VOID;
}

{SHORT} {

    printf("SHORT\n");
    return SHORT;
}

{LONG} {

    printf("LONG\n");
    return LONG;
}

{DOUBLE} {

    printf("DOUBLE\n");
    return DOUBLE;
}

{CHAR} {

    printf("CHAR\n");
    return CHAR;
}

{INT} {

    printf("INT\n");
    return INT;
}

{FLOAT} {

    printf("FLOAT\n");
    return FLOAT;
}

{EQ} {

    printf("EQ\n");
    return EQ;
}

{LE} {

    printf("LE\n");
    return LE;
}

{ADD} {

    printf("ADD\n");
    return ADD;
}

{DIV} {

    printf("DIV\n");
    return DIV;
}

{AND} {

    printf("AND\n");
    return AND;
}

{BITXOR} {

    printf("BITXOR\n");
    return BITXOR;
}

{LSH} {

    printf("LSH\n");
    return LSH;
}

{SETADD} {

    printf("SETADD\n");
    return SETADD;
}

{SETDIV} {

    printf("SETDIV\n");
    return SETDIV;
}

{SETAND} {

    printf("SETAND\n");
    return SETAND;
}

{SETRSH} {

    printf("SETRSH\n");
    return SETRSH;
}

{NE} {

    printf("NE\n");
    return NE;
}

{GT} {

    printf("GT\n");
    return GT;
}

{SUB} {

    printf("SUB\n");
    return SUB;
}

{MOD} {

    printf("MOD\n");
    return MOD;
}

{BITOR} {

    printf("BITOR\n");
    return BITOR;
}

{NOT} {

    printf("NOT\n");
    return NOT;
}

{RSH} {

    printf("RSH\n");
    return RSH;
}

{SETSUB} {

    printf("SETSUB\n");
    return SETSUB;
}

{SETMOD} {

    printf("SETMOD\n");
    return SETMOD;
}

{SETXOR} {

    printf("SETXOR\n");
    return SETXOR;
}

{GE} {

    printf("GE\n");
    return GE;
}

{LT} {

    printf("LT\n");
    return LT;
}

{MUL} {

    printf("MUL\n");
    return MUL;
}

{OR} {

    printf("OR\n");
    return OR;
}

{BITAND} {

    printf("BITAND\n");
    return BITAND;
}

{COM} {

    printf("COM\n");
    return COM;
}

{SET} {

    printf("SET\n");
    return SET;
}

{SETMUL} {

    printf("SETMUL\n");
    return SETMUL;
}

{SETOR} {

    printf("SETOR\n");
    return SETOR;
}

{SETLSH} {

    printf("SETLSH\n");
    return SETLSH;
}

{RETURN} {

    printf("RETURN\n");
    return RETURN;
}

{WHILE} {

    printf("WHILE\n");
    return WHILE;
}

{SWITCH} {

    printf("SWITCH\n");
    return SWITCH;
}

{DEFAULT} {

    printf("DEFAULT\n");
    return DEFAULT;
}

{ELSE} {

    printf("ELSE\n");
    return ELSE;
}

{BREAK} {

    printf("BREAK\n");
    return BREAK;
}

{DO} {

    printf("DO\n");
    return DO;
}

{FOR} {

    printf("FOR\n");
    return FOR;
}

{CASE} {

    printf("CASE\n");
    return CASE;
}

{IF} {

    printf("IF\n");
    return IF;
}

{CONTINUE} {

    printf("CONTINUE\n");
    return CONTINUE;
}

{GOTO} {

    printf("GOTO\n");
    return GOTO;
}

{UNSIGNED} {

    printf("UNSIGNED\n");
    return UNSIGNED;
}

{STRUCT} {

    printf("STRUCT\n");
    return STRUCT;
}

{CONST} {

    printf("CONST\n");
    return CONST;
}

{EXTERN} {

    printf("EXTERN\n");
    return EXTERN;
}

{REGISTER} {

    printf("REGISTER\n");
    return REGISTER;
}

{TYPEDEF} {

    printf("TYPEDEF\n");
    return TYPEDEF;
}

{UNION} {

    printf("UNION\n");
    return UNION;
}

"static" {

    printf("STATIC\n");
    return STATIC;
}

{AUTO} {

    printf("AUTO\n");
    return AUTO;
}

{SIZEOF} {

    printf("SIZEOF\n");
    return SIZEOF;
}


{ID} {
    /**************************************
    * If an identifier is matched, then
    * print ID and return a token ID
    **************************************/

    printf("ID\n");
    return ID;
}

[ \t\n\r]+ {

}

. { }

%%
int main(int argc, const char* argv[]) {
    /*Make a call to yylex() recursively. Whenever yylex() is called, it scans
    tokens from the global input file yyin (which defaults to stdin). It
    continues until it either reaches an end-of-file (at which point it returns
    the value 0) or one of its actions executes a return statement.*/

    while(yylex()) ;

    return 0;
}
