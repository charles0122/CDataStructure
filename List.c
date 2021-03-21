#include<stdio.h>

/* 状态码 */
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20		/* 存储空间初始分配量 */


typedef int ElemType;		/* ElemType根据实际情况而定，这里假定为 int */
typedef int Status;			/* 状态代码 */


/*
typedef 数据类型 别名;
该段将（匿名）结构体的别名设置为SqList（顺序表）
顺序存储结构的线性表
*/
typedef struct
{
	ElemType data[MAXSIZE];
	int length;
} SqList; 



/*初始化顺序表  建立一个空的线性表L
返回值类型 Status（自定义类型）
函数名 InitList 初始化表
参数列表 SqList *L  结构体指针 */ 
Status InitList(SqList *L) {
	L->length = 0;
	return OK;
}


/*判断线性表是否为空 若为空返回true 否则返回false
返回值类型 Status  
函数名 ListEmpty  表空？
参数列表 SqList L 结构体 */
Status ListEmpty(SqList L) {
	return L.length == 0 ? TRUE : FALSE;
}


/*将线性表清空
返回值类型 Status 
函数名 ClearList 
参数列表 SqList *L 结构体指针 */
Status ClearList(SqList* L) {
	L->length = 0;
	return OK;
}

/*将线性表L中的第i个位置元素值返回给e
返回值类型 Status
函数名 GetElem 
参数列表 SqList L 结构体, int i , ElemType *e ElemType型引用   */
Status GetElem(SqList L,int i,ElemType *e){
	if (L.length == 0) return ERROR;
	if (i>=1 && i<=L.length)
	{
		*e = L.data[i-1];
		return OK;
	}
	return ERROR;
	
}

/*在线性表中查找与给定元素e值相等的元素 如果查找成功 返回该该元素在表中的序号 否则返回 0
返回值类型 int
函数名 LocateElem
参数列表 SqList L 结构体, ElemType e ElemType型参数 */
int LocateElem(SqList L, ElemType e) {
	if (L.length == 0) return 0;
	for (int i = 0; i < L.length; i++)
	{
		if (e == L.data[i]) return i+1;
	}
	return 0;
}

/*在线性表L中第i个位置之前插入元素e
返回值类型 Status
函数名 ListInsert
参数列表 SqList *L 结构体指针, int i,ElemType e ElemType型参数 */
Status ListInsert(SqList* L, int i, ElemType e) {
	if (L->length == MAXSIZE) return ERROR;   /*表满*/
	if (i<1 || i>L->length + 1) return ERROR;
	if (i<=L->length)        /* 若插入数据位置不在表尾 */
	{
		for (int k = L->length - 1; k >= i - 1; k--)  /* 将i以及i位置之后的数据元素向后移动一位 */
			L->data[k + 1] = L->data[k];
	}
	L->data[i - 1] = e;
	L->length++;
	return OK;
	
}

/*删除线性表L中第i个位置的元素，并用e返回其值
返回值类型 Status
函数名 ListDelete
参数列表 SqList *L 结构体指针, int i,ElemType *e ElemType型引用 */
Status ListDelete(SqList* L, int i, ElemType *e) {
	if (L->length == 0) return ERROR;   /* 表空 */
	if (i<1 || i>L->length) return ERROR;
	*e = L->data[i - 1];		/* 将要删除的值返回给e*/	
	if (i < L->length)        /* 若删除数据位置不在表尾 */
	{
		for (int k = i; k < L->length; k++)  /* 将i以及i位置之后的数据元素向前移动一位 */
			L->data[k - 1] = L->data[k];
	}
	L->length--;
	return OK;

}

/*返回线性表L的元素个数
返回值类型 int
函数名 ListLength
参数列表 SqList L */
int ListLength(SqList L) {
	return L.length;
}

/* 遍历L的所有元素
返回值类型 Status
函数名 ListTraverse
参数列表 SqList L 结构体*/
Status ListTraverse(SqList L) {
	for (int i = 0; i < L.length; i++)
		visit(L.data[i]);
	return OK;
}


/* 将元素c输出*/
Status visit(ElemType c)
{
	printf("%d ", c);
	return OK;
}

/* 将所有的在线性表Lb中但不在La中的数据元素插入到La中*/
void unionL(SqList* La, SqList Lb) {
	ElemType e;
	int La_len = ListLength(*La);
	int Lb_len = ListLength(Lb);
	for (int i = 1; i < Lb_len; i++)
	{
		GetElem(Lb, i, &e);
		if (!LocateElem(*La, e)) ListInsert(La,++La_len, e);
	}
}

int main() {
	SqList L;
	SqList Lb;

	ElemType e;
	Status i;
	int j, k;
	i = InitList(&L);
	printf("初始化L后：L.length=%d\n", L.length);
	for (j = 1; j <= 5; j++) {
		i = ListInsert(&L, 1, j);
	}
	printf("在L的表头依次插入1～5后：L.data=");
	ListTraverse(L);

	printf("L.length=%d \n", L.length);
	i = ListEmpty(L);
	printf("L是否空：i=%d(1:是 0:否)\n", i);

	i = ClearList(&L);
	printf("清空L后：L.length=%d\n", L.length);
	i = ListEmpty(L);
	printf("L是否空：i=%d(1:是 0:否)\n", i);

	for (j = 1; j <= 10; j++)
		ListInsert(&L, j, j);
	printf("在L的表尾依次插入1～10后：L.data=");
	ListTraverse(L);

	printf("L.length=%d \n", L.length);

	ListInsert(&L, 1, 0);
	printf("在L的表头插入0后：L.data=");
	ListTraverse(L);
	printf("L.length=%d \n", L.length);

	GetElem(L, 5, &e);
	printf("第5个元素的值为：%d\n", e);
	for (j = 3; j <= 4; j++)
	{
		k = LocateElem(L, j);
		if (k)
			printf("第%d个元素的值为%d\n", k, j);
		else
			printf("没有值为%d的元素\n", j);
	}


	k = ListLength(L); /* k为表长 */
	for (j = k + 1; j >= k; j--)
	{
		i = ListDelete(&L, j, &e); /* 删除第j个数据 */
		if (i == ERROR)
			printf("删除第%d个数据失败\n", j);
		else
			printf("删除第%d个的元素值为：%d\n", j, e);
	}
	printf("依次输出L的元素：");
	ListTraverse(L);

	j = 5;
	ListDelete(&L, j, &e); /* 删除第5个数据 */
	printf("删除第%d个的元素值为：%d\n", j, e);

	printf("依次输出L的元素：");
	ListTraverse(L);

	//构造一个有10个数的Lb
	i = InitList(&Lb);
	for (j = 6; j <= 15; j++)
		i = ListInsert(&Lb, 1, j);

	unionL(&L, Lb);

	printf("依次输出合并了Lb的L的元素：");
	ListTraverse(L);
	return 0;
}


