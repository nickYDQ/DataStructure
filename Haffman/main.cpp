//#include <iostream>
//using namespace std;
//
//struct HuffNode         //哈夫曼树结点结构
//{
//	int weight;         //权值
//	int parent;         //父结点
//	int lchild;         //左儿子
//	int rchild;         //右儿子
//};
//
//
//struct HuffCode         //哈夫曼编码结构
//{
//	int bit[10];        //存储哈夫曼编码
//	int start;          //哈夫曼编码在数组中的起始位置
//	int weight;         //权值
//};
//
//
////实现哈夫曼编码
//void Huffman(int w[], int n, HuffNode hn[], HuffCode hc[])
//{
//	int m1, m2;          //分别存放最小，次小权值
//	int x1, x2;          //分别表示当前结点左右儿子
//	HuffCode cd;
//	int child, parent;
//	int i, j;
//	
//	for (i = 0; i<2 * n - 1; i++)//初始化哈夫曼树
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
//	for (i = 0; i<n - 1; i++)   //构造哈夫曼树的n-1个分支结点
//	{
//		m1 = m2 = 1000;
//		x1 = x2 = 0;
//		for (j = 0; j<n + i; j++)
//		{
//
//			if (hn[j].weight<m1&&hn[j].parent == 0)//最小保存到次小
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
//	for (i = 0; i<n; i++) //由哈夫曼树生成哈夫曼编码      
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
//	cout << "哈夫曼编码如下:" << endl;
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
*Name:   哈夫曼编码源代码。
* Date : 2011.04.16
* Author : Jeffrey Hill + Jezze(解码部分)
* 在 Win - TC 下测试通过
* 实现过程：着先通过 HuffmanTree() 函数构造哈夫曼树，然后在主函数 main()中
*           自底向上开始(也就是从数组序号为零的结点开始)向上层层判断，若在
*           父结点左侧，则置码为 0, 若在右侧, 则置码为 1。最后输出生成的编码。
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
} HCodeType;        /* 编码结构体 */
typedef struct
{
	int weight;
	int parent;
	int lchild;
	int rchild;
	int value;
} HNodeType;        /* 结点结构体 */

/* 构造一颗哈夫曼树 */
void HuffmanTree(HNodeType HuffNode[MAXNODE], int n)
{
	/* i、j： 循环变量，m1、m2：构造哈夫曼树不同过程中两个最小权值结点的权值，
	x1、x2：构造哈夫曼树不同过程中两个最小权值结点在数组中的序号。*/
	int i, j, m1, m2, x1, x2;
	/* 初始化存放哈夫曼树数组 HuffNode[] 中的结点 */
	for (i = 0; i<2 * n - 1; i++)
	{
		HuffNode[i].weight = 0;//权值 
		HuffNode[i].parent = -1;
		HuffNode[i].lchild = -1;
		HuffNode[i].rchild = -1;
		HuffNode[i].value = i; //实际值，可根据情况替换为字母  
	} /* end for */

	/* 输入 n 个叶子结点的权值 */
	for (i = 0; i<n; i++)
	{
		printf("Please input weight of leaf node %d: \n", i);
		scanf("%d", &HuffNode[i].weight);
	} /* end for */

	/* 循环构造 Huffman 树 */
	for (i = 0; i<n - 1; i++)
	{
		m1 = m2 = MAXVALUE;     /* m1、m2中存放两个无父结点且结点权值最小的两个结点 */
		x1 = x2 = 0;
		/* 找出所有结点中权值最小、无父结点的两个结点，并合并之为一颗二叉树 */
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
		/* 设置找到的两个子结点 x1、x2 的父结点信息 */
		HuffNode[x1].parent = n + i;
		HuffNode[x2].parent = n + i;
		HuffNode[n + i].weight = HuffNode[x1].weight + HuffNode[x2].weight;
		HuffNode[n + i].lchild = x1;
		HuffNode[n + i].rchild = x2;

		printf("x1.weight and x2.weight in round %d: %d, %d\n", i + 1, HuffNode[x1].weight, HuffNode[x2].weight);  /* 用于测试 */
		printf("\n");
	} /* end for */
	/*  for(i=0;i<n+2;i++)
	{
	printf(" Parents:%d,lchild:%d,rchild:%d,value:%d,weight:%d\n",HuffNode[i].parent,HuffNode[i].lchild,HuffNode[i].rchild,HuffNode[i].value,HuffNode[i].weight);
	}*///测试 
} /* end HuffmanTree */

//解码 
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

	HNodeType HuffNode[MAXNODE];            /* 定义一个结点结构体数组 */
	HCodeType HuffCode[MAXLEAF], cd;       /* 定义一个编码结构体数组， 同时定义一个临时变量来存放求解编码时的信息 */
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
		while (p != -1)   /* 父结点存在 */
		{
			if (HuffNode[p].lchild == c)
				cd.bit[cd.start] = 0;
			else
				cd.bit[cd.start] = 1;
			cd.start--;        /* 求编码的低一位 */
			c = p;
			p = HuffNode[c].parent;    /* 设置下一循环条件 */
		} /* end while */

		/* 保存求出的每个叶结点的哈夫曼编码和编码的起始位 */
		for (j = cd.start + 1; j<n; j++)
		{
			HuffCode[i].bit[j] = cd.bit[j];
		}
		HuffCode[i].start = cd.start;
	} /* end for */

	/* 输出已保存好的所有存在编码的哈夫曼编码 */
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