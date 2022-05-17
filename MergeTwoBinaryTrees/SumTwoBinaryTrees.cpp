#include <iostream>
#include <queue>
#include <malloc.h>
using namespace std;

struct node {
	int data;
	node* left;
	node* right;
};



node* sumTwoTrees(node* root1, node* root2) {
	if (root1 == NULL && root2 == NULL) return NULL;
	if (root1 == NULL) return root2;
	if (root2 == NULL) return root1;

	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = root1->data + root2->data;

	newNode->left = sumTwoTrees(root1->left, root2->left);
	newNode->right = sumTwoTrees(root1->right, root2->right);

	return newNode;
}



struct node* newNode(int data)
{
	struct node* node = (struct node*) malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return(node);
}

void dumpInOrder(struct node* root, vector<int>& vec) {
	if (root == nullptr)
		return;
	dumpInOrder(root->left, vec);
	vec.push_back(root->data);
	dumpInOrder(root->right, vec);
}

int main()
{
	struct node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);

	struct node* root2 = newNode(9);
	root2->left = newNode(3);
	root2->right = newNode(2);
	root2->left->left = newNode(7);
	root2->right->left = newNode(16);
	root2->right->right = newNode(97);


	printf("Sum of Two Binary Trees \n");
	struct node* rootX = sumTwoTrees(root, root2);

	vector<int> vec;
	dumpInOrder(rootX, vec);
	for(int i = 0 ; i < vec.size() ; i++)
	{
		cout << vec[i] << " ";
	}


	return 0;
}