#pragma once
#include <string>
using namespace std;
class BTNode
{
public:
	BTNode(void);
	~BTNode(void);

	BTNode* lchild,*rchild;
	int left_int,right_int;

	BTNode *Father;
	int Father_int;
	int isleft(BTNode*);
	int isright(BTNode*);//判断是左右加0，1时用
	
	bool isable;//判断是否可访问，生成haffman树时用

	char ch;
	double percent;
	int num;
	string str;
};

