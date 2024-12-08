#include <iostream>
#include <queue>
#include <malloc.h>
using namespace std;


struct node {
	int data;
	node* left;
	node* right;
};
struct node* newNode(int data)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return(node);
}

int SumOfRootToLeaf(node* root) {
	if (root == NULL)
		return 0;
	return root->data + SumOfRootToLeaf(root->left) + SumOfRootToLeaf(root->right);
}


int main()
{
	struct node* root = newNode(2);
	root->left = newNode(1);
	root->right = newNode(4);
	root->left->left = newNode(4);
	root->left->right = newNode(-1);
	root->left->right->left = newNode(-5);
	root->right->right = newNode(-5);

	//-11 + 10 = -1
	cout << SumOfRootToLeaf(root) << endl;

	return 0;
}

 