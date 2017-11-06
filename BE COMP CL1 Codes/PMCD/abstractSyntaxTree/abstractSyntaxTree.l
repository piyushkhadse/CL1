%{
	#include "y.tab.h"
	extern YYSTYPE yylval;
	#include<string.h>
	#include "abstractSyntaxTree.h"
%}

letter [a-zA-Z]+

%%

{letter}|[0-9]+ {strcpy(yylval.dname ,yytext); return id;}
"\n" { return 0; }
" " { printf(""); }
"+" {strcpy(yylval.dname ,yytext); return plus;}
"-" {strcpy(yylval.dname ,yytext); return minus;}
\* {strcpy(yylval.dname ,yytext); return mul;}
"/" {strcpy(yylval.dname ,yytext); return div;}
"(" {return ob;}
")" {return cb;}
"=" {strcpy(yylval.dname ,yytext); return eq;}

%%

int yywrap() {
    return 1;
}
