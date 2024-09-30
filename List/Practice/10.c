/*
  10.试写出将一个线性表分解为两个带有头结点的循环链表
  并将两个循环链表的长度放在各自的头结点的数据域中的C函数
  其中,线性表中序号为偶数的元素分解到第一个循环链表中
  序号为奇数的元素分解到第二个循环链表中。 
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
    int data;
    struct LNode *next;
}LNode, *LinkList;

void Split(LinkList L, LinkList *head1, LinkList *head2) {
    LNode *p = L;
    LNode *q = (LNode*)malloc(sizeof(LNode));
    *head1 = p;
    *head2 = q;
    LNode *temp1 = *head1;
    LNode *temp2 = *head2;
    int count1 = 0;
    int count2 = 0;
    while (p->next != L) {
        if (count1 % 2 == 0) {
            temp1->next = p;
            temp1 = p;
            count1++;
        } else {
            temp2->next = p;
            temp2 = p;
            count2++;
        }
        p = p->next;
    }
    if (count1 % 2 == 0) {
        temp1->next = p;
        temp1 = p;
        count1++;
    } else {
        temp2->next = p;
        temp2 = p;
        count2++;
    }
    temp1->next = *head1;
    temp2->next = *head2;
    (*head1)->data = count1;
    (*head2)->data = count2;
}