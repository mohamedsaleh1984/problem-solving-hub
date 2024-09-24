#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <set>
using namespace std;

//https://leetcode.com/problems/count-good-nodes-in-binary-tree/
/*
Runtime: 161 ms, faster than 65.61% of C++ online submissions for Count Good Nodes in Binary Tree.
*/

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
};

class Solution {
public:
	int goodNodes(TreeNode* root) {
		int currentMax = root->val;
		int mxLeft = goodNodesHelper(root->left, currentMax);
		int mxRight = goodNodesHelper(root->right, currentMax);
		return mxLeft + mxRight+1;
	}

	int goodNodesHelper(TreeNode* root, int currentMax) {
		if (root == nullptr) {
			return 0;
		}

		if (root->val >= currentMax ) {
			currentMax = root->val;
			return 1 + goodNodesHelper(root->left, currentMax) + goodNodesHelper(root->right, currentMax);
		}
		else {
			return  goodNodesHelper(root->left, currentMax) + goodNodesHelper(root->right, currentMax);
		}
	}
};





/* utility that allocates a new node with the
given data and NULL left and right pointers. */
TreeNode* newnode(int data)
{
	TreeNode* Node = new TreeNode();
	Node->val = data;
	Node->left = NULL;
	Node->right = NULL;

	return(Node);
}


int main()
{
	TreeNode* root = newnode(5);
	root->left = newnode(4);
	root->right = newnode(6);

	root->left->left = newnode(3);
	root->left->right = newnode(8);

	Solution s;
	cout << s.goodNodes(root);
	return 0;
}
