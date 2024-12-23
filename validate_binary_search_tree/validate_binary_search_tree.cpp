#include "../common.h"

// https://leetcode.com/problems/validate-binary-search-tree/
//TODO: Fix it


class Solution {
public:
    bool isValidBST(TreeNode* root) {
        
        if (root == nullptr) {
            return true;
        }
        //no children
        if (root->left == nullptr && root->right == nullptr)
            return true;

        //left side
        if (root->left != nullptr && root->left->val >= root->val) {
                return false;
        }

        //right side
        if (root->right != nullptr && root->right->val <= root->val) {
            return false;
        }

        bool bLeft = isValidBST(root->left);
        bool bRight = isValidBST(root->right);

        return bLeft && bRight;
    }
};

int main()
{
	struct TreeNode* root = new TreeNode(5);
	root->left = new TreeNode(4);
	root->right = new TreeNode(6);
    root->left->left = nullptr;
    root->left->right = nullptr;
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(7);

    Solution s;
    cout << s.isValidBST(root);
	return 0;
}
