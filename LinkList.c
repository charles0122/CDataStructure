#include<stdio.h>
#include<stdlib.h>

/* 状态码 */
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20		/* 存储空间初始分配量 */


typedef int ElemType;		/* ElemType根据实际情况而定，这里假定为 int */
typedef int Status;			/* 状态代码 */


typedef struct Node{
	ElemType data;
	struct Node* next;
} Node;

/* 声明一个指向单链表第一个结点的指针 
比 Node* 可读性更强
Node* 强调是一个结点
LinkList 强调是一个单链表 */
typedef struct Node* LinkList;


/*初始化单链表  建立一个空的线性表L
返回值类型 Status（自定义类型）
函数名 InitList 初始化表
参数列表 LinkList *L  结构体指针 */
Status InitList(LinkList L) {
	/* 不带头结点的写法 */
	//L = NULL;
	//return TRUE;
	/* 带头结点的写法 
	头结点不存储数据*/
	L = (LinkList)malloc(sizeof(Node));
	if (L == NULL) 
		return FALSE;
	L->next = NULL;
	return TRUE;
}

/*判断线性表是否为空 若为空返回true 否则返回false
返回值类型 Status
函数名 Empty  表空？
参数列表 ListList L 结构体 */
Status Empty(LinkList L) {
	if (L->next == NULL) return TRUE;
	return FALSE;
}

/*将线性表清空
返回值类型 Status
函数名 ClearList
参数列表 LinkList L 结构体 */
Status ClearList(LinkList L) {
	return OK;
}


Status ListInsert(LinkList L,int i,ElemType e) {
	if (i < 1) return FALSE;
	Node* p;		 /* 指针p指向当前扫描的结点 */
	int j = 0;			/* 当前p指向第几个结点 */
	p = L;			/* L指向头结点，头结点是下标为0的结点，不存储数据 */
	while (p!=NULL&&j<i-1)	/* 找到第i-1个结点 */
	{
		p = p->next;
		j++;
	}
	if (p == NULL) return FALSE;
	Node* s = (Node*)malloc(sizeof(Node));
	s->data = e;			/* 在结点s的存储数据元素e */
	s->next = p->next;		/* 将p结点的下一个结点的地址值赋值给s的next指针 */
	p->next = s;		/* 将结点s接到p之后 */
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
	s->data = p->data;		/* 将p结点存放的数据赋值给s结点的data */
	p->data = e;			/* 将需要存的e数据覆盖p结点的旧数据 */
	return TRUE;
}


Status ListDelete(LinkList L,int i,ElemType e) {

}

main() {

}
