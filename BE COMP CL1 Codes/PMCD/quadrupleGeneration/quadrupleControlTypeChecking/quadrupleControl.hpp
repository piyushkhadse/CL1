struct Q{
	char op[10];
	char opr1[10];
	char opr2[10];
	char result[10];
};

struct nextList{
	int val;
	struct nextList *next;
};

struct parseTreeNode{
	char place[10];
	char type[10];
	struct nextList *trueList, *falseList;
};


struct symtab{
	char name[10];
	char type[10];
};
