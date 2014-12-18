//#include <iostream>
//using namespace std;
//
//struct HuffNode         //�����������ṹ
//{
//	int weight;         //Ȩֵ
//	int parent;         //�����
//	int lchild;         //�����
//	int rchild;         //�Ҷ���
//};
//
//
//struct HuffCode         //����������ṹ
//{
//	int bit[10];        //�洢����������
//	int start;          //�����������������е���ʼλ��
//	int weight;         //Ȩֵ
//};
//
//
////ʵ�ֹ���������
//void Huffman(int w[], int n, HuffNode hn[], HuffCode hc[])
//{
//	int m1, m2;          //�ֱ�����С����СȨֵ
//	int x1, x2;          //�ֱ��ʾ��ǰ������Ҷ���
//	HuffCode cd;
//	int child, parent;
//	int i, j;
//	
//	for (i = 0; i<2 * n - 1; i++)//��ʼ����������
//	{
//		if (i<n)
//			hn[i].weight = w[i];
//		else
//			hn[i].weight = 0;
//		hn[i].parent = 0;
//		hn[i].lchild = -1;
//		hn[i].rchild = -1;
//	}
//
//
//	for (i = 0; i<n - 1; i++)   //�������������n-1����֧���
//	{
//		m1 = m2 = 1000;
//		x1 = x2 = 0;
//		for (j = 0; j<n + i; j++)
//		{
//
//			if (hn[j].weight<m1&&hn[j].parent == 0)//��С���浽��С
//			{
//				m2 = m1;
//				m1 = hn[j].weight;
//				x2 = x1;
//				x1 = j;
//			}
//			else if (hn[j].weight<m2&&hn[j].parent == 0)
//			{
//				m2 = hn[j].weight;
//				x2 = j;
//			}
//		}
//		hn[n + i].weight = hn[x1].weight + hn[x2].weight;
//		hn[x1].parent = n + i;
//		hn[x2].parent = n + i;
//		hn[n + i].lchild = x1;
//		hn[n + i].rchild = x2;
//	}
//
//
//	for (i = 0; i<n; i++) //�ɹ����������ɹ���������      
//	{
//		cd.weight = hn[i].weight;
//		cd.start = n - 1;
//		child = i;
//		parent = hn[i].parent;
//		while (parent != 0)
//		{
//			if (hn[parent].lchild == child)
//				cd.bit[cd.start] = 0;
//			else if (hn[parent].rchild == child)
//				cd.bit[cd.start] = 1;
//			cd.start--;
//			child = parent;
//			parent = hn[child].parent;
//		}
//		hc[i].weight = cd.weight;
//		hc[i].start = cd.start;
//		for (j = hc[i].start + 1; j<n; j++)
//			hc[i].bit[j] = cd.bit[j];
//	}
//
//}
//
//
//int main(int argc, char* argv[])
//{
//	int w[] = { 4, 2, 6, 8, 3, 2, 1 };
//	int n = 7;
//	HuffNode *hn = new HuffNode[2 * n - 1];
//	HuffCode *hc = new HuffCode[n];
//	Huffman(w, n, hn, hc);
//	cout << "��������������:" << endl;
//	for (int i = 0; i<n; i++)
//	{
//		cout << "weight=" << hc[i].weight << "    " << "code=";
//		for (int j = hc[i].start + 1; j<n; j++)
//			cout << hc[i].bit[j];
//		cout << endl;
//	}
//
//	return 0;
//}

/*------------------------------------------------------------------------ -
*Name:   ����������Դ���롣
* Date : 2011.04.16
* Author : Jeffrey Hill + Jezze(���벿��)
* �� Win - TC �²���ͨ��
* ʵ�ֹ��̣�����ͨ�� HuffmanTree() �����������������Ȼ���������� main()��
*           �Ե����Ͽ�ʼ(Ҳ���Ǵ��������Ϊ��Ľ�㿪ʼ)���ϲ���жϣ�����
*           �������࣬������Ϊ 0, �����Ҳ�, ������Ϊ 1�����������ɵı��롣
*------------------------------------------------------------------------*/
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXBIT      100
#define MAXVALUE  10000
#define MAXLEAF     30
#define MAXNODE    MAXLEAF*2 -1

typedef struct
{
	int bit[MAXBIT];
	int start;
} HCodeType;        /* ����ṹ�� */
typedef struct
{
	int weight;
	int parent;
	int lchild;
	int rchild;
	int value;
} HNodeType;        /* ���ṹ�� */

/* ����һ�Ź������� */
void HuffmanTree(HNodeType HuffNode[MAXNODE], int n)
{
	/* i��j�� ѭ��������m1��m2���������������ͬ������������СȨֵ����Ȩֵ��
	x1��x2���������������ͬ������������СȨֵ����������е���š�*/
	int i, j, m1, m2, x1, x2;
	/* ��ʼ����Ź����������� HuffNode[] �еĽ�� */
	for (i = 0; i<2 * n - 1; i++)
	{
		HuffNode[i].weight = 0;//Ȩֵ 
		HuffNode[i].parent = -1;
		HuffNode[i].lchild = -1;
		HuffNode[i].rchild = -1;
		HuffNode[i].value = i; //ʵ��ֵ���ɸ�������滻Ϊ��ĸ  
	} /* end for */

	/* ���� n ��Ҷ�ӽ���Ȩֵ */
	for (i = 0; i<n; i++)
	{
		printf("Please input weight of leaf node %d: \n", i);
		scanf("%d", &HuffNode[i].weight);
	} /* end for */

	/* ѭ������ Huffman �� */
	for (i = 0; i<n - 1; i++)
	{
		m1 = m2 = MAXVALUE;     /* m1��m2�д�������޸�����ҽ��Ȩֵ��С��������� */
		x1 = x2 = 0;
		/* �ҳ����н����Ȩֵ��С���޸�����������㣬���ϲ�֮Ϊһ�Ŷ����� */
		for (j = 0; j<n + i; j++)
		{
			if (HuffNode[j].weight < m1 && HuffNode[j].parent == -1)
			{
				m2 = m1;
				x2 = x1;
				m1 = HuffNode[j].weight;
				x1 = j;
			}
			else if (HuffNode[j].weight < m2 && HuffNode[j].parent == -1)
			{
				m2 = HuffNode[j].weight;
				x2 = j;
			}
		} /* end for */
		/* �����ҵ��������ӽ�� x1��x2 �ĸ������Ϣ */
		HuffNode[x1].parent = n + i;
		HuffNode[x2].parent = n + i;
		HuffNode[n + i].weight = HuffNode[x1].weight + HuffNode[x2].weight;
		HuffNode[n + i].lchild = x1;
		HuffNode[n + i].rchild = x2;

		printf("x1.weight and x2.weight in round %d: %d, %d\n", i + 1, HuffNode[x1].weight, HuffNode[x2].weight);  /* ���ڲ��� */
		printf("\n");
	} /* end for */
	/*  for(i=0;i<n+2;i++)
	{
	printf(" Parents:%d,lchild:%d,rchild:%d,value:%d,weight:%d\n",HuffNode[i].parent,HuffNode[i].lchild,HuffNode[i].rchild,HuffNode[i].value,HuffNode[i].weight);
	}*///���� 
} /* end HuffmanTree */

//���� 
void decodeing(char string[], HNodeType Buf[], int Num)
{
	int i, tmp = 0, code[1024];
	int m = 2 * Num - 1;
	char *nump;
	char num[1024];
	for (i = 0; i<strlen(string); i++)
	{
		if (string[i] == '0')
			num[i] = 0;
		else
			num[i] = 1;
	}
	i = 0;
	nump = &num[0];

	while (nump<(&num[strlen(string)]))
	{
		tmp = m - 1;
		while ((Buf[tmp].lchild != -1) && (Buf[tmp].rchild != -1))
		{

			if (*nump == 0)
			{
				tmp = Buf[tmp].lchild;
			}
			else tmp = Buf[tmp].rchild;
			nump++;

		}

		printf("%d", Buf[tmp].value);
	}
	printf("\n");
}


int main0(void)
{

	HNodeType HuffNode[MAXNODE];            /* ����һ�����ṹ������ */
	HCodeType HuffCode[MAXLEAF], cd;       /* ����һ������ṹ�����飬 ͬʱ����һ����ʱ���������������ʱ����Ϣ */
	int i, j, c, p, n;
	char pp[100];
	printf("Please input n:\n");
	scanf("%d", &n);
	HuffmanTree(HuffNode, n);

	for (i = 0; i < n; i++)
	{
		cd.start = n - 1;
		c = i;
		p = HuffNode[c].parent;
		while (p != -1)   /* �������� */
		{
			if (HuffNode[p].lchild == c)
				cd.bit[cd.start] = 0;
			else
				cd.bit[cd.start] = 1;
			cd.start--;        /* �����ĵ�һλ */
			c = p;
			p = HuffNode[c].parent;    /* ������һѭ������ */
		} /* end while */

		/* ���������ÿ��Ҷ���Ĺ���������ͱ������ʼλ */
		for (j = cd.start + 1; j<n; j++)
		{
			HuffCode[i].bit[j] = cd.bit[j];
		}
		HuffCode[i].start = cd.start;
	} /* end for */

	/* ����ѱ���õ����д��ڱ���Ĺ��������� */
	for (i = 0; i<n; i++)
	{
		printf("%d 's Huffman code is: ", i);
		for (j = HuffCode[i].start + 1; j < n; j++)
		{
			printf("%d", HuffCode[i].bit[j]);
		}
		printf(" start:%d", HuffCode[i].start);

		printf("\n");

	}
	/*    for(i=0;i<n;i++){
	for(j=0;j<n;j++)
	{
	printf ("%d", HuffCode[i].bit[j]);
	}
	printf("\n");
	}*/
	printf("Decoding?Please Enter code:\n");
	scanf("%s", &pp);
	decodeing(pp, HuffNode, n);
	getchar();
	return 0;
}