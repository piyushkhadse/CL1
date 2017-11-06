%{
	#include "y.tab.h"
	extern YYSTYPE yylval;
%}

letter [a-zA-Z]

%%

[0-9]+ {yylval.dname=(char)yytext[0]; return num;}
{letter} {yylval.dname=(char)yytext[0]; return name;}
"\n" { return 0; }
"+" {yylval.dname=(char)yytext[0];return plus;}
"-" {yylval.dname=(char)yytext[0];return minus;}
\* {yylval.dname=(char)yytext[0];return mul;}
"/" {yylval.dname=(char)yytext[0];return div;}
"(" {return ob;}
")" {return cb;}
"=" {yylval.dname=(char)yytext[0];return eq;}

%%

int yywrap() {
    return 1;
}
