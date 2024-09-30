/*
9.用循环链表作线性表(a0,a1,...,an-1)和（b0,b1,...,bm-1）的存储结构 头指针分别为ah和bh
设计C函数 把两个线性表合并成形如（a0,b0,a1,b1,…）的线性表
要求不开辟新的动态空间 利用原来循环链表的结点完成合并操作 结构仍为循环链表
头指针为head 并分析算法的时间复杂度。 
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
