#include "list.h"
#include <stdlib.h>
#include <stdio.h>

struct Node
{
    ElementType Element;
    Position Next;
};

int IsEmpty(List L)
{
    return L->Next == NULL;
}

int IsLast(Position P, List L)
{
    return P->Next == NULL;
}

Position Find(ElementType X, List L) {
    Position P;

    P = L->Next;
    while (P != NULL && P->Element != X) {
        P = P->Next;
    }
    return P;
}

void Delete(ElementType X, List L) {
    Position P, TmpCell;
    P = FindPrevious(X, L);
    if (!IsLast(P, L)) {
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free(TmpCell);
    }
}

Position FindPrevious(ElementType X, List L) {
    Position P;
    P = L;
    while (P->Next != NULL && P->Next->Element != X) {
        P = P->Next;
    }
    return P;
}

void Insert(ElementType X, List L, Position P) {
    Position TmpCell;
    TmpCell = malloc(sizeof(struct Node));
    if (TmpCell == NULL) {
        printf("Out of space!!!");
    }

    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}

void DeleteList(List L) {
    Position P, Tmp;
    P = L->Next;
    L->Next = NULL;
    while (P != NULL) { 
        Tmp = P->Next;
        free(P);
        P = Tmp;
    }
}
int main() {
    List myList;
    Position pos;
    ElementType elem;

    // ����һ��������
    myList = malloc(sizeof(struct Node));
    myList->Next = NULL;

    // ���Բ��뺯��
    Insert(10, myList, myList);
    Insert(20, myList, myList);
    Insert(30, myList, myList);

    // ��ӡ����Ԫ��
    printf("List elements after insertion: ");
    pos = myList->Next;
    while (pos != NULL) {
        printf("%d ", pos->Element);
        pos = pos->Next;
    }
    printf("\n");

    // ���Բ��Һ���
    pos = Find(20, myList);
    if (pos != NULL) {
        printf("Element 20 found in the list.\n");
    } else {
        printf("Element 20 not found in the list.\n");
    }

    // ����ɾ������
    Delete(20, myList);
    printf("List elements after deleting 20: ");
    pos = myList->Next;
    while (pos != NULL) {
        printf("%d ", pos->Element);
        pos = pos->Next;
    }
    printf("\n");

    // ����ɾ����������
    DeleteList(myList);
    if (IsEmpty(myList)) {
        printf("List is empty after deleting all elements.\n");
    } else {
        printf("List is not empty after deleting all elements.\n");
    }

    // �ͷ�����ͷ�ڵ�
    free(myList);

    return 0;
}