#include <stdio.h>
#define MaxSize  100
typedef int DataType;

typedef struct
{
	DataType list[MaxSize];
	int size;
} SeqList;

void ListInitiate(SeqList *L)/*��ʼ��˳���L*/
{
	L->size = 0;/*�����ʼ����Ԫ�ظ���*/
}

int  ListLength(SeqList L)/*����˳���L�ĵ�ǰ����Ԫ�ظ���*/
{
	return L.size;
}

int ListInsert(SeqList *L, int i, DataType x)
/*��˳���L��λ��i��0 �� i �� size��ǰ��������Ԫ��ֵx*/
/*����ɹ�����1������ʧ�ܷ���0*/
{
	int j = 0;
	if (L->size >= MaxSize)
	{
		printf("˳��������޷�����! \n");
		return 0;
	}
	else if (i < 0 || i > L->size)
	{
		printf("����i���Ϸ�! \n");
		return 0;
	}
	else
	{ //�˶γ�����һ������
		for (j = L->size; j > i - 1; j--) L->list[j + 1] = L->list[j];/*Ϊ������׼��*/
		L->list[i] = x;/*����*/
		L->size++;/*Ԫ�ظ�����1*/
		return 1;
	}
}

int ListDelete(SeqList *L, int i, DataType *x)
/*ɾ��˳���L��λ��i��0 �� i �� size - 1��������Ԫ��ֵ����ŵ�����x��*/
/*ɾ���ɹ�����1��ɾ��ʧ�ܷ���0*/
{
	int j;
	if (L->size <= 0)
	{
		printf("˳����ѿ�������Ԫ�ؿ�ɾ! \n");
		return 0;
	}
	else if (i < 0 || i > L->size - 1)
	{
		printf("����i���Ϸ�");
		return 0;
	}
	else
	{//�˶γ�����һ������
		*x = L->list[i];/*����ɾ����Ԫ�ص�����x��*/
		for (j = i + 1; j <= L->size - 1; j++) L->list[j - 1] = L->list[j];/*����ǰ��*/
		L->size--;/*����Ԫ�ظ�����1*/
		return 1;
	}
}

int ListGet(SeqList L, int i, DataType *x)
/*ȡ˳���L�е�i������Ԫ�ص�ֵ����x�У��ɹ��򷵻�1��ʧ�ܷ���0*/
{
	if (i < 0 || i > L.size - 1)
	{
		printf("����i���Ϸ�! \n");
		return 0;
	}
	else
	{
		*x = L.list[i];
		return 1;
	}
}
int ListMerge(SeqList La, SeqList Lb, SeqList *Lc)
{
	ListInitiate(Lc);
	int i = 0, j = 0, k = 0;
	int xa, xb;
	int La_len = ListLength(La);
	int Lb_len = ListLength(Lb);
	while ((i <= La_len - 1) && (j <= Lb_len - 1))
	{
		ListGet(La, i, &xa);
		ListGet(Lb, j, &xb);
		if (xa >= xb)//aԪ�ش��b
		{
			ListInsert(Lc, k++, xb);

			j++;
			//      Lc->size++;
		}
		else//bԪ�ش��a
		{
			ListInsert(Lc, k, xa);
			k++;
			i++;
			//        Lc->size++;
		}
	}
	while (i <= La_len - 1)//La long
	{
		ListGet(La, i++, &xa);
		ListInsert(Lc, k, xa);
		k++;
		//     Lc->size++;
	}
	while (j <= Lb_len - 1)
	{
		ListGet(Lb, j++, &xb);
		ListInsert(Lc, k, xb);
		k++;
		//        Lc->size++��
	}
	return 0;
}
//int main(void)
//{
//	SeqList myList, myList2, Lc;
//
//	int i, x;
//	ListInitiate(&myList);
//	ListInitiate(&myList2);
//	for (i = 0; i < 10; i++)
//		ListInsert(&myList, i, i + 1);
//	for (i = 0; i < 10; i++)
//		ListInsert(&myList2, i, i + 1);
//	ListMerge(myList, myList2, &Lc);
//	for (i = 0; i < ListLength(myList); i++)
//	{
//		ListGet(myList, i, &x);
//		printf("%d", x);
//
//	}
//	printf("\n");
//	for (i = 0; i < ListLength(myList2); i++)
//	{
//		ListGet(myList2, i, &x);
//		printf("%d", x);
//
//	}
//	printf("\n");
//	for (i = 0; i < ListLength(Lc); i++)
//	{
//		ListGet(Lc, i, &x);
//		printf("%d", x);
//
//	}
//	//   ListDelete(&myList, 4, &x);
//	 //  for(i = 0; i < ListLength(myList); i++)
//	 //  {
//	  //     ListGet(myList,i,&x); //�˶γ�����һ������
//   //printf("%d", x);
//	 //  }
//	return 0;
//}
