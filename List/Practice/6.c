/*
  6.��A=(a0,a1,a2,...,an-1),B=(b0,b1,b2,...,bm-1)���������������Ա�,���ǵĽ������ֱ���n��m,�ҽ��ֵ���������� 
  ��n=m���� ai= bi ��0��i<n ������A=B�� 
  ��n<m ����ai=bi ��0��i<n ������A<B�� 
  ������һ��j�� j<m ��j<n ����ai=bi ��0��i<j ���� ��aj<bj����A<B������ A>B�� 
  �Ա�дһ���Ƚ�A��B��C�������ú������� -1�� 0�� 1���ֱ��ʾ A<B�� A=B�� A>B�� 
*/
#include <stdio.h>

int compare(int A[], int n, int B[], int m) {
    int i;
    for (i = 0; i < n && i < m; i++) {
        if (A[i] < B[i]) {
            return -1;
        } else if (A[i] > B[i]) {
            return 1;
        }
    }
    if (n == m) {
        return 0;
    } else if (n < m) {
        return -1;
    } else {
        return 1;
    }
}

int main() {
    int A[] = {1, 2, 3};
    int B[] = {1, 2, 3, 4};
    int n = sizeof(A) / sizeof(A[0]);
    int m = sizeof(B) / sizeof(B[0]);
    int result = compare(A, n, B, m);
    printf("Result: %d\n", result); // ��� -1 ��ʾ A < B
    return 0;
}