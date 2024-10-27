#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Maxn 104

typedef struct {
    int data;
} Node[Maxn][Maxn];

typedef struct {
    Node length;
    int node;
    int aec;
} Figure;

Figure* CreatFigure(Figure *f) {
    int node, aec;
    scanf("%d%d", &node, &aec);
    f->node = node;
    f->aec = aec;
    for (int i = 1; i <= f->node; i++) {
        for (int j = 1; j <= f->node; j++) {
            f->length[i][j].data = 105; // 这里105相当于两点间没有路
        }
    }
    for (int i = 1; i <= f->aec; i++) {
        int j, k;
        scanf("%d%d", &j, &k);
        f->length[j][k].data = 1;
        f->length[k][j].data = 1;
    }
    return f;
}

double BFS(Figure* f, int node) {
    int cur[Maxn], next[Maxn];
    bool visited[Maxn] = {false};
    int cur_front = 0, cur_back = 0, next_front = 0, next_back = 0;
    cur[cur_back++] = node;
    visited[node] = true;
    int degree = 0;
    double count = 1;

    while (cur_front != cur_back) {
        degree++;
        if (degree == 7)
            break;

        while (cur_front != cur_back) {
            int tmp = cur[cur_front++];
            for (int i = 1; i <= f->node; i++) {
                if (!visited[i] && f->length[tmp][i].data == 1) {
                    next[next_back++] = i;
                    visited[i] = true;
                    count++;
                }
            }
        }

        int temp[Maxn];
        for (int i = 0; i < next_back; i++) {
            temp[i] = next[i];
        }
        for (int i = 0; i < next_back; i++) {
            cur[i] = temp[i];
        }
        cur_front = 0;
        cur_back = next_back;
        next_back = 0;
        next_front = 0;
    }
    return count;
}

        



int main() {
    Figure* f = (Figure*)malloc(sizeof(Figure));
    f = CreatFigure(f);
    for (int i = 1; i <= f->node; i++) {
        printf("%d: %.2lf%%\n", i, (BFS(f, i) / f->node) * 100);
    }
    free(f);
    system("pause");
    return 0;
}