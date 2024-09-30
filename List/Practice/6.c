/*
  6.设A=(a0,a1,a2,...,an-1),B=(b0,b1,b2,...,bm-1)是两个给定的线性表,它们的结点个数分别是n和m,且结点值均是整数。 
  若n=m，且 ai= bi （0≤i<n ），则A=B； 
  若n<m ，且ai=bi （0≤i<n ），则A<B； 
  若存在一个j， j<m ，j<n ，且ai=bi （0≤i<j ）， 若aj<bj，则A<B，否则 A>B。 
  试编写一个比较A和B的C函数，该函数返回 -1或 0或 1，分别表示 A<B或 A=B或 A>B。 
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
    printf("Result: %d\n", result); // 输出 -1 表示 A < B
    return 0;
}