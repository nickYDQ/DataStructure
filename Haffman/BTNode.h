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
	int isright(BTNode*);//�ж������Ҽ�0��1ʱ��
	
	bool isable;//�ж��Ƿ�ɷ��ʣ�����haffman��ʱ��

	char ch;
	double percent;
	int num;
	string str;
};

