%{
	#include "quadrupleControl.hpp"
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	extern int yylex();
	extern int yyparse();
	int i, t=0;char buffer[5];
	struct Q q[10];
	
	int count = 0;
	char glbChar[10];
	
	int curTemp = 1;
	char temp[10];
	
	extern int symTabCount;
	extern struct symtab record[10];
%}


%union
{
	char dname[10];
	int quad;
	struct nextList *nextListO;
	struct parseTreeNode attr;
	char dataType[10];
}
%start Sdash

%token IF
%token<dname> RELOP
%token<dname> num
%token<dname> plus
%token<dname> minus
%token<dname> mul
%token<dname> div
%token ob
%token cb
%token ocb
%token ccb
%token sc
%token<dname> eq
%token<dataType> TYPE
%token comma
%token<attr> ID

%type<dataType> IDLIST
%type<nextListO> S
%type<attr> E

%type<quad> M
%type<nextListO> SN

%left plus minus
%left mul div
%left ob cb

%%

Sdash	: S
	;

S 	: IF ob E cb M ocb SN ccb	{ backpatch($3.trueList, $5);
					$$ = merge($3.falseList, $7); }
	| DECL sc { $$ = NULL; }
	| S S
	;
	
DECL	: TYPE IDLIST	{ strcpy($2, $1); }
	;

IDLIST	: IDLIST comma ID { strcpy($1, $<dataType>0); addType($3.place, $1); }
	| ID { strcpy($$, $<dataType>0); addType($1.place, $$); }
	;

E	: ID RELOP ID	{getType($1.place); strcpy($1.type, glbChar);
			getType($3.place); strcpy($3.type, glbChar);
			if(!strcmp($1.type,$3.type)){
				$$.trueList = makeList(count);
				$$.falseList = makeList(count+1);
				addQ($2, $1.place, $3.place, "goto(_)");
				addQ("#","#","#","goto(_)");
			}else {printf("\nType mismatch in statement for (%s %s %s)\n",$1.place, $2, $3.place);
				exit(1);}  }
	| E plus E	{ if(strcmp($1.type,$3.type)){
				printf("\nType mismatch in statement for (%s %s %s)\n",$1.place, $2, $3.place);
				exit(1);
			} newTemp(); strcpy($$.place, temp); addQ($2, $1.place, $3.place, temp); }
	| E minus E	{ if(strcmp($1.type,$3.type)){
				printf("\nType mismatch in statement for (%s %s %s)\n",$1.place, $2, $3.place);
				exit(1);
			} newTemp(); strcpy($$.place, temp); addQ($2, $1.place, $3.place, temp); }
	| E mul E	{ if(strcmp($1.type,$3.type)){
				printf("\nType mismatch in statement for (%s %s %s)\n",$1.place, $2, $3.place);
				exit(1);
			} newTemp(); strcpy($$.place, temp); addQ($2, $1.place, $3.place, temp); }
	| E div E	{ if(strcmp($1.type,$3.type)){
				printf("\nType mismatch in statement for (%s %s %s)\n",$1.place, $2, $3.place);
				exit(1);
			} newTemp(); strcpy($$.place, temp); addQ($2,$1.place, $3.place, temp); }
	| ob E cb	{ strcpy($$.place, $2.place); }
	| ID		{ getType($1.place); strcpy($$.place, $1.place); strcpy($$.type, glbChar); }
	| num		{ strcpy($$.place, $1); }
	;
	
M	: { $$ = count; }	
	;

SN	: ID eq E sc	{ addQ($2, $3.place, "#", $1.place); }
	| S		{$$ = $1;}
	| SN SN
	;
%%

int main(){
	printf("Enter Expression: ");
	yyparse();
	displayQuadruple();
	displaySymTab();
	return 0;
}

void addQ(char *op, char *opr1, char *opr2, char *result){
	strcpy(q[count].op, op);
	strcpy(q[count].opr1, opr1);
	strcpy(q[count].opr2, opr2);
	strcpy(q[count].result, result);
	count++;
}


displayQuadruple(){
	printf("\t--------------------------------------------\n");
	printf("\t| %7s | %7s  | %7s | %7s |\n","Operation","Arg 1","Arg 2", "Result");
	printf("\t--------------------------------------------\n");
	for(i=0; i<count; i++)
		printf("\t| %9s | %8s | %7s | %7s |\n", q[i].op, q[i].opr1, q[i].opr2, q[i].result);
	printf("\t--------------------------------------------\n");
}

displaySymTab(){
	printf("\n\nSymbol Table:\n");
	printf("\t-----------------------------------------\n");
	printf("\t|\t%7s\t|\t%14s\t|\n","Name","Type");
	printf("\t-----------------------------------------\n");
	for(i=0; i < symTabCount; i++)
		printf("\t|\t%7s\t|\t%14s\t|\n", record[i].name, record[i].type);
	printf("\t-----------------------------------------\n");
}

struct nextList *makeList(int i){
	struct nextList *t;
	t = (struct nextList *) malloc(sizeof(struct nextList));
	t->val = i;
	t->next = NULL;
	return t;
}

void backpatch(struct nextList *p, int i){
	char buff[10];
	snprintf(buff, 10,"%d", i);
	//itoa(i,buff,10);
	while(p != NULL){
		strcpy(q[p->val].result, "goto(");
		strcat(q[p->val].result, buff);
		strcat(q[p->val].result, ")");
		p = p->next;		
	}
}

struct nextList *merge(struct nextList *p1, struct nextList *p2){
	struct nextList *t;
	if(p1 == NULL)
		return p2;
	t = p1;
	while(t->next != NULL)
		t = t->next;
	t->next = p2;
	return p1;
}

void newTemp(){
	char buff2[5];
	snprintf(buff2, 5,"%d", curTemp++);
	//itoa(curTemp++,buff2,10);
	strcpy(temp,"T");
	strcat(temp,buff2);
}

void addType(char *id, char *type){
	int i;
	for(i = 0; i < symTabCount; i++){
		if(!strcmp(record[i].name, id)){
			strcpy(record[i].type, type);
			return;
		}
	}
	printf("\nUnknown ID %s", id);
	exit(1);
}

void getType(char *id){
	int i;
	for(i = 0; i < symTabCount; i++){
		if(!strcmp(record[i].name, id)){
			strcpy(glbChar, record[i].type);
			return;
		}
	}
	printf("\nUnknown ID %s",id);
	exit(1);
}

int yyerror(char *r){
	printf(" : %s\n", r);
	exit(1);
}


/* OUTPUT

student@B4L0106:~$ flex quadrupleControl.l
student@B4L0106:~$ byacc -d quadrupleControl.y
byacc: 7 shift/reduce conflicts.
student@B4L0106:~$ gcc -o quadrupleControl lex.yy.c y.tab.c -ll
student@B4L0106:~$ ./quadrupleControl 
Enter Expression: int a, b, c, d, e; if(a<b){a=5;b=a+b-c*d/e;}
      	--------------------------------------------
	| Operation |   Arg 1  |   Arg 2 |  Result |
	--------------------------------------------
	|         < |        a |       b | goto(2) |
	|         # |        # |       # | goto(_) |
	|         = |        5 |       # |       a |
	|         + |        a |       b |      T1 |
	|         * |        c |       d |      T2 |
	|         / |       T2 |       e |      T3 |
	|         - |       T1 |      T3 |      T4 |
	|         = |       T4 |       # |       b |
	--------------------------------------------


Symbol Table:
	-----------------------------------------
	|	   Name	|	          Type	|
	-----------------------------------------
	|	      a	|	           int	|
	|	      b	|	           int	|
	|	      c	|	           int	|
	|	      d	|	           int	|
	|	      e	|	           int	|
	-----------------------------------------
student@B4L0106:~$ ./quadrupleControl 
Enter Expression: int a,b; char c,d; if(a<c)a=c;
    
Type mismatch in statement for (a < c)
student@B4L0106:~$

*/
