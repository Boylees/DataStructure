//已知带有头结点的循环链表中头指针为head,试写出删除并释放数据域值为x的所有结点的c函数
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode *next;
}*LinkList, LNode;

void Deletex(LinkList *L, ElemType x) {
    if (*L == NULL) {
        return;
    }
    LNode *p = *L;
    LNode *temp;
    while (p->data == x) {
        temp = p;
        while (p->next != *L) {
            p = p->next;
        }
        p->next = (*L)->next;//p->next 访问的是 p 所指向的结构体，而 (*L)->next 指向的是 L 所指向的结构体的 next
        *L = (*L)->next;
        releasex(temp);
        if (*L == temp) {
            *L = NULL;
            return;
        }
        p = *L;
    }
    LNode *prev = p;
    p = p->next;
    while (p != *L) {
        if (p->data == x) {
            temp = p;
            prev->next = p->next;
            p = p->next;
            releasex(temp);
        }
        else {
            prev = p;
            p = p->next;
        }
    }
}
void releasex(LNode *p) {
    free(p);
}