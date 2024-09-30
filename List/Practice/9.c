/*
9.��ѭ�����������Ա�(a0,a1,...,an-1)�ͣ�b0,b1,...,bm-1���Ĵ洢�ṹ ͷָ��ֱ�Ϊah��bh
���C���� ���������Ա�ϲ������磨a0,b0,a1,b1,���������Ա�
Ҫ�󲻿����µĶ�̬�ռ� ����ԭ��ѭ������Ľ����ɺϲ����� �ṹ��Ϊѭ������
ͷָ��Ϊhead �������㷨��ʱ�临�Ӷȡ� 
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
    int data;
    struct LNode *next;
}LNode, *LinkList;

LinkList Merge(LinkList head1, LinkList head2) {
    LNode *p = head1;
    LNode *q = head2;
    LNode *temp1, *temp2;
    while (p->next != head1) {
        temp1 = p->next;
        p->next = q;
        temp2 = q->next;
        q->next = temp1;
        p = temp1;
        q = temp2;
    }
    p->next = q;
    q->next = head1;
    return head1;
}
