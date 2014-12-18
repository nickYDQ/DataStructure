#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "stackArray.h"
#include "infixAndPostfix.h"

#define elementType int

int processPostfix(char *p)
{
	stack s;
	char *n;
	elementType sum, num1, num2;
	char tmp[255] = { 0 };
	int i = 0;
	elementType *point, *cur;         /* every number should allocat a new space for it */

	n = p;
	s = createStack(50);
	while (*n != '\0')
	{
		if (isdigit(*n))
		{
			while (isdigit(*n)){
				tmp[i++] = *n++;
			}
			tmp[i] = '\0';
			sum = atoi(tmp);
			point = (elementType *)malloc(sizeof(elementType));
			*point = sum;

			push((void *)point, s);
		}
		else
		{
			if ('#' == *n)
			{
				n++;
				continue;
			}
			num1 = num2 = 0;
			if (top(s))   /* get the first number on the top of the stack */
			{
				cur = (int*)top(s);
				num1 = *(elementType *)cur;
				pop(s);
				free(cur);    /* free the allocate space */
			}
			if (top(s))   /* get the second number on the top of the stack */
			{
				cur = (int*)top(s);
				num2 = *(elementType *)cur;
				pop(s);
				free(cur);
			}

			if (*n == '+')
			{
				sum = num2 + num1;
				point = (elementType *)malloc(sizeof(elementType));
				*point = sum;
				push((void *)point, s);
				n++;
			}
			else if (*n == '-')
			{
				sum = num2 - num1;
				point = (elementType *)malloc(sizeof(elementType));
				*point = sum;
				push((void *)point, s);
				n++;
			}
			else if (*n == '*')
			{
				sum = num2 * num1;
				point = (elementType *)malloc(sizeof(elementType));
				*point = sum;
				push((void *)point, s);
				n++;
			}
			else if (*n == '/') {
				sum = num1 / num2;
				point = (elementType *)malloc(sizeof(elementType));
				*point = sum;
				push((void *)point, s);
				n++;
			}
			else
			{
				n++;  // other charactor then the pointer point to next char
			}
		}
		i = 0;
		tmp[i] = '\0';

	}
	sum = *(elementType *)topAndPop(s);
	disposeStack(s);

	return sum;
}