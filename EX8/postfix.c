#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100 /*Max size of operand or operator*/
#define MAXVAL 100 /*Max depth of the stack of operation*/
#define NUMBER '0' /*Flag that a number was found*/

int getop(char[]);
void push(double);
double pop(void);
void ungetchh(int);
int getchh(void);

/*This is the first version of a Polish calculator.*/

int main(void)
{
	int type;
	double op2; /* This is a temp variable to help perform substractions and divisions*/
	char s[MAXOP];
	
	while((type = getop(s)) != EOF) {
		switch(type) {
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2  = pop();
				if (op2){
				push(pop() / op2);
				}
				else {
				printf("Error: Zero division\n");
				}
				break;
			case '\n':
				printf("\t%.4f\n", pop());
				break;
			default:
				printf("Error: Unknown command %c\n", type);
				break;
		}
	}
	return 0;
}

int sp = 0; /*This is a pointer to the next free stack position*/
double val[MAXVAL];

void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("Error: Stack full, can't push %.4f.\n", f);
}

double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else
	{
		printf("Error: Stack is empty");
		return 0.0;
	}
}

/*This funciton gets the next operand*/
int getop(char s[])
{
	int i = 0, c;
	while ((c = getchh()) == ' ' || c == '\t') /* ignore spaces and tab*/
	;
	if (!isdigit(c) && c != '.')
		return c; 
	s[i++] = c;
	if (isdigit(c))
		while (isdigit(s[i++] = c = getchh()))
		;
	if (c == '.') /*Start collection the decimal part of the input number*/
		while(isdigit(s[i++] = c = getchh()))
		;
	s[--i] = '\0';
	if (c != ' ' && c != '\t')
		ungetchh(c);
	return NUMBER;
}

enum {EMPTY, FULL};

int flag = EMPTY, buf;

/*This funciton gets the next character*/
int getchh(void) {

	if (flag == FULL) {
		flag = EMPTY;
		return buf;
	}
	else 
		return getchar();
}

void ungetchh(int c){
	
	if (flag == EMPTY){
		buf = c;
		flag = FULL;
	}
	else
		printf("Buffer is full can not enter more information \n");
}