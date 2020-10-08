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

int main() {
	struct node* root = newNode(1);
	struct node* rootLeft = addLeft(root, 2);
	struct node* rootRight = addRight(root, 4);
	struct node* LeftLeft = addLeft(rootLeft, 3);
	printf("\nInorder Traversal: ");
	inOrder(root);
	printf("\n");
	return 0;
}