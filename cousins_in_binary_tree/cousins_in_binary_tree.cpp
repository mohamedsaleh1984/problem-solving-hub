#include <iostream>
#include <queue>
using namespace std;

struct TreeNode;
struct TreeNode* newNode(int data);

//https://leetcode.com/problems/cousins-in-binary-tree/
// 
class Solution {
private: 
public:
	int height(TreeNode* root, int val) {
		
		queue<TreeNode*> Q;
		Q.push(root);
		
		if (root->val == val)
			return 1;
		int heightToReturn = 0;
		bool bFound = false;
		while (!Q.empty())
		{
			TreeNode* topNode = Q.front();

			if (topNode->left != nullptr) {
				if (topNode->left->val == val) {
					heightToReturn++;
					bFound = true;
					break;
				}
				else {
					Q.push(topNode->left);
				}
			}


			if (topNode->right != nullptr) {
				if (topNode->right->val == val) {
					heightToReturn++;
					bFound = true;
					break;
				}
				else {
					Q.push(topNode->right);
				}
			}

			Q.pop();
			heightToReturn++;
		}
		if (bFound)
			heightToReturn++;
		else
			heightToReturn = -1;

		return heightToReturn;
	}

	bool isCousins(TreeNode* root, int x, int y) {
		cout << height(root, x);
		cout << height(root, y);
		return false;
	}
};

int main()
{
	struct TreeNode* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	
	Solution s;

//	cout << s.height(root, 4) << endl;
	cout << s.isCousins(root, 2,3) << endl;
	return 0;
}


struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
};

struct TreeNode* newNode(int data)
{
	struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	node->val = data;
	node->left = NULL;
	node->right = NULL;
	return(node);
}