/* 给你一个链表 L 和 另一个链表 P，它们包含以升序排列的整数。
操作 PrintLots(L, P) 将打印 L 中那些由 P 指定的位置上的元素。
例如，如果 P = 1, 3, 4, 6，那么 L 中的第 1，3，4，6 个元素将被打印。
写出过程 PrintLots(L, P)。只使用基本的表操作。
*/
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

void PrintLots(List L, List P) {
    Position p = P->next;
    Position l = L->next;
    while (p != NULL && l != NULL) {
        int tmp = p->data;
        while (tmp - 1) {
            l = l->next;
            tmp--;
        }
        printf("%d ", l->data);
        p = p->next;
    }
}