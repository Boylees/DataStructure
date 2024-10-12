// 设计函数求一元多项式的导数。
// 输入格式说明：以指数递降方式输入多项式非零项的系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔

// 输出格式说明：以与输入相同的格式输出导数多项式非零项的系数和指数。数字间以空格分隔，行末不得有多余空格。
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int xishu;
    int zhishu;
    struct Node *next;
};

typedef struct Node *duoxiangshi;
void insert(duoxiangshi *head, duoxiangshi *rear, int xishu, int zhishu) {
    duoxiangshi xiang = (duoxiangshi)malloc(sizeof(struct Node));
    xiang->xishu = xishu;
    xiang->zhishu = zhishu;
    xiang->next = NULL;
    if (*head == NULL) {
        *head = xiang;
        *rear = xiang;
    } else {
        (*rear)->next = xiang;
        *rear = xiang;
    }
}

void printduoxiangshi(duoxiangshi head) {
    duoxiangshi temp = head;
    while (temp != NULL) {
        printf("%d %d", temp->xishu, temp->zhishu);
        if (temp->next != NULL) {
            printf(" ");
        }
        temp = temp->next;
    }
    printf("\n");
}

duoxiangshi qiudao(duoxiangshi head) {
    duoxiangshi temp = head;
    duoxiangshi result = NULL;
    duoxiangshi resultrear = NULL;
    while (temp != NULL) {
        if (temp->zhishu != 0) {
            int new_xishu = temp->xishu * temp->zhishu;
            int new_zhishu = temp->zhishu - 1;
            insert(&result, &resultrear, new_xishu, new_zhishu);
        }
        temp = temp->next;
    }
    return result;
}

void freeList(duoxiangshi head) {
    duoxiangshi temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3 || argc % 2 == 0) {
        printf("error\n");
        return 0;
    }
    duoxiangshi head = NULL;
    duoxiangshi rear = NULL;
    for (int i = 1; i < argc; i += 2) {
        int xishu = atoi(argv[i]);
        int zhishu = atoi(argv[i + 1]);
        insert(&head, &rear, xishu, zhishu);
    }
    duoxiangshi result = qiudao(head);
    if (result == NULL) {
        printf("0 0\n");
    } else {
        printduoxiangshi(result);
    }
    freeList(head);
    freeList(result);
    return 0;
}