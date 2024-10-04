#ifndef _Stack_h

typedef int ElemType;
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

int IsEmpty(Stack S);
Stack CreateStack(void);
void MakeEmpty(Stack S);
void Push(ElemType X, Stack S);
ElemType Top(Stack S);
void Pop(Stack S);

#endif /* _Stack_h */
