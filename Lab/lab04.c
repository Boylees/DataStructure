#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define Maxn 10
#define Minn 2
#define MaxHashTable 600000

typedef char Word[Maxn + 1];

typedef struct WordList {
    int word;
    struct WordList* next;
} IndexList;

typedef struct FileList {
    int No;
    struct FileList* next;
} Filetable;

typedef struct HashHeader {
    Word word;
    int No;
    struct FileList* next;
} HashHeader;

typedef struct Hashtable {
    int size;
    HashHeader array[MaxHashTable];
} Hashtable;

// 初始化索引链表
IndexList* WordListInit(int size) {
    IndexList* ilist = (IndexList*)malloc(sizeof(IndexList) * size);
    if (!ilist) {
        perror("Failed to allocate memory for WordList");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < size; i++) {
        ilist[i].word = 0;
        ilist[i].next = NULL;
    }
    return ilist;
}

// 初始化哈希表
Hashtable* HashInit(int size) {
    Hashtable* ht = (Hashtable*)malloc(sizeof(Hashtable));
    if (!ht) {
        perror("Failed to allocate memory for Hashtable");
        exit(EXIT_FAILURE);
    }
    ht->size = size;
    for (int i = 0; i < size; i++) {
        ht->array[i].No = 0;
        ht->array[i].next = NULL;
        ht->array[i].word[0] = '\0';
    }
    return ht;
}

// 读取单词
int ReadWord(Word word) {
    char c;
    int i = 0;
    // 读取第一个有效字符
    scanf("%c", &c);
    while ((!isalpha(c)) && (c != '#')) {
        scanf("%c", &c);
    }
    if (c == '#') {
        return 0;
    }
    // 读取单词，转换为小写
    while (isalpha(c) && i < Maxn) {
        word[i++] = tolower(c);
        scanf("%c", &c);
    }
    // 读取剩余字符（如果单词长度超过Maxn）
    while (isalpha(c)) {
        scanf("%c", &c);
    }
    if (i <= Minn) { // 如果单词长度小于等于Minn，则抛弃该单词
        return ReadWord(word);
    } else {
        word[i] = '\0';
        return 1;
    }
}

// 计算哈希值
int CalculateLocation(char* word, int tablesize) {
    unsigned int h = 0;
    while (*word != '\0') {
        h = (h << 5) + (*word++);
    }
    return h % tablesize;
}

// 查找插入位置
int FindLocation(Word word, Hashtable* Ht) {
    int pos = CalculateLocation(word, Ht->size);
    while (Ht->array[pos].No && strcmp(Ht->array[pos].word, word)) {
        pos++;
        if (pos == MaxHashTable) {
            pos = 0;
        }
    }
    return pos;
}

// 插入哈希表
int InsertHash(Word word, int no, Hashtable* Ht) {
    int pos = FindLocation(word, Ht);
    if (Ht->array[pos].No != no) { // 判断是否为同一个文件的重复单词
        if (!Ht->array[pos].No) { // 新单词
            strcpy(Ht->array[pos].word, word);
        }
        Ht->array[pos].No = no;
        // 创建新的文件节点
        Filetable* Ft = (Filetable*)malloc(sizeof(Filetable));
        if (!Ft) {
            perror("Failed to allocate memory for Filetable");
            exit(EXIT_FAILURE);
        }
        Ft->No = no;
        Ft->next = Ht->array[pos].next;
        Ht->array[pos].next = Ft;
        return pos;
    } else {
        return -1; // 重复单词
    }
}

// 插入索引表
void InsertWorkFile(IndexList* IL, int no, int pos) {
    if (pos < 0) {
        return;
    }
    IndexList* il = (IndexList*)malloc(sizeof(IndexList));
    if (!il) {
        perror("Failed to allocate memory for IndexList");
        exit(EXIT_FAILURE);
    }
    il->word = pos;
    il->next = IL[no - 1].next;
    IL[no - 1].next = il;
    IL[no - 1].word++;
}

// 查找重复
void FindRepeat(IndexList* IL, int n1, int n2, Hashtable* Ht) {
    int num = 0;
    double radio;
    IndexList* il;
    Filetable* ft;

    if (IL[n1 - 1].word > IL[n2 - 1].word) { // 交换n1和n2
        int temp = n1;
        n1 = n2;
        n2 = temp;
    }

    il = IL[n1 - 1].next;
    while (il != NULL) {
        ft = Ht->array[il->word].next;
        while (ft != NULL) {
            if (ft->No == n2) {
                break;
            }
            ft = ft->next;
        }
        if (ft) {
            num++;
        }
        il = il->next;
    }
    if ((IL[n1 - 1].word + IL[n2 - 1].word - num) == 0) {
        radio = 0.0;
    } else {
        radio = ((double)num * 100) / (double)(IL[n1 - 1].word + IL[n2 - 1].word - num);
    }
    printf("%.1lf%%\n", radio);
}

int main() {
    int n, m, n1, n2;
    Word word;
    Hashtable* Ht;
    IndexList* IL;

    // 读取文件数量
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Failed to read the number of files.\n");
        return EXIT_FAILURE;
    }

    IL = WordListInit(n);
    Ht = HashInit(MaxHashTable);

    // 读取每个文件的单词并插入哈希表
    for (int i = 0; i < n; i++) {
        while (ReadWord(word)) {
            InsertWorkFile(IL, i + 1, InsertHash(word, i + 1, Ht));
        }
    }

    // 读取查询数量
    if (scanf("%d", &m) != 1) {
        fprintf(stderr, "Failed to read the number of queries.\n");
        return EXIT_FAILURE;
    }

    // 处理每个查询
    for (int i = 0; i < m; i++) {
        if (scanf("%d %d", &n1, &n2) != 2) {
            fprintf(stderr, "Failed to read query %d.\n", i + 1);
            return EXIT_FAILURE;
        }
        FindRepeat(IL, n1, n2, Ht);
    }

    // 释放内存（可选，但推荐）
    // 释放哈希表中的文件列表
    for (int i = 0; i < Ht->size; i++) {
        Filetable* ft = Ht->array[i].next;
        while (ft) {
            Filetable* temp = ft;
            ft = ft->next;
            free(temp);
        }
    }
    free(Ht);

    // 释放索引链表
    for (int i = 0; i < n; i++) {
        IndexList* il = IL[i].next;
        while (il) {
            IndexList* temp = il;
            il = il->next;
            free(temp);
        }
    }
    free(IL);

    return 0;
}
