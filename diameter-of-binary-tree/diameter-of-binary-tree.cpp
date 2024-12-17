
#include "../common.h"

class Solution {
private:
    int diameter = 0;

public:
    int treeHeight(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int leftHeight = treeHeight(root->left);
        int rightHeight = treeHeight(root->right);

        int dia = leftHeight + rightHeight + 1;
        diameter = max(diameter, dia);

        return max(leftHeight, rightHeight) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        treeHeight(root);
        return diameter-1;
    }
};

int main()
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	
	Solution s;
	cout << s.treeHeight(root) << endl;
    
	return 0;
}
