/*
  编写将两个多项式相加的函数。
  不要毁坏输入数据
  用一个链表实现
  如果这两个多项式分别有 M 项和 N 项，那么你的程序的时间复杂度是多少？
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node *PtrToNode;
typedef struct Node {
    int Coefficient;
    int Exponent;
    struct Node *next;
};
typedef PtrToNode Polynomial;

void AddPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolySum) {
    PtrToNode P1, P2, P3;
    P1 = Poly1->next;
    P2 = Poly2->next;
    P3 = PolySum;
    while (P1 != NULL && P2 != NULL) {
        if (P1 == NULL) {
            P3->next = malloc(sizeof(struct Node));
            P3 = P3->next;
            P3->Coefficient = P2->Coefficient;
            P3->Exponent = P2->Exponent;
            P2 = P2->next;
            continue;
        }
        else if (P2 == NULL) {
            P3->next = malloc(sizeof(struct Node));
            P3 = P3->next;
            P3->Coefficient = P1->Coefficient;
            P3->Exponent = P1->Exponent;
            P1 = P1->next;
            continue;
        } else if (P1->Exponent > P2->Exponent) {
            P3->next = malloc(sizeof(struct Node));
            P3 = P3->next;
            P3->Coefficient = P1->Coefficient;
            P3->Exponent = P1->Exponent;
            P1 = P1->next;
        } else if (P1->Exponent < P2->Exponent) {
            P3->next = malloc(sizeof(struct Node));
            P3 = P3->next;
            P3->Coefficient = P2->Coefficient;
            P3->Exponent = P2->Exponent;
            P2 = P2->next;
        } else {
            if (P1->Coefficient + P2->Coefficient != 0) {
                P3->next = malloc(sizeof(struct Node));
                P3 = P3->next;
                P3->Coefficient = P1->Coefficient + P2->Coefficient;
                P3->Exponent = P1->Exponent;
            }
            P1 = P1->next;
            P2 = P2->next;
        }
    }
}