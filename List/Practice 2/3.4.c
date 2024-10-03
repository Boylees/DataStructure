// 给定两个已排序的表 L1 和 L2，只使用基本的表操作编写计算 L1 交 L2 的过程

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