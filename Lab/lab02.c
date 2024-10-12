// ����һ�ö�����������������к�����������У�Ҫ�����ö������ĸ߶�
// �����ʽ˵�����������ȸ���������N��<=50)��Ϊ���нڵ�����������2���Ⱥ�������������������У�����
// ����ΪN�Ĳ����ظ��ַ�(�����Сд�����ַ�����
// �����ʽ˵��������ö������ĸ߶�
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ����������ڵ�ṹ
typedef struct Node {
    char val;
    struct Node *left;
    struct Node *right;
} Node;
typedef Node TreeNode;

TreeNode* newNode(char val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

TreeNode* buildTree(char* preorder, char* inorder, int inorderStart, int inorderEnd, int* preorderIndex) {
    if (inorderStart > inorderEnd) {
        return NULL;
    }

    char currentVal = preorder[*preorderIndex];
    (*preorderIndex)++;

    TreeNode* node = newNode(currentVal);

    if (inorderStart == inorderEnd) {
        return node;
    }

    int inorderIndex = inorderStart;
    while (inorder[inorderIndex] != currentVal) {
        inorderIndex++;
    }

    node->left = buildTree(preorder, inorder, inorderStart, inorderIndex - 1, preorderIndex);
    node->right = buildTree(preorder, inorder, inorderIndex + 1, inorderEnd, preorderIndex);
    return node;
}

int calculateHeight(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

void freeTree(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int N;
    scanf("%d", &N);
    char preorder[N + 1];
    char inorder[N + 1];
    scanf("%s", preorder);
    scanf("%s", inorder);
    int preorderIndex = 0;
    TreeNode* root = buildTree(preorder, inorder, 0, N - 1, &preorderIndex);
    int height = calculateHeight(root);
    printf("%d", height);
    freeTree(root);
    return 0;
}
