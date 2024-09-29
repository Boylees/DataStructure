#include <stdio.h>
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef enum {
    OK = 1,
    ERROR = 0,
    TRUE = 1,
    FALSE = 0
} Status;

typedef struct{
    int *elem;
    int length;
    int listsize;
}SqList;

int InitList(SqList *L){
    L->elem=(int *)malloc(LIST_INIT_SIZE*sizeof(int));
    if(!L->elem) exit(0);
    L->length=0;
    L->listsize=LIST_INIT_SIZE;
    return 1;
}

void check(int i, SqList *L) {
    // 当前存储空间已满，重新分配。这步比较重要。
    if (L->length >= L->listsize) {
        int *newbase = (int *)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(int));
        if (!newbase) {
            exit(0);
        };
        L->elem = newbase;
        L->listsize += LISTINCREMENT;
    }
}

int ListInsert_Sq(int num, int i, SqList *L) {
    // 将元素 num 插入到 线性表 L 的第 i 个元素之前
    if (i < 1 || i > L->length + 1) {
        printf("比如插入到正确位置");
        return 0;      
    }    
    check(i, L);
    for (int j = L->length + 1; j >= i; j++) {
        L->elem[j] = L->elem[j - 1];
    }
    L->length += 1;
    L->elem[i - 1] = num;
    return 1;
}

int ListDelete_Sq(SqList *L, int i, int e) {
    // 检查删除位置是否合法
    if (i < 1 || i > L->length) {
        printf("删除位置不合法");
        return 0;
    }
    e = L->elem[i - 1];
    for (int j = i; j < L->length; j++) {
        L->elem[j - 1] = L->elem[j];
    }
    L->length -= 1;
    return 1;
}

int LocateElem_Sq(SqList L, int e, Status (*compare)(int, int)) {
    // 返回线性表 L 中第一个与 e 满足关系 compare() 的数据元素的位序
    int i;
    for (i = 0; i < L.length; i++) {
        if (compare(L.elem[i], e)) {
            return i + 1;
        }
    }
    return 0;
}

Status compare(int a, int b) {
    if (a == b) {
        return TRUE;
    } else {
        return FALSE;
    }
}

void MergeList_Sq(SqList La, SqList Lb, SqList *Lc) {
    // 已知线性表 La 和 Lb 的元素按值非递减排列
    // 归并 La 和 Lb 得到新的线性表 Lc，Lc 的元素也按值非递减排列
    int *pa, *pb, *pc;
    int *pa_last, *pb_last;
    pa = La.elem;
    pb = Lb.elem;
    Lc->listsize = Lc->length = La.length + Lb.length;
    pc = Lc->elem = (int *)malloc(Lc->listsize * sizeof(int));
    if (!Lc->elem) {
        exit(0);
    }
    pa_last = La.elem + La.length - 1;
    pb_last = Lb.elem + Lb.length - 1;
    while (pa <= pa_last && pb <= pb_last) {
        if (*pa <= *pb) {
            *pc = *pa;
            pc++;
            pa++;
        } else {
            *pc = *pb;
            pc++;
            pb++;
        }
    }
    while (pa <= pa_last) {
        *pc = *pa;
        pc++;
        pa++;
    }
    while (pb <= pb_last) {
        *pc = *pb;
        pc++;
        pb++;
    }
}


int main(){
    return 0;
}