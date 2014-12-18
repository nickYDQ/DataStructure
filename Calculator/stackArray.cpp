#include <stdio.h>
#include <stdlib.h>
#include "stackArray.h"

#define EMPTYSTACK -1
#define MINSTACKSIZE 5

struct stackRecord
{
	int capacity;
	int topOfStack;
	void **array;
};


int
isEmpty(stack s)
{
	return s->topOfStack == EMPTYSTACK;
}

int
isFull(stack s)
{
	return (s->topOfStack + 1) == s->capacity;
}
void
disposeStack(stack s)
{
	s->topOfStack = -1;

	if (s != NULL) {
		free(s->array);
		free(s);
	}
}

stack
createStack(int maxElements)
{
	stack s = (stack)malloc(sizeof(struct stackRecord));

	if (maxElements < MINSTACKSIZE)
		perror("Stack size is too small.");
	if (s == NULL)
		perror("Out of space!");

	s->array = (void **)malloc(sizeof(void *) * maxElements);
	s->capacity = maxElements;
	s->topOfStack = -1;

	return s;
}

int
push(void *e, stack s)
{
	if (!isFull(s))
	{
		s->array[++s->topOfStack] = e;
		return 0;
	}
	else
		return 1;
}

/* when the stack is empty it'll return 0 */
void *
top(stack s)
{
	if (!isEmpty(s))
		return s->array[s->topOfStack];
	else
		return NULL;
}

int
pop(stack s)
{
	if (!isEmpty(s))
	{
		s->array[s->topOfStack--] = '\0';
		return 0;
	}
	else
		return 1;
}

void *
topAndPop(stack s)
{
	void *e;
	e = top(s);
	pop(s);

	return e;
}