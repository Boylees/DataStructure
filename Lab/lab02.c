// 给定一棵二叉树的先序遍历序列和中序遍历序列，要求计算该二叉树的高度
// 输入格式说明：输入首先给出正整数N（<=50)，为树中节点总数。下面2行先后给出先序和中序遍历序列，均是
// 长度为N的不含重复字符(区别大小写）的字符串。
// 输出格式说明：输出该二叉树的高度
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义二叉树节点结构
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
