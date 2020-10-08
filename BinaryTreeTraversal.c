#include<stdio.h>
#include<stdlib.h>

struct node {
	int val;
	struct node *left, *right;
};

struct node* newNode(int val) {
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->val = val;
	node->left = NULL;
	node->right = NULL;
	return node;
}

struct node* addLeft(struct node* n, int val) {
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->val = val;
	n->left = node;
	return node;
}

struct node* addRight(struct node* n, int val) {
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->val = val;
	n->right = node;
	return node;
}

void inOrder(struct node* root) {
	if (root == NULL)
		return;
	inOrder(root->left);
	printf("%d ", root->val);
	inOrder(root->right);
}

void preOrder(struct node* root) {
	if (root == NULL)
		return;
	printf("%d ", root->val);
	preOrder(root->left);
	preOrder(root->right);
}

void postOrder(struct node* root) {
	if (root == NULL)
		return;
	preOrder(root->left);
	preOrder(root->right);
	printf("%d ", root->val);
}

int main() {
	struct node* root = newNode(1);
	struct node* rootLeft = addLeft(root, 2);
	struct node* rootRight = addRight(root, 3);
	struct node* LeftLeft = addLeft(rootLeft, 4);
	struct node* LeftRight = addRight(rootLeft, 5);
	printf("\nInOrder Traversal: ");
	inOrder(root);
	printf("\nPreOrder Traversal: ");
	preOrder(root);
	printf("\nPostOrder Traversal: ");
	postOrder(root);
	printf("\n");
	return 0;
}