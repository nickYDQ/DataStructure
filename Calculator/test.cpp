#include <stdio.h>
#include <stdlib.h>
#include "infixAndPostfix.h"
#include <string.h>

int main(int argv, char *argc[])
{
	char *expression = "  (1 * 2 + 5 )+2 + (1*5+5)+ 3";
	char *p;
	//if (argv != 2) {
	//	puts("Usage: a.exe {algorith expression(must valid)}");
	//	return 1;
	//}

	p = infixToPostfix(expression);
	printf("The infix expression is: %s\n", expression);
	puts("+++++++++++++++++++++++++++++++++++++++++++++++");
	printf("The Postfix expression is: %s\n", p);
	if (strchr(expression, '='))
		printf("%s %d\n", expression, processPostfix(p));
	else
		printf("%s =  %d\n", expression, processPostfix(p));

	if (p != NULL)
		free(p);

	return 0;
}