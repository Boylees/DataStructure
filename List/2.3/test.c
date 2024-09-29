#include <stdio.h>
#include <stdlib.h>

#include "2.3.3.h"
Status visit(ElemType c) {
    printf("%d ", c);
    return OK;
}
int main() {
    LinkList L;
    if (InitList(&L) != OK) {
        printf("²âÊÔ¿ªÊ¼");
        return 1;
    }

    for (int i = 1; i <= 5; i++) {
        Link p;
        if (MakeNode(&p, i) != OK) {
            printf("\n");
            return 1;
        }
        if (Append(&L, p) != OK) {
            printf("\n");
            return 1;
        }
        printf(":%d\n", i); 
    }

    
    printf("");
    if (ListTraverse(L, visit) != OK) {
        printf("\n");
        return 1;
    }

    if (DestroyList(&L) != OK) {
        printf("");
        return 1;
    }

    printf("\n");
    return 0;
}
