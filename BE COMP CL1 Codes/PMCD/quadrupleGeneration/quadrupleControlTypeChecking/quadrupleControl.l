%{
	#include "quadrupleControl.hpp"
	#include "y.tab.h"
	extern YYSTYPE yylval;
	#include<string.h>
	struct symtab record[10];
	int flag;
	int symTabCount = 0;
	int i;
	void addRecord(char *n);
%}

letter [a-zA-Z]

%%

"if" {return IF;}
"int"|"char"|"float"|"double" {strcpy(yylval.dname,yytext); return TYPE;}
[0-9]+ {strcpy(yylval.dname,yytext); return num;}
{letter} { addRecord(yytext); strcpy(yylval.attr.place,yytext); return ID;}
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
"," {return comma;}

%%

int yywrap() {
    return 1;
}

void addRecord(char *n){
	flag = 0;
	for(i=0; i<symTabCount; i++)
		if(strcmp(record[i].name, yytext) == 0)
			flag = 1;
	if(flag == 0){
		strcpy(record[symTabCount].name, n);
		symTabCount++;
	}
}
