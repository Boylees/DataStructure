// ��дһ����������������ʽ��ˣ���һ������ʵ�֡�����뱣֤����Ķ���ʽ���ݴ����в��������һ��Ϊ������
// a.������ O(M��N��)ʱ������������㷨

#include <stdio.h>
#include <stdlib.h>

typedef struct Node *PtrToNode;

typedef struct Node {
    int Coefficient;
    int Exponent;
    struct Node *next;
};
typedef PtrToNode Polynomial;


Polynomial OM2N2(Polynomial Poly1, Polynomial Poly2) {
    // the output polynomial must be sorted
    PtrToNode P1, P2, P3, P4, P5;
    Polynomial PolySum = malloc(sizeof(struct Node));
    P1 = Poly1->next;
    P2 = Poly2->next;
    P3 = PolySum;
    while (P1 != NULL) {
        P2 = Poly2->next;
        while (P2 != NULL) {
            P3 = PolySum;
            while (P3->next != NULL) {
                P3 = P3->next;
            }
            P3->next = malloc(sizeof(struct Node));
            P3 = P3->next;
            P3->Coefficient = P1->Coefficient * P2->Coefficient;
            P3->Exponent = P1->Exponent + P2->Exponent;
            P2 = P2->next;
        }
        P1 = P1->next;
    }
    P3 = PolySum;

    while (P3->next != NULL) {
        P4 = P3->next;
        P5 = P4->next;
        while (P5 != NULL) {
            if (P4->Exponent < P5->Exponent) {
                int temp = P4->Exponent;
                P4->Exponent = P5->Exponent;
                P5->Exponent = temp;
                temp = P4->Coefficient;
                P4->Coefficient = P5->Coefficient;
                P5->Coefficient = temp;
            }
            P5 = P5->next;
        }
        P3 = P4;
    }
    return PolySum;
}
