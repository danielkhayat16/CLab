#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100 /*Max size of operand or operator*/
#define MAXVAL 100 /*Max depth of the stack of operation*/
#define NUMBER '0' /*Flag that a number was found*/

int getop(char[]);
void push(double)'
double pop(void);
void ungetchh(int);
int getchh(void);

/*This is the first version of a Polish calculator.*/

void main(void)
{
	int type;
	double op2; // This is a temp variable to help perform substractions and divisions
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
			default:
				printf("Error: Unknown command %c\n", type);
				break;
		}
	}
}