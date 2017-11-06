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
extern YYSTYPE yylval;
