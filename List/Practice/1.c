//�Ա�дһ������֪��������������ƽ��ֵ�ĺ�������������������Ϊ���ͣ�
#include <stdio.h>

typedef struct LNode {
    int data;
    struct LNode *next;
}*LinkList, LNode;


double Average(LinkList L) {
    LinkList p = L->next;
    int sum = 0;
    int count = 0;
    while (p != NULL) {
        sum += p->data;
        count++;
        p = p->next;
    }
    if (count == 0) {
        return 0;
    } else {
        return (double)sum / count;
    }
}