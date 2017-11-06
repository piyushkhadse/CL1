%{
	#include<stdio.h>
	#include<string.h>
	FILE *file;
	int count = 0, flag = 0, i;
	struct symtab{
		char name[100];
		char type[100];
	} record[10];
	void addRecord(char * , char *);
%}

header "stdio.h"|"string.h"|"stdlib.h"|"math.h"
letter [a-zA-Z]
digit [0-9]

%%

"#include" {printf("%s => is preprocessor directive\n",yytext);}
"<"{header}">" {printf("%s => is header file\n",yytext);}
" " {printf("");}
"\n" {printf("");}
"\t" {printf("");}
"auto"|"double"|"int"|"struct"|"break"|"else"|"long" {printf("%s => is a keyword\n",yytext);}
"do"|"volatile"|"case"|"enum"|"register"|"typedef"|"char" {printf("%s => is a keyword\n",yytext);}
"extern"|"return"|"union"|"const"|"float"|"short"|"unsigned" {printf("%s => is a keyword\n",yytext);}
"static"|"continue"|"signed"|"void"|"default"|"goto"|"sizeof" {printf("%s => is a keyword\n",yytext);}
("for"|"if"|"while"|"switch")/[" \n"]*"(".*")" {printf("%s => is a control/looping structure\n",yytext);}
"main"/"(".*")" {printf("%s => is main function\n",yytext);}
"printf"/"(".*")" {printf("%s => is output function\n",yytext);}
"scanf"/"(".*")" {printf("%s => is input function\n",yytext);}
"{"|"}" {printf("%s => is curly bracket\n",yytext);}
"("|")" {printf("%s => is parenthesis\n",yytext);}
"["|"]" {printf("%s => is index bracket\n",yytext);}
";" {printf("%s => is semicolon\n",yytext);}
"," {printf("%s => is comma operator\n",yytext);}
"=" {printf("%s => is assignment operator\n",yytext);}
"++"|"--" {printf("%s => is increment/decrement operator\n",yytext);}
"+"|"-"|"*"|"/"|"%" {printf("%s => is arithmetic operator\n",yytext);}
"<"|">"|"<="|">="|"!="|"==" {printf("%s => is conditional operator\n",yytext);}
"&"{letter}({letter}|{digit})* {printf("%s => is reference to identifier\n",yytext);}

{letter}({letter}|{digit})*/"["{digit}+"]" {
	printf("%s => is an array\n",yytext);
	addRecord(yytext, "array");
}

{letter}({letter}|{digit})*/"(".*")" {
	printf("%s => is an user defined function\n",yytext);
	addRecord(yytext, "user_function");
}

{letter}({letter}|{digit})* {
	printf("%s => is an identifier\n",yytext);
	addRecord(yytext, "identifier");
}


{digit}+ {printf("%s => is number\n",yytext);}
\".*\" {printf("%s => is string\n",yytext);}
"//".* {printf("%s => is comment\n",yytext);}

%%

int main(){
	file = fopen("sampleCode.txt","r");
	if(file){
		yyin = file;
		yylex();
		yywrap();
	}else
		printf("File does not exist");

	printf("\n\nSymbol Table:\n");
	printf("\t-----------------------------------------\n");
	printf("\t|\t%7s\t|\t%14s\t|\n","Name","Type");
	printf("\t-----------------------------------------\n");
	for(i=0; i<count; i++)
		printf("\t|\t%7s\t|\t%14s\t|\n", record[i].name, record[i].type);
	printf("\t-----------------------------------------\n");
}

void addRecord(char *n, char *v){
	flag = 0;
	for(i=0; i<count; i++)
		if(strcmp(record[i].name, yytext) == 0)
			flag=1;
			
	for(i=0; i<strlen(n); i++){
		if(n[i]=='[')
			n[i]='\0';
		else if(n[i] == '(')
			n[i]='\0';
	
	}
	if(flag == 0){
		strcpy(record[count].name, n);
		strcpy(record[count++].type, v);
	}
}

extern int yywrap(){
	return 1;
}

/* OUTPUT

student@B4L0106:~$ flex cScanner.l 
student@B4L0106:~$ gcc -o cScanner lex.yy.c 
student@B4L0106:~$ ./cScanner 
#include => is preprocessor directive
<stdio.h> => is header file
int => is a keyword
main => is main function
( => is parenthesis
) => is parenthesis
{ => is curly bracket
int => is a keyword
n => is an identifier
, => is comma operator
i => is an identifier
, => is comma operator
flag => is an identifier
= => is assignment operator
0 => is number
, => is comma operator
arr => is an array
[ => is index bracket
10 => is number
] => is index bracket
; => is semicolon
printf => is output function
( => is parenthesis
"Enter a positive integer: " => is string
) => is parenthesis
; => is semicolon
scanf => is input function
( => is parenthesis
"%d" => is string
, => is comma operator
&n => is reference to identifier
) => is parenthesis
; => is semicolon
for => is a control/looping structure
( => is parenthesis
i => is an identifier
= => is assignment operator
2 => is number
; => is semicolon
i => is an identifier
<= => is conditional operator
n => is an identifier
/ => is arithmetic operator
2 => is number
; => is semicolon
++ => is increment/decrement operator
i => is an identifier
) => is parenthesis
{ => is curly bracket
// condition for nonprime number => is comment
if => is a control/looping structure
( => is parenthesis
n => is an identifier
% => is arithmetic operator
i => is an identifier
== => is conditional operator
0 => is number
) => is parenthesis
{ => is curly bracket
flag => is an identifier
= => is assignment operator
1 => is number
; => is semicolon
break => is a keyword
; => is semicolon
} => is curly bracket
} => is curly bracket
if => is a control/looping structure
( => is parenthesis
flag => is an identifier
== => is conditional operator
0 => is number
) => is parenthesis
printf => is output function
( => is parenthesis
"%d is a prime number." => is string
, => is comma operator
n => is an identifier
) => is parenthesis
; => is semicolon
else => is a keyword
printf => is output function
( => is parenthesis
"%d is not a prime number." => is string
, => is comma operator
n => is an identifier
) => is parenthesis
; => is semicolon
return => is a keyword
0 => is number
; => is semicolon
} => is curly bracket
int => is a keyword
add => is an user defined function
( => is parenthesis
int => is a keyword
a => is an identifier
, => is comma operator
int => is a keyword
b => is an identifier
) => is parenthesis
{ => is curly bracket
return => is a keyword
a => is an identifier
+ => is arithmetic operator
b => is an identifier
; => is semicolon
} => is curly bracket
int => is a keyword
sub => is an user defined function
( => is parenthesis
int => is a keyword
a => is an identifier
, => is comma operator
int => is a keyword
b => is an identifier
) => is parenthesis
{ => is curly bracket
return => is a keyword
a => is an identifier
- => is arithmetic operator
b => is an identifier
; => is semicolon
} => is curly bracket


Symbol Table:
	-----------------------------------------
	|	   Name	|	          Type	|
	-----------------------------------------
	|	      n	|	    identifier	|
	|	      i	|	    identifier	|
	|	   flag	|	    identifier	|
	|	    arr	|	         array	|
	|	    add	|	 user_function	|
	|	      a	|	    identifier	|
	|	      b	|	    identifier	|
	|	    sub	|	 user_function	|
	-----------------------------------------
student@B4L0106:~$ 

*/
