#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
    int num;
    char name[100];
    int score;
} Student;

void Quicksort(int left, int right, int a, Student* student) {
    if (left >= right)
        return;
    int i = left;
    int j = right;
    if (a == 1) {
        int base = student[left].num;
        while (i < j) {
            while (student[j].num >= base && i < j)
                j--;
            while (student[i].num <= base && i < j)
                i++;
            if (i < j) {
                Student temp = student[i];
                student[i] = student[j];
                student[j] = temp;
            }
        }
        Student temp = student[left];
        student[left] = student[i];
        student[i] = temp;
        Quicksort(left, i - 1, a, student);
        Quicksort(i + 1, right, a, student);
    } else if (a == 2) {
        char base[100];
        strcpy(base, student[left].name);
        while (i < j) {
            while ((strcmp(student[j].name, base) > 0 || (strcmp(student[j].name, base) == 0 && student[j].num >= student[left].num)) && i < j)
                j--;
            while ((strcmp(student[i].name, base) < 0 || (strcmp(student[i].name, base) == 0 && student[i].num <= student[left].num)) && i < j)
                i++;
            if (i < j) {
                Student temp = student[i];
                student[i] = student[j];
                student[j] = temp;
            }
        }
        Student temp = student[left];
        student[left] = student[i];
        student[i] = temp;
        Quicksort(left, i - 1, a, student);
        Quicksort(i + 1, right, a, student);
    } else if (a == 3) {
        int base = student[left].score;
        while (i < j) {
            while ((student[j].score > base || (student[j].score == base && student[j].num >= student[left].num)) && i < j)
                j--;
            while ((student[i].score < base || (student[i].score == base && student[i].num <= student[left].num)) && i < j)
                i++;
            if (i < j) {
                Student temp = student[i];
                student[i] = student[j];
                student[j] = temp;
            }
        }
        Student temp = student[left];
        student[left] = student[i];
        student[i] = temp;
        Quicksort(left, i - 1, a, student);
        Quicksort(i + 1, right, a, student);
    }
}

int main() {
    int n, c;
    scanf("%d %d", &n, &c);
    Student* st = (Student*)malloc((n + 1) * sizeof(Student));
    for (int i = 1; i <= n; i++) {
        scanf("%d", &st[i].num);
        scanf("%s", st[i].name);
        scanf("%d", &st[i].score);
    }
    Quicksort(1, n, c, st);
    for (int i = 1; i <= n; i++) {
        printf("%06d %s %d\n", st[i].num, st[i].name, st[i].score);
    }
    free(st);
    return 0;
}