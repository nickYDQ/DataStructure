#include <stdio.h>
#include <stdlib.h>

typedef struct link
{
	char data;
	struct link *next;
}linklist;

linklist *CreateList_Front();	//ͷ�巨����������
linklist *CreateList_End();		//β�巨����������
linklist *ReverseLinklist(linklist *head);
void ShowLinklist(linklist *h); //�����ʾ����

int main(void)
{
	int choice;
	linklist *head = NULL;

	//head = (linklist*)malloc(sizeof(linklist));
	while (1)
	{
		printf("������Ĵ���\n");
		printf("1.ʹ��ͷ�巨����������\n");
		printf("2.ʹ��β�巨����������\n");
		printf("3.���������ʾ\n");
		printf("4.��ת����\n");
		printf("5.�˳�\n");
		printf("����ѡ��\n");
		scanf_s("%d", &choice);
		switch (choice)
		{
			//ͷ�巨
		case 1:
			head = CreateList_Front();
			break;
			//β�巨
		case 2:
			head = CreateList_End();
			break;
			//�������
		case 3:
			ShowLinklist(head);
			break;
		case 4:
			head = ReverseLinklist(head);
			break;
		case 5:
			return 0;
			break;
		default:
			break;
		}
	}
	return 1;
}

linklist *CreateList_Front()
{
	linklist *head, *p;
	char ch;

	head = NULL;
	printf("���������ַ�����(��#����ʾ�������):\n");
	ch = getchar();
	while (ch != '#')
	{
		p = (linklist*)malloc(sizeof(linklist));
		p->data = ch;
		p->next = head;
		head = p;
		ch = getchar();				//ͷ�巨�㷨�� ���ľ�����p->next = head;head = p;
	}
	return head;
}

linklist *CreateList_End()
{
	linklist *head, *p, *e;
	char ch;

	head = NULL;
	e = NULL;
	printf("�����������ַ�����('#'��ʾ�������):\n");
	ch = getchar();
	while (ch != '#')
	{
		p = (linklist*)malloc(sizeof(linklist));
		p->data = ch;
		if (head == NULL)		//���ж�������ǲ��ǵ�һ���ڵ�
		{
			head = p;
		}
		else
		{
			e->next = p;		//eʼ��ָ����������һ���ڵ�
		}
		e = p;
		ch = getchar();
	}
	if (e != NULL)				//�������Ϊ�գ������ڵ����һ���ڵ�Ϊ��
	{
		e->next = NULL;
	}
	return head;				//β�巨��ͷ�巨����һЩ��������Ҫ�������жϣ��ֱ����жϵ�һ���ڵ�����һ���ڵ���жϡ������Ķ�һ��ָ�����e��
}

void ShowLinklist(linklist *h)
{
	linklist *p;

	p = h;
	while (p != NULL)
	{
		printf("%c ", p->data);
		p = p->next;
	}
	printf("\n");
}

linklist *ReverseLinklist(linklist *head)
{
	
	return NULL;
}