#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode {
    int price;
    int count;
    struct LNode *next;
}*LinkList, LNode;

//3.某百货公司仓库中有一批电视机，按其价格从低到高的次序构成一个循环链表，每个结点有价格、数量和链指针三个域。现出库（销售）m台价格为h的电视机，试编写算法修改原链表。 
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