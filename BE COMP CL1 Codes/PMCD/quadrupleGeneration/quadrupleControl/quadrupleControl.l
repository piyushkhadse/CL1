%{
	#include "quadrupleControl.hpp"
	#include "y.tab.h"
	extern YYSTYPE yylval;
	#include<string.h>
%}

letter [a-zA-Z]

%%

"if" {return IF;}
[0-9]+ {strcpy(yylval.dname,yytext); return num;}
{letter} { strcpy(yylval.attr.place,yytext); return ID;}
"\n" { return 0; }
"+" {strcpy(yylval.dname,yytext); return plus;}
"-" {strcpy(yylval.dname,yytext); return minus;}
"*" {strcpy(yylval.dname,yytext); return mul;}
"/" {strcpy(yylval.dname,yytext); return div;}
"(" {return ob;}
")" {return cb;}
"{" {return ocb;}
"}" {return ccb;}
"=" {strcpy(yylval.dname,yytext); return eq;}
";" {return sc;}
"<"|">"|">="|"<="|"==" {strcpy(yylval.dname,yytext); return RELOP;}

%%

int yywrap() {
    return 1;
}
