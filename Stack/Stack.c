#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

typedef struct Node {
    ElemType data;
    struct Node *next;
};

typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

int IsEmpty(Stack S) {
    return S->next == NULL;
}

Stack CreateStack(void) {
    Stack S = malloc(sizeof(struct Node));
    if (S == NULL) {
        printf("Out of space!");
        return NULL;
    }
    S->next = NULL;
    MakeEmpty(S);
    return S;
}

void MakeEmpty(Stack S) {
    if (S == NULL) {
        printf("Must use CreateStack first");
        return;
    }
    while (!IsEmpty(S)) {
        Pop(S);
    }
}

void Push(ElemType X, Stack S) {
    PtrToNode TmpCell;
    TmpCell = malloc(sizeof(struct Node));
    if (TmpCell = NULL) {
        printf("Out of space");
        return; 
    }
    TmpCell->data = X;
    TmpCell->next = S->next;
    S->next = TmpCell;
}

ElemType Top(Stack S) {
    if (!IsEmpty(S)) {
        return S->next->data;
    }
    printf("Empty Stack");
    return 0;
}

void Pop(Stack S) {
    PtrToNode FirstCell;
    if (IsEmpty(S)) {
        printf("Empty Stack");
    }
    FirstCell = S->next;
    S->next = S->next->next;
    free(FirstCell);
}