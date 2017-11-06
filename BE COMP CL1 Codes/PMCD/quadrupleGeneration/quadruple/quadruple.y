%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	extern int yylex();
	extern int yyparse();
	int i, t=0;char buffer[5];
	struct Q{
		char op;
		char opr1;
		char opr2;
		char result;
	} q[10];
	int count = 0;
	char temp='A';
%}


%union
{
	char dname;
}
%token<dname> num
%token<dname> name
%type<dname> E
%start S
%token<dname> plus
%token<dname> minus
%token<dname> mul
%token<dname> div
%token ob
%token cb
%token<dname> eq
%left plus minus
%left mul div
%left ob cb


%%

S 	: name eq E	{ addQF($2, $3, '-', $1); }
	;

E	: E plus E	{ $$ = addQ($2, $1, $3, temp); temp++; }
	| E minus E	{ $$ = addQ($2, $1, $3, temp); temp++; }
	| E mul E	{ $$ = addQ($2, $1, $3, temp); temp++; }
	| E div E	{ $$ = addQ($2,$1, $3, temp); temp++; }
	| ob E cb	{ $$ = $2; }
	| num		{ $$ = $1; }
	| name		{ $$ = $1; }
	;
	
%%

int main(){
	printf("Enter Expression: ");
	yyparse();
	displayQuadruple();
	return 0;
}

char addQ(char op, char opr1, char opr2, char result){
	q[count].op = op;
	q[count].opr1 = opr1;
	q[count].opr2 = opr2;
	q[count].result = result;
	count++;
	return temp;
}

void addQF(char op, char opr1, char opr2, char result){
	q[count].op = op;
	q[count].opr1 = opr1;
	q[count].opr2 = opr2;
	q[count].result = result;
	count++;
}

displayQuadruple(){
	printf("\t--------------------------------------------\n");
	printf("\t| %7s | %7s  | %7s | %7s |\n","Operation","Arg 1","Arg 2", "Result");
	printf("\t--------------------------------------------\n");
	for(i=0; i<count; i++)
		printf("\t| %9c | %8c | %7c | %7c |\n", q[i].op, q[i].opr1, q[i].opr2, q[i].result);
	printf("\t--------------------------------------------\n");
}

int yyerror(char *r){
	printf(" : %s\n", r);
	exit(1);
}


/*
OUTPUT

student@B4L0106:~$ flex quadruple.l
student@B4L0106:~$ byacc -d quadruple.y
student@B4L0106:~$ gcc -o quadruple lex.yy.c y.tab.c
student@B4L0106:~$ ./quadruple 
Enter Expression: a=b+c*d/e
	--------------------------------------------
	| Operation |   Arg 1  |   Arg 2 |  Result |
	--------------------------------------------
	|         * |        c |       d |       A |
	|         / |        A |       e |       B |
	|         + |        b |       B |       C |
	|         = |        C |       - |       a |
	--------------------------------------------
student@B4L0106:~$ 

*/
