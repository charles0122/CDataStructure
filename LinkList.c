#include<stdio.h>
#include<stdlib.h>

/* ״̬�� */
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20		/* �洢�ռ��ʼ������ */


typedef int ElemType;		/* ElemType����ʵ���������������ٶ�Ϊ int */
typedef int Status;			/* ״̬���� */


typedef struct Node{
	ElemType data;
	struct Node* next;
} Node;

/* ����һ��ָ�������һ������ָ�� 
�� Node* �ɶ��Ը�ǿ
Node* ǿ����һ�����
LinkList ǿ����һ�������� */
typedef struct Node* LinkList;


/*��ʼ��������  ����һ���յ����Ա�L
����ֵ���� Status���Զ������ͣ�
������ InitList ��ʼ����
�����б� LinkList *L  �ṹ��ָ�� */
Status InitList(LinkList L) {
	/* ����ͷ����д�� */
	//L = NULL;
	//return TRUE;
	/* ��ͷ����д�� 
	ͷ��㲻�洢����*/
	L = (LinkList)malloc(sizeof(Node));
	if (L == NULL) 
		return FALSE;
	L->next = NULL;
	return TRUE;
}

/*�ж����Ա��Ƿ�Ϊ�� ��Ϊ�շ���true ���򷵻�false
����ֵ���� Status
������ Empty  ��գ�
�����б� ListList L �ṹ�� */
Status Empty(LinkList L) {
	if (L->next == NULL) return TRUE;
	return FALSE;
}

/*�����Ա����
����ֵ���� Status
������ ClearList
�����б� LinkList L �ṹ�� */
Status ClearList(LinkList L) {
	return OK;
}


Status ListInsert(LinkList L,int i,ElemType e) {
	if (i < 1) return FALSE;
	Node* p;		 /* ָ��pָ��ǰɨ��Ľ�� */
	int j = 0;			/* ��ǰpָ��ڼ������ */
	p = L;			/* Lָ��ͷ��㣬ͷ������±�Ϊ0�Ľ�㣬���洢���� */
	while (p!=NULL&&j<i-1)	/* �ҵ���i-1����� */
	{
		p = p->next;
		j++;
	}
	if (p == NULL) return FALSE;
	Node* s = (Node*)malloc(sizeof(Node));
	s->data = e;			/* �ڽ��s�Ĵ洢����Ԫ��e */
	s->next = p->next;		/* ��p������һ�����ĵ�ֵַ��ֵ��s��nextָ�� */
	p->next = s;		/* �����s�ӵ�p֮�� */
	return TRUE;
}



Status InsertNextNode(Node* p, ElemType e) {
	if (p == NULL) return FALSE;
	Node* s = (Node*)malloc(sizeof(Node));
	if (s == NULL) return FALSE;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return TRUE;
}


Status InsertPriorNode(Node* p,ElemType e) {
	if (p == NULL) return FALSE;
	Node* s = (Node*)malloc(sizeof(Node));
	if (s == NULL) return FALSE;
	s->next = p->next;
	p->next = s;
	s->data = p->data;		/* ��p����ŵ����ݸ�ֵ��s����data */
	p->data = e;			/* ����Ҫ���e���ݸ���p���ľ����� */
	return TRUE;
}


Status ListDelete(LinkList L,int i,ElemType e) {

}

main() {

}
