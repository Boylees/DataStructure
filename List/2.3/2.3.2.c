#define MAXSIZE 1000
typedef int ElemType;
typedef struct {
    ElemType data;
    int cur;
}component, SLinkList[MAXSIZE];

int LocateElem_SL(SLinkList S, ElemType e) {
    int i = S[0].cur;
    while (i && S[i].data != e) {
        i = S[i].cur;
    }
    return i;
}

void InitSpace_SL(SLinkList *space) {
    for (int i = 0; i < MAXSIZE - 1; i+=1) {
        space[i]->cur = i + 1;
    }
    space[MAXSIZE - 1]->cur = 0;
}

int Malloc_SL(SLinkList *space) {
    int i = space[0]->cur;
    if (space[0]->cur) {
        space[0]->cur = space[i]->cur;
    }
    return i;
}

void Free_SL(SLinkList *space, int k) {
    space[k]->cur = space[0]->cur;
    space[0]->cur = k;
}

void difference(SLinkList *space, int *S) {
    // 依次输入集合A和B的元素，在一维数组space中建立表示集合(A-B)∪(B-A)的静态链表
    InitSpace_SL(space);
    S = Malloc_SL(space);
    int r = S;
    int m, n;
    scanf("%d", &m);
    scamf("%d", &n);
    for (int j = 1; j <= m; j+=1) {
        int i = Malloc_SL(space);
        scanf("%d", &space[i]->data);
        space[r]->cur = i;
        r = i;
    }
    space[r]->cur = 0;
    for (int j = 1; j <= n; j+=1) {
        int b;
        scanf("%d", &b);
        int p = S;
        int k = space[*S]->cur;
        while (k != space[r]->cur && space[k]->data != b) {
            p = k;
            k = space[k]->cur;
        }
        if (k == space[r]->cur) {
            int i = Malloc_SL(space);
            space[i]->data = b;
            space[i]->cur = space[r]->cur;
            space[r]->cur = i;
        } else {
            space[p]->cur = space[k]->cur;
            Free_SL(space, k);
            if (r == k) {
                r = p;
            }
        }
    }

}