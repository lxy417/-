// 数据结构作业三.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std; 
typedef char TElemType ;
typedef struct BiTNode {
	TElemType data;
	struct BiTNode *lchild, *rchild;
	
}BiTNode,*BiTree;
typedef char Status;

Status PrintElement(TElemType e)
{
	printf("%c",e);
	return 1;
}
//order顺序Traverse遍历1


Status PreOrderTraverse(BiTree T,Status(*Visit)(TElemType e))//先序遍历二叉树递归算法
{
	if (T) {
		if (Visit(T->data))
			if(PreOrderTraverse(T->lchild,Visit))
				if (PreOrderTraverse(T->rchild, Visit)) return 1;
		return -1;
	}
	else return 1;
}
Status InOrderTraverse(BiTree T, Status(*Visit)(TElemType e))//中序遍历递归算法
{
	if (T)
	{
		if (InOrderTraverse(T->lchild, Visit))
			if (Visit(T->data))
				if (InOrderTraverse(T->rchild, Visit)) return 1;
		return -1;
	}
	else return 1;
}
Status PostOrderTraverse(BiTree T, Status(*Visit)(TElemType e))//后序遍历递归算法
{
	if (T)
	{
		if(PostOrderTraverse(T->lchild,Visit))
			if(PostOrderTraverse(T->rchild,Visit))
				if(Visit(T->data)) return 1;
		return -1;
	}
	else return 1;
}

Status CreateBiTree(BiTree &T) {
	char ch;
	
	scanf_s("%c", &ch);
	if (ch == '#')
		T = NULL;
	else {
		T = (BiTree)malloc(sizeof(BiTNode));
		T->data = ch;
		CreateBiTree(T->lchild);//递归建树（根左右：先序建树）
		CreateBiTree(T->rchild);
	}
	return 1;//返回根节点
}

int main()
{
	BiTNode *T;
	CreateBiTree(T);
	PostOrderTraverse(T, PrintElement);
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
