#include "BTNode.h"


BTNode::BTNode(void)
{
}

int BTNode::isleft(BTNode *T)
{
	if (T == NULL)
	{
		return 2;
	}
	if(T->lchild == this)
	{
		return 1;
	}
	else{
		return 0;
	}
}

int BTNode::isright(BTNode* T)
{
	if (T == NULL)
	{
		return 2;
	}
	if(T->rchild == this)
	{
		return 1;
	}
	else{
		return 0;
	}
}

BTNode::~BTNode(void)
{
}

