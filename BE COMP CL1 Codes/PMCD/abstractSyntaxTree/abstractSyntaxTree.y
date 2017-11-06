%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	#include "abstractSyntaxTree.h"
	extern int yylex();
	extern int yyparse();
	struct treeNode *temp1, *root;
	struct treeNode *createNode(char value[20], struct treeNode *left, struct treeNode *right);
	void postfix(struct treeNode *root);
%}


%union
{
	struct treeNode *node;
	char dname[20];
}

%token<dname> id
%type<node> E
%start S
%left plus minus
%left mul div
%left ob cb
%token<dname> plus
%token<dname> minus
%token<dname> mul
%token<dname> div
%token ob
%token cb
%token<dname> eq

%%

S 	: id eq E	{ 	temp1 = createNode($1, NULL, NULL);
					root = createNode($2, temp1, $3);
					printf("Postfix Traversal => ");
					postfix(root);
					printf("\n");
					}
	;

E	: E plus E	{ $$ = createNode($2, $1, $3); }
	| E minus E	{ $$ = createNode($2, $1, $3); }
	| E mul E	{ $$ = createNode($2, $1, $3); }
	| E div E	{ $$ = createNode($2, $1, $3); }
	| ob E cb	{ $$ = $2; }
	| id		{ $$ = createNode($1, NULL, NULL); }
	;
	
%%

int main(){

	yyparse();
	return 0;
	
}

struct treeNode *createNode(char value[20], struct treeNode *left, struct treeNode *right){
	struct treeNode *temp;
	temp = (struct treeNode *)malloc(sizeof(struct treeNode));
	strcpy(temp->value, value);
	temp->left = left;
	temp->right = right;
	return temp;
}

void postfix(struct treeNode *root){
	if(root!=NULL){
		postfix(root->left);
		postfix(root->right);
		printf("%s ",root->value);
	}
}

int yyerror(char *r){
	printf(" : %s\n", r);
	exit(1);
}

/* OUTPUT

student@B4L0106:~$ flex abstractSyntaxTree.l
student@B4L0106:~$ byacc -d abstractSyntaxTree.y
student@B4L0106:~$ gcc -o abstractSyntaxTree lex.yy.c y.tab.c -ll
student@B4L0106:~$ ./abstractSyntaxTree 
a = b + c * d / e
Postfix Traversal => a b c d * e / + = 
student@B4L0106:~$ ./abstractSyntaxTree 
var = var + 10 * 5 + 100 / ( temp - 6 )
Postfix Traversal => var var 10 5 * + 100 temp 6 - / + = 
student@B4L0106:~$

*/
