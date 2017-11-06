/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
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
	
	int curTemp = 1;
	char temp[10];
#line 18 "quadrupleControl.y"
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
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 50 "y.tab.c"

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
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

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
#define ID 270
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    1,    2,    2,    2,    2,    2,    2,    2,
    2,    3,    4,    4,    4,
};
static const YYINT yylen[] = {                            2,
    1,    8,    2,    3,    3,    3,    3,    3,    3,    1,
    1,    0,    4,    1,    2,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,   11,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   12,    9,    4,    0,    0,
    7,    8,    0,    0,    0,    0,    0,    0,    2,    0,
    0,   13,
};
static const YYINT yydgoto[] = {                          2,
    5,    9,   23,   30,
};
static const YYINT yysindex[] = {                      -239,
 -245,    0, -239, -250, -239,    0, -250, -230, -212, -206,
 -224, -250, -250, -250, -250,    0,    0,    0, -252, -252,
    0,    0, -235, -253, -226, -239, -254, -250,    0, -253,
 -227,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,   52,    0,    1,    0,    0, -238,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -223, -221,
    0,    0,    0,    0,    0, -255,    0,    0,    0, -209,
    0,    0,
};
static const YYINT yygindex[] = {                         0,
    2,   -7,    0,   36,
};
#define YYTABLESIZE 271
static const YYINT yytable[] = {                         10,
    3,    3,    1,    1,   19,   20,   21,   22,    6,   14,
   15,   14,   29,    7,   14,   25,   25,    1,    4,    8,
   31,   10,   10,   10,   10,   26,   10,   11,   26,   10,
   24,   26,   12,   13,   14,   15,    5,    5,    6,    6,
   32,    5,   28,    6,    5,   18,    6,   12,   13,   14,
   15,    1,   16,   12,   13,   14,   15,   15,   17,   27,
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
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    3,    0,    0,
    3,
};
static const YYINT yycheck[] = {                          7,
    0,    0,  257,  257,   12,   13,   14,   15,  259,  262,
  263,  267,  267,  264,  270,  270,  270,  257,  264,  270,
   28,  260,  261,  262,  263,   24,  265,  258,   27,  268,
  266,   30,  260,  261,  262,  263,  260,  261,  260,  261,
  268,  265,  269,  265,  268,  270,  268,  260,  261,  262,
  263,    0,  265,  260,  261,  262,  263,  267,  265,   24,
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
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  267,   -1,   -1,
  270,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 270
#define YYUNDFTOKEN 277
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"IF","RELOP","num","plus","minus",
"mul","div","ob","cb","ocb","ccb","sc","eq","ID",0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : Sdash",
"Sdash : S",
"S : IF ob E cb M ocb SN ccb",
"S : S S",
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
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 84 "quadrupleControl.y"

void displayQuadruple(){
	printf("\t--------------------------------------------\n");
	printf("\t| %7s | %7s  | %7s | %7s |\n","Operation","Arg 1","Arg 2", "Result");
	printf("\t--------------------------------------------\n");
	for(i=0; i<count; i++)
		printf("\t| %9s | %8s | %7s | %7s |\n", q[i].op, q[i].opr1, q[i].opr2, q[i].result);
	printf("\t--------------------------------------------\n");
}

int main(){
	printf("Enter Expression: ");
	yyparse();
	displayQuadruple();
	return 0;
}

void addQ(char *op, char *opr1, char *opr2, char *result){
	strcpy(q[count].op, op);
	strcpy(q[count].opr1, opr1);
	strcpy(q[count].opr2, opr2);
	strcpy(q[count].result, result);
	count++;
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
#line 375 "y.tab.c"

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
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

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

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
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
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
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

    YYERROR_CALL("syntax error");

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
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
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
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
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
#line 56 "quadrupleControl.y"
	{ backpatch(yystack.l_mark[-5].attr.trueList, yystack.l_mark[-3].quad);
					yyval.nextListO = merge(yystack.l_mark[-5].attr.falseList, yystack.l_mark[-1].nextListO); }
break;
case 4:
#line 61 "quadrupleControl.y"
	{
				yyval.attr.trueList = makeList(count);
				yyval.attr.falseList = makeList(count+1);
				addQ(yystack.l_mark[-1].dname, yystack.l_mark[-2].attr.place, yystack.l_mark[0].attr.place, "goto(_)");
				addQ("#","#","#","goto(_)");
			}
break;
case 5:
#line 67 "quadrupleControl.y"
	{ newTemp(); strcpy(yyval.attr.place, temp); addQ(yystack.l_mark[-1].dname, yystack.l_mark[-2].attr.place, yystack.l_mark[0].attr.place, temp); }
break;
case 6:
#line 68 "quadrupleControl.y"
	{ newTemp(); strcpy(yyval.attr.place, temp); addQ(yystack.l_mark[-1].dname, yystack.l_mark[-2].attr.place, yystack.l_mark[0].attr.place, temp); }
break;
case 7:
#line 69 "quadrupleControl.y"
	{ newTemp(); strcpy(yyval.attr.place, temp); addQ(yystack.l_mark[-1].dname, yystack.l_mark[-2].attr.place, yystack.l_mark[0].attr.place, temp); }
break;
case 8:
#line 70 "quadrupleControl.y"
	{ newTemp(); strcpy(yyval.attr.place, temp); addQ(yystack.l_mark[-1].dname,yystack.l_mark[-2].attr.place, yystack.l_mark[0].attr.place, temp); }
break;
case 9:
#line 71 "quadrupleControl.y"
	{ strcpy(yyval.attr.place, yystack.l_mark[-1].attr.place); }
break;
case 10:
#line 72 "quadrupleControl.y"
	{ strcpy(yyval.attr.place, yystack.l_mark[0].attr.place); }
break;
case 11:
#line 73 "quadrupleControl.y"
	{ strcpy(yyval.attr.place, yystack.l_mark[0].dname); }
break;
case 12:
#line 76 "quadrupleControl.y"
	{ yyval.quad = count; }
break;
case 13:
#line 79 "quadrupleControl.y"
	{ addQ(yystack.l_mark[-2].dname, yystack.l_mark[-1].attr.place, "#", yystack.l_mark[-3].attr.place); }
break;
case 14:
#line 80 "quadrupleControl.y"
	{yyval.nextListO = yystack.l_mark[0].nextListO;}
break;
#line 631 "y.tab.c"
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
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
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
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
