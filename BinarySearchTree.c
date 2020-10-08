#include<stdio.h>
#include<stdlib.h>

struct node {
    int val;
    struct node *left, *right;
};

struct node *newNode(int val) {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct node *insert(struct node *node, int val) {
    if (node == NULL)
        return newNode(val);

    if (val < node->val)
        node->left = insert(node->left, val);
    else if (val > node->val)
        node->right = insert(node->right, val);

    return node;
}

struct node* search(struct node* root, int val) {
    if (root == NULL || root->val == val)
        return root;

    if (root->val < val)
        return search(root->right, val);
    return search(root->left, val);
}

void inOrder(struct node *root) {
    if (root == NULL)
        return;
    inOrder(root->left);
    printf("%d ", root->val);
    inOrder(root->right);
}

int main() {
    struct node *root = NULL;
    root = insert(root, 1);
    insert(root, 4);
    insert(root, 2);
    insert(root, 3);
    insert(root, 5);
    insert(root, 8);
    insert(root, 6);
    printf("Inorder Traversal: ");
    inOrder(root);
    printf("\n");
}