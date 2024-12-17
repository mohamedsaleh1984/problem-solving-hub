#include "../common.h"

//https://leetcode.com/problems/cousins-in-binary-tree/
// 0ms Beats 100.00%
// 12/16/2024
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
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	
	Solution s;

//	cout << s.height(root, 4) << endl;
	cout << s.isCousins(root, 2,3) << endl;
	return 0;
}

 