// 给定两个已排序的表 L1 和 L2，只使用基本的表操作编写计算 L1 并 L2 的过程

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

List bing(List L1, List L2) {
    List L = (List)malloc(sizeof(List));
    Position P = L1->next;
    Position Q = L2->next;
    Position R = L;
    L->next = NULL;
    while (! (P == NULL && Q == NULL)) {
        if (P == NULL) {
            Position tmp = (Position)malloc(sizeof(Position));
            tmp->data = Q->data;
            tmp->next = NULL;
            R->next = tmp;
            R = R->next;
            Q = Q->next;
        }
        else if (Q == NULL) {
            Position tmp = (Position)malloc(sizeof(Position));
            tmp->data = P->data;
            tmp->next = NULL;
            R->next = tmp;
            R = R->next;
            P = P->next;
        }
        else if (P->data == Q->data) {
            Position tmp = (Position)malloc(sizeof(Position));
            tmp->data = P->data;
            tmp->next = NULL;
            R->next = tmp;
            R = R->next;
            P = P->next;
            Q = Q->next;
        }
        else if (P->data < Q->data) {
            Position tmp = (Position)malloc(sizeof(Position));
            tmp->data = P->data;
            tmp->next = NULL;
            R->next = tmp;
            R = R->next;
            P = P->next;
        }
        else {
            Position tmp = (Position)malloc(sizeof(Position));
            tmp->data = Q->data;
            tmp->next = NULL;
            R->next = tmp;
            R = R->next;
            Q = Q->next;
        }
    }

}