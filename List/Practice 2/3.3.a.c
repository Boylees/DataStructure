// ͨ��ֻ����ָ�루���������ݣ��������������ڵ�Ԫ�أ�ʹ��
// a. ������

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

void changebyptr(List L, Position P, Position Q) {
    Position ptr = L->next;
    while (ptr != P) {
        ptr = ptr->next;
    }
    Position after = Q;
    P->data = after->data;
    after->data = ptr->data;
}
