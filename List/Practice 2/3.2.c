/* ����һ������ L �� ��һ������ P�����ǰ������������е�������
���� PrintLots(L, P) ����ӡ L ����Щ�� P ָ����λ���ϵ�Ԫ�ء�
���磬��� P = 1, 3, 4, 6����ô L �еĵ� 1��3��4��6 ��Ԫ�ؽ�����ӡ��
д������ PrintLots(L, P)��ֻʹ�û����ı������
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