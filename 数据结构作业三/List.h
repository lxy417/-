#include <stdio.h>
#define MaxSize  100
typedef int DataType;

typedef struct
{
	DataType list[MaxSize];
	int size;
} SeqList;

void ListInitiate(SeqList *L)/*初始化顺序表L*/
{
	L->size = 0;/*定义初始数据元素个数*/
}

int  ListLength(SeqList L)/*返回顺序表L的当前数据元素个数*/
{
	return L.size;
}

int ListInsert(SeqList *L, int i, DataType x)
/*在顺序表L的位置i（0 ≤ i ≤ size）前插入数据元素值x*/
/*插入成功返回1，插入失败返回0*/
{
	int j = 0;
	if (L->size >= MaxSize)
	{
		printf("顺序表已满无法插入! \n");
		return 0;
	}
	else if (i < 0 || i > L->size)
	{
		printf("参数i不合法! \n");
		return 0;
	}
	else
	{ //此段程序有一处错误
		for (j = L->size; j > i - 1; j--) L->list[j + 1] = L->list[j];/*为插入做准备*/
		L->list[i] = x;/*插入*/
		L->size++;/*元素个数加1*/
		return 1;
	}
}

int ListDelete(SeqList *L, int i, DataType *x)
/*删除顺序表L中位置i（0 ≤ i ≤ size - 1）的数据元素值并存放到参数x中*/
/*删除成功返回1，删除失败返回0*/
{
	int j;
	if (L->size <= 0)
	{
		printf("顺序表已空无数据元素可删! \n");
		return 0;
	}
	else if (i < 0 || i > L->size - 1)
	{
		printf("参数i不合法");
		return 0;
	}
	else
	{//此段程序有一处错误
		*x = L->list[i];/*保存删除的元素到参数x中*/
		for (j = i + 1; j <= L->size - 1; j++) L->list[j - 1] = L->list[j];/*依次前移*/
		L->size--;/*数据元素个数减1*/
		return 1;
	}
}

int ListGet(SeqList L, int i, DataType *x)
/*取顺序表L中第i个数据元素的值存于x中，成功则返回1，失败返回0*/
{
	if (i < 0 || i > L.size - 1)
	{
		printf("参数i不合法! \n");
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
		if (xa >= xb)//a元素大放b
		{
			ListInsert(Lc, k++, xb);

			j++;
			//      Lc->size++;
		}
		else//b元素大放a
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
		//        Lc->size++；
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
//	  //     ListGet(myList,i,&x); //此段程序有一处错误
//   //printf("%d", x);
//	 //  }
//	return 0;
//}
