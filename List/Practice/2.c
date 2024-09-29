//��֪����ͷ����ѭ��������ͷָ��Ϊhead,��д��ɾ�����ͷ�������ֵΪx�����н���c����
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
        p->next = (*L)->next;//p->next ���ʵ��� p ��ָ��Ľṹ�壬�� (*L)->next ָ����� L ��ָ��Ľṹ��� next
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