/*
8.线性表由前后两部分性质不同的元素组成(a0,a1,...,an-1,b0,b1,...,bm-1)
m和n为两部分元素的个数,若线性表分别采用数组和链表两种方式存储
编写算法将两部分元素换位成(b0,b1,...,bm-1,a0,a1,...,an-1)
分析两种存储方式下算法的时间和空间复杂度。 
*/

#include <stdio.h>
#include <stdlib.h>

int* Merge(int* array, int n, int m) {
    int *temp = (int*)malloc(sizeof(int) * (n + m));
    for (int i = 0; i < m; i++) {
        temp[i] = array[n + i];
    }
    for (int i = 0; i < n; i++) {
        temp[m + i] = array[i];
    }
    return temp;
}