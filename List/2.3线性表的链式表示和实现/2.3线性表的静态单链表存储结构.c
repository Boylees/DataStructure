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