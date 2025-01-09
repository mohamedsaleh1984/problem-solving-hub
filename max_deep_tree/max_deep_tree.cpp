#include "../common.h"

struct node
{
	int data;
	node *left;
	node *right;
	node(int v)
	{
		data = v;
		left = right = NULL;
	}
};

int maxDepth(node *root)
{
	if (root == NULL)
		return 0;

	int leftSide = 1 + maxDepth(root->left);
	int rightSide = 1 + maxDepth(root->right);
	return max(leftSide, rightSide);
}

int main()
{
	struct node *root = new node(1);
	root->left = new node(2);
	root->right = new node(5);
	root->right->left = new node(4);
	root->left->left = new node(1);
	root->right->right = new node(6);
	root->right->right = new node(7);
	printf("Max Depth %d \n", maxDepth(root));

	return 0;
}