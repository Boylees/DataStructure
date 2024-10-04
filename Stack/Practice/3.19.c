// 编写一个计算后缀表达式的程序
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int main() {
    Stack S;
    S = CreateStack();
    char c;
    int a, b;
    while ((c = getchar()) != '\n') {
        if (c >= '0' && c <= '9') {
            Push(c - '0', S);
        } else {
            a = Top(S);
            Pop(S);
            b = Top(S);
            Pop(S);
            switch (c) {
                case '+':
                    Push(a + b, S);
                    break;
                case '-':
                    Push(b - a, S);
                    break;
                case '*':
                    Push(a * b, S);
                    break;
                case '/':
                    Push(b / a, S);
                    break;
                default:
                    break;
            }
        }
    }
    printf("%d\n", Top(S));
    return 0;
}