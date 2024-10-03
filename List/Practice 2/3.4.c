// ��������������ı� L1 �� L2��ֻʹ�û����ı������д���� L1 �� L2 �Ĺ���

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct Node {
    ElemType data;
    struct Node *next;
};

typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List jiaoyunsuan(List L1, List L2) {
    Position P = L1->next;
    Position Q = L2->next;
    List L = (List)malloc(sizeof(struct Node));
    L->next = NULL;
    Position R = L;
    while (P != NULL && Q != NULL) {
        if (P->data == Q->data) {
            Position tmp = (Position)malloc(sizeof(struct Node));
            tmp->data = P->data;
            R->next = tmp;
            tmp->next = NULL;
            R = R->next;
            P = P->next;
            Q = Q->next;
        } else if (P->data < Q->data) {
            P = P->next;
        } else {
            Q = Q->next;
        }
        
    }
}