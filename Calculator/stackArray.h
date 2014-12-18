#ifndef _stackArray_h
#define _stackArray_h


struct stackRecord;
typedef struct stackRecord *stack;

int isEmpty(stack s);
int isFull(stack s);
stack createStack(int maxElementsNumber);
void disposeStack(stack s);
int push(void *e, stack s);
void *top(stack s);
int pop(stack s);
void *topAndPop(stack s);

#endif