//5.线性表中的元素值按递增有序排列，针对 顺序表 和 循环链表 两种不同的存储方式
//分别编写C函数删除线性表中值介于a与b（a≤b）之间的元素。 
#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
    int data;
    struct LNode *next;
}LNode, *LinkList;

void Delete_List(LinkList *L, int a, int b) {
    LNode *p = *L;
    // 处理头结点
    while (p != NULL && p->data >= a && p->data <= b){
        (*L) = (*L)->next;
        free(p);
        p = (*L);
    }
    LNode *temp;
    while (p != NULL && p->next != NULL && p->next != *L) {
        if (p->next->data >= a && p->next->data <=b) {
            temp = p->next;
            p->next = temp->next;
            free(temp);
        }
        else {
            p = p->next;
        }
    }
}