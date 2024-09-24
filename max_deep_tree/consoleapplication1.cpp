#include <iostream>
#include <queue>
#include <malloc.h>
using namespace std;

struct node {
	int data;
	node* left;
	node* right;
};

int maxDepth(node* root) {
	if (root == NULL)
		return 0;

	int leftSide = 1 + maxDepth(root->left);
	int rightSide = 1 + maxDepth(root->right);
	return max(leftSide, rightSide);
}


struct node* newNode(int data)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return(node);
}

int main()
{
	struct node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(5);
	root->right->left = newNode(4);
	root->left->left = newNode(1);
	root->right->right = newNode(6);
	root->right->right = newNode(7);
	printf("Max Depth %d \n", maxDepth(root));
	

	return 0;
}