#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20110908

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "quadrupleControl.y"
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
#line 22 "quadrupleControl.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union
{
	char dname[10];
	int quad;
	struct nextList *nextListO;
	struct parseTreeNode attr;
	char dataType[10];
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 53 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#define YYERROR_DECL() yyerror(const char *s)
#define YYERROR_CALL(msg) yyerror(msg)

extern int YYPARSE_DECL();

#define IF 257
#define RELOP 258
#define num 259
#define plus 260
#define minus 261
#define mul 262
#define div 263
#define ob 264
#define cb 265
#define ocb 266
#define ccb 267
#define sc 268
#define eq 269
#define TYPE 270
#define comma 271
#define ID 272
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    2,    2,    2,    6,    1,    1,    3,    3,    3,
    3,    3,    3,    3,    3,    4,    5,    5,    5,
};
static const short yylen[] = {                            2,
    1,    8,    2,    2,    2,    3,    1,    3,    3,    3,
    3,    3,    3,    1,    1,    0,    4,    1,    2,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    7,    0,    0,    3,
   15,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   16,    6,   13,    8,    0,    0,   11,   12,    0,
    0,    0,    0,    0,    0,    2,    0,    0,   17,
};
static const short yydgoto[] = {                          3,
    8,    9,   14,   30,   37,    5,
};
static const short yysindex[] = {                      -246,
 -252, -258,    0, -246, -243, -244,    0, -245, -246,    0,
    0, -244, -223, -205, -234, -199, -222, -244, -244, -244,
 -244,    0,    0,    0,    0, -241, -241,    0,    0, -239,
 -253, -210, -246, -254, -244,    0, -253, -220,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,   53,    0,    0,    0, -203,    1,    0,
    0,    0, -231,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -216, -214,    0,    0,    0,
    0,    0, -262,    0,    0,    0, -200,    0,    0,
};
static const short yygindex[] = {                         0,
    0,    2,  -12,    0,   37,    0,
};
#define YYTABLESIZE 273
static const short yytable[] = {                         16,
    4,    4,    1,    1,   18,   26,   27,   28,   29,   18,
    1,    6,   36,    7,   11,    2,    2,   32,   32,   12,
   20,   21,   38,    2,   10,   15,   31,   13,   14,   14,
   14,   14,   33,   14,   17,   33,   14,   23,   33,   18,
   19,   20,   21,    9,    9,   10,   10,   39,    9,   25,
   10,    9,    1,   10,   18,   19,   20,   21,   35,   22,
   18,   19,   20,   21,    5,   24,   19,   34,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    4,    0,    0,
    0,    0,    4,
};
static const short yycheck[] = {                         12,
    0,    0,  257,  257,  267,   18,   19,   20,   21,  272,
  257,  264,  267,  272,  259,  270,  270,  272,  272,  264,
  262,  263,   35,  270,  268,  271,  266,  272,  260,  261,
  262,  263,   31,  265,  258,   34,  268,  272,   37,  260,
  261,  262,  263,  260,  261,  260,  261,  268,  265,  272,
  265,  268,    0,  268,  260,  261,  262,  263,  269,  265,
  260,  261,  262,  263,  268,  265,  267,   31,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  267,   -1,   -1,
   -1,   -1,  272,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 272
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"IF","RELOP","num","plus","minus",
"mul","div","ob","cb","ocb","ccb","sc","eq","TYPE","comma","ID",
};
static const char *yyrule[] = {
"$accept : Sdash",
"Sdash : S",
"S : IF ob E cb M ocb SN ccb",
"S : DECL sc",
"S : S S",
"DECL : TYPE IDLIST",
"IDLIST : IDLIST comma ID",
"IDLIST : ID",
"E : ID RELOP ID",
"E : E plus E",
"E : E minus E",
"E : E mul E",
"E : E div E",
"E : ob E cb",
"E : ID",
"E : num",
"M :",
"SN : ID eq E sc",
"SN : S",
"SN : SN SN",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 116 "quadrupleControl.y"

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


/*
OUTPUT

student@B4L0106:~$ flex quadrupleControl.l
student@B4L0106:~$ byacc -d quadrupleControl.y
byacc: 1 shift/reduce conflict.
student@B4L0106:~$ gcc -o quadrupleControl lex.yy.c y.tab.c -ll
student@B4L0106:~$ ./quadrupleControl 
Enter Expression: if(a<b)a=5;b=a+b-c*d/e;
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
student@B4L0106:~$ 

student@B4L0106:~$ flex quadrupleControl.l
student@B4L0106:~$ byacc -d quadrupleControl.y
byacc: 7 shift/reduce conflicts.
student@B4L0106:~$ gcc -o quadrupleControl lex.yy.c y.tab.c -ll
student@B4L0106:~$ ./quadrupleControl 
Enter Expression: int a,b; char c,d; if(a<c)a=c;
    
Type mismatch in statement for (a < c)
student@B4L0106:~$ ./quadrupleControl 
Enter Expression: int a,b,c,d; if(a<b){a=b+c/d;}
  	--------------------------------------------
	| Operation |   Arg 1  |   Arg 2 |  Result |
	--------------------------------------------
	|         < |        a |       b | goto(2) |
	|         # |        # |       # | goto(_) |
	|         / |        c |       d |      T1 |
	|         + |        b |      T1 |      T2 |
	|         = |       T2 |       # |       a |
	--------------------------------------------


Symbol Table:
	-----------------------------------------
	|	   Name	|	          Type	|
	-----------------------------------------
	|	      a	|	           int	|
	|	      b	|	           int	|
	|	      c	|	           int	|
	|	      d	|	           int	|
	-----------------------------------------
student@B4L0106:~$ 



*/
#line 432 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = data->s_mark - data->s_base;
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 2:
#line 65 "quadrupleControl.y"
	{ backpatch(yystack.l_mark[-5].attr.trueList, yystack.l_mark[-3].quad);
					yyval.nextListO = merge(yystack.l_mark[-5].attr.falseList, yystack.l_mark[-1].nextListO); }
break;
case 3:
#line 67 "quadrupleControl.y"
	{ yyval.nextListO = NULL; }
break;
case 5:
#line 71 "quadrupleControl.y"
	{ strcpy(yystack.l_mark[0].dataType, yystack.l_mark[-1].dataType); }
break;
case 6:
#line 74 "quadrupleControl.y"
	{ strcpy(yystack.l_mark[-2].dataType, yystack.l_mark[-3].dataType); addType(yystack.l_mark[0].attr.place, yystack.l_mark[-2].dataType); }
break;
case 7:
#line 75 "quadrupleControl.y"
	{ strcpy(yyval.dataType, yystack.l_mark[-1].dataType); addType(yystack.l_mark[0].attr.place, yyval.dataType); }
break;
case 8:
#line 78 "quadrupleControl.y"
	{getType(yystack.l_mark[-2].attr.place); strcpy(yystack.l_mark[-2].attr.type, glbChar);
			getType(yystack.l_mark[0].attr.place); strcpy(yystack.l_mark[0].attr.type, glbChar);
			if(!strcmp(yystack.l_mark[-2].attr.type,yystack.l_mark[0].attr.type)){
				yyval.attr.trueList = makeList(count);
				yyval.attr.falseList = makeList(count+1);
				addQ(yystack.l_mark[-1].dname, yystack.l_mark[-2].attr.place, yystack.l_mark[0].attr.place, "goto(_)");
				addQ("#","#","#","goto(_)");
			}else {printf("\nType mismatch in statement for (%s %s %s)\n",yystack.l_mark[-2].attr.place, yystack.l_mark[-1].dname, yystack.l_mark[0].attr.place);
				exit(1);}  }
break;
case 9:
#line 87 "quadrupleControl.y"
	{ if(strcmp(yystack.l_mark[-2].attr.type,yystack.l_mark[0].attr.type)){
				printf("\nType mismatch in statement for (%s %s %s)\n",yystack.l_mark[-2].attr.place, yystack.l_mark[-1].dname, yystack.l_mark[0].attr.place);
				exit(1);
			} newTemp(); strcpy(yyval.attr.place, temp); addQ(yystack.l_mark[-1].dname, yystack.l_mark[-2].attr.place, yystack.l_mark[0].attr.place, temp); }
break;
case 10:
#line 91 "quadrupleControl.y"
	{ if(strcmp(yystack.l_mark[-2].attr.type,yystack.l_mark[0].attr.type)){
				printf("\nType mismatch in statement for (%s %s %s)\n",yystack.l_mark[-2].attr.place, yystack.l_mark[-1].dname, yystack.l_mark[0].attr.place);
				exit(1);
			} newTemp(); strcpy(yyval.attr.place, temp); addQ(yystack.l_mark[-1].dname, yystack.l_mark[-2].attr.place, yystack.l_mark[0].attr.place, temp); }
break;
case 11:
#line 95 "quadrupleControl.y"
	{ if(strcmp(yystack.l_mark[-2].attr.type,yystack.l_mark[0].attr.type)){
				printf("\nType mismatch in statement for (%s %s %s)\n",yystack.l_mark[-2].attr.place, yystack.l_mark[-1].dname, yystack.l_mark[0].attr.place);
				exit(1);
			} newTemp(); strcpy(yyval.attr.place, temp); addQ(yystack.l_mark[-1].dname, yystack.l_mark[-2].attr.place, yystack.l_mark[0].attr.place, temp); }
break;
case 12:
#line 99 "quadrupleControl.y"
	{ if(strcmp(yystack.l_mark[-2].attr.type,yystack.l_mark[0].attr.type)){
				printf("\nType mismatch in statement for (%s %s %s)\n",yystack.l_mark[-2].attr.place, yystack.l_mark[-1].dname, yystack.l_mark[0].attr.place);
				exit(1);
			} newTemp(); strcpy(yyval.attr.place, temp); addQ(yystack.l_mark[-1].dname,yystack.l_mark[-2].attr.place, yystack.l_mark[0].attr.place, temp); }
break;
case 13:
#line 103 "quadrupleControl.y"
	{ strcpy(yyval.attr.place, yystack.l_mark[-1].attr.place); }
break;
case 14:
#line 104 "quadrupleControl.y"
	{ getType(yystack.l_mark[0].attr.place); strcpy(yyval.attr.place, yystack.l_mark[0].attr.place); strcpy(yyval.attr.type, glbChar); }
break;
case 15:
#line 105 "quadrupleControl.y"
	{ strcpy(yyval.attr.place, yystack.l_mark[0].dname); }
break;
case 16:
#line 108 "quadrupleControl.y"
	{ yyval.quad = count; }
break;
case 17:
#line 111 "quadrupleControl.y"
	{ addQ(yystack.l_mark[-2].dname, yystack.l_mark[-1].attr.place, "#", yystack.l_mark[-3].attr.place); }
break;
case 18:
#line 112 "quadrupleControl.y"
	{yyval.nextListO = yystack.l_mark[0].nextListO;}
break;
#line 723 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
