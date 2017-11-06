%{
	#include<stdio.h>
	#include<stdlib.h>
	extern int yylex();
	extern int yyparse();
%}

%token num
%start S
%left plus minus
%left mul div
%left ob cb
%token plus
%token minus
%token mul
%token div
%token ob
%token cb

%%

S 	: E		{ printf("Result: %d\n", $1);}
	;
	
E	: E plus E	{ $$ = $1 + $3; }
	| E minus E	{ $$ = $1 - $3; }
	| E mul E	{ $$ = $1 * $3; }
	| E div E	{ $$ = $1 / $3; }
	| num		{ $$ = $1; }
	| ob E cb	{ $$ = $2; }
	;
	
%%

int main(){

	yyparse();
	return 0;
	
}

int yyerror(char *r){
	printf(" : %s", r);
	exit(1);
}

/* OUTPUT

student@B4L0106:~$ flex calculator.l 
student@B4L0106:~$ byacc -d calculator.y
student@B4L0106:~$ gcc -o calculator lex.yy.c y.tab.c
student@B4L0106:~$ ./calculator 
2 + 3 * 5 + 4 / 2 - 1
Result: 18
student@B4L0106:~$ 

*/
