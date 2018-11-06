#include<stdio.h>
typedef char TElemType;
int a = 0;
int i = 0;
typedef struct BiTNode {
	TElemType data;
	struct BiTNode *lchild, *rchild;

}BiTNode, *BiTree;
typedef char Status;

Status PrintElement(TElemType e)//遍历每一个数，都输出
{
	printf("%c", e);
	return 1;
}


Status Visit(TElemType e)//输出遍历的第i个数
{
	a++;
	if (a == i)
		printf("%c", e);
	return 1;
}
//order顺序Traverse遍历1


Status PreOrderTraverse(BiTree T, Status(*Visit)(TElemType e))//先序遍历二叉树递归算法
{
	if (T) {
		if (Visit(T->data))
			if (PreOrderTraverse(T->lchild, Visit))
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
		if (PostOrderTraverse(T->lchild, Visit))
			if (PostOrderTraverse(T->rchild, Visit))
				if (Visit(T->data)) return 1;
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
Status FindBiTree(BiTree &T, int i)//查找
{
	PreOrderTraverse(T, Visit);
	return 1;
}
int Count(BiTree &T) {
	if (T == NULL) {
		return 0;
	}
	else if ((T->lchild == NULL) && (T->rchild == NULL)) {
		return 1;
	}
	else {
		return Count(T->lchild) + Count(T->rchild);
	}
}
