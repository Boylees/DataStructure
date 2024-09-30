#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode {
    int price;
    int count;
    struct LNode *next;
}*LinkList, LNode;

//3.ĳ�ٻ���˾�ֿ�����һ�����ӻ�������۸�ӵ͵��ߵĴ��򹹳�һ��ѭ������ÿ������м۸���������ָ���������ֳ��⣨���ۣ�m̨�۸�Ϊh�ĵ��ӻ����Ա�д�㷨�޸�ԭ���� 
void Sell(LinkList *L, int m, int h) {
    LNode *p = *L;
    LNode *temp;
    if ((*L)->price == h) {   
        if (p->count > m) {
            p->count -=m;
        }
        else if (p->count == m) {
            while (p->next != *L) {
                p = p->next;
            }
            temp = *L;
            *L = (*L)->next;
            free(temp);
            temp = NULL;
        }
        else return;
        return;
    }
    while (p->price != h && p->next != *L) {
        temp = p;
        p = p->next;
    }
    if (p->count > m) {
        p->count -= m;
    }
    else if (p->count == m) {
        temp->next = p->next;
        free(p);
        p = NULL;
    }
    else return;
}