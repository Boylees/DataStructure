// 通过只调整指针（而不是数据）来交换两个相邻的元素，使用
// a. 单链表

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
