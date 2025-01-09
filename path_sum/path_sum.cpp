#include "../common.h"

class Solution
{
public:
	// decrease the value and check left/right trees.
	bool hasPathSum(TreeNode *root, int targetSum)
	{
		if (root == NULL)
			return false;

		targetSum = targetSum - root->val;

		if (root->left == NULL && root->right == NULL && targetSum == 0)
			return true;

		bool leftSubTree = hasPathSum(root->left, targetSum);
		bool rightSubTree = hasPathSum(root->right, targetSum);
		return leftSubTree || rightSubTree;
	}
};

int main()
{

	struct TreeNode *t4 = new TreeNode(1);
	t4->left = new TreeNode(2);

	Solution s;
	printf("has Path Sum %d \n", s.hasPathSum(t4, 1));

	return 0;
}
