//5.���Ա��е�Ԫ��ֵ�������������У���� ˳��� �� ѭ������ ���ֲ�ͬ�Ĵ洢��ʽ
//�ֱ��дC����ɾ�����Ա���ֵ����a��b��a��b��֮���Ԫ�ء� 
#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
    int data;
    struct LNode *next;
}LNode, *LinkList;

void Delete_List(LinkList *L, int a, int b) {
    LNode *p = *L;
    // ����ͷ���
    while (p != NULL && p->data >= a && p->data <= b){
        (*L) = (*L)->next;
        free(p);
        p = (*L);
    }
    LNode *temp;
    while (p != NULL && p->next != NULL && p->next != *L) {
        if (p->next->data >= a && p->next->data <=b) {
            temp = p->next;
            p->next = temp->next;
            free(temp);
        }
        else {
            p = p->next;
        }
    }
}