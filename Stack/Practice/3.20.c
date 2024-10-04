// 编写一个程序将中缀表达式转换成成后缀表达式
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int main() {
    Stack S;
    S = CreateStack();
    char c;
    while ((c = getchar()) != '\n') {
        if (c >= '0' && c <= '9') {
            printf("%c", c);
        } else {
            if (c == '(') {
                Push(c, S);
            } else if (c == ')') {
                while (Top(S) != '(') {
                    printf("%c", Top(S));
                    Pop(S);
                }
                Pop(S);
            } else {
                while (!IsEmpty(S) && Top(S) != '(' && (c == '*' || c == '/') && (Top(S) == '+' || Top(S) == '-')) {
                    printf("%c", Top(S));
                    Pop(S);
                }
                Push(c, S);
            }
        }
    }
    while (!IsEmpty(S)) {
        printf("%c", Top(S));
        Pop(S);
    }
    printf("\n");
    return 0;
}