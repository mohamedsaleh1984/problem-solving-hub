#include "../common.h"

class Solution
{
public:
	vector<vector<int>> pathSum(TreeNode *root, int targetSum)
	{
		vector<vector<int>> res = {{}};
		vector<int> entry = {};
		// entry.push_back(root->val);
		pathSumFiller(root, targetSum, entry, res);
		return res;
	}

	void pathSumFiller(TreeNode *root, int targetSum, vector<int> &entry, vector<vector<int>> &res)
	{
		if (root == NULL)
			return;
		targetSum = targetSum - root->val;

		if (root->left == NULL && root->right == NULL && targetSum == 0)
		{
			res.push_back(entry);
		}
		else
		{
			entry.push_back(root->val);
			pathSumFiller(root->left, targetSum, entry, res);
			pathSumFiller(root->right, targetSum, entry, res);
		}
	}
};

int main()
{
	struct TreeNode *root = new TreeNode(5);
	root->left = new TreeNode(4);
	root->left->left = new TreeNode(11);
	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(2);

	root->right = new TreeNode(8);
	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);
	root->right->right->right = new TreeNode(1);
	root->right->right->left = new TreeNode(5);

	Solution s;
	vector<vector<int>> result = s.pathSum(root, 22);

	return 0;
}
