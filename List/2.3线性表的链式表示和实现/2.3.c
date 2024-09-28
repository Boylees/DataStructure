#include <stdio.h>
//-----------------------------------------
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef int ElemType;
typedef int bool;
//----------------------------------------

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

Status GetElem_L(LinkList L, int i, ElemType *e) {
    LNode *p = L->next;
    int j = 1;
    while(p && j < i) {
        p = p->next;
        ++j;
    }
    if (!p || j > i) {
        return ERROR;
    }
    *e = p->data;
    return OK;
}

Status ListInsert_L(LinkList *L, int i , ElemType e) {
    // 在带头结点的单链线性表L的第i个元素之前插入元素e
    LNode *p = *L;
    int j = 0;
    while(p && j < i - 1) {
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1) {
        return ERROR;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

Status ListDelete_L(LinkList *L, int i, ElemType *e) {
    // 在带头结点的单链线性表L中，删除第i个元素，并由e返回其值
    LNode *p = *L;
    int j = 0;
    while(p->next && j < i - 1) {
        p = p->next;
        ++j;
    }
    if (!(p->next) || j > i - 1) {
        return ERROR;
    }
    LNode *q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    return OK;
}

void CreateList_L(LinkList *L, int n) {
    // 逆位序输入n个元素的值，建立带表头结点的单链线性表L
    *L = (LinkList)malloc(sizeof(LNode));
    (*L)->next = NULL;
    for (int i = n; i > 0; --i) {
        LNode *p = (LNode *)malloc(sizeof(LNode));
        scanf("%d", &p->data);
        p->next = (*L)->next;
        (*L)->next = p;
    }
}

void MergeList_L(LinkList *La, LinkList *Lb, LinkList *Lc) {
    // 已知单链线性表La和Lb的元素按值非递减排列
    // 归并La和Lb得到新的单链线性表Lc，Lc的元素也按值非递减排列
    LNode *pa = (*La)->next;
    LNode *pb = (*Lb)->next;
    LNode *pc = *Lc = *La;
    while(pa && pb) {
        if (pa->data <= pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        } else {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa ? pa : pb;
    free(*Lb);
}

