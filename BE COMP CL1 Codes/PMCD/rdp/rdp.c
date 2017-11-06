#include<stdio.h>
#include<stdlib.h>

char *input;
void E();
void E_();
void T();
void T_();
void F();
void error();
int main(){
	input = (char *)malloc(15);
	printf("Enter input string: ");
	scanf("%s", input);
	E();
	printf("\n****String Matched****\n");
}

void E(){
	T();
	E_();
}

void E_(){
	if(*input == '+'){
		input++;
		T();
		E_();
	}
}

void T(){
	F();
	T_();
}

void T_(){
	if(*input == '*'){
		input++;
		F();
		T_();
	}
}

void F(){
	if(*input == 'i')
		input++;
	else if(*input == '('){
		input++;
		E();
		if(*input==')')
			input++;
	}
	else{
		error();
	}	
}

void error(){
	printf("\n****String not matched****\n");
	exit(0);
}

/* OUTPUT

student@B4L0106:~$ gcc -o rdp rdp.c 
student@B4L0106:~$ ./rdp 
Enter input string: i+i*i

****String Matched****
student@B4L0106:~$ ./rdp 
Enter input string: i+(i+i*i)*i+i

****String Matched****
student@B4L0106:~$ ./rdp 
Enter input string: i++i

****String not matched****
student@B4L0106:~$ 

*/
