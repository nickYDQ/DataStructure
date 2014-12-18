#include <stdio.h>
#include <stdlib.h>
#include "stackArray.h"
#include "string.h"
#include "infixAndPostfix.h"

int priority(char c, char topOfStack);
char * eraseSpace(char *infix);

char *
infixToPostfix(char * infix)
{
	char *postfix; //pointer to  a arry to hold the postfix string
	int i;        // index of the postfix array
	char *n;      //pointer to iterate the infix
	stack s;      // the stack to hold the operators

	postfix = (char *)malloc(strlen(infix) * 2);

	s = createStack(50);
	i = 0;
	n = infix;
	while (*n != '\0')
	{
		n = eraseSpace(n);

		if (n == '\0')
			break;
		switch (*n)
		{
		case '+':
		case '-':
			// if the front is not a # or operator then add the diviter character # to the end
			if (postfix[i - 1] != '#' && postfix[i - 1] != '*' && postfix[i - 1] != '+' && postfix[i - 1] != '-' && postfix[i - 1] != '/')
				postfix[i++] = '#';
			if (!top(s))
			{
				push(n, s);
				break;
			}

			if (priority(*n, *(char *)top(s)) > 0)           // if it's priority is big then front of it push it
				push(n, s);
			else
			{
				if (*(char *)top(s) == '(')                     // if the front is the '(' whatever push it
					push(n, s);
				else {
					postfix[i++] = *(char *)topAndPop(s);          // else pop the front and push it
					push(n, s);
				}
			}
			break;
		case '*':
		case '/':
			if (!top(s))
			{
				push(n, s);
				break;
			}

			if (postfix[i - 1] != '#' && postfix[i - 1] != '*' && postfix[i - 1] != '+' && postfix[i - 1] != '-' && postfix[i - 1] != '/')
				postfix[i++] = '#';

			if (priority(*n, *(char *)top(s)) > 0)
				push(n, s);
			else
			{
				if (*(char *)top(s) == '(')
					push(n, s);
				else {
					postfix[i++] = *(char *)topAndPop(s);
					push(n, s);
				}
			}
			break;
		case '(':

			if (!top(s))
			{
				push(n, s);
				break;
			}
			if (postfix[i - 1] != '#' && postfix[i - 1] != '*' && postfix[i - 1] != '+' && postfix[i - 1] != '-' && postfix[i - 1] != '/')
				postfix[i++] = '#';

			push(n, s);
			break;
		case ')':                                  // when get the ), and pop it
			while (*(char *)top(s) != '(')                  //pop the operator entill get the ( 
				postfix[i++] = *(char *)topAndPop(s);
			pop(s);                               // pop the (
			break;
		case ' ':
		case '\t':
		case '=':
			break;
		default:
			postfix[i++] = *n;           //if it's a number then hold it into the postfix array
		}
		n++;
	}
	while (!isEmpty(s))
		postfix[i++] = *(char *)topAndPop(s);
	postfix[i] = '\0';

	disposeStack(s);   //importen! Don't forget delete the stack
	return postfix;
}

/* erase the space between numbers and operator */
char *
eraseSpace(char *infix)
{
	char *p;

	p = infix;

	while (*p == ' ' || *p == '\t')
		p++;

	return p;
}

/* compare the two operator's priority */
int
priority(char c, char topOfStack)
{


	switch (c)
	{
	case '+':
	case '-':
		c = 1;
		break;
	case '*':
	case '/':
		c = 2;
		break;
	case '(':
	case ')':
		c = 5;
		break;
	default:
		c = 0;
	}

	switch (topOfStack)
	{
	case '+':
	case '-':
		topOfStack = 1;
		break;
	case '*':
	case '/':
		topOfStack = 2;
		break;
	case '(':
	case ')':
		topOfStack = 5;
		break;
	default:
		topOfStack = 0;
	}

	return c - topOfStack;

}