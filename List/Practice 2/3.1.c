// ��д��ӡһ�������������Ԫ�صĳ���
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

void printlist(List L) {
    Position P = L->next;
    while (P != NULL) {
        printf("%d ", P->data);
        P = P->next;
    }
}

