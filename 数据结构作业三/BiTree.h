#include<stdio.h>
typedef char TElemType;
int a = 0;
int i = 0;
typedef struct BiTNode {
	TElemType data;
	struct BiTNode *lchild, *rchild;

}BiTNode, *BiTree;
typedef char Status;

Status PrintElement(TElemType e)//����ÿһ�����������
{
	printf("%c", e);
	return 1;
}


Status Visit(TElemType e)//��������ĵ�i����
{
	a++;
	if (a == i)
		printf("%c", e);
	return 1;
}
//order˳��Traverse����1


Status PreOrderTraverse(BiTree T, Status(*Visit)(TElemType e))//��������������ݹ��㷨
{
	if (T) {
		if (Visit(T->data))
			if (PreOrderTraverse(T->lchild, Visit))
				if (PreOrderTraverse(T->rchild, Visit)) return 1;
		return -1;
	}
	else return 1;
}
Status InOrderTraverse(BiTree T, Status(*Visit)(TElemType e))//��������ݹ��㷨
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
Status PostOrderTraverse(BiTree T, Status(*Visit)(TElemType e))//��������ݹ��㷨
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
		CreateBiTree(T->lchild);//�ݹ齨���������ң���������
		CreateBiTree(T->rchild);
	}
	return 1;//���ظ��ڵ�
}
Status FindBiTree(BiTree &T, int i)//����
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
