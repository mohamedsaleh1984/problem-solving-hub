#include "../common.h"

// https://leetcode.com/problems/minimum-depth-of-binary-tree
// 0 ms Beats 100.00%
// 12/16/2024

class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        // leaf node
        if (root->left == nullptr && root->right == nullptr)
        {
            return 1;
        }

        int l = INT_MAX;
        int r = INT_MAX;

        if (root->left)
            l = minDepth(root->left) + 1;
        if (root->right)
            r = minDepth(root->right) + 1;

        return min(l, r);
    }
};

int main()
{
    return 0;
}