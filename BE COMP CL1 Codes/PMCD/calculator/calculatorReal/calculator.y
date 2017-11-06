%{
	#include<stdio.h>
	#include<stdlib.h>
	extern int yylex();
	extern int yyparse();
%}


%union
{
	double dval;
	char dname[10];
}
%token<dval> num
%token<dname> name
%type<dval> E
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
%token eq

%%

S 	: name eq E	{ printf("Result: %s = %lf\n", $1, $3);}
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
	printf(" : %s\n", r);
	exit(1);
}

/* OUTPUT

student@B4L0106:~$ flex calculator.l 
student@B4L0106:~$ byacc -d calculator.y
student@B4L0106:~$ gcc -o calculator lex.yy.c y.tab.c
student@B4L0106:~$ ./calculator 
a = 2.0 + 3.0 * 3.0 / 2.0
Result: a = 6.500000
student@B4L0106:~$ 

*/
