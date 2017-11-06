%{
	#include "y.tab.h"
	extern YYSTYPE yylval;
	#include<string.h>
%}

letter [a-zA-Z]+

%%

[0-9]+|[0-9]+\.[0-9]+ {yylval.dval = atof(yytext); return num;}
{letter} {strcpy(yylval.dname,yytext); return name;}
"\n" { return 0; }
" " { printf(""); }
"+" {return plus;}
"-" {return minus;}
\* {return mul;}
"/" {return div;}
"(" {return ob;}
")" {return cb;}
"=" {return eq;}

%%

int yywrap() {
    return 1;
}
