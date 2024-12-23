#include "../common.h"
/*
https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
*/
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
};

struct TreeNode* newNode(int data);
void findTargetHelper(TreeNode* root, vector<int>& visited) {
	if (root == NULL)
		return;
	findTargetHelper(root->left, visited);
	visited.push_back(root->val);
	findTargetHelper(root->right, visited);
}

bool findTarget(TreeNode* root, int k) {
	if (root == NULL)
		return false;

	vector<int> visitedNodes;
	findTargetHelper(root, visitedNodes);
	if (visitedNodes.size() == 1 && visitedNodes[0] != k) {
		return false;
	}

	for (int i = 0; i < visitedNodes.size(); i++) {
		int rem = k - visitedNodes[i];
		if (find(visitedNodes.begin() + i + 1, visitedNodes.end(), rem) != visitedNodes.end()) {
			return true;
		}
	}
	return false;
}


int main()
{ 
	struct TreeNode* root = newNode(5);
	root->left = newNode(3);
	root->right = newNode(6);
	root->left->left = newNode(2);
	root->left->right = newNode(4);
	root->right->right = newNode(7);
	int k = 9;
	printf("findTarget %d %d\n", k,findTarget(root,k));
}


struct TreeNode* newNode(int data)
{
	struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	node->val = data;
	node->left = NULL;
	node->right = NULL;
	return(node);
}