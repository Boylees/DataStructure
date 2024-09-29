#include <stdio.h>
#include <stdlib.h>
//-----------------------------------------
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef int ElemType;
//----------------------------------------

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *Link;

typedef struct {
    Link head, tail;
    int len;
} LinkList;

Status MakeNode(Link *p, ElemType e) {
    *p = (Link)malloc(sizeof(LNode));
    if (!*p) {
        return ERROR;
    }
    (*p)->data = e;
    (*p)->next = NULL;
    return OK;
}

void FreeNode(Link *p) {
    free(*p);
    *p = NULL;
}

Status InitList(LinkList *L) {
    L->head = L->tail = (Link)malloc(sizeof(LNode));
    if (!L->head) {
        return ERROR;
    }
    L->head->next = NULL;
    L->len = 0;
    return OK;
}

Status DestroyList(LinkList *L) {
    Link p = L->head;
    while (p) {
        Link q = p->next;
        FreeNode(&p);
        p = q;
    }
    L->head = L->tail = NULL;
    L->len = 0;
    return OK;
}

Status ClearList(LinkList *L) {
    Link p = L->head->next;
    while (p) {
        Link q = p->next;
        FreeNode(&p);
        p = q;
    }
    L->head->next = NULL;
    L->tail = L->head;
    L->len = 0;
    return OK;
}

Status InsFirst(Link h, Link s) {
    s->next = h->next;
    h->next = s;
    return OK;
}

Status DelFirst(Link h, Link *q) {
    if (h->next == NULL) {
        return ERROR;
    }
    *q = h->next;
    h->next = (*q)->next;
    (*q)->next = NULL;
    return OK;
}

Status Append(LinkList *L, Link s) {
    Link p = s;
    int count = 0;
    while (p) {
        L->tail->next = p;
        L->tail = p;
        p = p->next;
        count++;
    }
    L->len += count;
    return OK;
}

Status Remove(LinkList *L, Link *q) {
    Link p = L->head;
    while (p->next && p->next != *q) {
        p = p->next;
    }
    if (p->next == *q) {
        if (*q == L->tail) {
            L->tail = p;
        }
        p->next = (*q)->next;
        FreeNode(q);
        L->len--;
        return OK;
    }
    return ERROR;
}

Status InsBefore(LinkList *L, Link *p, Link s) {
    Link q = L->head;
    while (q->next && q->next != *p) {
        q = q->next;
    }
    if (q->next == *p) {
        s->next = *p;
        q->next = s;
        L->len++;
        return OK;
    }
    return ERROR;
}

Status InsAfter(LinkList *L, Link *p, Link s) {
    s->next = (*p)->next;
    (*p)->next = s;
    if (*p == L->tail) {
        L->tail = s;
    }
    L->len += 1;
    return OK;
}

Status SetCurElem(Link *p, ElemType e) {
    (*p)->data = e;
    return OK;
}

ElemType GetCurElem(Link p) {
    return p->data;
}

Status ListEmpty(LinkList L) {
    if (L.len == 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}

int ListLength(LinkList L) {
    return L.len;
}

typedef Link Position;

Position GetHead(LinkList L) {

    return L.head;
}

Position GetLast(LinkList L) {
    return L.tail;
}

Position PriorPos(LinkList L, Link p) {
    Link q = L.head;
    while (q->next != p) {
        q = q->next;
    }
    return q;
}

Position NextPos(Link p) {
    if (p->next == NULL) {
        return NULL;
    }
    return p->next;
}

Status LocatePos(LinkList L, int i, Link *p) {
    if (i <= 0 || i > L.len) {
        return ERROR;
    }
    *p = L.head;
    for (int j = 1; j <= i; j++) {
        *p = (*p)->next;
    }
    return OK;
}

Position LocateElem(LinkList L, ElemType e, Status (*compare)(ElemType, ElemType)) {
    Link p = L.head->next;
    while (p && !compare(p->data, e)) {
        p = p->next;
    }
    return p;
}

Status ListTraverse(LinkList L, Status (*visit)(ElemType)) {
    Link p = L.head->next;
    while (p) {
        visit(p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}




