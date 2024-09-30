/*
8.���Ա���ǰ�����������ʲ�ͬ��Ԫ�����(a0,a1,...,an-1,b0,b1,...,bm-1)
m��nΪ������Ԫ�صĸ���,�����Ա�ֱ����������������ַ�ʽ�洢
��д�㷨��������Ԫ�ػ�λ��(b0,b1,...,bm-1,a0,a1,...,an-1)
�������ִ洢��ʽ���㷨��ʱ��Ϳռ临�Ӷȡ� 
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
    int data;
    struct LNode *next;
}LNode, *LinkList;

LinkList Merge(LinkList L, int n, int m) {
    LNode *p = L;
    LNode *q = L;
    for (int i = 0; i < n; i++) {
        q = q->next;
    }
    LNode *temp = q->next;
    q->next = NULL;
    q = temp;
    while (q->next != NULL) {
        q = q->next;
    }
    q->next = p;
    return temp;
}