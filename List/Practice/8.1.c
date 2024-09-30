/*
8.���Ա���ǰ�����������ʲ�ͬ��Ԫ�����(a0,a1,...,an-1,b0,b1,...,bm-1)
m��nΪ������Ԫ�صĸ���,�����Ա�ֱ����������������ַ�ʽ�洢
��д�㷨��������Ԫ�ػ�λ��(b0,b1,...,bm-1,a0,a1,...,an-1)
�������ִ洢��ʽ���㷨��ʱ��Ϳռ临�Ӷȡ� 
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