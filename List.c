#include<stdio.h>

/* ״̬�� */
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20		/* �洢�ռ��ʼ������ */


typedef int ElemType;		/* ElemType����ʵ���������������ٶ�Ϊ int */
typedef int Status;			/* ״̬���� */


/*
typedef �������� ����;
�öν����������ṹ��ı�������ΪSqList��˳���
˳��洢�ṹ�����Ա�
*/
typedef struct
{
	ElemType data[MAXSIZE];
	int length;
} SqList; 



/*��ʼ��˳���  ����һ���յ����Ա�L
����ֵ���� Status���Զ������ͣ�
������ InitList ��ʼ����
�����б� SqList *L  �ṹ��ָ�� */ 
Status InitList(SqList *L) {
	L->length = 0;
	return OK;
}


/*�ж����Ա��Ƿ�Ϊ�� ��Ϊ�շ���true ���򷵻�false
����ֵ���� Status  
������ ListEmpty  ��գ�
�����б� SqList L �ṹ�� */
Status ListEmpty(SqList L) {
	return L.length == 0 ? TRUE : FALSE;
}


/*�����Ա����
����ֵ���� Status 
������ ClearList 
�����б� SqList *L �ṹ��ָ�� */
Status ClearList(SqList* L) {
	L->length = 0;
	return OK;
}

/*�����Ա�L�еĵ�i��λ��Ԫ��ֵ���ظ�e
����ֵ���� Status
������ GetElem 
�����б� SqList L �ṹ��, int i , ElemType *e ElemType������   */
Status GetElem(SqList L,int i,ElemType *e){
	if (L.length == 0) return ERROR;
	if (i>=1 && i<=L.length)
	{
		*e = L.data[i-1];
		return OK;
	}
	return ERROR;
	
}

/*�����Ա��в��������Ԫ��eֵ��ȵ�Ԫ�� ������ҳɹ� ���ظø�Ԫ���ڱ��е���� ���򷵻� 0
����ֵ���� int
������ LocateElem
�����б� SqList L �ṹ��, ElemType e ElemType�Ͳ��� */
int LocateElem(SqList L, ElemType e) {
	if (L.length == 0) return 0;
	for (int i = 0; i < L.length; i++)
	{
		if (e == L.data[i]) return i+1;
	}
	return 0;
}

/*�����Ա�L�е�i��λ��֮ǰ����Ԫ��e
����ֵ���� Status
������ ListInsert
�����б� SqList *L �ṹ��ָ��, int i,ElemType e ElemType�Ͳ��� */
Status ListInsert(SqList* L, int i, ElemType e) {
	if (L->length == MAXSIZE) return ERROR;   /*����*/
	if (i<1 || i>L->length + 1) return ERROR;
	if (i<=L->length)        /* ����������λ�ò��ڱ�β */
	{
		for (int k = L->length - 1; k >= i - 1; k--)  /* ��i�Լ�iλ��֮�������Ԫ������ƶ�һλ */
			L->data[k + 1] = L->data[k];
	}
	L->data[i - 1] = e;
	L->length++;
	return OK;
	
}

/*ɾ�����Ա�L�е�i��λ�õ�Ԫ�أ�����e������ֵ
����ֵ���� Status
������ ListDelete
�����б� SqList *L �ṹ��ָ��, int i,ElemType *e ElemType������ */
Status ListDelete(SqList* L, int i, ElemType *e) {
	if (L->length == 0) return ERROR;   /* ��� */
	if (i<1 || i>L->length) return ERROR;
	*e = L->data[i - 1];		/* ��Ҫɾ����ֵ���ظ�e*/	
	if (i < L->length)        /* ��ɾ������λ�ò��ڱ�β */
	{
		for (int k = i; k < L->length; k++)  /* ��i�Լ�iλ��֮�������Ԫ����ǰ�ƶ�һλ */
			L->data[k - 1] = L->data[k];
	}
	L->length--;
	return OK;

}

/*�������Ա�L��Ԫ�ظ���
����ֵ���� int
������ ListLength
�����б� SqList L */
int ListLength(SqList L) {
	return L.length;
}

/* ����L������Ԫ��
����ֵ���� Status
������ ListTraverse
�����б� SqList L �ṹ��*/
Status ListTraverse(SqList L) {
	for (int i = 0; i < L.length; i++)
		visit(L.data[i]);
	return OK;
}


/* ��Ԫ��c���*/
Status visit(ElemType c)
{
	printf("%d ", c);
	return OK;
}

/* �����е������Ա�Lb�е�����La�е�����Ԫ�ز��뵽La��*/
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
	printf("��ʼ��L��L.length=%d\n", L.length);
	for (j = 1; j <= 5; j++) {
		i = ListInsert(&L, 1, j);
	}
	printf("��L�ı�ͷ���β���1��5��L.data=");
	ListTraverse(L);

	printf("L.length=%d \n", L.length);
	i = ListEmpty(L);
	printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n", i);

	i = ClearList(&L);
	printf("���L��L.length=%d\n", L.length);
	i = ListEmpty(L);
	printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n", i);

	for (j = 1; j <= 10; j++)
		ListInsert(&L, j, j);
	printf("��L�ı�β���β���1��10��L.data=");
	ListTraverse(L);

	printf("L.length=%d \n", L.length);

	ListInsert(&L, 1, 0);
	printf("��L�ı�ͷ����0��L.data=");
	ListTraverse(L);
	printf("L.length=%d \n", L.length);

	GetElem(L, 5, &e);
	printf("��5��Ԫ�ص�ֵΪ��%d\n", e);
	for (j = 3; j <= 4; j++)
	{
		k = LocateElem(L, j);
		if (k)
			printf("��%d��Ԫ�ص�ֵΪ%d\n", k, j);
		else
			printf("û��ֵΪ%d��Ԫ��\n", j);
	}


	k = ListLength(L); /* kΪ�� */
	for (j = k + 1; j >= k; j--)
	{
		i = ListDelete(&L, j, &e); /* ɾ����j������ */
		if (i == ERROR)
			printf("ɾ����%d������ʧ��\n", j);
		else
			printf("ɾ����%d����Ԫ��ֵΪ��%d\n", j, e);
	}
	printf("�������L��Ԫ�أ�");
	ListTraverse(L);

	j = 5;
	ListDelete(&L, j, &e); /* ɾ����5������ */
	printf("ɾ����%d����Ԫ��ֵΪ��%d\n", j, e);

	printf("�������L��Ԫ�أ�");
	ListTraverse(L);

	//����һ����10������Lb
	i = InitList(&Lb);
	for (j = 6; j <= 15; j++)
		i = ListInsert(&Lb, 1, j);

	unionL(&L, Lb);

	printf("��������ϲ���Lb��L��Ԫ�أ�");
	ListTraverse(L);
	return 0;
}


