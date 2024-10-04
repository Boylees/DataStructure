/*
用下面语言编写检测平衡符号的程序：
a. Pascal (begin/end, (), [], {})
b. C( )
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node *PtrToNode;
typedef struct Node {
    char Data;
    struct Node *next;
};
typedef PtrToNode Stack;

int IsEmpty(Stack S) {
    return S->next == NULL;
}

Stack CreateStack(void) {
    Stack S;
    S = malloc(sizeof(struct Node));
    if (S == NULL) {
        printf("Out of space!!!");
        exit(1);
    }
    S->next = NULL;
    return S;
}

void MakeEmpty(Stack S) {
    if (S == NULL) {
        printf("Must use CreateStack first!!!");
        exit(1);
    } else
        while (!IsEmpty(S))
            Pop(S);
}

void Push(char X, Stack S) {
    PtrToNode TmpCell;
    TmpCell = malloc(sizeof(struct Node));
    if (TmpCell == NULL) {
        printf("Out of space!!!");
        exit(1);
    } else {
        TmpCell->Data = X;
        TmpCell->next = S->next;
        S->next = TmpCell;
    }
}

char Top(Stack S) {
    if (!IsEmpty(S))
        return S->next->Data;
    printf("Empty stack!!!");
    return 0;
}

void Pop(Stack S) {
    PtrToNode FirstCell;
    if (IsEmpty(S)) {
        printf("Empty stack!!!");
        exit(1);
    } else {
        FirstCell = S->next;
        S->next = S->next->next;
        free(FirstCell);
    }
}

int main(void) {
    Stack S;
    S = CreateStack();
    char c;
    while ((c = getchar()) != '\n') {
        if (c == '(' || c == '[' || c == '{')
            Push(c, S);
        else if (c == ')') {
            if (Top(S) == '(')
                Pop(S);
            else {
                printf("Not balanced!!!");
                return 0;
            }
        } else if (c == ']') {
            if (Top(S) == '[')
                Pop(S);
            else {
                printf("Not balanced!!!");
                return 0;
            }
        } else if (c == '}') {
            if (Top(S) == '{')
                Pop(S);
            else {
                printf("Not balanced!!!");
                return 0;
            }
        }
    }
    if (IsEmpty(S))
        printf("Balanced!!!");
    else
        printf("Not balanced!!!");
    return 0;
}
// 时间复杂度是 O(N)