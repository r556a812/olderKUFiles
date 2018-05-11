%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylineno;
int yydebug = 1;
char* lastFunction = "";
extern void yyerror( char* );
extern int yylex();
%}

/*********************************************************
 ********************************************************/
%union {
    char* id;
}

%token <id> ID
%token INTVAL
%token STRVAL
%token CHARVAL
%token DBLVAL
%token FLTVAL
%token EQ
%token NE
%token GE
%token LE
%token GT
%token LT
%token ADD
%token SUB
%token MUL
%token DIV
%token MOD
%token LSH
%token RSH
%token BITAND
%token BITOR
%token BITXOR
%token VOID
%token CHAR
%token SHORT
%token INT
%token LONG
%token FLOAT
%token DOUBLE


%start top

%%

/*********************************************************
 * The top level parsing rule, as set using the %start
 * directive above.
 ********************************************************/
top :
|function top


/*This rule matches a  function in C Program*/
function : func_signature '{' func_body '}'

/*This rule matches a function signature such as int main( int argc, char *argv[] )*/
func_signature : type ID '(' args ')' { printf("%s", $2); printf(";\n"); lastFunction = $2;}

func_body :
          | declaration func_body
          | statement func_body

declaration : type ID ';'

statement :
          | ID '=' expr ';'
          | return expr ';'
          | 'if' '(' expr ')' statement 'else' statement
          | 'if' '(' expr ')' statement
          | 'while' '(' expr ')' statement

/*********************************************************
 * An example rule used to parse arguments to a
 * function call. The arguments to a function call
 * can either be nothing, one parameter, or multiple
 * parameters separated by commas.
 ********************************************************/
args : /* empty rule */
     | expr
     | expr ',' args

/*********************************************************
 * An example rule used to parse a single expression.
 * Currently this rule parses only an integer value
 * but you should modify the rule to parse the required
 * expressions.
 ********************************************************/
expr : INTVAL
     | STRVAL
     | CHARVAL
     | DBLVAL
     | FLTVAl
     | ID
     | ID '(' args ')'
     | expr op expr

op : MUL
   | DIV
   | MOD
   | op2

op2 : ADD
    | SUB
    | op3

op3 : LS
    | RSH
    | op4

op4 : LT
    | LE
    | GT
    | GE
    | op5

op5 : EQ
    | NE
    | op6

op6 : BITAND
    | op7

op7 : BITXOR
    | op8

op8 : BITOR 

type : VOID
     | CHAR
     | SHORT
     | INT
     | LONG
     | FLOAT
     | DOUBLE

%%

/*********************************************************
 * This method is invoked by the parser whenever an
 * error is encountered during parsing; just print
 * the error to stderr.
 ********************************************************/
void yyerror( char *err ) {
    fprintf( stderr, "at line %d: %s\n", yylineno, err );
}

/*********************************************************
 * This is the main function for the function call
 * graph program. We invoke the parser and return the
 * error/success code generated by it.
 ********************************************************/
int main( int argc, const char *argv[] ) {
    printf( "digraph funcgraph {\n" );
    int res = yyparse();
    printf( "}\n" );

    return res;
}
